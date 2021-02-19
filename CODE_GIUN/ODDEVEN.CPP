#include<bits/stdc++.h>
using namespace std;
int n;
long x,s=0,chan=0, le =0;
int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("ODDEVEN.INP","r",stdin);
    freopen("ODDEVEN.OUT","w",stdout);
    cin >> n;
    for (int i=1 ; i <= n ; i++){
        cin >> x;
        if (x % 2 == 0) chan++;
        else le++;
    }
    if (chan  == 0) s=s+1;
    else s=s+chan%3 ;
    if ( le  2 == 0) s=s+1;
    else s=s+le%2 ;
    cout << s;
return 0;
}
