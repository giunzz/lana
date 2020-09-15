#include<iostream>
#include<queue>
#define fi first
#define se second

using namespace std;

<<<<<<< HEAD
int n, m, q, u[200005], v[200005], r1, r2, r[200005], s1[200005];
bool kt[200005];
char s[200005];
long long da[200005], ans[200005], s2[200005], a[200005];
typedef pair <long long, int> li;
priority_queue<li>Q;

int root(int i){
    if(r[i] == 0) return i;
    r[i] = root(r[i]);
    return r[i];
}

int main(){
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        da[i] = a[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i];
        kt[i] = false;
    }
    for(int i = 1; i <= q; i++){
        cin >> s[i] >> s1[i];
        if(s[i] == 'C'){
            cin >> s2[i];
            da[s1[i]] = s2[i];
            swap(a[s1[i]], s2[i]);
        }
        else kt[s1[i]] = true;
    }
    for(int i = 1; i <= m; i++){
        if(!kt[i]){
            r1 = root(u[i]); r2 = root(v[i]);
            if(r1 != r2){
                r[r1] = r2; da[r2] += da[r1]; da[r1] = 0;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(r[i] == 0){
            Q.push({da[i], i});
        }
    }
    for(int i = q; i >= 1; i--){
        while(!Q.empty() && (da[root(Q.top().se)] != Q.top().fi)) Q.pop();
        ans[i] = Q.top().fi;
        if(i == 1) break;
        if(s[i] == 'C'){
            r1 = root(s1[i]);
            da[r1] += -a[s1[i]] + s2[i];
            swap(a[s1[i]], s2[i]);
            Q.push({da[r1], r1});
        }
        else{
            r1 = root(u[s1[i]]); r2 = root(v[s1[i]]);
            if(r1 != r2){
                r[r1] = r2; da[r2] += da[r1]; da[r1] = 0;
                Q.push({da[r2], r2});
            }
        }
    }

    for(int i = 1; i <= q; i++){
        cout << ans[i] << endl;
    }
}
=======
ll a, n, b = LLONG_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> n;
    ll i = 0;
    // while(1e18/n >= i){
    //     b = min(b, a ^ (n * i++));
    //     cerr << 1;
    // }
    ll tmp = 1e18/n * n;
    // cerr << (a ^ 0);
    cout << (a ^ tmp);
    b = a ^ tmp;
    cerr << endl << tmp;
}
>>>>>>> 362548bee5c79f88a3d7aa1a9f6456595f3586f4
