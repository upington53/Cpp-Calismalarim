#include <iostream>
using namespace std;

int main ()
{
int i;
int * p;
p= new int[2];

//int *p = new int[2];    //Tek satır halinde yazılmış hali

     for (i=0; i<2; i++)
      {
            cout << "Sayi giriniz :";
            cin >> p[i];
      }
     cout << "Girilen sayilar"<<endl;
     
     for (i=0; i<2; i++)
     {
          cout << p[i] <<endl;
     } 
     delete[] p;  
cout << p[0] <<endl;  

return 0; 
}

