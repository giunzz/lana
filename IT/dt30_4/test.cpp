#include <bits/stdc++.h>

using namespace std;

int bs(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
        if (arr[m] == x){
            if (arr[m] == arr[1]) return 1;
            while (arr[--m] == x && m > 1){}
            ++m;
            return m;
        } 
        if (arr[m] < x) 
            l = m + 1; 
        else
            r = m - 1; 
    } 
    cerr << l << endl << r;
    return -1; 
}

int main(){
    int a[] = {0, 1, 4, 4, 7};
    cout << bs(a, 1, 4, 5);
}