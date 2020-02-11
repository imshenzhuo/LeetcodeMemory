#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;


// class Solution {
// public:
//     bool stoneGame(vector<int>& piles) {
//         int m[502][502];
//         int len = piles.size();
//         int sum = piles[0];
//         for(int i=1;i<len;i++) {
//             sum += piles[i];
//             if(i%2==0) {
//                 for(int j=0; j+i<len;j++) {
//                     m[j][j+i] = min(m[j][j+i-1], m[j+1][j+i]);
//                 }    
//             } else {
//                 for(int j=0; j+i<len;j++) {
//                     m[j][j+i] = max(m[j][j+i-1]+piles[j+i], m[j+1][j+i]+piles[j]);
//                 }
//             }
//         }
//         return m[0][len-1]*2 > sum;
//     }
// };

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int m[502];
        int len = piles.size();
        for(int i=0; i<len; i++) {
            m[i] = piles[i];
        }
        int sum = piles[0];
        for(int i=1;i<len;i++) {
            sum += piles[i];
            if(i%2==0) { // 奇数个
                for(int j=0; j+i<len;j++) {
                    m[j] = min(m[j][j+i-1], m[j+1][j+i]);
                }    
            } else {
                for(int j=0; j+i<len;j++) {
                    m[j] = max(m[j][j+i-1]+piles[j+i], m[j+1][j+i]+piles[j]);
                }
            }
        }
        return m[0][len-1]*2 > sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec = {5, 3, 4, 5};
    Solution s;
    auto a = s.stoneGame(ivec);
    cout << a << endl;
    return 0;
}
