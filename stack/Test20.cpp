#include <cassert>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(auto i : s) {
            if(i == '(' || i== '{' || i == '[')       stack.push(s[i]);
            else {
                if (stack.size() <= 0)   return false;
                char c = stack.top();
                if (i == ')' && c == '(')    stack.pop();
                else if (i == ']' && c == '[' ) stack.pop();
                else if (i == '}' && c == '{' )   stack.pop();
                else return false;
            } 
        }
        if (stack.size() > 0)   return false;
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "()";
    Solution solution;
    assert(solution.isValid(s) == true);
    return 0;
}
