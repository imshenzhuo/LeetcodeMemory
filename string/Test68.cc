#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string> res;
        int i = 0;
        while (i < n) {
            int cur = words[i].size();
            int count = 1;
            int j = i + 1;
            for(; j < n; j++) {
                if (cur + count + words[j].size() > maxWidth) {
                    string s = words[i];
                    // [i:j)
                    if (count == 1) {
                        s += string(maxWidth - cur, ' ');
                        res.push_back(s);
                        i = j;
                        break;
                    } else {
                        int NumberSpace = (maxWidth - cur) / (count - 1);
                        int largerCount = (maxWidth - cur) % (count - 1);
                        int smallerCount = (count - 1) - largerCount;
                        for(int k = 0; k < largerCount; k++) {
                            s = s + string(NumberSpace + 1, ' ') + words[i + 1 + k];
                        }
                        for(int k = 0; k < smallerCount; k++) {
                            s = s + string(NumberSpace, ' ') + words[i + 1 + k + largerCount];
                        }
                        res.push_back(s);
                        i = j;
                        break;
                    }
                } else {
                    cur += words[j].size();
                    count++;
                }
            }
            if(j == n) {
                string s = words[i];
                if (i == j - 1) {
                    s += string(maxWidth - words[i].size(), ' ');
                    res.push_back(s);
                } else {
                    int cur = words[i].size();
                    for(int k = i + 1; k < j; k++) {
                        s += ' ' + words[k];
                        cur += 1 + words[k].size();
                    }
                    s += string(maxWidth - cur, ' ');
                    res.push_back(s);
                }
                return res;
            }
            i = j;
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> words{
        "Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"
    };
    Solution s;

    auto ret = s.fullJustify(words,  20);
    for(auto s : ret){
        cout << s << endl;
    }
    return 0;
}
