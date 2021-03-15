#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
int n , ans =INT_MAX;
char x[(int) 1e5+7];

// inline bool check(int mid )
// {
//     int  lt = 0;
//     int kq1, kq2,kq;
//     for (int i = 1 ; i <= n ; i++)
//     {
//         if (x[i] == '*' && i > kq && lt == 0 ) lt = i;
//         else 
//             if (x[i] == 'P')
//         {
//         //    cerr << i << " " << lt << endl;
//             int tam = i-lt;
//             if (tam < 0) tam = 0;
//             if (tam> mid) return 0;
//             kq1 = mid - 2*tam + i;
//             kq2 = (mid -tam)/2 + i;
//             kq = max(kq1,kq2);
//             lt = 0;
//       //      cerr << tam << " " << kq1 << " " << kq2 << " " << kq << endl;
//         }
//     }
//     //cerr << lt << endl;
//     if (lt == 0) return true;
//     else return false;
// }
bool check(int t) {
	int lt=0, rt=0;
	for (int i=1; i<=n; i++)
	if (x[i]=='*' && lt==0 && i>rt) lt=i;
	else
	if (x[i]=='P') {
		int tmp;
        if (lt > 0) tmp = i-lt;
        else tmp = 0 ;
         //lt>0?i-lt:0;
		//cerr<<"lt= "<<lt<<" "<< "i= "<<i<<endl;
		if (tmp>t) return 0;
		rt=max((t-tmp)/2,t-2*tmp)+i;
		lt=0;
	}
	if (lt) return 0;
	return 1;
}
void cnp ()
{
    int l = 1 , r = 2*n; 
    while ( l < r)
    {
        int mid = (l+r)/2;
        cerr << l << " " << r << " " << mid << endl;
        
        if(check(mid) == true) r = mid ;
        else l = mid + 1 , ans = l;
        cerr << endl;
    }

}

int main()
{
    giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
    cin >> n ;
    for (int i = 1 ; i <= n ; i++) cin >> x[i];
    cnp();
    cout << ans;
}
