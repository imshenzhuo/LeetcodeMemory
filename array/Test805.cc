#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() <= 1)  return false;
        sort(A.begin(), A.end());
        double sum = 0;
        for(int i : A)  sum += i;
        double avg = 1.0 * sum / A.size();
        auto iter = lower_bound(A.begin(), A.end(), avg);


        int size = 1;
        int i, j;
        i = j = iter - A.begin();
        sum = A[i];
        double t = sum / size;
        if (t == avg)    return true;

        while(i>0 && j<A.size()){
            if (t > avg) {
                sum += A[--i];
            } else {
                sum += A[++j];
            }
            size++;
            t = sum / size;
rrrrrrt            if (size == A.size())   return false;
            if (t == avg)    return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    // vector<int>A{1,2,3,4};
    // vector<int>A{1,2,3,4};
    // vector<int>A{1,3,0,4,7,9};
    // vector<int>A{10,29,13,53,33,48,76,70,5,5};
    vector<int>A{5,5,10,13,29,33,48,53,70,76};

    // vector<int>A{1, 3};
    // vector<int>A{100,100,100,100,100,100,100};
    Solution s;
    auto t = s.splitArraySameAverage(A);
    cout << t << endl;
    return 0;
}


