/**
 *  回溯: 借鉴了暴力排列的思想:
 *      通过函数的参数传递信息, 将大的问题转换成小的问题
 *  注意力:
 *      反过来看可能很简单
 * 
 *  细节:
 *      c_str => int     atoi()
 *      string => int    stoi(i)
 *      string s.substr(pos, len)
 */ 

#include <string>
#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.length() < 4) return res;
        vector<int> position;
        help(s, 0, 3, position, res);
        return res;
    }
    
    // 在字符串s[start:] 插入num个小数点
    void help(string &s, int start, int num, vector<int> position, vector<string>& res) {
        if (num == 0) {
            // 剩下的太长或者没有
            if (s.length() - start > 3 || s.length() - start <= 0)  return;
            // 剩下的超过255
            if (s.length() - start == 3 && stoi(s.substr(start,3)) > 255) return;
            // 0开头
            if (s[start] == '0' && start != s.length()-1)    return;
            string t = s.substr(0, position[0]) + '.' + s.substr(position[0], position[1]-position[0]) + '.' 
                + s.substr(position[1], position[2]-position[1]) + '.' + s.substr(position[2], s.length() - position[2]);
            res.push_back(t);
            return;
        }
        // 超过可能的长度
        if ( s.length() - start > 3*(num+1)) return;
        // 第一个'.'在第一个(s[start])的后面
        if (start < s.length()) {
            position.push_back(start+1);
            help(s, start+1, num-1, position, res); 
            position.pop_back();
        }
        // '0'开头就结束
        if (s[start] == '0')    return;
        if (start + 1 < s.length()) {
            position.push_back(start+2);
            help(s, start+2, num-1, position, res);
            position.pop_back();
        }
        if (start + 2 < s.length() && (stoi(s.substr(start,3)) <= 255)) {
            position.push_back(start+3);
            help(s, start+3, num-1, position, res);
        }
    }
};

int main(int argc, char const *argv[])
{
    string s = "222222";
    Solution solu;
    auto a = solu.restoreIpAddresses(s);
    for (auto aa : a) {
        cout << aa << endl;
    }
    return 0;
}
