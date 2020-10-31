#include <bits/stdc++.h>
#define fori(i,a,b) for(int i=a,b_=b;i<=b_;++i)
#define ford(i,a,b) for(int i=a,b_=b;i>=b_;--i)
#define forv(i,a) for(auto &i:a)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

const int N=305,mod=1e9+9;
int n,mmax,a[5],b[N];
ll res;
int cnt[5];

void Check()
{
    fori(i,1,3) cnt[i]=a[i];
    fori(i,1,n)
    {
        if(cnt[b[i]]==mmax) return;
        if(b[i]==1) cnt[1]++;
        if(b[i]==2)
        {
            if(cnt[1]<=0) return;
            cnt[1]--; cnt[2]++;
        }
        if(b[i]==3)
        {
            if(cnt[2]>=1 && cnt[1]>=1)
            {
                cnt[2]--; cnt[1]--; cnt[3]++;
            }
            else if(cnt[1]>=3)
            {
                cnt[1]-=3; cnt[3]++;
            }
            else return;
        }
    }
    res++;
}
void Att(int i)
{
    if(i>n) Check();
    else
    {
        fori(j,1,3)
        {
            b[i]=j; Att(i+1);
        }
    }
}
int main()
{
    freopen("icecream.inp","r",stdin);
    freopen("icecream.out","w",stdout);
    cin >> n >> mmax >> a[1] >> a[2] >> a[3];
    Att(1);
    cout << res;
}
