#include <bits/stdc++.h>
using namespace std;
const string file = "TIMSO";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
#define fi first
#define se second
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);
pair <int , int > b[5]; 
int N , a[100] ={1} , m ;

int main()
{
    giun;
    balabolo(file);
    cin >> m >> N;
    int n1 = N;
    for(int i = 2; i <= N; i++)
    {
        while(N % i == 0)
        {
            a[i]++;
            N /= i;
        }
    }
    b[1].fi = 2 , b[1].se = a[2];
    b[2].fi = 3 , b[2].se = a[3];
    b[3].fi = 5 , b[3].se = a[5];
    b[4].fi = 7 , b[4].se = a[7];
    int t , sum = 0 , p = 1;
    string st ="";
    for (int i = 1 ; i <= 4 ; i++)
    {
        //cerr << b[i].fi << " ^ " << b[i].se << endl;
        if ( b[i].se != 0 )
        {
            t = pow(b[i].fi, b[i].se);
            p *= t;
            st += char (t + 48);
            sum += t;
            cerr << t << " ";
        }
    }
    sort(st.begin(), st.end()); 
    cerr << endl;
    cerr << p << " " << sum << " " << st << endl;
    cerr << n1 << " " << m ;
    if ( (p == n1) && (sum == m) ) cout << st ;
    else    if (p == 1 ) 
                for (int i = 1; i <= m ; i++) cout << 1;
            else cout << -1;
    return 0;
}