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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> ivec(amount+1, -1);
        ivec[0] = 0;
        for(int i=1; i<=amount; i++) {
            int t = INT_MAX;
            for(auto c : coins) {
                if (i-c >= 0 && ivec[i-c] != -1) {
                    t = min(t, ivec[i-c]);
                }
            }
            if (t != INT_MAX)   ivec[i] = t+1;
            else ivec[i] = -1;
        }
        return ivec[amount];
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> coins {1, 2, 5};
    // int amount = 11;
    vector<int> coins { 2 };
    int amount = 3;
    Solution s;
    auto a = s.coinChange(coins, amount);
    cout << a << endl; 
    return 0;
}


