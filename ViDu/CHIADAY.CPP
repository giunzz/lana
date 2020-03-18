#include<bits/stdc++.h>
using namespace std;
int n, a[100006],k,s,s1;
void sx(int d, int c){
    int i,j,x;
    i=d;
    j=c;
    x=a[(i+j)/2];
    do {
        while (a[i]>x) i++;
        while (a[j]<x) j--;
        if (i<=j) swap(a[i],a[j]), i++, j--;
    }
    while (i<=j);
    if (j>d) sx (d,j);
    if (i<c) sx (i,c);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("CHIADAY.INP","r",stdin);
    freopen("CHIADAY.OUT","w",stdout);
    cin >> n;
    k=n/2;
    for (int i=1 ; i <= n ; i++ ) cin >> a[i];
    sx(1,n);
    for (int i=1; i<= min(k,n-k); i++) s+=a[i];
    for (int i=min(k,n-k)+1; i<=n; i++) s1+=a[i];
    cout<< s-s1;
    return 0;
}
