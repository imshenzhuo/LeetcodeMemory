#include <cstdlib>
#include <list>
#include <cstring>
#include <unordered_set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    // unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i = 0; i < prev.size(); ++i){
            prev[i] += " " + word;
        }
        return prev;
    }

public:
    vector<string> wordBreak(string s, unordered_set<string>& dict) {
        // if (m.count(s)) return m[s]; //take from memory
        vector<string> result;
        if (dict.count(s)){ //a whole string is a word
            result.push_back(s);
        }
        for(int i = 1; i < s.size(); ++i){
            string word = s.substr(i);
            if (dict.count(word)){
                string rem = s.substr(0,i);
                vector<string> prev = combine(word, wordBreak(rem, dict));
                result.insert(result.end(), prev.begin(), prev.end());
            }
        }
        // m[s] = result; //memorize
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string str = "catsand";
    unordered_set<string> dict {"cat", "cats", "and", "sand", "dog"};
    auto ret = s.wordBreak(str, dict);
    cout << ret.size() << endl;
    return 0;
}
