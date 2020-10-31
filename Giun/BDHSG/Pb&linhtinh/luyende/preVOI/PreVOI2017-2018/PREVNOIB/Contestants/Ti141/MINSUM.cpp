#include <bits/stdc++.h>

#define TASK "MINSUM"

using namespace std;

template<typename T> inline void read(T &x){
    x = 0; char ch; bool neg = 0;
    while(!isdigit(ch=getchar())&&ch!='-');
    if(ch=='-'){neg=1;ch=getchar();}
    do{x=10*x+ch-'0';}while(isdigit(ch=getchar()));
    if(neg) x = -x;
}

const int N = 500;

int test, x, y;
bool B[N][N];

void DFS(int u, int v){
    B[u][v] = 1;
    for(int i = 1; i*i <= u; i++){
        if(u%i==0){
            if(v%i==0&&!B[u/i][v/i]) DFS(u/i,v/i);
            else if(u%(i*i)==0&&v*i<=N&&!B[u/i][v*i]) DFS(u/i,v*i);
            int t = u/i;
            if(v%t==0&&!B[u/t][v/t]) DFS(u/t,v/t);
            else if(v*t<=N&&!B[u/t][v*t]) DFS(u/t,v*t);
        }
    }
    for(int i = 1; i*i <= v; i++){
        if(v%i==0){
            if(u%i==0&&!B[u/i][v/i]) DFS(u/i,v/i);
            else if(v%(i*i)==0&&u*i<=N&&!B[u*i][v/i]) DFS(u*i,v/i);
            int t = v/i;
            if(u%t==0&&!B[u/t][v/t]) DFS(u/t,v/t);
            else if(u*t<=N&&!B[u*t][v/t]) DFS(u*t,v/t);
        }
    }
}

void solve1(){
    memset(B,0,sizeof(B));
    DFS(x,y);
    int sum = x+y;
    int u = x, v = y;
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            if(B[i][j]&&sum>i+j){
                sum = i+j;
                u = i; v = j;
            }
        }
    }
    cout<<u<<' '<<v<<'\n';
}

void conv(map<int,int> &X, int xx){
    int tmp = xx;
    for(int i = 2; i*i <= xx && i <= tmp; i++){
        while(tmp%i==0){
            X[i]++;
            tmp /= i;
        }
    }
    if(tmp>1) X[tmp]++;
}

void magic(map<int,int> &X, map<int,int> &Y){
    for(auto i = X.begin(); i != X.end(); i++){
        int t = i->first;
        if(Y.find(t)!=Y.end())
        while(X[t]>0&&Y[t]>0){
            X[t]--;
            Y[t]--;
        }
        while(X[t]>1){
            X[t]-=2;
        }
    }
}

void solve2(){
    map<int,int> X, Y;
    conv(X,x);
    conv(Y,y);
    magic(X,Y);
    magic(Y,X);
    int u = 1, v = 1;
    for(auto i = X.begin(); i != X.end(); i++){
        if(i->second!=0) u *= i->first;
    }
    for(auto i = Y.begin(); i != Y.end(); i++){
        if(i->second!=0) v *= i->first;
    }
    cout<<u<<' '<<v<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    read(test);
    while(test--){
        read(x); read(y);
        if(x<=50&&y<=50) solve1();
        else solve2();
    }
    return 0;
}
