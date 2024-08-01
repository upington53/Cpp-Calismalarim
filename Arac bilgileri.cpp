#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Araba {
	private:
		string marka;
		string model;
		int uretimYili;
	public:
		Araba(){
		};
		Araba(string m, string mo, int u){
		};
		void kirala();
		
	void setMarka(string name){
	this->marka=name;	
	}
	
	string getMarka(){
		return marka;
	}

	void setModel(string name){
		this->model=name;	
	}	
	string getModel(){
		return model;
	}
		
	void setUretimYili(int yil){
		this->uretimYili=yil;
	}
	int getUretimYili(){
		return uretimYili;
	}
	
	void KiralikDurumu (bool a){
		if (a==true){
			cout<< "Kiralandi." <<endl;
		} else {
			cout<< "Kiralik Degil." <<endl;
		}
	}
};

int main(){
	int y;
	cout<<"Kac araba bilgisi gireceksiniz?"<<endl;
	cin>>y;
	Araba *araba = new Araba[y];
	bool a=false;
	y=y-1;
	cout<< y+1 << " sayida araba olusturuldu. Arabalar su an ";
	araba[y].KiralikDurumu(a);
	araba[y].setModel("Taunus");
	araba[y].setMarka("Ford");
	araba[y].setUretimYili(1982);
	cout<< araba[y].getUretimYili()<< "\n" << araba[y].getMarka() << "\n" << araba[y].getModel() << endl;
	a =true;
	cout<< araba[y].getUretimYili()<< " "<< araba[y].getMarka() << " "<< araba[y].getModel() << " ";
	araba[y].KiralikDurumu(a);
	
	delete[] araba;
	return 0;
}
	
