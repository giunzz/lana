#include <bits/stdc++.h>
using namespace std;
set <int> s;
int n;
void bfs(int u, int v)
{
    set <int> tmp;
    queue <int> q;
    q.push(u);q.push(v);
    tmp.insert(0);
    s.insert(0);
    while (!q.empty())
    {
        long long x=q.front();q.pop();
        //cout<<x<<" ";
        if(x*10+u<=n and tmp.find(x*10+u)==tmp.end() ) { s.insert(x*10+u); tmp.insert(x*10+u); q.push(x*10+u);};
        if(x*10+v<=n and tmp.find(x*10+v)==tmp.end() ) { s.insert(x*10+v); tmp.insert(x*10+v); q.push(x*10+v);};

    }
}
int main()
{
    cin>>n;
    for(int i=0;i<9;i++)
        for(int j=i+1;j<=9;j++)
        bfs(i,j);
    cout<<s.size()-1;
    return 0;
}
