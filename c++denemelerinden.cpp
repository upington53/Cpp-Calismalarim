#include <iostream>
#include <string>>
#include <conio.h>
using namespace std;
/*
void constPtr (const int *ptr2,const int *ptr3) {
    std::cout << "pointer b= " << ptr2 << std::endl;
    ptr2++; //burada pointeri degistirmedik. Degerini degistirdik.
    //*ptr2 = 100; deseydik bu sefer hata verirdi. Cunku const olmasina ragmen pointerý degistirmeye kalktik
    std::cout << "yeni pointer b= " << ptr2 << std::endl; }
*/


struct Calisan { //Gruplaþtýrma ile ileride karakter girdisi yapacaðýz.
    int id; 
    string adi;
    string birimi; 
};

void isci(Calisan eleman){ //Burada fonksiyon atamasý için koydum. Mesela eleman1 burada bulunuyor.
   cout<< "ID: " << eleman.id << ", Calisan Adi: " << eleman.adi << ", Birimi: " << eleman.birimi << cout;
}

namespace eslem { //Bunlara isim uzayý deniyor
	int Plaka =16;
}

namespace ulas{
    int Plaka=01;
}
int Ulas=53;
int Eslem=77;

int main () 
{
    /* int a=10;
    int b=20;
    int c=30;
    
    int *ptr1 = &a;

    std::cout << "a= "<< a << std::endl;
    std::cout << "pointer a= " << ptr1 << std::endl;
    constPtr(&b,&c); */
    

    
    std::cout << "Eslem= "<<Eslem<< ", Ulas= " <<Ulas<<std::endl;
    std::cout << "Eslem= "<<eslem::Plaka<< ", Ulas= " <<ulas::Plaka<<std::endl;
    Calisan eleman1={22,"Ulas", "IT"};
    
    isci(eleman1);
 
return 0; 


}
