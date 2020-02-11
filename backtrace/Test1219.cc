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
    vector<int> sequentialDigits(int low, int high) {
        long base[9] = {1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789};
        long top[9] = {1, 89, 789, 6789, 56789, 456789, 3456789, 23456789, 123456789};
        int w = 0;
        for(; w<9; w++) {
            if (base[w] > low)  break;            
        }
        // 位数 i 
        int internal = 0; // i+1个1 
        for(int i = 0; i < w; i++) {
            internal = internal * 10 + 1;
        }
        w--;
        
        vector<int> res;
        while(w<9) {
            for(int i = base[w]; i <= top[w] && i <= high; i+=internal) {
                if (i >= low)
                    res.push_back(i);
            }
            internal = internal * 10 + 1;
            if (internal > high)    break;
            w++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto res = s.sequentialDigits(58, 155);
    for(auto k : res)   cout << k << endl;
    return 0;
}
