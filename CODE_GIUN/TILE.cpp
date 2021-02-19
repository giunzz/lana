#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
const int maxn = 2e7+7;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int  n , m  , d = 0 , di = 0 ;
char ch[maxn], check0 = '0' , check1 ='1';
int main()
{
    balabalo;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m ;
    for (int i = 1 ; i <= n*m ; i++) cin >> ch[i] ;
    //for (int i = 1 ; i <= n*m ; i++) cerr << ch[i] << " ";
    for (int i = 1 ; i <= n*m ; i++)
    {
        if (ch[i] != check0 ) d++;
        if ( check0 == '0') check0 = '1';
        else check0 ='0';
    }
    for (int i = 1 ; i <= n*m ; i++)
    {
        if (ch[i] != check1 ) di++;
        if ( check1 == '0') check1 = '1';
        else check1 ='0';
    }
    printf("%d",min(d , di));
    return 0;
}

