#include <bits/stdc++.h>

using namespace std;
int a[100005],n,nm,kq=0,x[25];
bool kt[100005],kt1[100005];
struct
{
    int gt,cs;
}b[10005];
void xl()
{
    vector <int> b1;
    /*for (int i=1;i<=n;i++)
    {
        //cout<<m<<" "<<b[i].gt<<endl;
        if (x[i]==1) {d++;if (kt[b[i].gt]==false) return;}
        if (x[i]==1 && d>1) if (abs(b[m].gt-b[i].gt)>nm || b[i].cs<b[m].cs) return;
        if (x[i]==1) {m=i;}
    }
    if (d<kq) return;*/
    for (int i=1;i<=n;i++) if (x[i]==1) if (b[i].cs==0) return; else b1.push_back(i);
    for (int i=1;i<b1.size();i++) if (abs(b[b1[i]].gt-b[b1[i-1]].gt)>nm
                            || b[b1[i]].cs<b[b1[i-1]].cs) return;
    cout<<b1.size()<<endl;
    for (int i=0;i<b1.size();i++) cout<<b[b1[i]].gt<<" ";
    exit(0);
}
void try1(int i)
{
    for (int j=1;j>=0;j--)
    {
        x[i]=j;
        if (i==n) xl();
        else try1(i+1);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("liondance.inp","r",stdin);
     freopen("liondance.out","w",stdout);
     cin>>n>>nm;
     memset(kt,false,sizeof(kt));
     memset(kt1,true,sizeof(kt1));
     for (int i=1;i<=n;i++) cin>>a[i],kt[a[i]]=true;
     for (int i=1;i<=n;i++) cin>>b[i].gt,b[i].cs=0;
     for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) if (a[j]==b[i].gt && b[i].cs==0 && kt1[j]) b[i].cs=j,kt1[j]=false;
     try1(1);
}
