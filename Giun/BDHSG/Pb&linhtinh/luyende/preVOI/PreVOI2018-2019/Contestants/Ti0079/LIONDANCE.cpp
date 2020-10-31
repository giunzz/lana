#include <bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
vector <pi> ruler;
unordered_map <int,int> d1;
int result[4001][4001],a[4001],need,b[4001],cd,k;
pi trace[4001][4001];
void inp()
{
    cin >> cd >> need;
    for (int i = 1 ; i <= cd ; i++) cin >> a[i];
    for (int i = 1 ; i <= cd ; i++) cin >> b[i];
}
void do_it()
{
    int kq = 0;
    pi ide;
    int en = -1;
    for (int i = 1 ; i <= cd ; i++)
    {
        int t = 0 , k = -1;
        pi cur = pi(0,0);
        for (int e = 1 ; e <= cd ; e++)
        {
           // cout <<abs(b[e] - a[i])<<endl;
            result[i][e] = 0;
            if (abs(b[e] - a[i]) > need) continue;
            if (abs(a[i] - b[e]) == 0) result[i][e] = t + 1 , trace[i][e] = cur ;// cout <<"Trace["<<i<<"]["<<e<<"] : "<<cur.first<<" "<<cur.second<<endl;
            int pos = d1[b[e]];
           // cout <<"T : "<<t<<endl;
            if (result[pos][e] > t) k = b[e] , t = result[pos][e] , cur = pi(pos,e);
            else
            if (result[pos][e] == t)
                if (k < b[e]) k = b[e] , cur = pi(pos,e);
            if (kq < result[i][e]) en = b[e] , kq = result[i][e] , ide = pi(i,e);
            else
            if (kq == result[i][e] && en < b[e]) en = b[e] , ide = pi(i,e);
        }
        d1[a[i]] = i;
    }
  //  cout <<ide.first<<" "<<ide.second<<endl;
    cout << kq<<endl;
    while (kq != 0)
    {
        ruler.push_back(ide);
        ide = pi(trace[ide.first][ide.second]);
        kq--;
    }
   // cout << ruler.size()<<endl;
    for (int i = ruler.size() - 1 ; i >= 0 ; i--)
    {
        pi g = ruler[i];
        cout << a[g.first]<<" ";
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LIONDANCE.INP","r",stdin);
    freopen("LIONDANCE.OUT","w",stdout);
    inp();
    do_it();
}
