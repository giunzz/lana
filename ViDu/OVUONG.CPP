#include<bits/stdc++.h>
using namespace std;
int dem = 0, n, b[(int)1e4+8],a[(int) 1e4 +8], d;
void  sx(int d, int c){
    int i,j,x;
    i=d;
    j=c;
    x=a[(d+c)/2];
    do{
        while (a[i]<x) i++;
        while (a[j]>x) j--;
        if (i<=j) swap(a[i],a[j]),i++,j--;
    }
    while (i<=j);
    if (j>d) sx(d,j);
    if (i<c) sx (i,c);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("OVUONG.INP","r",stdin);
    freopen("OVUONG.OUT","w",stdout);
    cin >> n;
    for (int i=1 ; i<= n*n ; i++){
        cin >> a[i];
    }
    sx(1,n*n);
    for (int i=1 ; i<= n*n; i++){
        if ( a[i] % 2 != 0 ){
            cout << a[i] << " ";
            if ((i-dem)% n ==0) cout << endl;
        }
        else{
            b[++dem] = a[i];
        }
    }
    d = n * n - dem;
    for (int i=1; i<= dem ; i++) {
        cout << b[i]<< " ";
        if (++d % n == 0) cout << endl;
    }
    return 0;
}
