#include <iostream>
#include <string>
using namespace std;

void dizimiz(int sayilar[],int x) {
		for (int y=0 ; y<x ; y++) {
		cout<<"\nLutfen "<< y+1 << ". sayiyi giriniz: "<<endl;
		cin>>sayilar[y];
	}
}
void dizi_islemi (int sayilar[],int x){
	cout<<"Dizinin elemanlari; ";
	
	for (int y=0 ; y<x ; y++) {
		cout<<sayilar[y]<<",";
	}
	int islem;
	int indis1, indis2;
	cout<<"Hangi islemi yapmak istiyorsunuz? "<<endl;
	cout<<"1.Toplama "<<endl;
	cout<<"2.Cikarma "<<endl;
	cout<<"3.Carpma "<<endl;
	cout<<"4.Bolme "<<endl;
	cin >> islem;
		if (islem >= 1 && islem <=4) {
        switch(islem){
		case(1):{
			cout<<"Lutfen toplama yapmak istediginiz 1.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis1;
			cout<<"Lutfen toplama yapmak istediginiz 2.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis2;
			int toplam;
			toplam= sayilar[indis1] + sayilar[indis2];
			cout <<"Toplam sonucunuz; " << toplam <<endl;
			break;
		}
		case(2):{
			cout<<"Lutfen cikarma yapmak istediginiz 1.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis1;
			cout<<"Lutfen cikarma yapmak istediginiz 2.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis2;
			int toplam;
			toplam= sayilar[indis1] - sayilar[indis2];
			cout <<"Cikarma sonucunuz; " << toplam <<endl;
			break;
		}
		case(3):{
			cout<<"Lutfen carpim yapmak istediginiz 1.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis1;
			cout<<"Lutfen carpim yapmak istediginiz 2.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis2;
			int toplam;
			toplam= sayilar[indis1] * sayilar[indis2];
			cout <<"Carpim sonucunuz; " << toplam <<endl;
			break;
		}
		case(4):{
			cout<<"Lutfen bolme yapmak istediginiz 1.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis1;
			cout<<"Lutfen bolme yapmak istediginiz 2.sayinin dizideki indisini giriniz "<<endl;
			cin >> indis2;
			int toplam;
			toplam= sayilar[indis1] / sayilar[indis2];
			cout <<"Bolme sonucunuz; " << toplam <<endl;
			break;
		}
		}
   		} else {
        cout << "Gecersiz sayi!" << endl;
		}
	
}

int main(){
	int x,y,z;
	cout<<"Lutfen dizi uzunlugunu giriniz: "<<endl;
	cin>> x;
	int sayilar[x];
	
	dizimiz(sayilar,x);	
	dizi_islemi(sayilar,x);
	delete [] sayilar; // Belleði serbest býrakma
}
