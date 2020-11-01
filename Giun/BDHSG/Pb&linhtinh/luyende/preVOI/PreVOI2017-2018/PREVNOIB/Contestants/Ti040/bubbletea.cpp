#include <bits/stdc++.h>
using namespace std;

#define task "bubbletea"

int n,k,res;

int main() {
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
	scanf("%d%d",&n,&k);
	int cc = 0;
	int u,v,c;
	for (int i=n; i>=1; --i) {
		scanf("%d%d%d",&u,&v,&c);
		res = max(res,c + cc); 
		cc = c;
	}
	printf("%d\n", res);

}