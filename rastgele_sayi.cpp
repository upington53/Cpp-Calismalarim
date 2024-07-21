#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	int a;
	cout<< "0-5 araliginda rastgele degerler" <<endl;
	
	for (a=0; a<3; ++a) {
		cout<< rand() %6 <<endl;

	}
	
	cout<< "10-17 araliginda rastgele degerler" <<endl;
		for (a=0; a<3; ++a) {
		cout<< rand() %8 + 10 <<endl;
	}
	return 0;
}
