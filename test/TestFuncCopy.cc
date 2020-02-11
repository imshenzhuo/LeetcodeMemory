#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

struct T{
    T(int s, int val) : size(s) {
        cout << "new " << s << " int" << endl;
        p = new int[size];
        for(int i = 0; i < size; i++) {
            p[i] = val;
        }
    }
    
    T(const T& hs) {
        cout << "copy ";
        cout << "new " << hs.size << " int" << endl;
        size = hs.size;
        p = new int[size];
        for(int i=0; i<size; i++) {
            p[i] = hs.p[i];
        }
    }
    
    T(T&& hs) noexcept
    : size(hs.size) {
        cout << "move" << endl;
        p = hs.p;
        hs.p = nullptr;
        hs.size = 0;
    }
    
    int *p;
    int size;
    
    ~T() {
        delete[] p;
        // cout << "delete" << endl;
    }
};

T f(T t) {
    int i  = 0;
    i = t.size + 5;
    return t;
}

int main(int argc, char const *argv[])
{
    f(T (4, 5));
    return 0;
}

