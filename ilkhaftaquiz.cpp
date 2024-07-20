#include <iostream>
using namespace std;
int main() {
	int x,y,z;
	cout<<"Lutfen dizi uzunlugunu giriniz: "<<endl;
	cin>> x; 
	int sayilar[x];
	
	for (y=0 ; y<x ; y++) {
		cout<<"\nLutfen "<< y+1 << ". sayiyi giriniz: "<<endl;
		cin>>sayilar[y];
	}
	cout<<"Dizinin elemanlari; ";
	
	for (y=0 ; y<x ; y++) {
		cout<<sayilar[y]<<","<<endl;
	}
	cout<<"Dizinin elemanlarinin tersten; ";
	
	for (y=x-1 ; y>=0 ; y--) {
		cout<<sayilar[y]<<","<<endl;
	}
	cout<<"Dizinin elemanlarinin kareleri; ";
	for (y=0 ; y<x ; y++) {
	    z=sayilar[y]*sayilar[y];
	    cout<<", "<< z<<endl;
	}
	
	
	
	int uzunluk =sizeof(sayilar) /sizeof(sayilar[0]); //Bölünen sayý verilerin byte toplamý. Bölen ise 1 tanesinin byte'sý (4 genelde).
							//Yani bu sayede kaç tane dizi elemaný olduðu öðrenilebilir. 
	
	int a,b,c,f;
	bool dizide= false;
	cout<<"\nLutfen carpim tablosu icin dizide bulunan bir sayi giriniz: ";
	cin>>a;
	
	for(f=0; f<=uzunluk ; f++) {	
		if (a==sayilar[f]){
		 dizide=true;
	       	 break;
		} 
	}
	
	if (dizide == false) {
			cout<<"\nSectiginiz sayi dizide degil"<<endl;
			return 0;
		}	

	for(b=1; b<=10; b++) {
	    	c=b*a;
		cout << b <<" x "<< a << "= "<<c<<endl;
	}
	
	return 0;

}
