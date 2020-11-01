#include<bits/stdc++.h>
using namespace std;
int n,m,q;
char a[3003],b[3003];
string s[3003];
int main()
{
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    for(int p=0;p<=n;p++)
         if(q-p<=m)
         {
            queue<int> va;
            queue<int> vb;
            int j=0;
            while(va.size()!=p)
            {
            for(int i=j;i<=n-p+va.size();i++)
                {
                    if(a[i]<a[j]) j=i;
                }
                va.push(j);
                j++;
            }
            j=0;
           while(vb.size()!=q-p)
           {

            for(int i=j;i<m-(q-p)+vb.size();i++)
            {
                    if(b[i]<b[j]) j=i;
            }

            vb.push(j);
            j++;
           }

           while(va.size()||vb.size())
           {
               if(vb.size()==0||va.size()&&a[va.front()]<=b[vb.front()])
                {
                    s[p]+=(a[va.front()]);
                    s[p]+=" ";
                    va.pop();
                }
                else
                {
                    s[p]+=b[vb.front()];
                    s[p]+=" ";
                    vb.pop();
                }

           }

         }
    string res;

    for(int p=0;p<=n;p++)
    {
        if(s[p]!="")
        {
            res=s[p];
        }
    }
    for(int p=0;p<=n;p++)
    {
        if(s[p]!="")
            {
                res=min(res,s[p]);
            }
    }
    cout<<res;
}
