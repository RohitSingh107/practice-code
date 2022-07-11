#include <iostream>
using namespace std;

int main(){
	register int i = 47;
	int *ptr = &i;
	std::cout << *ptr << std::endl;
	return 0;
}
