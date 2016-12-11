#include <iostream>

using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int i=0;
        int j=1;
        if (n == 0) {
            return i;
        } else if (n == 1){
            return j;
        } else {
            for (int k=0;k<n-2;k++){
                int tmp=i+j;
                i=j;
                j=tmp;
            }
            return j;
        }
    }
};
