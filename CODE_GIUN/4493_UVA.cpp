#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
int p , c , x , cases = 1 ;
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
        if (p == 0 || c == 0) cout << "Case " << cases++ << ":" <<  endl;
        else 
        {
            cout << "Case " << cases++ << ":" << endl;
            for (int i = 1; i <= min(p,1000) ; i++) q.push_back(i);
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
                    q.erase(remove(q.begin(),q.end(),x),q.end());
                    q.push_front(x);
                }
            }
        }
    }
}