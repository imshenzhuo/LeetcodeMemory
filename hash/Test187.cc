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
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.size() < 11)  return res;
        unordered_map<string, int> m;
        for(int i = 0; i <= s.size() - 10; i++) {
            string ss = s.substr(i, 10);
            if (m.count(ss) && m[ss] == 1)
                res.push_back(ss);
            m[ss]++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.findRepeatedDnaSequences("AAAAAAAAAAAA");
    return 0;
}
