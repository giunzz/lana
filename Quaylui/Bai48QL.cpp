#include<bits/stdc++.h>
using namespace std;
const string tenfile = "bai48ql";
#define C2H2 freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define CH3COOH ios_base::sync_with_stdio(0) , cin.tie(0);

int n, a[22] , dd[1009]={0} , t  , s = 0;
vector < int > x;

void C2H5OH(int vt)
{
    if ( vt > n ) return;
    if (x.empty()) t = 1;
    else t = x.back()+1;
    for (int i = t ; i <= n ;i++)
    {
        s+=a[i];
        x.push_back(i);
        dd[s] = 1;
        C2H5OH(vt+1);
        s-=a[i];
        x.pop_back();
    }
}      
int main()
{
    C2H2;
    CH3COOH;
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    C2H5OH(1);
    for (int i = 1 ; i <= 1000 ; i++)
    {
        if (!dd[i])
        {
            cout << i ;
            return 0;
        } 
    }    
}
