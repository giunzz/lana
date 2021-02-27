/*#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int d[maxn] = {0}, n, t, ans[maxn] = {0}, tk = 0;

bool cnt(int k){
    for (int i = 2; i * i <= k; i++){
        if (!(k % i)) return false;
    }
    return 1;
}

int dao(int k){
    int b = 0;
    while (k){
        b = b * 10 + k % 10;
        k /= 10;
    }
    return b;
}

int main(){
    freopen("CSNT.INP", "r", stdin);
    freopen("CSNT.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 12; i <= n; i++){
        if(!cnt(i)) continue;
        t = dao(i);
        if(!cnt(t) || t == i || d[i] || d[t]) continue;
        ans[++tk] = i;       
        d[i] = 1, d[t] = 1;
    }
    printf("%d\n", tk);
    for(int i = 1; i <= tk; i++) printf("%d %d\n", ans[i], dao(ans[i]));
}*/
#include<bits/stdc++.h>
using namespace std;
const string tenfile = "giun";
const int maxn = 1e5+7;
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
int sang[maxn] = {0};

void xaysang()
{
   sang[0] = 1; sang[1] = 1;
   for (int i = 2; i * i <= 1e5; i++)
        if (sang[i] == 0 ) 
           for (int j = i * 2; j <= 1e5; j += i) 
               sang[j] = 1;
}

int daoso(int k)
{
    int b = 0;
    while (k)
    {
        b = b * 10 + k % 10;
        k /= 10;
    }
    return b;
}

int  n , dd[maxn] = {0} , t;
vector<int> ans;
int main()
{
    balabalo;
    scanf("%d",&n);
    xaysang();
    for (int i = 12 ; i <= n ; i++)
    {
        t = daoso(i);
        if ( sang[i] == 0  && sang[t] == 0 && dd[i] == 0 && i != t )
        {
            cerr << i << " " << t << endl;
            ans.push_back(i) ;
            dd[i] = 1 , dd[t] = 1;
        }
    }

    printf("%d\n", (int) ans.size());
    for (int i = 0 ; i < (int) ans.size() ; i++)
    {
        printf("%d %d\n",ans[i] , daoso(ans[i]) );
    }
    return 0;
}
