#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;

int main()
{
    std::string str = "Hello";
    std::vector<std::string> v;
  
    // uses the push_back(const T&) overload, which means
    // we'll incur the cost of copying str
    v.push_back(str);
    std::cout << "After copy, str is \"" << str << "\"\n";
  
    // uses the rvalue reference push_back(T&&) overload,
    // which means no strings will copied; instead, the contents
    // of str will be moved into the vector.  This is less
    // expensive, but also means str might now be empty.
    v.push_back(std::move(str));
    std::cout << "After move, str is \"" << str << "\"\n";
  
    std::cout << "The contents of the vector are \"" << v[0]
                                         << "\", \"" << v[1] << "\"\n";


    {
        vector<vector<int>> ivvec;
        vector<int> ivec = {1, 2 ,3 ,4 };
        cout << "before move " << ivec.size() << endl;
        ivvec.push_back(std::move(ivec));
        cout << "after move " << ivec.size() << endl;
    }

    {
        vector<vector<int>> ivvec;
        vector<int> ivec = {1, 2 ,3 ,4 };
        cout << "before move " << ivec.size() << endl;
        ivvec.push_back(ivec);
        cout << "after move " << ivec.size() << endl;
    }

    {

        string s1 = "hahaha", s2;
        s2 = std::move(s1);
        cout << "s1" << s1 << endl;
        string &&t = std::move(s2);
        string s3(t);
        // s3[0] = 'J';
        cout << "s2" << s2 << endl;
        cout << "s3" << s3 << endl;
        // printf("s1 %p\n", s1.data());
        // printf("s2 %p\n", s2.data());
        // printf("s3 %p\n", s3.data());
    }

     {

        string s1 = "hahaha", s2;
        s2 = std::move(s1);
        cout << "s1" << s1 << endl;
        string s3(std::move(s2));
        cout << "s2" << s2 << endl;
        cout << "s3" << s3 << endl;
        // printf("s1 %p\n", s1.data());
        // printf("s2 %p\n", s2.data());
        // printf("s3 %p\n", s3.data());
    }
    

    {
        int i = 100;
        vector<int> ivec;
        ivec.push_back(std::move(i));
        cout << i << endl;

        char ch  = '!';
        vector<char> cvec;
        cvec.push_back(std::move(ch));
        cout << ch << endl;
    }

    {
        struct T{
            T(int s, int val) : size(s) {
                cout << "new " << s << " int" << endl;
                p = new int[size];
                for(int i = 0; i < size; i++) {
                    p[i] = val;
                }
            }
            T(const T& hs) {
                cout << "copy" << endl;
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

        T t(5, 1);
        T t2(55, 9);
        T t3(t2);
        T t4(std::move(t));
        int i = 1;
    }
}
