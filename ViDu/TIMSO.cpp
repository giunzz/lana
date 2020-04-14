/*#include <bits/stdc++.h>
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
}*/

#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define err(variable) cerr << variable << " "
#define errl(variable) cerr << variable << "\n"
#define loop(variable, valuegan, valuebehonbang) for(long long variable = valuegan; variable <= valuebehonbang; variable++)
#define loopd(variable, valuegan, valuelonhonbang) for(long long variable = valuegan; variable >= valuelonhonbang; variable--)
#define loopdk(variable, valuegan, conditions, thaydoi) for(long long variable = valuegan; conditions; thaydoi) 
#define pp(type) pair<type, type>
#define vec(type) vector<type>
#define vecite(type) vector<type>::iterator
using namespace std;
const string tenfile = "TIMSO";
#define fi freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

cii df[] = {2, 3, 5, 7};
ii n, m, ts[11] = {0}, s = 0;

bool tachn(){
    int t = n;
    loop(i, 0, 3)
        while(!(t % df[i]))
            ++ts[df[i]], t /= df[i], s += df[i];
    if(t != 1) return 1;
    else return 0;
}

void xuly4(){
    ts[4] = ts[2] / 2;
    ts[2] %= 2;
}

void xuly1(){
    ts[1] = m - s;
    s = m;
}

void xuly(){
    while((m - s) >= 3 && ts[3] > 1)
        s += 3, ts[3] -= 2, ++ts[9];
    while((m - s) >= 2 && ts[2] > 2)
        s += 2, ts[2] -= 3, ++ts[8];
    while((m - s) >= 1 && ts[3] > 0 && ts[2] > 0)
        s += 1, --ts[2], --ts[3], ++ts[6];
    xuly4();
    xuly1();
}

int main(){
    //opt;
    fi;
    scanf("%d%d", &m, &n);
    if (n == 0 && m == 0){
        printf("0");
        return 0;
    }
    if(m != 0 && n == 0){
        cerr << 1;
        if(m % 9 != 0 && (m / 9) <= 4) printf("%d0", m % 9);
        else if(m / 9 <= 5) {
            printf("90");
            m -= 9;
        }
        else {
            printf("-1");
            return 0;            
        }
        loop(i, 1, m / 9) printf("9");
        return 0;
    }    
    if (tachn() || m > 54 || (m == 0 && n != 0)){
        printf("-1");
        return 0;
    }
    if (m < s){
        printf("-1");
        return 0;       
    }
    xuly();
    int tc = 0;
    loop(i, 1, 9) tc += ts[i];
    if (tc > 6){
        printf("-1");
        return 0;
    }
    loop(i, 1, 9)
        loop(j, 1, ts[i]) 
            printf("%I64d", i);
}