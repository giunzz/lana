#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e6 + 7;
int t, d[maxn] = {0}, adj[(int)1e7 + 7], head[maxn], x[maxn], y[maxn], a[maxn], n, kq[maxn], st[(int)1e7], top = -1;

void Push(int value){
    //++top;
    st[++top] = value;
}
 
void Pop(){
    return stack[top--];
}

int Size(){
    return top + 1;
}
 
void enter(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n + 1; i++)
        head[i] = 0;
 
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x[i] >> y[i];
        head[x[i]]++, head[y[i]]++;
    }
 
    for (int i = 2; i <= n + 1; i++)
        head[i] = head[i - 1] + head[i];
    
    for (int i = 1; i <= n - 1; i++)
    {    
        adj[head[x[i]]] = y[i];
        adj[head[y[i]]] = x[i];
        head[x[i]]--, head[y[i]]--;
    }
}

void sol(){
    int sum, i, next, sum = 0;
    Push(1);
    while (Size()){
        d[i] = 1;
        i = Pop();
        for (int j = head[i] + 2; j <= head[j + 1]; i++){
            if (d[adj[j]] != 1) Push(adj[j]);
        }
        if (head[i] + 1 == head[i + 1]) i = Pop(), sum -= a[i]; 
        else i = adj[head[i] + 1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("spc5.inp", "r", stdin);
    freopen("spc5.out", "w", stdout);
    cin >> t;
    for (int i = 1; i <= t; i++){
        enter();
        //for (int i = 1; i <= n + 1; i++) cerr << head[i] << " ";
        //cerr << endl;
        //for (int i = 1; i <= (n-1) * 2; i++) cerr << adj[i] << " ";
        sol();
    }
}