#include <bits/stdc++.h>
#define forr(i,a,b) for( int i=(a);i<=(b);++i)
#define ford(i,a,b) for( int i=(a);i>=(b);--i)
#define f first
#define s second
#define ll long long
#define pii pair<int,int>
#define task "GIFTS"

using namespace std;

const long long mod=1e17+7;
const long dad=2e6 ;
int n,k ;
ll a[dad],l[dad],r[dad],ans=mod ;

int getint()
{
   int ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

ll getll()
{
   ll ww = 0; char cc = getchar();
   while (cc > '9' || cc < '0') cc = getchar();
   while (cc >= '0' && cc <= '9') { ww = ww * 10 + cc - '0'; cc = getchar(); }
   return ww;
}

int getbit(int bit,int id)
{
    return bit>>id&1;
}

void input()
{
    n=getint();
    k=getint();
    forr(i,1,n)
    {
        a[i]=getll();
        a[i]+=a[i-1];
    }
    forr(i,k,n)
    {
        l[i]=max(l[i-1],a[i]-a[i-k]);
//        cout<< i << " " << i-k+1 << " " << l[i] << endl;
    }
//    cout<< endl;
    ford(i,n-k+1,1)
    {
        r[i]=max(r[i+1],a[i+k-1]-a[i-1]);
//        cout<< i << " " << i+k-1 << " " << r[i] << endl;
    }
//    cout<< endl;
    forr(i,1,n-k+1)
    {
        ll xx=a[i+k-1]-a[i-1];
        ll yy=max(l[i-1],r[i+k]);
        if (xx>=yy)
        {
            ans=min(ans,xx);
//            cout<< i << endl;
        }
    }
    cout<< ans ;
}

void output()
{

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen( task".inp" , "r" , stdin );
    freopen( task".out" , "w" , stdout );
    input();
    output();
    return 0;
}
