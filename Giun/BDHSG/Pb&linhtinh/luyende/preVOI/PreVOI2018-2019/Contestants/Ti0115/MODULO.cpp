#include<bits/stdc++.h>
using namespace std;
int64_t lt;
int64_t LT(int a,int k)
{
    if(k==1) return a;
    int64_t t=LT(a,k/2);
    if(k%2) return t*t*(int64_t)a;
    return t*t;
}
bool ok=false;
int x[70],n,A,B;
int64_t k;
typedef pair<int64_t,int> LI;
map<int64_t,LI> pre;
void trace(int64_t v,int type)
{
    int cnt=1;
    x[cnt]=type;
    while(pre[v].second>0&&cnt<n) {
        x[++cnt]=pre[v].second;
        v=pre[v].first;
    }
    if(cnt==n) {
        ok=true;
        for(int i=cnt;i>=1;i--)
            if(x[i]==1) printf("%d",A);
            else printf("%d",B);
    }
}
queue<LI> q;
void BFS()
{
    q.push(LI(A%lt,1));
    q.push(LI(B%lt,2));
    while(!q.empty()) {
        LI u=q.front();
        q.pop();
        int64_t v=((u.first*10)%lt+A)%lt;
        pre[v]=u;
        q.push(LI(v,1));
        if(v==k) {
            trace(v,1);
            if(ok) return ;
        }
        v=((u.first*10)%lt+B)%lt;
        pre[v]=u;
        q.push(LI(v,2));
        if(v==k) {
            trace(v,2);
            if(ok) return ;
        }
    }
    printf("-1");
}
#define LO "MODULO"
int main ()
{
    freopen(LO".inp","r",stdin);
    freopen(LO".out","w",stdout);
    scanf("%d%d",&A,&B);
    scanf("%d%I64d",&n,&k);
    lt=LT(2,n);
    BFS();
}
