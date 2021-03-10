#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)

int n , x;
int main()
{
    giuncute;
    while (cin >> n  , n)
    {
        priority_queue< int, vector<int> ,greater<int> > q;
        for (int i = 1 ; i <= n ; i++)  cin >> x ,q.push(x);
        int cost = 0 ;
        while (q.size() != 1)
        {
            x = q.top() , q.pop();
            x += q.top() , q.pop();
            cost += x;
            q.push(x);
        }
        cout << cost << endl;
    }
}