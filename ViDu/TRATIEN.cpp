// #include<bits/stdc++.h>
// using namespace std;
// const string tenfile = "giun";
// #define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

// int n , a[26] , d , ok = 1 ;
// long long sum = 0 , s = 0;
// vector<int> b;

// void printf_ans()
// {
//     for (int i = 0 ; i < (int) b.size() ; i++)
//         cout << b[i] << " ";
// }

// void Try (int vt )
// {
//     if ( ok == 1 || vt == n + 1  ) return;
//     s = 0;
//     b.clear();
//     for (int i = vt  ; i <= n ; i++)
//     {
//         if ( dd[a[i]] == 0 ) s += a[i];
//         cerr << s << " ";
//         b.push_back(a[i]);
//         if ( s == d  ) 
//         {
//             printf_ans();
//             ok = 1;
//         }
//         else Try(vt + 1) ;
//     }
// }

// int main()
// {
//     balabalo;
//     scanf("%d %d",&n,&d);
//     for (int i = 1 ; i <= n ; i++)
//     {
//         scanf("%d",&a[i]);
//         sum += a[i];
//     }
//     sort( a + 1 , a + 1 + n );
//     if ( sum == d ) 
//         for (int i = 1 ; i <= n ; i++) cout << a[i] << " ";
//     else if ( sum < d ) cout << -1;
//          else  Try(1);
//     return 0;
// }

#include <bits/stdc++.h>
#define ll long long
#define elif esle if
using namespace std;

ll n, d, a[25] = {0}, s = 0, tt, check = 0;
vector<ll> ans;

void printans(){
    for (int i = 0; i < ans.size(); ++i){
        printf("%I64d ", a[ans[i]]);
    }
}

void quaylui(ll vt){
    if (s > d || vt == n + 1 || check) return; //tu nghi
    if (s == d){ //tu nghi
        printans();
        check = 1;
        return;
    }
    if (vt == 1) tt = 1; //neu ans chua co phan tu thi bat dau chon tu vi tri dau tien
    else tt = ans.back() + 1; //nguoc lai tim tu vi tri tiep theo cua to tien cuoi cung da chon
    for (ll i = tt; i <= n; i++){
        s += a[i]; //tu nghi het
        ans.push_back(i);
        quaylui(vt + 1);
        s -= a[i];
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("giun.inp", "r", stdin);
    freopen("giun.out", "w", stdout);
    scanf("%I64d %I64d", &n, &d);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]), s += a[i];
    if (s < d) {cout << -1; return 0;} //tong a1 -> an < d
    sort(a + 1, a + 1 + n);
    if (s == d){
        for(int i = 1; i <= n; i++) printf("%I64d", &a[i]);
        return 0;
    }
    s = 0; //bat dau tim nghiem s la tong cac so duoc chon trong vector ans
    quaylui(1);
    if(!check) printf("-1");
}