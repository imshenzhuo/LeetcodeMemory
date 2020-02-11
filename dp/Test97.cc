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
    bool help(string s1, int begin1, int end1, string s2, int begin2, int end2, string s3, int begin3, int end3) {
        if (begin1 != end1 && s3[begin3] == s1[begin1] && help(s1, begin1 + 1, end1, s2, begin2, end2, s3, begin3 + 1, end3)) {
            return true;
        } else if (begin2 != end2 && s3[begin3 == s2[begin2]] && help(s1, begin1, end1, s2, begin2 + 1, end2, s3, begin3 + 1, end3)) {
            return true;
        } 
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        return help(s1, 0, s1.size(), s2, 0, s2.size(), s3, 0, s3.size());
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    string s1 = "aabcc";
    string s2 = "dbbca";
    string s3 = "aadbbcbcac";
    cout << s.isInterleave(s1, s2, s3) << endl;
    return 0;
}
