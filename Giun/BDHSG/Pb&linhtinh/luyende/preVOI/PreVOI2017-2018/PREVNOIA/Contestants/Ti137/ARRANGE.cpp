#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define NAME "ARRANGE."
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
typedef long long ll;

#define maxn (100000+5)
int n;
int a[maxn];
ll sum=0;

void input(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}

struct subtask1{
    subtask1(){}
    bool ok(){
        FOR(i,1,n) sum+=(ll) a[i];
        return ((sum%(ll)n)==0);
    }
    void Xuli(){
        ll t=sum/(ll)n;
        ll res=0;
        FOR(i,1,n) if ((ll)a[i]<t) res+=t-(ll)a[i];
        cout<<res;
    }
} st1;

struct subtask2{
    subtask2(){}
    ll x1,x2;

    bool ok1(){
        x1=(sum/n)-1;
        x2=(sum+n)/n-1+1;
        return (x2-x1+1<=50000);
    }

//    vector<int> way;
    ll way;
    ll res;
    ll dutru;
    map<int,int> d;
    void Xuli1(){
        res=1e17;
        FOR(x,x1,x2){
            int k=(ll)n*(x+1ll)-sum;
            if (k<1 || k>n) continue;
            ll tam=0;
            for(int i=n;i>=k+1;i--) if (a[i]>=x+1) {tam+=a[i]-(x+1); d[a[i]-(x+1)]++;}
            int tk=k;
            for(int i=k;i>=1;i--)  {
                if (a[i]>=x) { tam+=(a[i]-x); d[(a[i]-x)]++;}
            }
            way+=tam;
            for(int i=n;i>=k+1;i--) if (a[i]<x+1) tam-=((x+1)-a[i]);
            FOR(i,1,k) if (a[i]<x) {
                tam-=x-a[i];
                if (d[x-a[i]]==0) {
                        for(auto it=d.rbegin(); it!=d.rend(); ++it){
                        while (it->second >0){
                            if (it->first < x-a[i]){
                                it->second--;
                                d[x-a[i]- (it->first)]++;
                                way+=it->first;
                            }
                            else if (it->first > x-a[i]){
                                it->second--;
                                d[it->first - (x-a[i])]++;
                                way+=(it->first - (x-a[i]));
                            }
                            else {
                                way+=it->first;
                                it->second--;
                            }
                        }
                    }
                }
            }
            res=min(res,way);
        }
        cout<<res;
    }

} st2;

int main()
{
    freopen(NAME"inp","r",stdin);
    freopen(NAME"out","w",stdout);
    iostream::sync_with_stdio(0);
    input();
    if (st1.ok()) {st1.Xuli(); return 0;}
    sort(a+1,a+n+1);
    if (n<=2000){
        if (st2.ok1())
            {st2.Xuli1(); return 0;}
    }
}
