#include <iostream>
#include <string>
using namespace std;

class Ogretmen {
	private:
		int id;
		string name;
	public:
		Ogretmen(int kimlik, string ad){		
			this->id = kimlik;
			this->name = ad;
		}
		
		void setId (int numara){
			this->id = numara;
		}
		
		int getId(){
			return id;
		}
		
		void setName(string isim){
			this->name = isim;
		}
		
		string getName(){
			return name;
		}

	friend void ogretmenBilgi(Ogretmen &ogretmen1);
};

void ogretmenBilgi(Ogretmen &ogretmen1){

	cout<< ogretmen1.id << " + " << ogretmen1.name << endl;

}

int main(){

	Ogretmen ogretmen1(53,"Ulas");
	ogretmenBilgi(ogretmen1);

}
