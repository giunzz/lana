// #include <bits/stdc++.h>
// #define ll long long
// #define cll const ll
// #define giuncute  ios_base::sync_with_stdio(0),cin.tie(0); cout.tie(0);
// cll maxn = 2007;
// using namespace std;
// ll n , t ;
// vector<ll> h,a;

// int main()
// {
//     giuncute;
//     freopen("chuyen02.inp","r",stdin);
//     freopen("chuyen02.out","w",stdout);
//     cin >> n ;
//     h.push_back(0);
//     for (int i = 1 ; i <= n ; i++)
//     {
//         int dem =0;
//         for (int j = 1 ; j <= n ; j++)
//         {
//             cin >> t;
//             if (t == 1) a.push_back(j),dem++;
//         }
//         h.push_back(dem+h[h.size()-1]);
//     }
//     for (int i = 0 ; i < (int) h.size() ; i++) cout << h[i] << " ";
//     cout << endl;
//     for (int i  = 0 ; i < (int) a.size() ; i++) cout << a[i] << " ";
// }
#include<bits/stdc++.h>
using namespace std;
int n,a[11000][11000];
long long sum=0;
int check(int i){
    int dem=0;
    for(int j=1;j<=n;j++){
        if(a[i][j]==1) dem++;
    }
    return dem;
}
int main(){
    freopen("CHUYEN02.INP","r",stdin);
    freopen("CHUYEN02.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    cout<<0<<" ";
    for(int i=1;i<=n;i++){
        sum+=check(i);
        cout<<sum<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1) cout<<j<<" ";
        }
    }

}