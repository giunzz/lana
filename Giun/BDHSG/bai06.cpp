#include <bits/stdc++.h>
using namespace std;
const string tenfile = "bai06";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

int ans[107] = {0}, n, s, k;
vector<int> tt;

int sol(int vt){
    vector<int> res = tt;
    int dem = 0;
    while((int)res.size() - 1){
        if (!(s - ++dem)){
            dem = 0;
            res.erase(res.begin() + vt);
        }
        else
        {
            vt = (vt + 1) % res.size();
        }
    }
    return res[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fi;
    cin >> n >> s >> k;
    for (int i = 1; i <= n; i++) tt.push_back(i);
    for (int i = 0; i < n; i++)
    {
        ans[i + 1] = sol(i);
    }
    cout << ans[1] << endl;
    for (int i = 1; i <= n; i++){
        if (ans[i] == k) {
            cout << i;
            return 0;
        }
    }
}