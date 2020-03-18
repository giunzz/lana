#include<bits/stdc++.h>
using namespace std;
const  int maxn=10009;
long t[maxn] ,n, s = 0 ,d[maxn];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("BAI19.INP","r",stdin);
    freopen("BAI19.out","w",stdout);
    cin >> n;
    for (int i=1 ; i<=n ; i++ ){
            cin >> t[i] >> d[i];
    }
    for (int i = 1 ; i <= n -1 ; i++){
        for (int j = i+1 ; j <= n ; j++){
            if ( t[i] > t[j]) swap(t[i],t[j]),swap(d[i],d[j]);
        }
    }
     //for (int i=1 ; i<=n ; i++ ) cerr << t[i] << " "<< d[i]<< endl;

    s =  t[1]+d[1];
    for (int i= 2  ; i <= n ; i++ ) {
            if ( t[i] <= s) s += d[i];
            else  s = t[i]+d[i];
    }

    cout << s;
    return 0;
}
