#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define FORD(i,a,b) for (int i=a; i<b; i++)
#define REP(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
const int N=5e3+5;
int n;
ll a[N],s,kq;
vector<int>v;
int main()
{
    freopen("arrange.inp","r",stdin);
    freopen("arrange.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i];
        s=s+a[i];
    }
    if (s%n==0)
    {
        s=s/n;
        FOR(i,1,n) if (a[i]>s || a[i]<s) v.push_back(i);
        if (v.size()==0)
        {
            cout << 0;
            return 0;
        }
        FORD(i,0,v.size()-1)
        {
            int x=v[i];
            int y=v[i+1];
            kq=kq+abs(a[x]-s)*(y-x);
            if (a[x]<s) a[y]-=s-a[x];
            if (a[x]>s) a[y]+=a[x]-s;
        }
        cout << kq;
        return 0;
    }
    s=s/n;
    FOR(i,1,n)
        if(a[i]<s) v.push_back(i);
    if (v.size()==1)
    {
        int p=v[0];
        FOR(i,1,n)
        {
            if (a[i]>s+1)
            {
                kq+=abs(i-p)*(a[i]-(s+1));
                a[p]+=a[i]-(s+1);
            }
        }
        if (a[p]<s)
        {
            int i=p-1;
            int j=p+1;
            while (a[p]<s)
            {
                if (a[i]==s+1)
                {
                    kq+=p-i;
                    a[p]++;
                    i--;
                }
                if (a[j]==s+1)
                {
                    kq+=j-p;
                    a[p]++;
                    j++;
                }
            }
        }
        cout << kq;
        return 0;
    }
    if (!v.empty())
    {
        FORD(x,0,v.size())
        {
            int p=v[x];
            int i=x-1, j=x+1;
            while (a[i]>s+1 || a[j]>s+1)
            {
                if (a[i]<=s+1) i--;
                if (a[j]<=s+1) j++;
            }
            if (p-i>j-p)
            {

            }
        }
    }
}
