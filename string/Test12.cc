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
    string intToRoman(int num) {
        vector<string> gewei {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        vector<string> shiwei {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> baiwei {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string res;
        res = gewei[num % 10] + res; num /= 10;
        res = shiwei[num % 10] + res; num /= 10;
        res = baiwei[num % 10] + res; num /= 10;
        res = string(num, 'M') + res;
        return res;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3994;
    Solution s;
    cout << s.intToRoman(n) << endl;
    return 0;
}
