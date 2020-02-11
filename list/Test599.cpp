#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        map<string, int> mp1, mp2;
        for(int i = list1.size()-1; i>=0; i--) {
            mp1[list1[i]] = i;
        }
        int minIndex = 1 << 30;
        for(int i = list2.size()-1; i>=0; i--) {
            if (!mp1.count(list2[i]))   continue;

            if (i + mp1[list2[i]] < minIndex) {
                minIndex = i + mp1[list2[i]];
                res.clear();
                res.push_back(list2[i]);
            } else if (i + mp1[list2[i]] == minIndex) {
                res.push_back(list2[i]); 
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KNN","KFC","Burger King","Tapioca Express","Shogun"};
    Solution ss;
    ss.findRestaurant(list1, list2);

    return 0;
}
