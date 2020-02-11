#include <cstdlib>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        num = abs((long)num);
        while(num >1){
            if (num % 2 == 0)   num /= 2;
            else if (num % 3 == 0)   num /= 3;
            else if (num % 5 == 0)   num /= 5;
            else return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sss;

    int i = 2147483648;
    int j = abs(i);
    cout << i << endl;
    cout << j << endl;
    return 0;
}
