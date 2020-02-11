#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> s;
        while(label > 1) {
            s.push_back(label);
            label /= 2;
            int level = getLevel(label);
            label = 3 * (1<<level) - 1 - label;            
        }
        s.push_back(label);

        vector<int> ivec;
        while(!s.empty()) {
            ivec.push_back(s.back());
            s.pop_back();
        }
        return ivec;
    }
    
    int getLevel(int n) {
        int level = 0;
        int t = 1;
        while(t*2 <= n) {
            t *= 2;
            level++;
        }
        return level;
    }
};