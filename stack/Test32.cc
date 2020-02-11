#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int cur = 0;
        stack<char> st;
        for(char ch : s) {
            if (ch == '(') {
                st.push(ch);    
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    cur += 2;
                    res = max(res, cur);
                } else {
                    cur = 0;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    return 0;
}
