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
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        // write your code here
        int cnt = 1;
        int max_cnt=0;
        int max_num=nums[0];
        int num=nums[0];
        for(int i = 1;i< nums.size();i++){
            if(num == nums[i]){
                cnt++;

            }else {
                num = nums[i];
                cnt=1;
            }
            if(max_cnt<cnt) {
                max_cnt=cnt;
                max_num=nums[i-1];
            }
        }
        return max_num;
    }
};