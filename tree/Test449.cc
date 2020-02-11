/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <cassert>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

     // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        encodeNode(root, s);
        return s;
    }
    void encodeNode(TreeNode* node, string &s) {
        if (!node)  return;
        s += to_string(node->val);
        if (node->left == node->right)  return;
        s+='[';
        if (node->left){
            encodeNode(node->left, s);
        }
        s+=']';
        s+='{';
        if (node->right){
            encodeNode(node->right, s);
        }
        s+='}';
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return parseNode(data, start);
    }
    
    TreeNode *parseNode(string s, int &start) {
        TreeNode *node;
        int flag = 1;  int num = 0;
        // left right == 1:当前的子树   0:上层的树
        int left = 0;  int right = 0;
        while (start < s.size()) {
            if (s[start] == '-') {
                flag = -1;
                start++;
            }
            else if (s[start] >= '0' && s[start] <= '9') {
                num = num * 10 + s[start] - '0';
                start++;
            } else if (s[start] == '[') {
                left++; // 进入左子树
                // 左侧必是数字
                node = new TreeNode(num * flag);
                num = 0; flag = 1;
                // assert(start>0 && (s[start-1]>='0'&&s[start-1]<='9'));
                start++;
                node->left = parseNode(s, start); // parse 直到当前子树的](不包括)
            } else if (s[start] == '{') {
                right++;
                assert(start>0);
                // no left tree
                if (s[start-1]>='0'&&s[start-1]<='9') {
                    node = new TreeNode(num * flag);
                    num = 0; flag = 1;
                }
                start++;
                node->right = parseNode(s, start); // // parse 直到当前子树的}(不包括
            } else if (s[start] == ']') {
                if (left == 0)  {
                    if (s[start-1]>='0'&&s[start-1]<='9') {
                        return new TreeNode(num * flag);
                    }  
                    return nullptr;
                } 
                start++;
            } else if (s[start] == '}'){
                if (right == 0)  { // 不是当前的 '}'  有数值返回数值 没有数值直接返回
                    if (s[start-1]>='0'&&s[start-1]<='9') { // 没有左子树
                        return new TreeNode(num * flag);
                    }  
                    return nullptr;
                }
                start++;
                return node;
            }
        }
        return node;
    }

    // // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
    //     string order;
    //     inorderDFS(root, order);
    //     return order;
    // }
    
    // inline void inorderDFS(TreeNode* root, string& order) {
    //     if (!root) return;
    //     char buf[4];
    //     memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
    //     for (int i=0; i<4; i++) order.push_back(buf[i]);
    //     inorderDFS(root->left, order);
    //     inorderDFS(root->right, order);
    // }

    // // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {
    //     int pos = 0;
    //     return reconstruct(data, pos, INT_MIN, INT_MAX);
    // }
    
    // inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
    //     if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
    //     int value;
    //     memcpy(&value, &buffer[pos], sizeof(int));
    //     if (value < minValue || value > maxValue) return NULL;
        
    //     TreeNode* node = new TreeNode(value);
    //     pos += sizeof(int);
    //     node->left = reconstruct(buffer, pos, minValue, value);
    //     node->right = reconstruct(buffer, pos, value, maxValue);
    //     return node;
    // }
};

TreeNode* constructTree() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(-22);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node3->left = node5;
    node3->right = node6;
    return node1;
}

void print(TreeNode *node) {
    if (!node)  return;
    cout << node->val << endl;
    print(node->left);
    print(node->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = constructTree();
    print(root);
    Codec c;
    string s = c.serialize(root);
    cout << s << endl;

    root = c.deserialize(s);
    print(root);
    
    /* code */
    return 0;
}
