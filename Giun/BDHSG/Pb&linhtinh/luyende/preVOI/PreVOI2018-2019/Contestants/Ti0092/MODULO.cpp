#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b;
int n,k;
int base;
map<int,vector<int> > m;
vector<int> v;
void snp(int x,int sd)
{
    for(int i=0;i<=1;i++)
    {
        if(i==0) v.push_back(a);
        else v.push_back(b);
        if(x==n/2)
        {
            //cerr<<x<<n/2<<endl;
             int tsd=((sd*10)%base+v[x-1])%base;
            //cerr<<sd<<endl;
            for(int i=0;i<n-n/2;i++)
                tsd=(tsd*10)%base;
            //cerr<<tsd<<endl;
            m[tsd]=v;
        }
        else
        {
          //  cerr<<x<<endl;
            snp(x+1,((sd*10)%base+v[x])%base);
        }
        v.pop_back();
    }
}
void snp1(int x,int sd)
{
   // cerr<<n<<endl;
  //cerr<<x<<endl;
    for(int i=0;i<=1;i++)
    {
        if(i==0) v.push_back(a);
        else v.push_back(b);
        //cerr<<v[0];
        if(x==n)
        {
            int tsd=((sd*10)%base+v[x-n/2-1])%base;
            int tmp=k-tsd;
            if(tmp<0) tmp+=base;
            if(m[tmp].size()>0)
            {
                for(int i=0;i<m[tmp].size();i++)
                    cout<<m[tmp][i];
                for(int i=0;i<v.size();i++)
                    cout<<v[i];

                exit(0);
            }

        }
        else
        {
            snp1(x+1,((sd*10)%base+v[x-n/2-1])%base);
        }

        v.pop_back();
    }

}
main()
{
    freopen("MODULO.inp","r",stdin);
    freopen("MODULO.out","w",stdout);
    cin>>a>>b;
    cin>>n>>k;
    if(n<=44)
    {
    base=pow(2,n);
    snp(1,0);
    v.clear();
    snp1(n/2+1,0);
    }
    else
    {
        cout<<-1;
    }
}
