#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int deger(int d){
	if(d>10) {
		d++;
		cout<< "Yeni deger: " << d <<endl;
	}
	else {
		d--;
		cout<< "Yeni deger: " << d <<endl;
	}
	
}
int main(){
	int d;
	cout<< "Integer girin: " <<endl;
	cin>>d;
	cout<< deger(d) << endl;
	
	return 0;
}
	
