#include <iostream>
#include <string>

enum {a=0,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

int place(char ch) {
	switch(ch) {
		case 'a' : return a;
		case 'b' : return b;
		case 'c' : return c;
		case 'd' : return d;
		case 'e' : return e;
		case 'f' : return f;
		case 'g' : return g;
		case 'h' : return h;
		case 'i' : return i;
		case 'j' : return j;
		case 'k' : return k;
		case 'l' : return l;
		case 'm' : return m;
		case 'n' : return n;
		case 'o' : return o;
		case 'p' : return p;
		case 'q' : return q;
		case 'r' : return q;
		case 's' : return s;
		case 't' : return t;
		case 'u' : return u;
		case 'v' : return v;
		case 'w' : return w;
		case 'x' : return x;
		case 'y' : return y;
		case 'z' : return z;	

		case 'A' : return a;
                case 'B' : return b;
                case 'C' : return c;
                case 'D' : return d;
                case 'E' : return e;
                case 'F' : return f;
                case 'G' : return g;
                case 'H' : return h;
                case 'I' : return i;
                case 'J' : return j;
                case 'K' : return k;
                case 'L' : return l;
                case 'M' : return m;
                case 'N' : return n;
                case 'O' : return o;
                case 'P' : return p;
                case 'Q' : return q;
                case 'R' : return r;
                case 'S' : return s;
                case 'T' : return t;
                case 'U' : return u;
                case 'V' : return v;
                case 'W' : return w;
                case 'X' : return x;
                case 'Y' : return y;
                case 'Z' : return z;
	}
}

class Letter{
	int item;
public:
	Letter *link[26];
	Letter(int d) : item(d) {
		int i;
		for (i=0; i<26; i++) {
			link[i] = NULL;
		}
	}
	void display() {
		std::cout << " Item value: " << item+1 << std::endl;
	}
}*dictHead=NULL;

Letter* insert(Letter *head,char *ch, int n) {
	if(head == NULL && ch[0] != '\0') {
		head = new Letter(n);
		std::cout << "New link created at : " << ch[0];
	}
	if(head != NULL && ch[0] != '\0') {
		head -> display();
		ch = ch + 1;
		if (ch[0] != '\0') {
			n = place(ch[0]);
			head -> link[n] = insert(head -> link[n], ch, n);
		}
	}
	return head;		
}

void search(Letter *head, char *ch) {
	std::cout << "Received word : " << ch << " - for item " ;
	if(head != NULL)
		head -> display();
	if(head != NULL && ch[0] != '\0') {
		ch = ch + 1;
		if(ch[0] != '\0') 
			search(head -> link[place(ch[0])], ch);
	}
	else {
		std::cout << "Search failed" << std::endl; 
	}
	if (ch[0] == '\0') {
		std::cout << "Search success" << std::endl;
	}
}

int main () {
	int i,n,ch=1;
	char word[100];
	dictHead = new Letter(-1);
	
	while(ch){
	std::cout << "Enter 0.EXIT 1.INSERT 2.SEARCH 3.DELETE" << std::endl;
	std::cin >> ch;
	switch (ch) {
		case 0: std::cout << "Exiting....!!!" << std::endl;
			break;
		case 1: std::cout << "Enter word : ";
			std::cin >> word;
			if(word[0] != '\0') {
				n = place(word[0]);
				dictHead -> link[n]  = insert(dictHead -> link[n], word, n);
			}
			break;
		case 2: std::cout << "Enter word to search : " ;
			std::cin >> word;
			std::cout << "Started searching at " << word[0] << " for " << word << std::endl;
			if(word[0] != '\0') {
				n = place(word[0]);
				search(dictHead -> link[n], word);
			}
			break;
		default:std::cout << "Wrong entry!!! " << std::endl; 
	}
	}
	return 0;
}
