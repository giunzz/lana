#include<bits/stdc++.h>
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define ll long long 
using namespace std;

int n , c[30][30] ;
void blablalolo()
{
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
}
bool check(string x , int l)
{

    for (int i = 1 ; i <=  l/2  ; i++)
    {
        if ( x.substr(l-i,i) == x.substr(l-2*i,i) ) return false;
    }
    return true;
}
ll countC = 0;
void TRY (int vt)
{
    for (int i = 'A' ; i <= 'C' ; i++)
    {
        ans.push_back(i);
        if (check (ans,vt))
        {
            if (ans[ans.length()-1] == 'C') countC ++;
            if (countC < CC) CC = countC;
            if (ans.length() == n ) 
            {
                a.push_back(ans);
            }
            else 
            {
                if (countC TRY (vt+1);
        }
    }
}
int main()
{
    giuncute;
    blablalolo();
    cin >> n ;
    TRY(1);
}

