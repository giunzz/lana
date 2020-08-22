#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main(){
    clock_t t0 = clock();
/* Work. */
    Sleep(5000);
    clock_t t1 = clock();
    printf("%Lf", (long double)(t1 - t0));
}