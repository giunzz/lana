#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair <long long,long long > p1;
long long a,b,n,k,n1,n2;
long long luu1=-1,luu2=-1;
long long du;
set <p1 > myset;
set <p1 > ::iterator it;
void dauvao()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
}
bool bi(long long x,long long y)
{
    return ((x&(1LL<<y))!=0);
}
void nhap()
{
        cin>>a>>b>>n>>k;
        du=(1LL<<n);
        if (n==1)
        {
            if (a%du==k) cout<<a;
            else
            {
                if (b%du==k) cout<<b;
                else cout<<-1;
            }
        }
        else
        {
            if (n<=20)
         {                bool ok=0;
             for (long long i=0;i<(1LL<<n)&& ok==0;i++)
            {
                long long tam=0;
                for (long long j=0;j<n;j++)
                {
                    if (bi(i,j)==0)
                {
                    tam=(tam*10+a)%du;
                }
                else tam=(tam*10+b)%du;
                }
                if (tam%du==k)
                {
                     for (long long j=0;j<n;j++)
                {
                    if (bi(i,j)==0)
                {
                    cout<<a;
                } else cout<<b;
                }
                cout<<"\n";
                ok=1;
                }
            }
            if (ok==0) cout<<-1;
         }
         else {
        n1=n/2;
        n2=n-n1;
        for (long long i=0;i<(1LL<<n1);i++)
        {
            long long tam=0;
            for (long long j=0;j<n1;j++)
            {
                if (bi(i,j)==0)
                {
                    tam=(tam*10+a)%du;
                }
                else tam=(tam*10+b)%du;
            }
            myset.insert(mp(tam,i));
        }
        long long gt=(1%du);
        for (long long i=0;i<n1;i++) gt=(gt*10)%du;
        for (long long i=0;i<(1LL<<n2);i++)
        {
            long long tam=0;
            for (long long j=0;j<n2;j++)
            {
                if (bi(i,j)==0)
                {
                    tam=(tam*10+a)%du;
                }
                else tam=(tam*10+b)%du;
            }
            tam=(tam*gt)%du;
            long long tam1=(k-tam)%du;
            if (tam1<0) tam1=tam1+du;
            it=myset.upper_bound(mp(tam1,-1));
            if (it!=myset.end())
            {
                p1 u=*it;
                if (u.fi==tam1)
                {
                    luu1=i;
                    luu2=u.se;
                }
            }
        }
        if (luu1==-1) cout<<-1;
        else
        {for (long long i=0;i<n2;i++)
        {
            if (bi(luu1,i)==0) cout<<a;
            else cout<<b;
        }
        for (long long i=0;i<n1;i++)
        {
            if (bi(luu2,i)==0) cout<<a;
            else cout<<b;
        }
        }}
        }
}
int main()
{
    dauvao();
    nhap();
    return 0;
}
//cacccccccccccccccccccccccccccccccc
