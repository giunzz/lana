#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    queue<int> q;
    ios_base::sync_with_stdio(false);
	cout.tie();cin.tie(0);
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
	while (cin >> n)
	{
	    for (int i = 1; i <= n; i++) q.push(i);
	    cout << "Discarded cards: ";
        if (n != 1)
        {
            while (q.size() > 1)
            {
                cout << q.front();
                q.pop();
                x = q.front();
                q.pop();
                if (!q.empty()) cout << ", ";
                q.push(x);
            }
            cout << endl;
        }
        cout << "Remaining card: " << q.front() << endl;
        q.pop();
	}
    return 0;
}

