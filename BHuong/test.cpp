#include <bits/stdc++.h>

using namespace std;

struct point 
{
	long x, y, id;
} a[2000];
long n;
vector <point> b, bb;

bool sortin1(const point a, const point b)
{
    return a.y < b.y;
}

bool angle__(const point a, const point b)
{
    return a.y * b.x < a.x * b.y;
}

double dis(long i, long j)
{
	return sqrt((a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));
}

long Sdagiac(vector <point> b)
{
    long Sn = 0;
    b.push_back(b[0]);
    for(long i = 0; i < b.size() - 1; i++)
    {
        Sn += (b[i + 1].x - b[i].x)*(b[i + 1].y + b[i].y);
    }
    return abs(Sn);
}

int main()
{
	freopen("giun.inp","r",stdin);
	freopen("giun.out","w",stdout);
	cin >> n;
	for(long i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, sortin1);
    for(long i = 1; i <= n; i++)
    {
        if(a[i].y == a[1].y && a[1].x < a[i].x)
        {
            swap(a[i], a[1]);
        }
        if(a[i].y != a[1].y) break;
    }
    for(long i = 2; i <= n; i++)
    {
        a[i].x -= a[1].x;
        a[i].y -= a[1].y;
    }
    a[1].x = 0;
    a[1].y = 0;
	long pos1, pos2;
	double maxx = 0.0;
	sort(a + 1, a + n + 1, angle__);
	for(long i = 1; i <= n; i++)
	{
		for(long j = 1; j <= n; j++)
		{
			//cout << maxx << ' ' << dis(i, j) << endl;
			if(maxx < dis(i, j))
			{
				maxx = dis(i, j);
				pos1 = i;
				pos2 = j;
			}
		}
	}
	b.push_back(a[pos1]);
	b.push_back(a[pos2]);
	long Smax = 0;
	for(long i = 1; i <= n; i++)
	{
		if(i != pos1 && i != pos2) 
		{
			b.push_back(a[i]);
			for(long j = i + 1; j <= n; j++)
			{	
				if (j != pos1 && j != pos2) 
				{
					b.push_back(a[j]);
					bb = b;
					sort(bb.begin(), bb.end(), angle__);
					Smax = max(Smax, Sdagiac(bb));
	//				for(long k = 0; k < b.size(); k++) cout << bb[k].id <<' ';
					b.erase(b.begin() + b.size() - 1);
	//				cout << endl;
				}
			}
			b.erase(b.begin() + b.size() - 1);
		}
	}
	//cout << Smax / 2;
	cerr << (Smax/2) << "." << (Smax%2) * 5; 
	//if(Smax % 2 == 0) cout << ".0";
	//else cout << ".5";
	return 0;
}