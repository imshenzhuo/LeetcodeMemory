#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int res = 0;
        int last = 0;
        for(int i = 0; i < s.size(); i++) {
             if (m[s[i]] > last)    {
                 res = res + m[s[i]] - 2 * last;
                 last = m[s[i]];
             } else {
                 res += m[s[i]];
                 last = m[s[i]];
             }
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    string str = "MCMXCIV";
    Solution s;
    cout << s.romanToInt(str) << endl;

    return 0;
}
