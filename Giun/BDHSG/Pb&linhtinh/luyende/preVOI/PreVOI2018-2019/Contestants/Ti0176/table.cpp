#include <bits/stdc++.h>
using namespace std;

int m,n,k;
int a[82][82],f[82][82],g[82][82];

void init(){
	freopen("table.inp","r",stdin);
	freopen("table.out","w",stdout);
}

void input(){
	scanf("%d%d%d",&m,&n,&k);
	for (int i = 1 ; i <= m ; i++)
		for (int j = 1 ; j <= n ; j++)
			scanf("%d",&a[i][j]);
}

struct data{
	int first;
	int second;
	int val;
};

bool cmp(data _x , data _y){
	return _x.val < _y.val;
}

pair<int,int> Prev[82][82];

void findRes(int u, int v, int p, int q){
	int Res = INT_MAX;

	memset(f,0,sizeof(f));
	vector<pair<int,int>> Path;
	for (int i = 0 ; i <= m ; i++)
		f[i][0] = -1;
	for (int i = 0 ; i <= n ; i++)
		f[0][i] = -1;
	f[0][1] = 0;
	f[1][0] = 0;
	
	for (int i = u ; i <= m ; i++)
		for (int j = v ; j <= n ; j++){
			if (f[i][j-1] < f[i-1][j]){
				Prev[i][j] = {i-1,j};
//				cerr<<"PREV "<<i<<" "<<j<<" = "<<i-1<<" "<<j<<endl;
				f[i][j] = f[i-1][j] + a[i][j];
			}
			else{
				Prev[i][j] = {i,j-1};
//				cerr<<"PREV "<<i<<" "<<j<<" = "<<i<<" "<<j-1<<endl;
				f[i][j] = f[i][j-1] + a[i][j];
			}
			
			if (i==p && j==q)
				break;
		}
	
	int curp = p, curq = q;
	while (true){
		pair<int,int> prevPos = Prev[curp][curq];
		curp = prevPos.first;
		curq = prevPos.second;
//		cerr<<curp<<" "<<curq<<endl;
		if (curp == u && curq == v)
			break;
		Path.push_back({curp,curq});
	}

	for (int i = 0 ; i < Path.size() ; i++){
		memset(f,0,sizeof(f));
		for (int i = 0 ; i <= m ; i++)
			f[i][0] = -1;
		for (int i = 0 ; i <= n ; i++)
			f[0][i] = -1;
		f[0][1] = 0;
		f[1][0] = 0;
		pair<int,int> cur = Path[i];
		f[cur.first][cur.second] = -1;
//		cerr<<" TRY "<<cur.first<<" "<<cur.second<<endl;
		for (int i = u ; i <= m ; i++)
			for (int j = v ; j <= n ; j++){
				if (i == cur.first && j == cur.second)
					continue;
				if (f[i][j-1] < f[i-1][j]){
					f[i][j] = f[i-1][j] + a[i][j];
				}
				else{
					f[i][j] = f[i][j-1] + a[i][j];
				}
				
				if (i==p && j==q)
					break;
			}
//		for (int i = u ; i <= m ; i++){
//			for (int j = v ; j <= n ; j++){
//				cerr<<f[i][j]<<" ";
//			}
//			cerr<<endl;
//		}
		Res = min(Res,f[p][q]);
//		cerr<<"   "<<Res<<endl;
	}
	printf("%d\n",Res);
}

void compute(){
	int u,v,p,q;
	for (int i = 0 ; i < k ; i++){
		scanf("%d%d%d%d",&u,&v,&p,&q);
		findRes(u,v,p,q);
	}
}

void output(){
	
}

main(){
	init();
	input();
	compute();
}
