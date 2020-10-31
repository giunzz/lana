#include<bits/stdc++.h>
#define llong long long
#define _pair pair<llong, llong>
#define MP make_pair
using namespace std;
map<_pair, int> mapp;
queue<llong> q;
void mini(_pair &a, _pair b)
    {
        if (a.first+a.second > b.first+b.second)
            a=b;
    }
bool inT(llong u, llong v)
    {
        return (u >= 1)&&(u <= 1000)&&(v >= 1)&&(v <= 1000);
    }
void BFS(llong uu, llong vv)
    {
        while(!q.empty()) q.pop();
        mapp.clear();
        _pair res=MP(uu,vv);
        q.push(uu), q.push(vv);
        mapp[MP(uu,vv)]=1;
        while (!q.empty()){
            llong u=q.front(); q.pop();
            llong v=q.front(); q.pop();
            llong x=__gcd(u,v);
            llong nu=u/x, nv=v/x;
            if (!mapp.count(MP(nu,nv))){
                mapp[MP(nu,nv)]=1;
                q.push(nu), q.push(nv);
                mini(res,MP(nu,nv));
            }
            for (llong i=2; i <= sqrt(u); i++)
                if (u%i == 0){
                    nu=u/i, nv=v*i;
                    if (inT(nu,nv)&&(!mapp.count(MP(nu,nv)))){
                        mapp[MP(nu,nv)]=1;
                        q.push(nu), q.push(nv);
                        mini(res,MP(nu,nv));
                    }
                    llong j=u/i;
                    nu=i, nv=v*j;
                    if (inT(nu,nv)&&(!mapp.count(MP(nu,nv)))){
                        mapp[MP(nu,nv)]=1;
                        q.push(nu), q.push(nv);
                        mini(res,MP(nu,nv));
                    }
                }
            for (llong i=2; i <= sqrt(v); i++)
                if (v%i == 0){
                    nv=v/i, nu=u*i;
                    if (inT(nu,nv)&&(!mapp.count(MP(nu,nv)))){
                        mapp[MP(nu,nv)]=1;
                        q.push(nu), q.push(nv);
                        mini(res,MP(nu,nv));
                    }
                    llong j=v/i;
                    nv=i, nu=u*j;
                    if (inT(nu,nv)&&(!mapp.count(MP(nu,nv)))){
                        mapp[MP(nu,nv)]=1;
                        q.push(nu), q.push(nv);
                        mini(res,MP(nu,nv));
                    }
                }
        }
        cout<<res.first<<' '<<res.second<<'\n';
    }
void solve(llong a, llong b)
    {
        llong x=__gcd(a,b);
        a/=x, b/=x;
        for (llong i=2; i <= sqrt(a); i++){
            while (a%(i*i) == 0) a/=(i*i);
            while (b%(i*i) == 0) b/=(i*i);
            while ((a%i == 0)&&(b%i ==0))
                a/=i, b/=i;
            if (a%i == 0){
                llong na=a/i, nb=b*i;
                if (a+b > na+nb) a=na, b=nb;
            }
            if (b%i == 0){
                llong na=a*i, nb=b/i;
                if (a+b > na+nb) a=na, b=nb;
            }
        }
        cout<<a<<' '<<b<<'\n';
    }
int main()
{
    freopen("MINSUM.inp","r",stdin);
    freopen("MINSUM.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(NULL);
    int t; cin>>t;
    while (t--){
        llong a,b; cin>>a>>b;
        if ((a <= 100)&&(b <= 100))
            BFS(a,b);
          else
            solve(a,b);
    }
    return 0;
}
