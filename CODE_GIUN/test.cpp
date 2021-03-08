/*#include<bits/stdc++.h>
using namespace std;

int n , x[(int) 1e5+7] , dd[(int) 1e5+7] ={0};
map<int,int> a;
vector<int> tmp;
int main()
{
    ios_base::sync_with_stdio(false);
	cout.tie();cin.tie(0);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
        a[x[i]] = i;
        if (dd[x[i]] == 0) tmp.push_back(x[i]) , dd[x[i]] = 1;
    }
    for (int i = 0 ; i < tmp.size() ; i++)
        cout << x[a[i]] << " ";
}*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    queue<int> q;
    ios_base::sync_with_stdio(false);
	cout.tie();cin.tie(0);
	while (cin >> n)
	{
	    for (int i = 1; i <= n; i++) q.push(i);
            cout << "Discarded cards: ";
        while (q.size() > 1)
        {
            cout << q.front();
            q.pop();
            x = q.front();
            q.pop();
            if (!q.empty()) cout << ",";
            q.push(x);
        }
        cout << endl;
        cout << "Remaining card: " << q.front() << endl;
        q.pop();
	}
    return 0;
}
