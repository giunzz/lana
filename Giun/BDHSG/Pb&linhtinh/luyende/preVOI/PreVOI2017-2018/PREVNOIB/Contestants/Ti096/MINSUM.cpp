#include <bits/stdc++.h>
#define pb push_back
#define ii pair<int,int>
#define x first
#define y second

using namespace std;

const int N=1e5+2;
const int M=1e5;
const int MOD=1e9+7;
const int bm=1;
int dem,t;
int nt[N],d[N],dd[N];

void sinh()
{
    freopen(".inp","w",stdout);
    srand(time(0));
}

void xuli(int a, int b)
{
    int k=0;
    for(int i=1;i<=dem;i++)
    {
        int x=0;
        while( a%nt[i] == 0 ) a/=nt[i],x++;
        while( b%nt[i] == 0 ) b/=nt[i],x++;
        if ( x % 2 ) dd[++k]=nt[i];
    }
    if ( a == b ) a=b=1;
    else dd[++k]=a,dd[++k]=b;
    int MIN=MOD;
    for(int i=1;i<(1<<k);i++)
    {
        int x=1,y=1;
        for(int j=0;j<k;j++)
            if ( (i>>j)&1 ) x*=dd[j+1];
            else y*=dd[j+1];
        if ( MIN > abs(x-y) ) a=x,b=y,MIN=abs(x-y);
    }
    cout<<a<<" "<<b<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //sinh();
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    for(int i=2;i<=M;i++)
        if ( !d[i] )
        {
            for(int j=i;j<=M;j++) d[j]=1;
            nt[++dem]=i;
        }
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        xuli(a,b);
    }

}
