#include <iostream>
#include <stack>
using namespace std;

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}

class Solution {
public:
    /**
     * @param s A string
     * @return whether the string is a valid parentheses
     */
    bool isValidParentheses(string& s) {
        // Write your code here
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if (!st.empty() && (st.top() == s[i]-1 || st.top() == s[i]-2))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};