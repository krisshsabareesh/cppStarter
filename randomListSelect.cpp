#include <iostream>
//#include <random>
#include <vector>
#include <cstdlib>
#include <ctime>


std::vector<int> makeList() {
	std::vector<int> list;
	int i=1;
	list.push_back(i);
	return list;
}
int main()
{
	std::vector<int> l;
	l = makeList();//{1,2};
	int i;
	for (i=0;i<l.size();i++)
		std::cout << l[i] << std::endl;
	/*l = &list[0];
	srand(time(NULL));
	int index = rand() % list.size();
	int value = list[index];
	std::cout << "Hello World : I got this value --> " << value << std::endl; 
	std::cout << "Second value in the list is --> " << l[1] << std::endl;
//srand(time(NULL));
//std::cout << rand() << std::endl;*/
	return 0;
}
