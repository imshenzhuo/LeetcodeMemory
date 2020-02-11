#include <string>
#include <iostream>

using namespace  std;

int main(int argc, char const *argv[])
{
    char s[50];
    for(int i = 0; i < 10; i++) {
        s[i] = 'a' + i;
    }
    string str(s, 10);
    s[2] = '+';
    cout << str << endl;
    auto substr = str.substr(0,2);
    cout << substr << endl;
    return 0;
}
