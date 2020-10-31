#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a; i<=b; i++)
using namespace std;

const int N=4000+100;
int n,k;
int a[N],b[N];
vector<int> v1,v2;
vector< vector<int> > res;

void check()
{
    if (v1.size()!=v2.size() || v1.size()==0) return;
    FOR(i,0,v1.size()-1)
        if  (v1[i]!=v2[i] || (i>=1 && v1[i]-v1[i-1]>k)) return;

    res.push_back(v1);
}

void DFS(int i)
{
    if (i==n+1)
    {
        check();
        return;
    }

    v1.push_back(a[i]);
    DFS(i+1);
    v1.pop_back();

    v2.push_back(b[i]);
    DFS(i+1);
    v2.pop_back();

    v1.push_back(a[i]);
    v2.push_back(b[i]);
    DFS(i+1);
    v1.pop_back();
    v2.pop_back();
}

bool cmp1(vector<int> a, vector<int> b)
{
    if (a.size()==b.size())
        FOR(i,0,a.size()-1)
        {
            if (a[i]>b[i]) return true;
            if (b[i]<a[i]) return false;
        }
    return (a.size()>b.size());
}

void sub1()
{
    DFS(1);
    sort(res.begin(),res.end(),cmp1);
    cout<<res[0].size()<<endl;
    FOR(i,0,res[0].size()-1)
        cout<<res[0][i];
}

int main()
{
    freopen("liondance.inp","r",stdin);
    freopen("liondance.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>n>>k;

    FOR(i,1,n)
        cin>>a[i];
    FOR(i,1,n)
        cin>>b[i];

    sub1();

}
