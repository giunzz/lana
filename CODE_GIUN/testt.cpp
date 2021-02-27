#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n , a[55] , b[55];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n ; 
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
        sort (a+1, a+1+3);
        sort (b+1, b+1+3);
        if ((a[1]*2 = b[1] && a[2]*2 = b[2] && a[3]*2 = b[3]) || (b[1]*2 = a[1] && b[2]*2 =a[2] && a[3]*2 = b[3])) cout << "SAME SHAPE";
        else if (a[1] == b[1] && a[2] == b[2] && a[3] == b[3]) cout << "EQUAL"<< endl;
        else cout << "NOT SAME SHAPE"<< endl;
    
    }
    return 0;
}