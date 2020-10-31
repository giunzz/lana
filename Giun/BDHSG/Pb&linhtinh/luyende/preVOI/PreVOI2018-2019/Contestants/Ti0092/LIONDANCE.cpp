#include<bits/stdc++.h>
using namespace std;
int a[4001];
int b[4001];
int n,k;
int x[31];
vector<int> res;
bool cmp(vector<int> a,vector<int> b)
{
     if(a.size()!=b.size())
     return a.size()>b.size();
    else
    {

        int i=0;
       // cerr<<i<<endl;
      // cerr<<a.size();
        while(i<a.size()&&a[i]==b[i]) {i++;}
        if(a.size()>0)
        return a[i]>b[i];
        else return 1;
    }
}
void xuli()
{
    vector<int> ve;
    queue<int> v;
    for(int i=1;i<=n;i++)
        {
        if(x[i]==1)
        {
            v.push(a[i]);
            ve.push_back(a[i]);
//            cerr<<a[i]<<" ";
        }

        }
  //  cerr<<endl;
    for(int i=1;i<=n;i++)
    {
            //cerr<<v.front()<<" ";
        if(b[i]==v.front())
        {
            v.pop();
        }
    }
    //cerr<<endl;
    if(v.empty())
    {

        if(cmp(ve,res)) res=ve;
       // cerr<<res.size()<<endl;
        //cout<<res.size()<<ve.size()<<endl;
    }
}

void snp(int j)
{
    for(int i=0;i<=1;i++)
        {
            x[j]=i;
            if(j==n)
            {
            xuli();
            }
            else
            snp(j+1);

        }
}
int main()
{
    freopen("LIONDANCE.inp","r",stdin);
    freopen("LIONDANCE.out","w",stdout);
       cin>>n>>k;
       for(int i=1;i<=n;i++)
            cin>>a[i];
         for(int i=1;i<=n;i++)
            cin>>b[i];
        snp(1);
    cout<<res.size()<<"\n";
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
}
