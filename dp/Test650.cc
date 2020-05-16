#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2; i * i <= n;) {
            if (n % i == 0) {
                cout << i << endl;
                res += i;
                n /= i;
                i = 2;
            } else {
                i++;
            }
        }
        return res + n;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.minSteps(100) << endl;
    return 0;
}
