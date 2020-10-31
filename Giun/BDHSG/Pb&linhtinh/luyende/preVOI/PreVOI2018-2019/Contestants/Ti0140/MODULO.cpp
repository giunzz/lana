#include <bits/stdc++.h>

using namespace std;

int a,b,n;
long long d,f,s,k,h,l;

void input()
{
    cin>>a>>b>>n>>k;
    f=0;
    d=0;
    if(a>=b)
    {
        for(int i=1;i<=n;i++)
        {
            f=f*10+a;
            d=d*10+b;
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            f=f*10+b;
            d=d*10+a;
        }
    }
}

bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        l=x%10;
        x=x/10;
        if((l!=a)&&(l!=b))
            return false;
    }
    return true;
}
void solve()
{
    int thu=0;
    if(n<=20)
    {
        h=pow(2,n);
        int r=pow(10,n-1);
        f=f/h+1;
        d=d/h-1;
        for(int i=d;i<=f;i++)
        {
            s=h*i+k;
            check(s);
            if(check(s))
            {
                thu++;
                break;
//                cout<<s<<" ";
            }
//            cout<<s<<" ";
        }
        if(thu!=0)
            cout<<s;
        else
            cout<<"-1";
    }
    else
        cout<<"-1";
}
int main()
{
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
    input();
    solve();
    //cout<<check(277);
    return 0;
}
