#include<bits/stdc++.h>

using namespace std;

long a,b,c,k = 0,x,y,z,n, i = 1,m ;
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("xu.inp","r",stdin);
    freopen("xu.out","w",stdout);
    cin >> m ;
    while (  i <= m ){
        cin >> a >> b >> c >> n;
        k = (a + b + c + n ) ;
        x = k / 3 - a;
        y = k / 3 - b;
        z = k / 3 - c;
        if ( k % 3 == 0 &&  x >= 0 && y >= 0 && z >= 0) cout << " YES" << endl;
        else cout << " NO" << endl;
        i++;
    }
    return 0;
}
