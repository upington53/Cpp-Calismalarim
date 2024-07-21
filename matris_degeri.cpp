#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){
	int a,b;
	cout<<"Kaca kaclik Matris istiyorunuz: ([a][b] seklinde yaziniz)"<<endl;
	cout<<"a= ";
	cin>>a;
	cout<<"b= ";
	cin>>b;
	
	int matris[a][b];
	cout<< a <<"x"<< b <<" Matris degerlerini sirasiyla giriniz: "<<endl;
	cout<<"Ornek: 1,2,3  4,5,6  7,8,9"<<endl;
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin>>matris[i][j];
		}
	}
	
	cout<<"Matrisiniz: "<<endl;
	
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cout<<matris[i][j] << " ";
		}
		cout<<endl;
	}
	
	return 0;
}
	
