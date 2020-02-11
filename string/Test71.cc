#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
// #include <unordered_map>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        const int n = path.size();
        if (n < 2)  return "/";
        int index = 1, i = 1;
        while(i < n) {
            if (path[i] == '/') {
                if (path[index - 1] != '/') {
                    path[index] = path[i];
                    index++;
                }
                i++;
            } else if (path[i] == '.') {
                // ./
                if (i + 1 == n || i + 1 < n && path[i + 1] == '/')    i += 2;
                // ../
                else if (i + 1 < n && path[i + 1] == '.' && (i + 2 == n || i + 2 < n && path[i + 2] == '/') ) {
                    i += 3;
                    if (index == 1) continue;
                    index--; // skip cur '/'
                    for(; index > 0; index--)
                        if (path[index - 1] == '/') {break;}

                } else {
                    cout  << "???" << endl;
                }
            } else {
                path[index] = path[i];
                index++, i++;
            }
        }
        if (index != 1 && path[index - 1] == '/') index--;
        return path.substr(0, index);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.simplifyPath("/home/") << endl;
    cout << s.simplifyPath("/../") << endl;
    cout << s.simplifyPath("/home//foo/") << endl;
    cout << s.simplifyPath("/a/./b/../../c/") << endl;
    cout << s.simplifyPath("/a/../../b/../c//.//") << endl;
    cout << s.simplifyPath("/a//b////c/d") << endl;
    cout << s.simplifyPath("/a//b////c/d//././/..") << endl;
    return 0;
}
