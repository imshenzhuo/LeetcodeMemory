#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    
    int getN_One(int n) {
        int ans = 0;
        while(n--) {
            ans = ans * 10 + 1;
        }
        return ans;
    }
    
    int getWid(int n) {
        int res = 0;
        while(n) {
            res++;
            n /= 10;
        }
        return res;
    }
    // 获取n在所有字典中的位置 eg n=4400
    int getNPosition(int n) {
        int wid = getWid(n); // 4
        int base = getN_One(wid); // 1111
        int p = n / base * base; // 第一次是3333 1 2 3 开头的数量
        n %= (int)(pow(10, wid-1)); // n=400  // 统计 4 - 4400 之间的数字和 注意可从0开始
        base /= 10; 
        wid--; // 3
        while (n) {
            p++; //  单个1个4
            p += base * (n / (int)pow(10, wid-1)); // 3333 + 333 //   40 41 42 43 开头的数量
            n %= (int)(pow(10, wid-1));
            wid--;
            base /= 10;
        }
        return p;
    }
    // 返回顺序第k个的数字
    int f1(int n, int k) {
        int wid = getWid(n); // 4
        int base = getN_One(wid); // 1111
        int res = k / base + 1;
        k -= k / base * base; // 第一次是3333 1 2 3 开头的数量
        base /= 10;
        while (base) {
            k--;
            res = res * 10 + k / base;
            k -= k / base * base;
            base /= 10;
        }
        return res;
    }
    
    int findKthNumber(int n, int k) {
        int p = getNPosition(n);
        if (p >= k) {
            return f1(n, k);
        } else {
            k -= p;
            
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.findKthNumber(7561, 3800) << endl;
    cout << s.getNPosition(4420) << endl;
    return 0;
}
