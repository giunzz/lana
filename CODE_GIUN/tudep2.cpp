#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0), cout.tie(0)
#pragma GCC optimize("Ofast")
int n , d = 0;
string ans, x;

bool check(string x , int l)
{

    for (int i = 1 ; i <=  l/2  ; i++)
    {
        if ( x.substr(l-i,i) == x.substr(l-2*i,i) ) return false;
    }
    return true;
}
void TRYY (int vt)
{
    for (int i = 'A' ; i <= 'C' ; i++)
    {
            ans.push_back(i);
            if ( check(ans, vt) == true)
            {
                if ( ans.length() == n ) 
                {
                    cout << ans;
                    exit(0);
                }
                else TRYY (vt + 1);
                ans.pop_back();
            }
            else ans.pop_back();
    }
}
int main()
{
    giuncute;
    freopen("tudep2.inp","r",stdin);
    freopen("tudep2.out","w",stdout);
    cin >> n ;
    TRYY(1);
}
