#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> data = { 1, 1,  3, 3,   3, 3, 4, 4, 4,   5, 5, 6 };
 
    auto lower = std::lower_bound(data.begin(), data.end(), 2);
    // auto upper = std::upper_bound(data.begin(), data.end(), 4);
    
    cout << lower - data.begin() << endl;
    // cout << upper - data.begin();
 
    return 0;
}