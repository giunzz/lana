#include<bits/stdc++.h>
using namespace std;

int n, a[(int) 1e5],s = INT8_MIN;
void  ma (int x)
{
    if (x == 100000 + 1) return ;
    s = max (s,a[x]);
    cout << s << " " ;
    ma (x+1);
}
int main(){
    
   // freopen("giun.inp","r",stdin);
   // freopen("giun.out","w",stdout);
    //cin >> n;
    for (int i = 1 ; i <= 100000 ; i++) a[i] = i;
    ma(1);
    cout <<endl;
    cout << s ;
    cout << endl << clock() << " s";
}