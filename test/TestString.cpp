#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 789;
    string s = to_string(a);
    s += to_string(a);
    cout << s << endl;

    char c = '(';
    s += c;
    s += to_string(c);
    cout << s << endl;
    return 0;
}
