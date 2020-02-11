# C++ FAQ

> 遇到有限的key代替map
> int[26] for Letters 'a' - 'z' or 'A' - 'Z'
> int[128] for ASCII
> int[256] for Extended ASCII

> C++的map如果采用下标访问的同时会赋值(如果没有值) 正确的查找做法是用find函数`

> a = 1 2 2 2 3  5 5 5 5 6 7 
> 5 => a[5, 9)
> lower_bound(a, 5) index is 5
> upper_bound(a, 5) index is 9


自定义排序依据
eg 二维vector按照每个vector的第一个排序
`sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {return a[0] < b[0]; });`

vector切片
参数是两个迭代器
`vector<vector<int>>(intervals.begin(), intervals.begin() + index + 1);`

C++string 
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

template <class Container>
void split2(const std::string& str, Container& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

int & string
int->string 
> string to_string (int val);
string -> int
> string s = "12";
> int a = atoi(s.c_str());

