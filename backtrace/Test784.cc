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
    
    void backtrack(int index, vector<string>& res, string& S) {
        if (index == S.size()) {
            res.push_back(S);
            return;
        }
        backtrack(index+1, res, S);
        // if (S[index] >= 'a' && S[index] <= 'z') {
        //     S[index] = 'A' + S[index] - 'a'; 
        //     backtrack(index+1, res, S);
        // } else if (S[index] >= 'A' && S[index] <= 'Z') {
        //     S[index] = 'a' + S[index] - 'A'; 
        //     backtrack(index+1, res, S);
        // }
        if (isalpha(S[index])) {
            S[index] ^= 1 << 5;
            backtrack(index+1, res, S);
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(0, res, S);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string S = "ab";
    auto k = s.letterCasePermutation(S);
    for(auto i : k) {
        cout << i << endl;
    }
    return 0;
}
