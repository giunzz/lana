#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[102],b[102];

void init(){
	freopen("sequence.inp","r",stdin);
	freopen("sequence.out","w",stdout);
}

void input(){
	scanf("%d%d%d",&m,&n,&k);
	for (int i = 1 ; i <= m ; i++)
		scanf("%d",&a[i]);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d",&b[i]);
}

void compute(){
	int l1,l2;
	int Seq[202];
	for (int i = 1 ; i <= k ; i++)
		Seq[i] = INT_MAX;
	
	for (l1 = 0 ; l1 <= m ; l1++){
		cerr<<l1<<": "<<endl;
		l2 = k-l1;
//		cerr<<l2<<endl;
		if (l2 > n || l2 < 0) continue;
		vector<int> seqa,seqb;
		
		int p1 = 1,lastp1 = m-l1+1;
		while (p1 <= lastp1){
			int mina = INT_MAX;
			int afp1 = m+1;
			for (int i = p1 ; i <= lastp1 ; i++){
				if (mina > a[i]){
					mina = a[i];
					afp1 = i;
				}
			}
			lastp1++;
			if (lastp1 > m) lastp1 = m;
			p1 = afp1+1;
			seqa.push_back(mina);
		}
		
		int p2 = 1,lastp2 = n-l2+1;
		while (p2 <= lastp2){
			int minb = INT_MAX;
			int afp2 = n+1;
			for (int i = p2 ; i <= lastp2 ; i++){
				if (minb > b[i]){
					minb = b[i];
					afp2 = i;
				}
			}
			lastp2++;
			if (lastp2 > n) lastp2 = n;
			p2 = afp2+1;
			seqb.push_back(minb);
		}
		int curSeq[202];
		int p = 1;
		bool replace = 1;
		p1 = 0;
		p2 = 0;
		while (true){
			if (p1 == l1 && p2 == l2)
				break;
			if (p1 == l1){
				curSeq[p] = seqb[p2];
				p2++;
				p++;
			}
			if (p2 == l2){
				curSeq[p] = seqa[p1];
				p1++;
				p++;
			}
			if (seqa[p1] < seqb[p2]){
				curSeq[p] = seqa[p1];
				p1++;
				p++;
			}
			else{
				curSeq[p] = seqb[p2];
				p2++;
				p++;
			}
			if (curSeq[p] > Seq[p]){
				replace = 0;
				break;
			}
		}
//		for (int i = 0 ; i < seqa.size() ; i++)
//			cerr<<seqa[i]<<" ";
//		cerr<<endl;
//		
//		for (int i = 0 ; i < seqb.size() ; i++)
//			cerr<<seqb[i]<<" ";
//		cerr<<endl;
		if (replace){
			for (int i = 1 ; i <= k ; i++)
				Seq[i] = curSeq[i];
		}
	}
	
	for (int i = 1 ; i<=k; i++)
		printf("%d ",Seq[i]);
}

void output(){
	
}

main(){
	init();
	input();
	compute();
}
