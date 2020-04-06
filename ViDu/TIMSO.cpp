#include <bits/stdc++.h>
using namespace std;
const string file = "giun";
#define balabolo(a) freopen((a + ".inp").c_str(), "r", stdin) ,freopen((a + ".out").c_str(), "w", stdout)
#define fi first
#define se second
#define giun ios_base::sync_with_stdio(0) , cin.tie(0);

pair <int , int > b[4]; 
int N , a[100] = {1} , m , sum = 0 , p = 1 , d = 0 ;
vector<int> meo , ans;


void xuly()
{
    //if (b[1].se > 2 ) ans.push_back (2*b[1].se) , ans.push_back() 
    for (int i = (int) meo.size() -1 ; i >= 0 ; i--)
    {
        if (meo[i] == 2 && meo[i-1] == 2 && me[i-2] == 2) 
        {
            ans.push_back(8);
            sum -= 2;
    }
}

int main()
{
    giun;
    balabolo(file);
    cin >> m >> N;
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

    for (int i = 1; i <= 4 ; i++)
    {
        cerr << b[i].fi << " ^ " << b[i].se << endl ;
        for (int j = 1 ; j <= b[i].se ; j++)
        {
            d++;
            meo.push_back(b[i].fi);
            sum += b[i].fi;
            p *= b[i].fi;
        }
    }
    for (int i = 0 ; i < (int)meo.size() ; i++) cerr << meo[i];
    cerr << endl;
    if ( d > 7  ) meo.clear() , meo.push_back(-1) ;
    
    


    cerr << endl;
    cerr << d <<" " << sum << " " << p ;
    cerr << endl << clock() << " ms";
    return 0;
}