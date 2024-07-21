#include <iostream>
#include <string>
using namespace std;

class Ogretmen {
	private:
		int id;
		string name;
	public:

		void setId (int numara){
			this->id = numara;
		}
		
		int getId(){
			return id;
		}
		
		void setName (string isim){
			this->name = isim;
		}
		
		string getName(){
			return name;
		}
};

int main(){
	Ogretmen *ogretmen1 = new Ogretmen(); // Ogretmen s�n�f� i�in bellekte yer ay�r�yoruz.
	
	ogretmen1->setId(53);          // ��aret�i ile nesneye eri�erek fonksiyonlar� �a��r�yoruz.
	ogretmen1->setName("Ulas");    // ��aret�i ile nesneye eri�erek fonksiyonlar� �a��r�yoruz.
	cout<< ogretmen1->getId() << " + " << ogretmen1->getName() <<endl;
	delete ogretmen1;
	return 0;
}
