#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define Name "BUBBLETEA"
using namespace std;
const int maxN = 5 * 1e4 + 190;
const ll oo = 1e18;
typedef pair<ll , int > ii;
vector<ii> adj[maxN];
int n , k , dd[maxN] , st , fi;
map<pair<int,int> ,int > mp;
vector<int> pnt;
bool dfs(int u)
{

}
void sub_1()
{
    vector<int> p1;
    vector<int> p2;
    for(int i = 0 ; i < (k / 2); ++i)
	{
        p1.push_back(i);
        p2.push_back(i);
	}
    do
	{
        do
		{

		}while(next_permutation(p1.begin() ,p1.end()));
	}while(next_permutation(p2.begin() , p2.end()));
}
int main()
{
    freopen(Name".inp","r",stdin);
    freopen(Name".out","w",stdout);
    /*scanf("%d%d",&n,&k);
    int a , b;
    for(int i = 1 ; i <= k ; ++i) {scanf("%d",&a); pnt.push_back(a);}
	for(int i = 1 ; i < n ; ++i)
	{
		ll w;
        scanf("%d%d%lld",&a,&b,&w);
        adj[a].push_back(ii(w,b));
        adj[b].push_back(ii(w,a));
	}*/
	printf("-1");
    return 0;
}
