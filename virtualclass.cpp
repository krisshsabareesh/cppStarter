#include<iostream>

//A simple class 
class OrdinaryClass {
public:
	void display() {
		std::cout << "Inside ordinary class" << std::endl;
	}
};

//child class of ordinary class
class OrdinaryChild: public OrdinaryClass {
public:
	void display() {
		std::cout << "Inside ordinary child" << std::endl;
	}
};

//An abstract class
class AbstractClass {
public: 
	virtual void display() = 0;
};

void AbstractClass::display() {
		std::cout << "Inside abstract class" << std::endl;
}

class AbstractChild: public AbstractClass{
public:
	void display() {
		std::cout << "Inside abstract child" << std::endl;
	}
};

int main() {
	OrdinaryClass *oc = new OrdinaryChild;
	AbstractClass *ac = new AbstractChild;
	ac -> display();
	oc -> display();
	return 0;
}
