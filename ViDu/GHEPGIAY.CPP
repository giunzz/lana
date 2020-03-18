#include<bits/stdc++.h>
#include <dos.h> //for delay
#include <conio.h> //for getch()
using namespace std;
const  long maxn=1e6+9;
long a[maxn],b[maxn],o=0,t,k,m,n;
//long a[maxn],b[maxn],s=0,t,k,m,n,m1=-1,m2=-1,o=0,mi2=-maxn, mi1=-maxn;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("GHEPGIAY.INP","r",stdin);
    freopen("GHEPGIAY.OUT","w",stdout);
    cin >> m >> n;
    for (long i= 1 ; i<=m ; i++ ) {
            cin >> t;
            a[t]=a[t]+1;
            //cerr << t << " " << a[t] << endl;
            //m1=max(m1,t);
            //cerr << 1 << " " << " ";
            //mi1=min(mi1,t);
    }
    //cerr << endl;
    for (long i= 1 ; i<=n ; i++ ) {
            cin >> k;
            b[k]=b[k]+1;
            //cerr << k << " " << b[k] << endl;
            //m2=max(m2,k);
            //cerr << 1 << " " ;
            //mi1=min(mi2,k);
    }
    //cerr << endl;
    //cerr << m1 << " " << m2 << endl;
     //for (long i= 0 ; i<= max(m1,m2); i++)
        //if (a[i] > 0 && b[i] > 0 ) s+=min(a[i],b[i]);
     for (long i=0 ; i<=maxn; i++){
            //cerr << i << " " << a[i] << " " << b[i] << endl;
         o+=min(a[i],b[i]);
    }
    cout << o; //<< endl << o;
    return 0;
}
