#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
long n,k,a[30];
bool b[300]={false},ans=false;

void fastscan(long &number) 
{ 
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
}

void check(int k)
{
    for(int i=1;i<=n;i++)
    {
        if(b[i]==false)
        {
            b[i]=true;
            if(k-a[i]>0) check(k-a[i]);
            else
            {
                if(k-a[i]<0) check(k+a[i]);
                else
                {
                    ans=true;
                    break;
                }
            }
            b[i]=false;
        }
    }
}
int main()
{
    giuncute;
    freopen("CANK.inp","r",stdin);
    freopen("CANK.out","w",stdout);
    fastscan(n), fastscan(k);
    for(int i=1;i<=n;i++) fastscan(a[i]);
    check(k);
    if(ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}