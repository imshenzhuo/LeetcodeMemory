#include <cstdlib>
#include <set>
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
    void backtrace(int begin, unordered_map<char, int>m, set<long>& s, int size, long cur = 0) {
        if (begin == size) {
            s.insert(cur);
            return;
        }
        for(auto it = m.begin(); it != m.end(); it++) {
            if (it->second <= 0)    continue;
            cur = cur * 26 + it->first - 'A';
            s.insert(cur);
            it->second--;
            backtrace(begin+1, m, s, size, cur); 
            cur = cur - (it->first - 'A') / 26;
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> m;
        for(auto i : tiles)       m[i]++;
        set<long> s;
        backtrace(0, m, s, tiles.size());
        return s.size();
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.numTilePossibilities("AAB") << endl;
    return 0;
}
