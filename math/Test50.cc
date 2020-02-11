#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;


class Solution {
public:
    double myPow(double x, int n) { 
        if(n==0) return 1;
        double t = myPow(x,n/2);
        if(n%2) return n<0 ? 1/x*t*t : x*t*t;
        else return t*t;
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.myPow(2, -2) << endl;
    return 0;
}
