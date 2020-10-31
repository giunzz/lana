#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL Base =1e9 + 13;
const int N = 3003;

vector < int > vc_a[N],vc_b[N];
int a[N],b[N];

void load() {
    #ifndef ONLINE_JUDGE
    freopen("sequence.inp","r",stdin);
    freopen("sequence.out","w",stdout);
    #endif // ONLINE_JUDGE
}

void trungtt() {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d",&a[i]);
    for (int i = 1 ; i <= m ; ++ i)
        scanf("%d",&b[i]);
    vector < int > ans;

    for (int len = 1 ; len <= n ; ++ len) {
        int start = 1;
        int tmp = len;
        while (tmp > 0) {
            int pos = start;
            for (int i = start + 1 ; i <= n - tmp + 1 ; ++ i)
                if (a[i] < a[pos]) pos = i;
            vc_a[len].push_back(a[pos]);
            start = pos + 1;
            --tmp;
        }
    }
     for (int len = 1 ; len <= m ; ++ len) {
        int start = 1;
        int tmp = len;
        while (tmp > 0) {
            int pos = start;
            for (int i = start + 1 ; i <= m - tmp + 1 ; ++ i)
                if (b[i] < b[pos]) pos = i;
            vc_b[len].push_back(b[pos]);
            start = pos + 1;
            --tmp;
        }
    }

    for (int i =1  ; i <= k ; ++ i) ans.push_back(1e9);
    for (int i = max(1,k-m) ; i <= n ; ++ i) {
        int len = k - i;
        for (int j = 0 ; j < vc_b[len].size() ; ++ j) {
            vector < int > tmp;
            for (int t = 0 ; t < j ; ++ t) tmp.push_back(vc_b[len][t]);
            for (int t : vc_a[i]) tmp.push_back(t);
            for (int t = j ; t < vc_b[len].size() ; ++ t)
                tmp.push_back(vc_b[len][t]);
            if (ans > tmp) ans = tmp;
        }
    }
    for (int t : ans) printf("%d ",t);
    return ;
}

int main() {
    load();
    trungtt();
    return 0;
}
