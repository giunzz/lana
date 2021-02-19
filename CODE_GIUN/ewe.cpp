/*#include<bits/stdc++.h>
using namespace std;
const  int maxn = 10e5 +7;
int n,f[maxn] ={0}, a[maxn], kq[maxn], c[maxn]={0};

int Tong (int i){
    int j=n, ans = 0;
    while ( i<= j){
        if ((j-(j & (-j))) >= i){
            ans+=f[j];
            j = j-(j & (-j));
        }
        else {
            ans += c[j--];
        }
    }
    return ans;
}
void up (int i){
    while ( i<= n ){
        ++f[i];
        i += i & (-i);
    }
}

void dd (int  k ){
    kq[k]= n - a[k] - Tong(a[k]);
    c[a[k]] = 1;
    dd ( a[k] );
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    freopen("nghichthe.inp","r",stdin);
    freopen("nghichthe.out","w",stdout);
    cin >> n;
    for (int i=1 ; i <= n ;i++) cin >> a[i];
    for (int i=n ; i >= n ;i--) dd(i);
    for (int i=1 ; i <= n ;i++) cout << kq[i] << " " ;
}*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int n, f[maxn] = {0}, a[maxn], kq[maxn], c[maxn] = {0};

int getS(int i){
    int j = n, ans = 0;
    while (i <= j){
        if ((j - (j & (-j))) >= i){
            ans += f[j];
            j = j - (j & (-j));
            cerr << i << " " << j << " " << ans << endl;
        }
        else {
            ans += c[j--];
            cerr << i << " " << j << " " << ans << endl;
        }
    }
    return ans;
    cerr << ans +100 ;
}

void updt(int i){
    while(i <= n){
        ++f[i];
        i += i & (-i);
    }
}

void sol(int pi){
    kq[pi] = n - a[pi] - getS(a[pi]);
    if (pi == n) cerr << n <<" " <<  a[pi] << " " << getS << " " << kq[pi];
    c[a[pi]] = 1;
    updt(a[pi]);
}

int main(){
    //ios_base::sync_with_stdio(0);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("ewe.inp", "r", stdin);
    freopen("ewe.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) sol(i);
    for (int i = 1; i <= n; i++) cout << kq[i] << " ";
}

