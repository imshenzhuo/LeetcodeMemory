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
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        n -= 2;
        while(n) {
            a += b; n--;
            if (n==0)   return a;
            b += a; n--;
        }
        return b;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for(int i = 1; i <= 10; i++)
        cout << s.climbStairs(i) << endl;
    return 0;
}
