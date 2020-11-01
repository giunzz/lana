#include<bits/stdc++.h>
#define For(i,a,b) for(int i =a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define pii pair<int,int>
#define fi first
#define se second
#define maxn 40005
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x>>i) & 1)
using namespace std;

int n,d,k = 0,a[maxn],b[maxn],x[maxn],y[maxn],cnt = 0;

void Io()
{
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
}

void Read()
{
    scanf("%d%d",&n,&d);
    For(i,1,n) scanf("%d",&a[i]);
    For(j,1,n) scanf("%d",&b[j]);
}

void check()
{
    if(cnt < k) return;
    int vt = 1;
    For(i,1,n)
        if(b[i] == x[vt]) vt++;
    if(vt != cnt+1) return;
    if(cnt > k){
        k = cnt;
        For(i,1,k) y[i] = x[i];
        return;
    }
    if(cnt == k){
        int vt = k+1;
        For(i,1,k){
            if(y[i] > x[i]) return;
            if(x[i] > y[i]) {vt = i;break;}
        }
        For(i,vt,k) y[i] = x[i];
    }
}

void Subtask1()
{
    for(int i = 0;i < (1<<n);i++){
        cnt = 0;
        bool ok = true;
        For(j,0,n-1){
            if(Bit(i,j) == 1) x[++cnt] = a[j+1];
            if(cnt != 1 && x[cnt] - x[cnt-1]>d){ok = false;break;}
        }
        if(ok) check();
    }
    printf("%d\n",k);
    For(i,1,k)
        printf("%d ",y[i]);
}

void Solve()
{
    Subtask1();
}

int main()
{
    Io();
    Read();
    Solve();
}
