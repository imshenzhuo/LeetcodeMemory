#include <cstdlib>
#include <list>
#include <set>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
    string getName(vector<vector<int>>& points, int i, int j) {
        if (points[i][0] == points[j][0])   {
            double x = points[i][0];
            return "INT_MAX " + to_string(x);
        }
        double x1 = points[i][0], x2 = points[j][0], y1 = points[i][1], y2 = points[j][1];
        double b = y1 - (y2-y1)/(x2-x1)*x1;
        double k = (y1-y2) / (x1-x2);
        return to_string(k) + " " + to_string(b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) return n;
        if (n < 2)  return 1;
        unordered_map<string ,int> m;
        unordered_map<int, set<string>> point;
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                string name = getName(points, i, j);
                if (m.count(name) != 0) {
                    if (point[i].count(name) == 0) {
                        m[name]++;
                        point[i].insert(name);
                    }
                    if (point[j].count(name) == 0) {
                        m[name]++;
                        point[j].insert(name);
                    }

                } else  {
                    m[name] = 2;
                    point[i].insert(name);
                    point[j].insert(name);
                }
                res = max(m[name], res);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> points{{1,1},{3,2},{5,3}};
    // vector<vector<int>> points{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    // vector<vector<int>> points{{0,0},{65536,65536},{65536,131072}};

    cout << s.maxPoints(points) << endl;
    return 0;
}
