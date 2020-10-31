#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define maxn 10005
#define ll long long
#define fi first
#define se second
using namespace std;

const int mod=1e9+9;

int n,mmax,M50,M1,M2,cnt=0,x[51];

void IO() {
    freopen("ICECREAM.inp","r",stdin);
    freopen("ICECREAM.out","w",stdout);
}

void dfs(int i) {
    if (i>n) {
        int m50=M50,m1=M1,m2=M2;
        bool check=true;
        For(j,1,n) {
            bool ok=false;
            if (x[j]==0 && m50<mmax) {m50++;ok=true;}
            if (x[j]==1)
                if (m50>0&&m1<mmax) {m50--;m1++;ok=true;}
            if (x[j]==2)
                if (m50>=3&&m2<mmax) {m50-=3;m2++;ok=true;}
                else if(m1>0&&m50>0&&m2<mmax) {m50--;m1--;m2++;ok=true;}
            if (!ok) {check=false;break;}
        }
        if (check) {
//            For(j,1,n)
//            cout<<x[j]<<' ';
//            cout<<'\n';
            cnt++;
        }
        return ;
    }
    For(j,0,2) {
        x[i]=j;
        dfs(i+1);
    }
}

void Read() {
    scanf("%d%d",&n,&mmax);
    scanf("%d%d%d",&M50,&M1,&M2);
}

int main() {
    IO();
    Read();
    dfs(1);
    cnt%=mod;
    cout<<cnt<<'\n';
    return 0;
}
