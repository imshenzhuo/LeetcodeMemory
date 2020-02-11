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
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        if (n == 1)  return res;

        int count = 0;
        while(--n) {
            string next;
            for(int i = 0; i < res.size(); i++) {
                if (res[i] != res[i+1] || i == res.size() - 1) {
                    next.push_back(count + '1');
                    next.push_back(res[i]);
                    count = 0;
                } else {
                    count++;
                }
            }
            res = next;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for(int i = 1; i < 6; i++) {
        cout << s.countAndSay(i) << endl;
    }
    return 0;
}
