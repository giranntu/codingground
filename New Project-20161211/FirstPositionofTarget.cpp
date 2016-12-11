#include <iostream>
#include <vector>
using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int end = array.size();
        int head = 0;
        int mid = (head+end)/2;
        int firstnum;
        while (array[mid] != target){
            if(mid == head || mid == end ) break;
            if(array[mid] < target){
                head = mid;
                mid = (mid + end) / 2;
            } else if (array[mid] > target){
                end = mid;
                mid = (mid + head) / 2;
            }
        }
        if(array[mid]==target){
            int first = mid;
            while(array[first-1]==array[first]){
                first-=1;    
            }
            return first;
        }
        return -1;
    }
};
