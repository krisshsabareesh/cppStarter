#include <iostream>
#include <string.h>
class GameBoard {
	std::string ch;
public: 
	int init() {
		int i;
		for(i=0;i<9;i++)
			ch = ch + '-';
		return 0;
	}
	int draw() {
		int i,j;
		for(i=0;i<3;i++) {
			std::cout << "|-----|-----|-----|" << std::endl;
			std::cout << "|     |     |     |" << std::endl;
			std::cout << "|  " << ch[i*3] << "  |  " << ch[i*3+1] << "  |  " << ch[i*3+2] << "  |" << std::endl;
			std::cout << "|     |     |     |" << std::endl;
			std::cout << "|-----|-----|-----|" << std::endl;
		}
	}
	int insert(int n, char p) {
		if(ch[n-1] == '-') {
			ch[n-1] = p;
			return 1;
		} else {
			return 0;
		}
	}
	
	int check(char c) { 
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

	int full() {
		int i;
		for(i=0;i<9;i++) {
			if (ch[i] == '-')
				return 0;
		}
		return 1;
	}
};

class Player {
	char p;
public:
	Player(char in) : p(in) {}
	int markOn(GameBoard &gp) {
		int n;
		do{
	 		std::cout << "Enter a number : (1-9)";
			std::cin >> n;
			if(gp.insert(n, p))
				return 0;
			else {
				std::cout << "Wrong entry or already occupied" << std::endl;
				continue;
			}
		}while(1);
	}
	int checkOn(GameBoard &gp) {
		return gp.check(p);
	}
};

int main() {
	GameBoard g;
	Player a('X'),b('O');
	g.init();
	while(1) {
		a.markOn(g);
		g.draw();
		if(a.checkOn(g)) {
			std::cout << "Game over --- Player one wins!!!" << std::endl;
			break;
		}
		if(g.full()) {
			std::cout << "Game over --- All columns filled" << std::endl;
			break;
		}
		b.markOn(g);
		g.draw();
		if(b.checkOn(g)) {
			std::cout << "Game over --- Player two wins!!!" << std::endl;
			break;
		}
	}
	return 0;
}
