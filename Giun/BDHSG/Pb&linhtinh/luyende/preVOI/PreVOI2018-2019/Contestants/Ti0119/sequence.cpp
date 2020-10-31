#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> ii;

const int mod = 1e9 + 7;

const int N = 3000 + 5;

int m, n, k;

int a[N], b[N], nex1[N][N], nex2[N][N], cnt;

int mymap1[N], mymap2[N];

vector<long long> vec1, vec2, vec;

//Ti0119

vector<int> solve(int sx, int sy, int sk, int sig) {
    vector<int> temp;
    if(sig != -1)
        temp.pb(sig);
    //cout << sx << " " << sy << " " << sk << "\n";
    int pter1 = sx, pter2 = sy;
    if(sk > k) return temp;
    for(int i = sk; i <= k; i++) {
        for(int j = 0; j < vec.size(); j++) {
            int ok = 0, ok1 = 0, ok2 = 0, newpter1 = 0, newpter2 = 0;
            if(pter1 <= m && nex1[pter1][vec[j]] <= m) {
                newpter1 = nex1[pter1][vec[j]];
                if(m - newpter1 + n - pter2 + 1 >= k - i) {
                    ok1 = 1;
                    ok = 1;
                }
            }
            if(pter2 <= n && nex2[pter2][vec[j]] <= n) {
                newpter2 = nex2[pter2][vec[j]];
                if(n - newpter2 + m - pter1 + 1 >= k - i) {
                    ok2 = 1;
                    ok = 1;
                }
            }
            if(ok) {
                //cout << pter1 << " " << newpter1 << " " << pter2 << " " << newpter2 << "\n";
                if(ok1 && ok2 == 0) {
                    temp.pb(vec[j]);
                    //cout << "wtf\n";
                    //cout << pter1 << " " << newpter1 << " " << pter2 << "\n";
                    pter1 = newpter1 + 1;
                    //cout << pter1 << " " << i << "\n";
                }
                else if(ok1 == 0 && ok2) {
                    temp.pb(vec[j]);
                    pter2 = newpter2 + 1;
                }
                else {
                    //cout << pter1 << " " << newpter1 << " " << pter2 << " " << newpter2 << " " << i << "\n";
                    vector<int> temp1, temp2;
                    temp1 = solve(pter1, newpter2 + 1, i + 1, vec[j]);
                    temp2 = solve(newpter1 + 1, pter2, i + 1, vec[j]);
                    int diff = 0;
                    for(int l = 0; l < temp1.size(); l++) {
                        if(temp1[l] > temp2[l])
                            diff = 2;
                        else if(temp1[l] < temp2[l])
                            diff = 1;
                        if(diff > 0) break;
                    }
                    if(diff == 0 || diff == 1) {
                        for(int l = 0; l < temp1.size(); l++)
                            temp.pb(temp1[l]);
                    }
                    else {
                        for(int l = 0; l < temp2.size(); l++)
                            temp.pb(temp2[l]);
                    }
                    return temp;
                }
                break;
            }
        }
    }
    //cout << temp.size() << "\n";
    return temp;
}

int main() {
    freopen("sequence.inp", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &k);
    for(int i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
        if(mymap1[a[i]] == 0) {
            vec.pb(a[i]);
            vec1.pb(a[i]);
        }
        mymap1[a[i]]++;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if(mymap2[b[i]] == 0) {
            vec.pb(b[i]);
            vec2.pb(b[i]);
        }
        mymap2[b[i]]++;
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++) {
        nex1[m + 1][vec[i]] = m + 2;
        nex2[m + 2][vec[i]] = m + 2;
    }
    for(int i = 0; i < vec.size(); i++) {
        nex2[n + 1][vec[i]] = n + 2;
        nex2[n + 2][vec[i]] = n + 2;
    }
    for(int i = m; i >= 1; i--) {
        for(int j = 0; j < vec.size(); j++)
            nex1[i][vec[j]] = nex1[i + 1][vec[j]];
        nex1[i][a[i]] = i;
    }
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < vec.size(); j++)
            nex2[i][vec[j]] = nex2[i + 1][vec[j]];
        nex2[i][b[i]] = i;
    }
    vector<int> ans = solve(1, 1, 1, -1);
    for(int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
}

