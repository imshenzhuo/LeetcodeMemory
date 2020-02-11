#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <set>
#include <map>
// #include <limit>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits[digits.size() - 1] = digits[digits.size() - 1] + 1;
        int carry = digits[digits.size() - 1] / 10;
        digits[digits.size() - 1] %= 10;
        for(int i = digits.size() - 2; carry && i >= 0; i--) {
            digits[i] = digits[i] + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
        }
        if (carry)  digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> ivec{9,9,9};
    Solution s;
    s.plusOne(ivec);
    return 0;
}
