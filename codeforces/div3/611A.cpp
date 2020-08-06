#include<bits/stdc++.h>
using namespace std;
int n , t,b , a[10000], ok = 0;

void Xoapt(int a[], int &n, int pos){
    for(int i = pos; i < n ; i++) a[i] = a[i+1];
    --n;
}
int main()
{ 
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("giun.inp","r",stdin);freopen("giun.out","w",stdout);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1 ; i <= n ; i++) cin >> a[i];
        sort (a+1, a+1+n);
        ok = 0;
        for (int i = 2 ; i <= n ; i++)
        {
            if (a[i] == a[i-1]) Xoapt(a,n,i--);
        }
        for (int i = 2 ; i <=  n ; i++)
        {
            if (abs(a[i-1] - a[i]) != 1 )
            {
                cout << "NO" << endl;
                ok = 1;
                break; 
            }
        }   
            if (ok == 0) cout <<"YES"<<endl;
    }
}
