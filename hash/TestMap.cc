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
    int maxPoints() {
        map<int, int> m;
        m[1] = 2;
        cout << m.count(1) << endl;
        cout << m.count(10) << endl;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.maxPoints();
    return 0;
}
