#include <list>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        list<int> lis;
        for(int i = 0; i <= n; i++) {
            lis.push_back(i);
        }
        int count = 0;
        while (lis.size()!=1)
        {
            if (count % 2 == 0)
            auto iter = lis.begin();
        }
        
    }
};