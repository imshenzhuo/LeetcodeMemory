#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
// #include <limit>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = s;
        int index = 0;
        int i = s.size() - 1;
        while(i >= 0) {
            if (s[i] != ' ')    break;
            i--;
        }
        int start = i;
        while(i >= 0) {
            if (s[i] != ' ')    i--;
            else {
                for(int j = i + 1; j <= start; j++) 
                    res[index++] = s[j];
                res[index++] = ' ';
                while(i >= 0 && s[i] == ' ')    
                    i--;
                start = i;
            }
            if (i == -1) {
                for(int j = 0; j <= start; j++)
                    res[index++] = s[j];
            }
        }

        return res.substr(0, index);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.reverseWords(" the ") << endl;
    return 0;
}
