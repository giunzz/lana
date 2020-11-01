#include<bits/stdc++.h>
using namespace std;
const int maxn=40000;
int n,mmax;
int m50,m1,m2;
const int oo=1e9+7;
int a[]= {50,100,200};
int kq=0;
bool check(vector<int > p)
{
    int s50=m50,s1=m1,s2=m2;
    bool t=false;
    for(int i=0; i<p.size(); i++) if(t==false)
        {
            if(p[i]==50)
            {
                if(s50+1<=mmax) s50=s50+1;
                else
                {
                    t=true;
                    break;
                }
                continue;
            }
            if(p[i]==100)
            {
                if(s1+1<=mmax && s50>0 )
                {
                    s1=s1+1;
                    s50=s50-1;
                }
                else
                {
                    t=true;
                    break;
                }
                continue;
            }
            if(p[i]==200)
            {
                if(s2+1>mmax)
                {
                    t=true;
                    continue;
                }
                if( s1>0 && s50>0  )
                {
                    s1=s1-1;
                    s50=s50-1;
                    s2=s2+1;
                }
                else
                {
                    if( s50>=3 )
                    {
                        s2=s2+1;
                        s50=s50-3;
                    }
                    else
                    {
                        t=true;
                        break;
                    }
                }
                continue;
            }
        }
    if(t==true) return true;
    else return false;
}
void backb(vector<int > q)
{
    if(q.size()>n) return ;
    if(q.size()==n)
    {
        if(check(q)==false)
        {
            //for(int i=0;i<q.size();i++) cout<<q[i]<<" ";
            //cout<<"\n";
            kq=(kq+1)%oo;
        }
        return ;
    }
    for(int i=0; i<3; i++)
    {
        q.push_back(a[i]);
        backb(q);
        q.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
    cin>>n>>mmax;
    cin>>m50>>m1>>m2;
    if(n<=15)
    {
        vector<int > v;
        v.clear();
        backb(v);
        cout<<kq<<"\n";
        return 0;
    }
    return 0;
}
