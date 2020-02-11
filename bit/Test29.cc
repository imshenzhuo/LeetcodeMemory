#include <cstdlib>
#include <climits>
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
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) ^ (divisor > 0);
        int result = 0;
        if(dividend>0) {
            dividend = -dividend;
        }
        if(divisor>0) divisor = -divisor;
        while(dividend <= divisor) {
            int temp_result = -1;
            int temp_divisor = divisor;
            while(dividend <= (temp_divisor << 1)) {
                if(temp_divisor <= (INT_MIN >> 1))break;
                temp_result = temp_result << 1;
                temp_divisor = temp_divisor << 1;
            }
            dividend = dividend - temp_divisor;
            result += temp_result;
        }
        if(!sign) {
            if(result <= INT_MIN) return INT_MAX;
            result = - result;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.divide(100, 3) << endl;
    return 0;
}
