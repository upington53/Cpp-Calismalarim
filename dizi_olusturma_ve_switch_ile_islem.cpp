#include <iostream>
#include <string>
using namespace std;

struct Operator {
	int sayilar[],x,y,z;
	int islem;
};
void dizimiz(int sayilar1[],int x) {
		for (int y=0 ; y<x ; y++) {
		cout<<"\nLutfen "<< y+1 << ". sayiyi giriniz: "<<endl;
		cin>>sayilar1[y];
	}
}
void dizi_islemi (int sayilar2[],int x){
	cout<<"Dizinin elemanlari; ";
	
	for (int y=0 ; y<x ; y++) {
		cout<<sayilar2[y]<<",";
	}
	cout<<endl;
}
void yapilacak_islem (int sayilar3[],int a1, int islem1){
	
	switch(islem1){
		case(1):{
			sayilar3[a1] += a1;
			cout<<"Arttirma islemi sonucunuz: "<<sayilar3[a1]<<endl;
			break;
		}
		case(2):{
			sayilar3[a1] -= a1;
			cout<<"Arttirma islemi sonucunuz: "<<sayilar3[a1]<<endl;
			break;
		}
	}
	
}


int main(){
	Operator operator1;
	int a,b,c;
	cout<<"Lutfen dizi uzunlugunu giriniz: "<<endl;
	cin>> operator1.x;
	a=operator1.x;
	operator1.sayilar[a];
	dizimiz(operator1.sayilar,a);
	dizi_islemi(operator1.sayilar,a);
	cout<<"Dizinin hangi indisine islem yapmak istiyorsunuz?: "<<endl;
	cin>>b;
	operator1.y=b;
	cout<<"Dizinin"<< operator1.y<<". indisine hangi islemi yapmak istiyorsunuz?: "<<endl;
	cout<<"(Arttirma icin 1 yaziniz)"<<endl;
	cout<<"(Azaltma icin 2 yaziniz)"<<endl;
	cin>>operator1.islem;
	yapilacak_islem(operator1.sayilar,operator1.y,operator1.islem);
	delete [] operator1.sayilar; // Belleði serbest býrakma
}
