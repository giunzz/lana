#include<bits/stdc++.h>
#define maxn 55
using namespace std;

int n, mmax, a[4], c[4];
int p[maxn], ans= 0;
void Check()
{
    for (int i=1; i<=n; i++)
        c[i]= a[i];
    for (int i=1; i<=n; i++)
    {
        if ( p[i] == 0 )
            c[1]++;
        for (int i=1; i<=3; i++) if (c[i] > mmax) return;
        if ( p[i] == 1 )
        {
            if ( c[1] > 0 ) c[2]++, c[1]--;
            else return;
        }
        for (int i=1; i<=3; i++) if (c[i] > mmax) return;
        if ( p[i] == 2 )
        {
            if ( c[2] > 0 && c[1] > 0 )
            {
                c[2]--;
                c[1]--;
                c[3]++;
                continue;
            }
            if ( c[1] > 2 ) c[1]-= 3, c[3]++;
            else return;
        }
        for (int i=1; i<=3; i++) if (c[i] > mmax) return;
    }
    ans++;
    //for (int i=1; i<=n; i++) cout<<p[i]<<" "; cout<<endl;
}

void Try(int u)
{
    if ( u > n )
    {
        Check();
        return;
    }
    for (int i=0; i<=2; i++)
    {
        p[u]= i;
        Try(u+1);
    }
}
int main()
{
    freopen("icecream.inp", "r", stdin);
    freopen("icecream.out", "w", stdout);
    cin>> n>> mmax;
    for (int i=1; i<=3; i++)
        cin>> a[i];
    Try(1);
    cout<< ans;
}
