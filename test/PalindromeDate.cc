#include<iostream>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    int count = 0;
    vector<int> arr{0, 31,29,31,30,31,30,31,31,30,31,30,31};
    for(int i = 2000; i < 3000; i++) {
        for(int j = 1; j < 13; j++) {
            int a = i / 100;
            int b = i % 100;
            int c = j;
            int d = 10*(c%10) + (c/10);
            int e = 10*(b%10) + (b/10);
            int f = 10*(a%10) + (a/10);
            if(d < 32 && e < 25 && f < 60) {
                printf("%02d%02d_%02d%02d_%02d:%02d\t", a,b,c,d,e,f);
                // cout << a << " " << b << " " << c << " "<< endl;
                count++;
                if (count % 12 == 0)    printf("\n");
            }
        }
    }
    cout << "\n" << count << endl;
    return 0;
}
