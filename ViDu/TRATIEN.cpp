/*#include <bits/stdc++.h>
using namespace std;

int n, d, a[25] = {0}, s = 0, tt, check = 0;
vector<int> ans;

void printans()
{
    for (int i = 0; i < (int) ans.size(); ++i)
    {
        printf("%d ", a[ans[i]]);
    }
}

void quaylui(int vt)
{
    if (s > d || vt == n + 1 || check) return; 
    if (s == d)
    { 
        printans();
        check = 1;
        return;
    }
    if (vt == 1) tt = 1; 
    else tt = ans.back() + 1; 
    for (int i = tt; i <= n; i++)
    {
        s += a[i]; 
        ans.push_back(i);
        quaylui(vt + 1);
        s -= a[i];
        ans.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tratien.inp", "r", stdin);
    freopen("tratien.out", "w", stdout);
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]); 
        s += a[i];
    }
    if (s < d) {
        printf("-1"); 
        return 0;
    } 
    sort(a + 1, a + 1 + n);
    if (s == d)
    {
        for(int i = 1; i <= n; i++) printf("%d", a[i]);
        return 0;
    }
    s = 0; 
    quaylui(1);
    if(!check) printf("-1");
}*/
#include <bits/stdc++.h>

#define ii pair < int, int >
#define vi vector < int >
#define vii vector < ii >
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define fr front
#define mp make_pair
#define fileInput(problemName) freopen ((string(problemName) + ".inp").c_str(), "r", stdin);freopen ((string(problemName) + ".out").c_str(), "w", stdout);
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);

const int inf = 1e9 + 7;
const int N = 1e6 + 7;

using namespace std;

int n, d, a[N], x[N];

void fastscan(int &number) 
{ 
    bool negative = false; 
    register int c; 
  
    number = 0; 
    c = getchar(); 
    if (c == ' ') fastscan(number);
    if (c=='-') 
    { 
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

void backTrack(int id) 
{
    if (id == n + 1) 
    {
        long long s = 0;
        for (int i = 1; i <= n; i++)
        {
            s += (x[i] * a[i]);
        }
        if (s == d) 
        {
            for (int i = 1; i <= n; i++) 
            {
                if (x[i]) 
                {
                    cout << a[i] << " ";
                }
            }
            cout << endl;
            exit(0);
        }
    } 
    else 
    {
        for (int i = 0; i <= 1; i++) 
        {
            x[id] = i;
            backTrack(id + 1);
        }
    }
}

int main() 
{
    fileInput("Tratien");
    fastscan(n); fastscan(d);
    for (int i = 1; i <= n; i++)  fastscan(a[i]);
    sort(a + 1, a + 1 + n);
    backTrack(1);
    cout << -1 << endl;
    cerr << clock() << " ms";
    return(0);
}