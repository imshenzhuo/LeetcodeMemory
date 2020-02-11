#include <cstdlib>
#include <climits>
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
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if (n == 0)     return res;
        vector<int> gray(n+1, 0);
        for(int i = 1; i < 1 << n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                gray[j] ^= gray[j+1];
            }
            int t = 0;
            for(int j = 0; j < n; j++) {
                if (gray[j])    t += 1<<j;
            }
            res.push_back(t);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.grayCode(4);
    return 0;
}
