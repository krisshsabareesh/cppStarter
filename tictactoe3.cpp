#include <iostream>
#include <string.h>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

class GameBoard {
	std::string ch;
public: 
	int init() {	//Function to initialise the character string to a default char array : here '-'
		int i;
		for(i=0;i<9;i++)
			ch = ch + '-';
		return 0;
	}
	int draw() {	//Function to draw the updated board
		int i,j;
		for(i=0;i<3;i++) {
			std::cout << "|-----|-----|-----|" << std::endl;
			std::cout << "|     |     |     |" << std::endl;
			std::cout << "|  " << ch[i*3] << "  |  " << ch[i*3+1] << "  |  " << ch[i*3+2] << "  |" << std::endl;
			std::cout << "|     |     |     |" << std::endl;
			std::cout << "|-----|-----|-----|" << std::endl;
		}
	}
	int insert(int n, char p) {	//Function to insert a character p to a specified location n in the character array
		if(ch[n-1] == '-') {
			ch[n-1] = p;
			return 1;
		} else {
			return 0;
		}
	}
	
	int check(char c) { 	//To check the win conditions
		int i;
		for(i=0;i<3;i++) {
			//Horizontal check
			if(c == ch[i*3] && ch[i*3] == ch[i*3+1] && ch[i*3+1] == ch[i*3+2])
				return 1;
			//Vertical check
			if(c == ch[i] && ch[i] == ch[i+3] && ch[i+3] == ch[i+3*2])
				return 1;
		}
		//diagonal check
		if (c == ch[0] && ch[0] == ch[4] && ch[4] == ch[8])
			return 1;
		//cross diagonal check
		if (c == ch[2] && ch[2] == ch[4] && ch[4] == ch[6])
			return 1;
		return 0;
	 }

	std::vector<int> getList() { //Get a list of free positions in the character array
		std::vector<int> list;
		int i;
		for (i=0;i<ch.size();i++) {
			if(ch[i] == '-')
				list.push_back(i+1);
		}
		return list;
	}

	int full() {	//Check whether the board is full
		int i;
		for(i=0;i<9;i++) {
			if (ch[i] == '-')
				return 0;
		}
		return 1;
	}
};


//Class defining common player attributes
class Player {
	char p;
public:
	Player(char in) : p(in) {}
	virtual int markOn() = 0;	//pure virtual function markOn
	virtual char getPlayerChar() = 0;	//Creates a pure virtual function getPlayerChar
};

char Player::getPlayerChar() { return p; }  //Return character stored in the player object

//Class defining a human player
class HumanPlayer: public Player{
public:
	HumanPlayer(char ch) : Player(ch) { }

	int markOn() {
		int n; 
		std::cout << "Enter a number(1-9) : " ;
		std::cin >> n;
		return n;
	}
	
	char getPlayerChar() { return Player::getPlayerChar(); }	//returns the player char
};

//Class defining a pc player
class PC_Player : public Player {
	GameBoard &g;
public:
	PC_Player(char ch,GameBoard &tg) : Player(ch), g(tg) { }
	int markOn() {
		std::vector<int> l = g.getList();
		int i;
		std::cout << "getting from :";
		for(i=0;i<l.size();i++)
			std::cout << " " << l[i];
		std::cout << std::endl;
		srand(time(NULL));
		int index = rand() % l.size();
		return l[index]; 
	}
	
	char getPlayerChar() { return Player::getPlayerChar(); }	//returns the player char
};

class GameController {		//Function to control the whole game
	GameBoard gb;
public:
	GameController() { gb.init(); }
	
	void startGame() {
		std::shared_ptr<Player> user = std::make_shared<HumanPlayer>('X');
		std::shared_ptr<Player> pc = std::make_shared<PC_Player>('O',gb);
		srand(time(NULL));
		int playing = rand() % 2;
		std::vector<int> list;
	
		while(1) {
			if(playing == 0) {
				list = gb.getList();
				gb.insert(pc->markOn(),pc->getPlayerChar());
				playing = 1;
			}
			else{
				do {
					if(gb.insert(user->markOn(),user->getPlayerChar()))
						break;
					else {
						std::cout << "Wrong entry or column already occupied" << std::endl;
						std::cout << "Please enter again" << std::endl;
					}
				} while(1);
				playing = 0;
			}
			gb.draw();
			if(playing == 0) {
				if(gb.check(user->getPlayerChar())) {
					std::cout << "Player X wins!!!" << std::endl;
					break;	
				}
			}
			else {
				if(gb.check(pc->getPlayerChar())) {
					std::cout << "Player O wins" << std::endl;
					break;
				}
			}
			if(gb.full()) {
				std::cout << "Game over --- All columns filled" << std::endl;
				break;
			}
		}
	}
};

int main() {
	GameController gc;
	gc.startGame();

	return 0;
}
