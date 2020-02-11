#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() < num2.size())    swap(num1, num2);
        const int len2 = num2.size();
        string res;
        for(int i = len2 - 1; i >= 0; i--) {
            string a = num1;
            int k = num2[i] - '0';
            if (k == 0){
                continue;
            }
            int carry = 0;
            for(int j = num1.size() - 1; j >= 0; j--) {
                a[j] = ( (num1[j] - '0') * k + carry ) % 10 + '0';
                carry = ((num1[j] - '0') * k + carry) / 10;
            }
            if (carry) {
                a = (char)(carry + '0') + a;
                carry = 0;
            }
            // res += a << i
            a = a + string(len2 - 1 - i, '0');
            for(int i = res.size() - 1, j = a.size() - 1; i>= 0 && j >= 0; i--, j--) {
                int t = res[i] - '0' + a[j] - '0' + carry;
                a[j] = (t) % 10 + '0';
                carry = (t) / 10;
            }
            int j = a.size() - res.size() - 1;
            while (carry) {
                if (j >= 0) {
                    int t = a[j] - '0'+ carry;
                    a[j] = (t) % 10 + '0';
                    carry = (t) / 10;
                } else {
                    a = (char)(carry + '0') + a;
                    break;
                }
                j--;
            }
            res = a;
        }
        if (res.size() == 0)    return "0";
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.multiply("999", "999") << endl;
    return 0;
}
