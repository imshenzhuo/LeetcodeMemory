#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    void backtrace(int n, int k, string &strindex) {
        if (n == 1) {   strindex[strindex.size() - 1] = '1';  return;}
        int step = 1; // (n-1)!
        for(int i = 1; i < n; i++)  step *= i;
        strindex[strindex.size() - n] = '1' + ( (k-1) / step);
        k = k % (step);
        if ( k == 0)    k = step;
        n--;
        backtrace(n, k, strindex);
    }
    string getPermutation(int n, int k) {
        string index(n, ' ');
        backtrace(n, k, index);
        vector<bool> bvec(n, false);
        
        string base(n , '0');
        for(int i = 0; i < n; i++)  
            base[i] = '0' + i + 1;
        string res = base;

        for(int i = 0; i < n; i++) {
            int ind = index[i] - '0';
            int j = 0;
            while( j < n ) {
                if ( bvec[j] == false )
                    ind--;
                if (ind == 0)   break;
                j++;
            }
            res[i] = base[j];
            bvec[j] = true;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    for(int i = 1; i <= 4*3*2; i++) {
        cout << s.getPermutation(4, i) << endl;
    }
    return 0;
}
