#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)   return s;
        const int len = s.size();
        int index = 0;
        string res = s;
        for(int i=1; i<=numRows; i++) {
            if (i == 1) {
                for(int j=0; j<len; j+=2*numRows-2) {
                    res[index] = s[j];
                    index++;
                }
            } else if(i == numRows) {
                for(int j=i-1; j<len; j+=2*numRows-2) {
                    res[index] = s[j];
                    index++;
                }
            } else {
                for(int j=i-1; j<len; j+=2*numRows-2) {
                    res[index] = s[j];
                    index++;
                    if (j+2*numRows-i*2 >= len)  break;
                    res[index] = s[j+2*numRows-i*2];
                    index++;
                }
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    string s = "ABC";
    int numRows = 3;
    Solution so;
    cout << so.convert(s, numRows) << endl;
    return 0;
}
