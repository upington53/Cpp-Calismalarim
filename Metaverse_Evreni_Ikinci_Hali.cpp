#include <conio.h>
#include <iostream>   
#include <string>
#include <thread>
using namespace std;
const int INACTIVITY_TIME_LIMIT = 10; // Kullanýcý giriþ yapýlmama süresi sýnýrý (saniye)

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
		int xYondeHareket = 0;
		int yYondeHareket = 0;
		string uyumak;
		
		
		Karakter (){
			kimlik = (*id)++;  // Benzersiz kimlik numarasý atamasý
		}
		
		int getID() const {
        	return kimlik;
		}
		
		static void temizle() {
        	delete id;
    	}
    	
		void degerAta(int bakiye, int aclik, int susuzluk){
			
			this->bakiye = bakiye,
			this->aclik = aclik;
			this->susuzluk = susuzluk;
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
		
		void setUyuyor(bool durum) {
    		uyumak = durum;
		}
		
		void gucKarsilastir(){
			this->guc = (this->aclik + this->susuzluk)*this->bakiye;
		}
		
		int getGuc(){
			return guc;
		}
		void hareketEt(const string& yon) {
 			if (yon == "ileri") {
       			yYondeHareket++;
    		} else if (yon == "geri") {
       			yYondeHareket--;
   			} else if (yon == "sag") {
 		    	xYondeHareket++;
    		} else if (yon == "sol") {
        		xYondeHareket--;
    		}
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
	
	karakter1->degerAta(1000,100,100);
	karakter2->degerAta(2000,100,100);
	
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
	karakter1->gucKarsilastir();
	karakter2->gucKarsilastir();
	if ( karakter1->getGuc() > karakter2->getGuc() ) {
		cout<< "Karakter1'in gucu > Karakter2'in gucu "<<endl;
	} else if (karakter1->getGuc() < karakter2->getGuc()){
		cout<< "Karakter2'nin gucu > Karakter1'in gucu "<<endl;
	} else if (karakter1->getGuc() == karakter2->getGuc()){
		cout<< "Karakter2'nin gucu = Karakter1'in gucu "<<endl;
	}
	
	string hareket;
	cout<< "1.Karakter hangi yonde hareket edecek?"<<endl;
	cout<<"(ileri, geri, sag, sol)"<<endl;
	cin>> hareket;
	if (hareket=="ileri") {
		karakter1->yYondeHareket +=10;
	} else if (hareket=="geri") {
		karakter1->yYondeHareket -=10;
	} else if (hareket=="sag") {
		karakter1->xYondeHareket +=10;
	} else if (hareket=="sol") {
		karakter1->xYondeHareket -=10;
	} else { cout<< "Yanlis girdi yaptiniz"<<endl;
	}
	
	cout<< "2.Karakter hangi yonde hareket edecek?"<<endl;
	cout<<"(ileri, geri, sag, sol)"<<endl;
	cin>> hareket;
	if (hareket=="ileri") {
		karakter2->yYondeHareket +=10;
	} else if (hareket=="geri") {
		karakter2->yYondeHareket -=10;
	} else if (hareket=="sag") {
		karakter2->xYondeHareket +=10;
	} else if (hareket=="sol") {
		karakter2->xYondeHareket -=10;
	} else { cout<< "Yanlis girdi yaptiniz"<<endl;
	}
	
	cout<<"Karakter1'in yeni konumu: "<< "X yonde= " <<karakter1->xYondeHareket <<", Y yonde= "<< karakter1->yYondeHareket<<endl;
	cout<<"Karakter2'in yeni konumu: "<< "X yonde= " <<karakter2->xYondeHareket <<", Y yonde= "<< karakter2->yYondeHareket<<endl;

	cout<<"1.Karakter uyuyor mu?"<<endl;
	cout<<"Evet icin: 'true'"<<endl;
	cout<<"Hayir icin: 'false'"<<endl;
	cin>> karakter1->uyumak;

	if (karakter1->uyumak=="false") {
		cout<<"1.karakter uyaniktir." <<endl;
	} else if (karakter1->uyumak=="true"){
		cout<<"1.karakter uyuyor." <<endl;
	}
	
	cout<<"2.Karakter uyuyor mu?"<<endl;
	cout<<"Evet icin: 'True'"<<endl;
	cout<<"Hayir icin: 'False'"<<endl;
	cin>> karakter2->uyumak;
	if (karakter2->uyumak=="false") {
		cout<<"2.karakter uyaniktir." <<endl;
	} else if (karakter2->uyumak=="true"){
		cout<<"2.karakter uyuyor." <<endl;
	}

	Karakter::temizle();
	delete karakter1;
	delete karakter2;	
	
	return 0;

}
