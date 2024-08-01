#include <conio.h>
#include <iostream>   
#include <string>
#include <thread>
using namespace std;

//Zaman fonksiyonunun eklenmiþ hali
class Karakter {
	private:
		int kimlik;
		int aclik;
		int susuzluk;
		static int *id;
		const int aclikAzalma = 10; // Açlýk seviyesindeki azalma miktarý
    	const int susuzlukAzalma = 10; // Susuzluk seviyesindeki azalma miktarý
		
	public:
		int gonderilecek_bakiye;
		int guc;
		int bakiye;
		int xYondeHareket;
		int yYondeHareket;
		
		Karakter (){
			kimlik = (*id)++;  // Benzersiz kimlik numarasý atamasý
		}
		
		int getID() const {
        	return kimlik;
		}
		
		static void temizle() {
        	delete id;
    	}
    	
		void degerAta(int bakiye, int aclik, int susuzluk,int guc){
			
			this->bakiye = bakiye,
			this->aclik = aclik;
			this->susuzluk = susuzluk;
			this->guc = guc;
		}

		void paraGonder(int gonderilecek_bakiye){
			this->bakiye += gonderilecek_bakiye;
		}
		void paraAzalt(int kalan_bakiye){
			this->bakiye -= kalan_bakiye;
		}
		
		void zamanGecisi() {
        // Her saniye açlýk ve susuzluðu güncelle
        	while (this->aclik > 10 || this->susuzluk > 10) {
        	    this_thread::sleep_for(chrono::seconds(1));
            	aclik = max(this->aclik - this->aclikAzalma, 0);
            	susuzluk = max(this->susuzluk - this->susuzlukAzalma, 0);

            	cout << "Aclik: " << this->aclik << ", Susuzluk: " << this->susuzluk << endl;
			}
			
        	cout << "Aclik ve susuzluk seviyeleri %10'a dustu." << endl;
		}
		
		void yemekYe(){
			this->aclik=90;
		}
		
		void suIc(){
			this->susuzluk=90;
		}
	
		int getAclik() const {
        	return aclik;
		}
		
		int getSusuzluk() const {
			return susuzluk;
		}
};

int* Karakter::id = new int(1); //statik deðerin baþlangýç deðeri

int main (){
	int transfer;
	Karakter* karakter1 = new Karakter();
	Karakter* karakter2 = new Karakter();
	
	thread zamanThread1(&Karakter::zamanGecisi, karakter1);
	thread zamanThread2(&Karakter::zamanGecisi, karakter2);

	cout<<"Karakter1 in ID: "<< karakter1->getID() <<endl;
	cout<<"Karakter2 nin ID: "<< karakter2->getID() <<endl;
	
	karakter1->degerAta(1000,100,100,53);
	karakter2->degerAta(2000,100,100,77);
	
	zamanThread1.join();
	zamanThread2.join();
	
	cout<<"Para gondermek istiyor musunuz? " <<endl;
	cout<<"Evet icin 1 yaziniz.\n" <<"Hayir icin 2 yaziniz" <<endl;
	cin>>transfer;
	
	if (transfer==1){
		cout<<"Lutfen transfer yapilacak bilgileri sirasiyla giriniz"<<endl;
		cout<<"Gonderen Kisi (kullanici1 icin 1 / kullanici2 icin 2), Gonderilecek Bakiye Miktari, Gonderilecek Kisi (kullanici1 icin 1 / kullanici2 icin 2)"<<endl;
		int kisi, x, y;
		cin>> kisi >> x >> y;
		
		if (kisi == 1 && y == 2) {
            karakter2->paraGonder(x);
            karakter1->paraAzalt(x);
        } 
		else if (kisi == 2 && y == 1) {
        	karakter1->paraGonder(x);
        	karakter2->paraAzalt(x);
        } 
		else {
            cout << "Gecersiz transfer bilgileri." << endl;
        }
        cout << "Karakter1 yeni bakiye: " << karakter1->bakiye << endl;
        cout << "Karakter2 yeni bakiye: " << karakter2->bakiye << endl;
	}
	if (karakter1->getSusuzluk() <=10 || karakter1->getAclik() <=10){
		karakter1->yemekYe();
		karakter1->suIc();
		cout<< "Yeni Aclik: "<< karakter1->getAclik() << ", Yeni Susuzluk:" << karakter1->getAclik() <<endl;
	}
	if (karakter2->getSusuzluk() <=10 || karakter2->getAclik() <=10){
		karakter2->yemekYe();
		karakter2->suIc();
	}	
	

	Karakter::temizle();
	delete karakter1;
	delete karakter2;	
	
	return 0;

}
