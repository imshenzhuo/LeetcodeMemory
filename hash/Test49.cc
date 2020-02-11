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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        set<string> sset;
        map<string, int> m;
        for(string &s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            if (sset.find(t) == sset.end()) {
                sset.insert(t);
                m[t] = res.size();
                vector<string> c;
                c.push_back(s);
                res.push_back(c);
            } else {
                res[m[t]].push_back(s);
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s ;
    vector<string> vs = {"abbb", "ab", "abbbbbaa", "ate", "nat", "bat"};
    s.groupAnagrams(vs);
    return 0;
}
