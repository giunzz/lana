#include<bits/stdc++.h>
using namespace std;
const int maxn=4010;
int dis,n;
int l[maxn],r[maxn];
vector<int > kq;
bool check(vector<int > p)
{
    bool t=false;
    for(int i=1;i<p.size();i++) if(p[i]-p[i-1]>dis) t=true;
    if(t==true) return false;else return true;
}
void backb(vector<int > q,int il,int ir)
{
    if(check(q)==true)
    {
        if(kq.size()<q.size()) kq=q;
        if(kq.size()==q.size())
        {
            bool t=false;
            int smt=kq.size();
            for(int i=0;i<smt;i++)
            {
                if(kq[i]==q[i]) continue;
                if(kq[i]<q[i]) {t=true;break;}
                if(kq[i]>q[i]) break;
            }
            if(t==true) kq=q;
        }
        //for(int i=0;i<q.size();i++) cout<<q[i]<<" ";cout<<"\n";
    }else return ;
    for(int i=il;i<=n;i++) for(int j=ir;j<=n;j++)
        if(l[i]==r[j])
    {
        q.push_back(l[i]);
        backb(q,i+1,j+1);
        q.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
    cin>>n>>dis;
    for(int i=1;i<=n;i++) cin>>l[i];
    for(int i=1;i<=n;i++) cin>>r[i];
    l[n+1]=1e9+7;
    r[n+1]=1e9+6;
    if(n<=20)
    {
        vector<int > v;
        v.clear();
        backb(v,1,1);
        cout<<kq.size()<<"\n";
        for(int i=0;i<kq.size();i++) cout<<kq[i]<<" ";
        return 0;
    }

    return 0;
}
