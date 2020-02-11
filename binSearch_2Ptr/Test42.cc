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
    int help(vector<int>& height, int start, int end) {
        int res = 0;
        if (end - start <= 1)   return 0;
        int max = start;
        for(int i = start + 1; i <= end; i++) {
            if (height[i] > height[max])    max = i;
        }
        int leftStart = max - 1;
        while(leftStart > 0) {
            int maxLeft = leftStart;
            for(int i = leftStart - 1; i >= 0; i--) {
                if (height[i] >= height[maxLeft])    maxLeft = i;
            }
            for(int i = maxLeft + 1; i <= leftStart; i++) {
                res += height[maxLeft] - height[i];
            }
            leftStart = maxLeft - 1; 
        }
        
        int rightStart = max + 1;
        while(rightStart < end) {
            // find max range [rightStart, end]
            int maxRight = rightStart;
            for(int i = rightStart + 1; i <= end; i++) {
                if (height[i] >= height[maxRight])    maxRight = i;
            }

            for(int i = rightStart; i < maxRight; i++) {
                res += height[maxRight] - height[i];
            }
            rightStart = maxRight + 1;
        }
        
        return res;
    }
public:
    int trap(vector<int>& height) {
        return help(height, 0, height.size() - 1);
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{4,2,0,3,2,5};
    Solution s;
    cout << s.trap(ivec) << endl;
    return 0;
}
