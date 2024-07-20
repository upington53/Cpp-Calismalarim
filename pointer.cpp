#include <iostream>
#include <string>>
#include <conio.h>
using namespace std;
int main(){
  int a = 10;
  cout<<"a= " << a <<endl;
  int *ptr;
  //cout<<"b= " << *ptr <<endl;
  cout<<"pointer yeri= " << ptr <<endl;
  ptr =&a;
  cout<<"a'nin pointeri'= " << ptr << endl;
  return 0;
  }
