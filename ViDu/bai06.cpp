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
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define fin(tenfile) freopen(tenfile, "r", stdin)
#define fout(tenfile) freopen(tenfile, "w", stdout)
#define in(variable) cin >> variable
#define out(variable) cout << variable << " "
#define outl(variable) cout << variable << "\n"
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define fi first
#define se second
#define pp(kieu) pair<kieu, kieu>
#define vec vector<long long>
#define vec2 vector<vector<long long>>
#define vecite vector<long long>::iterator
using namespace std;
pp(float) a[107];

int main(){
    opt;
    fin("input.inp");
    fout("output.txt");
    in(n);
    loop(i, 1, n) in(a[i].fi), in(a[i].se);
    
}