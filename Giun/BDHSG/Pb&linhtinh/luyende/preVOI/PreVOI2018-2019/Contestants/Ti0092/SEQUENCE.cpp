#include<bits/stdc++.h>
using namespace std;
int n,m,q;
char a[3003],b[3003];
string s[3003];
int main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    for(int p=0;p<=n;p++)
         if(q-p<=m)
         {
            //cerr<<p<<endl;
            queue<int> va;
            queue<int> vb;

            int j=0;
            while(va.size()!=p)
            {
            //int j=0;
            for(int i=j;i<=n-p+va.size();i++)
                {
                    if(a[i]<a[j]) j=i;
                }
                //cerr<<j<<" ";
                va.push(j);
                j++;
            }
            //cerr<<endl;
//            if(m<)
            //cerr<<p<<endl;
            j=0;
           while(vb.size()!=q-p)
           {
            //cerr<<m-(q-p)<<" ";
            //int j=0;

            for(int i=j;i<m-(q-p)+vb.size();i++)
            {
                    if(b[i]<b[j]) j=i;
            }

            vb.push(j);
            j++;
           }
           //cerr<<p<<endl;
          // cerr<<1<<endl;
           //cerr<<va.size()<<" "<<vb.size()<<endl;
           while(va.size()||vb.size())
           {
               if(vb.size()==0||va.size()&&a[va.front()]<=b[vb.front()])
                {
                   // cerr<<a[va.front()];
                    s[p]+=(a[va.front()]);
                    s[p]+=" ";
                    //cerr<<s[p]<<endl;
                    va.pop();
                }
                else
                {
                    s[p]+=b[vb.front()];
                    s[p]+=" ";
                    vb.pop();
                }

           }
           //cerr<<p<<endl;
              //  for(int j=0;j<m;j++)
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
              //  cerr<<s[p]<<endl;
                res=min(res,s[p]);
            }
    }
    cout<<res;
}
