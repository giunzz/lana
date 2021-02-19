#include<bits/stdc++.h>
using namespace std;
const  int maxn=1009;
int a[maxn],s1=0,s2=0,n,k=0;
int sum(int p){
    int t=0;
    for (int i=1 ;  i<= p ; i++) t+=a[i];
    return t;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI16.INP","r",stdin);
    freopen("BAI16.OUT","w",stdout);
    cin >> n;
    //cerr << n << endl;
    for (int i=1 ; i<= n ; i++) cin >> a[i];
    sort(a+1,a+1+n);

    //for (int i=1 ; i<= n ; i++) cerr << a[i] << " ";
    //cerr << endl;

    if (n < 4){
        cout << -1;
        return 0;
    }
    s2=a[n]+a[n-1]+a[n-2];
    s1= sum(n-3);
    while (s2 >= s1){
            n=n-1;
            if (n < 4) break;
            //cerr << n << " ";
            k++;
            //cerr << " " << k;
            s2=a[n]+a[n-1]+a[n-2];
            s1= sum(n-3);
            //cerr << s1 << " " << s2;
    }
    if (n < 4 ) cout << -1;
    else cout << k;
    cerr << 2003%12;
    return 0;
}
