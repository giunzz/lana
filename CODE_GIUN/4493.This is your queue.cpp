#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int p , c , x , cases = 0 ;
char v;
int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    while (cin >> p >> c )
    {
        deque<int> q;
        if ( p == 0 && c == 0) return 0;
        if (p == 0 || c == 0) cout << "Case " << cases++ <<  endl;
        for (int i = 1; i <= p ; i++) q.push_front(i);
        for (int i = 1 ; i <= c ; i++)
        {
            cin >> v;
            if (v == 'N')
            {
                cout << q.front() << endl;
                q.push_back(q.front());
                q.pop_front();
            }
            else 
            {
                cin >> x;
                q.push_front(x);
                q.erase(remove(q.begin(),q.end(),x),q.end());
            }
        }
    }
}