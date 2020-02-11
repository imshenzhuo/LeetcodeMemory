#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int len = arr.size();
        vector<vector<int>> vec(len,vector<int>(len,0));
        for(int i=0; i<len; i++) {
            vec[i][i] = arr[i];
        }
        for(int i=1; i<len; i++) { // first col
            for(int j=0;j<len-i;j++) { // j=>row
                if (vec[j+1][i+j] < vec[j][i+j-1])   //下面的小
                    vec[j][i+j] = vec[j+1][i+j] * vec[j][j];
                else 
                    vec[j][i+j] = vec[j+1][j+1] * vec[j][i+j-1];
            }
        }
        int row = 0, col = len-1;
        int res = 0;
        while(--len) {
            res += vec[row][col];
            if (vec[row+1][col] > vec[row][col-1])  col--;
            else    row++;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {6, 2, 4};
    auto a = s.mctFromLeafValues(v);
    cout << a << endl;
    return 0;
}
