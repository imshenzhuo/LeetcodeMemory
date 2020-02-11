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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> cur;
        for(int i = 0; i < numRows; i++) {
            if (i == 0) cur.push_back(1);
            else {
                cur.push_back(1);
                for(int j = cur.size() - 2; j > 0; j--) {
                    cur[j] += cur[j-1];
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.generate(5);
    return 0;
}
