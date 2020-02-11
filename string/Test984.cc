#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    // int a = 100;
    // int b = 00;
    // max(a, b);
    char s[200];
    for(int i = 0; i != 10; i++)    s[i] = i+'0';
    string ss(s, 10);
    cout << ss << endl;
    // string s = to_string(a);
    return 0;
}
