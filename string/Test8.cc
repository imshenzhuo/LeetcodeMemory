#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>
#include <cctype>
#include <set>
#include <map>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        long long int result = 0;
        int indicator = 1;

        int i = str.find_first_not_of(' ');
        if (i < 0)  return 0;
        if(str[i] == '-' || str[i] == '+')
            indicator = (str[i++] == '-')? -1 : 1;
            
        while('0'<= str[i] && str[i] <= '9') 
        {
            result = result*10 + (str[i++]-'0');
            if(result*indicator >= INT_MAX) return INT_MAX;
            if(result*indicator <= INT_MIN) return INT_MIN;                
        }
            
        return result*indicator;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.myAtoi("") << endl;
    return 0;
}
