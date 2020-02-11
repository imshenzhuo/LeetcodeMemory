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
    int maxArea(vector<int>& height) {
        const int len = height.size();
        if (len < 2)    return 0;
        int res = 0;
        for(int i = 1; i < len; i++) {
            int tmpHeight = height[0];
            res = max(res, (i)*min(height[i], height[0]));
            for(int j = 1; j < i; j++) {
                if (tmpHeight > height[j])  continue;
                res = max(res, (i-j)*min(height[i], height[j]));
                tmpHeight = height[j];
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(ivec) << endl;
    return 0;
}
