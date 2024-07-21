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
	Ogretmen *ogretmen1 = new Ogretmen(); // Ogretmen sýnýfý için bellekte yer ayýrýyoruz.
	
	ogretmen1->setId(53);          // Ýþaretçi ile nesneye eriþerek fonksiyonlarý çaðýrýyoruz.
	ogretmen1->setName("Ulas");    // Ýþaretçi ile nesneye eriþerek fonksiyonlarý çaðýrýyoruz.
	cout<< ogretmen1->getId() << " + " << ogretmen1->getName() <<endl;
	delete ogretmen1;
	return 0;
}
