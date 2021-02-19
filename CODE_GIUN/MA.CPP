#include <iostream>
using namespace std;
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);
int DX[9] = {0,-2,-1,1,2, 2, 1,-1,-2};
int DY[9] = {0, 1, 2,2,1,-1,-2,-2,-1};
int B[10][10] = {{0}};
int x, y, n;
bool conghiem = false;

void GhiNghiem()
{
	for (int i = 1 ;i <= n ;i++)
	{
		for (int j = 1 ; j <= n; j++) cout << B[i][j] << " ";
		cout << endl;
	}
	conghiem = true;
}
bool DenDuoc(int d, int c)
{
	if (d<1 || d>n || c<1 || c>n) return false;
	if (B[d][c] != 0) return false;
	return true;
}
void Ttry(int i)
{
	if (conghiem) return;
	for (int j=1;j<=8;j++)
	{
		if (DenDuoc(x + DX[j], y + DY[j] ))
		{
			x += DX[j];
			y += DY[j];
			B[x][y] = i;
			if (i==n*n) GhiNghiem();
			else Ttry(i+1);
			B[x][y]=0;
			x-=DX[j];
			y-=DY[j];
		}
	}
}
int main()
{
	giuncute;
	balabalo;
	cin >> n >> x >> y;
	B[x][y] = 1;
	Ttry(2);
	if (!conghiem) cout << "Vo nghiem";
}