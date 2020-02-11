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
    int encode(string &s, int i) {
        return (s[i]-'A')*10 + s[i+1]-'A';
    }
    
    map<int, string> buildMap(vector<string>& allowed) {
        map<int, string> m;
        for(int i=0; i<allowed.size(); i++) {
            m[encode(allowed[i], 0)].push_back(allowed[i][2]); 
        }
        return m;
    }
    string getnewbottom(string &bottom, map<int, string>& m, int count, vector<int>& c){
        int len = c.size();
        char *ch = new char[len];
        while(len--) {
            ch[len] = m[encode(bottom, len)][count%c[len]];
            count /= c[len];
        }
        string str(ch, c.size());
        delete []ch;
        return str;
    }
    bool help(string &bottom, map<int, string>& m) {
        int len = bottom.size();
        if (len <= 1)     return true;
        if (m.size() == 0)  return false;
        // 有多少个排列
        int t = 1;
        vector<int> c;
        for(int i=0; i<len-1; i++) {
            int num = m[encode(bottom, i)].size();
            c.push_back(num);
            t *= num;
        }
        while(t--) {
            string newbottom = getnewbottom(bottom, m, t, c);
            if (help(newbottom, m)) return true;
        }
        return false;
    }
    
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<int, string> m = buildMap(allowed);
        return help(bottom, m);
    }
};

int main(int argc, char const *argv[])
{
    vector<string> allowed = {"CDD","CDA","CBD","DAC","BAD","BAC","AAC","BAA","CAD"};
    string str = "CA";
    // vector<string> allowed;
    // string str = "AA";
    Solution s;
    cout << s.pyramidTransition(str, allowed);
    return 0;
}
