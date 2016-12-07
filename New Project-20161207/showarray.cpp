#include <iostream>

using namespace std;

void showarray(int *a,int Size){
    for(int i=0;i<Size;i++){
        cout<< a[i] << ' ';
    }
    cout<< '\n' << endl;
}

int main()
{
   int a[5];
    a[0]=0,a[1]=1,a[2]=2,a[3]=3,a[4]=4,a[5]=5;
    showarray(a,3);
    
   return 0;
}

