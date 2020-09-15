#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans=0;
const int M=600005;
struct no{
    int w,v;
}a[M];
int ss(no a, no b)
{
    return a.w!=b.w? a.w<b.w:a.v>b.v;
}
priority_queue<int> q;
int main()
{

    freopen("vanchuyen.inp","r",stdin);
    freopen("vanchuyen.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i].w>>a[i].v;
    for(int i=1;i<=k;i++)
        cin>>a[i+n].w, a[i+n].v=-1;
    sort(a+1,a+n+k+1,ss);
    for(int i=1;i<=n+k;i++)
     if (a[i].v!=-1)
        q.push(a[i].v);
    else
        if(!q.empty())
    {
        ans=ans+q.top();
        q.pop();
    }
cout<<ans;
return 0;
}
