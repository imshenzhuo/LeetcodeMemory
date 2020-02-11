#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> ivec;
    ivec.push_back(3);
    ivec.push_back(13);
    ivec.push_back(33);
    cout << ivec.back() << endl;
    // 不是stack顺序
    for (auto i : ivec) {
        cout << i << endl;
    }
    ivec.clear();
    for(int i=5; i>0; i--) {
        ivec.push_back(i);
    }

    vector<vector<int>> ivvec;
    ivvec.push_back(ivec);

    ivec[2] = 255255;

    cout << "ivec is ";
    for(auto i : ivec)  
        cout << i << "\t";
    cout << endl;

    auto a = min(ivec.begin(), ivec.end()); 
    cout << *a << endl;

    auto b = max(ivec.begin(), ivec.end()); 
    cout << *b << endl;


    cout << "ivvec is ";
    for(auto i : ivvec[0])  
        cout << i << '\t';
    cout << endl;
    auto iter = find(ivvec[0].cbegin(), ivvec[0].cend(), 3);
    cout << *iter << endl;

    
    
    return 0;
}
