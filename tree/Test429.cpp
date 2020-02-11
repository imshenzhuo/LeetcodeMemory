/**
 *  层次遍历树
 * 
 * 
 */ 


#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


#pragma GCC optimize("Ofast")
static auto x = []() {std::ios::sync_with_stdio(false); std::cin.tie(nullptr); return nullptr; }();

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return {};
        
        vector<vector<int>> res;
        queue<Node *> q;
        q.push(root);
        
        int d = 0;
        while(!q.empty()){
            res.push_back(vector<int>());
            
            for(int i = 0, n = q.size(); i < n; i++){
                Node *node = q.front();
                res[d].push_back(node->val);
                q.pop();
                for(int n = 0, total = node->children.size(); n < total; n++){
                    q.push(node->children[n]);
                }
            }
            d++;
        }
        return res;
        
    }
};
// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> res;
//         vector<Node*> nstack;
//         vector<Node*> helpVec; // 
//         vector<int> levelData; // store data in one level
        
//         nstack.push_back(root);
//         while(!nstack.empty()) {
//             for(auto i : nstack) {
//                 levelData.push_back(i->val);
//                 for(auto j : i->children) {
//                     helpVec.push_back(j);
//                 }
//             }
//             nstack.clear();
//             nstack = helpVec;
//             helpVec.clear();
//             res.push_back(levelData);
//             levelData.clear();
//         }
//         return res;
//     }
// };

int main(int argc, char const *argv[])
{
    Node *n5 = new Node;
    n5->val = 5;
    Node *n6 = new Node;
    n6->val = 6;
    Node *n2 = new Node;
    n2->val = 2;
    Node *n4 = new Node;
    n4->val = 4;


    vector<Node*> nvec;
    nvec.push_back(n5);
    nvec.push_back(n6);
    Node *n3 = new Node(3, nvec);

    nvec.clear();
    nvec.push_back(n3);
    nvec.push_back(n2);
    nvec.push_back(n4);
    Node *n1 = new Node(1, nvec);
    
    Solution sss;
    auto res = sss.levelOrder(n1);
    for( auto i : res) {
        for (auto j : i ){
            cout << j << "\t";
        }
        cout << endl;
    }

    return 0;
}
