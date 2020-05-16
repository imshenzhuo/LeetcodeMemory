#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

vector<int> LIS(vector<int>& s) {
    const int n = s.size();
    // dp[i]代表以i结束的LIS长度
    vector<int> dp(n, 1);
    int res = 0;
    for(int i = 1; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if (s[j] < s[i]) {
                dp[i] = dp[j] + 1;
                res = max(res, dp[i]);
                break;
            }
        }
    }
    vector<int> sub(res, 1);
    // 找到最后一个value
    int i = dp.size() - 1;
    for(; i >= 0; i--) {
        if (dp[i] == res) break;
    }
    sub[--res] = s[i];

    for(; i >= 0; i--) {
        if (s[i] < sub[res]) {
            --res;
            sub[res] = s[i];
        }
    }
    return sub;
}

int main(int argc, char const *argv[])
{
    // 使用下面的样例检测, 上面的解决方法显然是不对的
    vector<int> ivec{4,15,2,50};
    auto ret = LIS(ivec);
    for(auto i : ret)
        cout << i << endl;
    return 0;
}
