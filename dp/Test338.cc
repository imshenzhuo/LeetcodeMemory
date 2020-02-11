#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        unsigned delta = 1;
        for(;;){
            for(int j=0; j<=delta&&j+delta<=num; j++)
                res.push_back(res[j]+1);
            delta *= 2;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    auto a = s.countBits(64);
    return 0;
}
