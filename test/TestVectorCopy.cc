#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <memory>
#include <climits>
#include <map>
#include <algorithm>
using namespace std;

struct Node{
    Node() {
        cout << "default" << endl;
    }
    Node(int x) : val(x) {
        cout << "construct" << endl;
    }
    Node(const Node& hs) {
        cout << "copy" << endl;
        val = hs.val;
    }
    Node(Node&& hs) noexcept {
        cout << "move" << endl;
        val = hs.val;
    }
    int val;
    ~Node() {
        // cout << "delete" << endl;
    }
};

int main(int argc, char const *argv[])
{
    const int n = 10;
    vector<Node> nvec;
    Node* nodes = new Node[n];
    for(int i = 0; i < n; i++) {
        cout << nvec.capacity() << endl;
        cout << "--------------" << endl;
        nodes[i].val = i;
        nvec.push_back(nodes[i]);
    }
    cout << "--------------" << endl;
    delete[] nodes;
    return 0;
}
