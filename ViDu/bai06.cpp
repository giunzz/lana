/*#include<bits/stdc++.h>

using namespace std;

int n , s  , k , d = 0 , len , ans1 ;
int dd[1007]={0};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.inp","r",stdin);
    freopen("output.txt","w",stdout);
    
    //freopen("Bai06.inp","r",stdin);
    //freopen("Bai06.out","w",stdout);
    cin >> n >> s >> k; 

    while ( len != n-1 )
    {
        for(int i = 1 ; i <= n ; i++)
        {
            if ( dd[i] == 0 ) d++;
            if (d == s ) 
            {
                dd[i] = 1;
                d = 0;
                len++;
            }
        }
    }
    for (int i = 1 ; i <= n ; i++) {
        if (dd[i] == 0) ans1 = i;
        //cerr << i << " "  << dd[i] << endl;
    }
    //cerr << endl;
    //for (int i = 0 ; i < (int) tam.size() ; i ++)  cerr << tam[i] << " ";
    cout << ans1 << endl ;
    return 0;
}*/

#include <bits/stdc++.h>

using namespace std;
int ans[107] = {0}, n, s, k;
vector<int> tt;

int sol(int vt){
    vector<int> res = tt;
    int dem = 0;
    while((int)res.size() - 1){
        if (!(s - ++dem)){
            cerr << vt << " ";
            dem = 0;
            res.erase(res.begin() + vt);
        }
        else
        {
            vt = (vt + 1) % res.size();
            //cerr << res[vt] << endl;
        }
    }
    //for (int i = 0 ; i < (int)res.size() ; i++ ) cerr << res[i] << " ";
    return res[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.inp", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("bai06.inp", "r", stdin);
    freopen("bai06.out", "w", stdout);
    cin >> n >> s >> k;
    for (int i = 1; i <= n; i++) tt.push_back(i);
    for (int i = 0; i < n; i++)
    {
        ans[i + 1] = sol(i);
    }
    cerr << endl;
    for (int i = 1 ; i <= n ; i++) cerr << ans[i] << " ";
    cout << ans[1] << endl;
    for (int i = 1; i <= n; i++){
        if (ans[i] == k) {
            cout << i;
            return 0;
        }
    }
}