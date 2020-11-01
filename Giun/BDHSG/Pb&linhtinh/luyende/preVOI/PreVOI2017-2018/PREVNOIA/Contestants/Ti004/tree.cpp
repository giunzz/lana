#include <bits/stdc++.h>
using namespace std;
int n,b,c,a[5001],cha[5001],socon[5001],st[5001];
int kq,tong;
bool gg=false,dx[5001],sx[5001];

vector<int> ke[5001];
void nhap()
{
    freopen("tree.inp","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cha[1]=1;
    for(int i=1;i<n;i++)
    {
        cin>>b>>c;
        cha[c]=b;
        ke[b].push_back(c);
        socon[b]++;
    }
}
void vi_xu_li()
{
    for(int i=1;i<=n;i++)
    {
        if(socon[i]==0)
        {
            sx[cha[i]]=true;
            if(a[i]>1)
            {
                kq=kq+a[i]-1;
                a[i]=a[i]-1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        tong=0;
        for(int j=0;j<ke[i].size();j++)
            tong+=a[ke[i][j]];
        if(a[i]!=tong)
        {
            gg=true;
            break;
        }
    }
}
int DFS(int i)
{
    st[i]=0;
    if(ke[i].size()==0)
        st[i]=a[i];
    for(int j=0;j<ke[i].size();j++)
    {
        int u=ke[i][j];
        DFS(u);
        st[i]+=a[u];
    }
    kq=kq+abs(a[i]-st[i]);
    return st[i];
}
void xu_li()
{
    kq=0;
    DFS(1);
    cout<<kq-1;

}
int main()
{
    nhap();
    vi_xu_li();
    if(gg==false)
    {
        cout<<kq;
        return 0;
    }
    xu_li();
}
