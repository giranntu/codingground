#include <iostream>

using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   char s[]="-1";
   cout<<atoi(s)<<endl;
   
   return 0;
}
int atoi(char *s){
    int sum = 0;
    for (int i = 0; s[i] !='\0';i++){
        sum = sum*10 + s[i]-'\0';
        return sum;
    }
}
