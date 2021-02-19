#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int f[52][52][52][52];

void add(int &a, int b){
	(a += b) %= mod;
}

class VocaloidsAndSongs
{
	public:
	int count(int S, int gumi, int ia, int mayu)
	{
		f[0][0][0][0] = 1;
		for (uint i = 1 ; i  <= S ; i++ )
            for (int a = 0 ; a <= gumi ; a++ )
				for (int b = 0 ; b <= ia ; b++ )
					for (int c = 0 ; c <= mayu ; c++ )
					{
						int &tmp = f[i][a][b][c]; 
						tmp = 0;
						if (a > 0)
						{
							add(tmp, f[i - 1][a - 1][b][c]);
							if(b > 0)
							{
								add(tmp, f[i - 1][a - 1][b-1][c]);
								if(c > 0) add(tmp,f[i-1][a-1][b-1][c-1]);
							}
							if (c > 0) add(tmp,f[i-1][a-1][b][c-1]);
						}
						if (b > 0 )
						{
							add(tmp,f[i-1][a][b-1][c]);
							if (c > 0 ) add(tmp,f[i-1][a][b-1][c-1]);	
						}
						if (c > 0 ) add(tmp,f[i-1][a][b][c-1]);
					}
		return f[S][gumi][ia][mayu];
    }
};
int main(){
	VocaloidsAndSongs giuncute;
    freopen("giun.inp","r",stdin);
    freopen("giun.out","w",stdout);
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << giuncute.count(a, b,c , d);
}