#include <iostream>
#include <iomanip>
using namespace std;

struct test{
    string c; 
    int a = 0;
};

int main(){
    test b = {"abc", 1};
    cout << b.c << " " << b.a;
}