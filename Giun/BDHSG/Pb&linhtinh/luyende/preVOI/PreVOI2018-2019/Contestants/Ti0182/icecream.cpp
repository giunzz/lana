#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define name "icecream"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll oo = 1e9+9;
const int nmax = 1e6+5;
ll ans=0;
int n,m;
int m1,m2,m4;
int xd[20];

void thu()
{
    int a=m1,b=m2,c=m4;
    for(int i=1;i<=n;++i)
    {
        if(xd[i]==1)
        {
            ++a;
            if(a>m) return;
        }
        if(xd[i]==2)
        {
            ++b; --a;
            if(b>m || a<0) return;
        }
        if(xd[i]==3)
        {
            if(a>0 && b>0)
            {
                ++c;--a;--b;
                if(c>m) return;
            }
            else
            {
                ++c;a-=3;
                if(c>m || a<0) return;
            }
        }
    }
    ++ans;
}

void ql(int i)
{
    for(int j=1;j<=3;++j)
    {
        xd[i]=j;
        if(i==n) thu();
            else ql(i+1);
    }
}

void xuli()
{

}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin >> n>>m;
    cin >> m1>>m2>>m4;
    if(n<=15 && m<=10)
    {
        ql(1);
        cout << ans;
    }
    else
    xuli();
	return 0;
}
