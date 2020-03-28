#include<iostream>
#include<string>
#define giuncute freopen("MATRIX.INP", "r", stdin) , freopen("MATRIX.OUT", "w", stdout)

/* N=6
1   2   6   7   15  16
3   5   8   14  17  26
4   9   13  18  25  27
10  12  19  24  28  33
11  20  23  29  32  34
21  22  30  31  35  36

+Ta có quy luật ma trận như sau: 
Số ở tam giác dưới = (n * n+1) - Số đối xứng tương ứng qua đường chéo chính của tam giác trên. 
vd: Hàng 1, cột 1 => 1 tương ứng có : (6 * 6+1) -1 =36 ở hàng 6, cột 6
Hướng làm: theo bước nhảy của con thỏ, nếu bước nhảy ở ô số thuộc tam giác trên ta tính bình thường, 
còn nếu con thỏ nảy vào ô số thuộc tam giác dưới thì ta phải đi tìm ô số đối xứng tường ứng thuộc tam giác trên. 
sau đó áp dụng quy luật nêu trên.
*/

using namespace std;
int n,k;
int xx( int h, int c)
{
	int cheo=h+c-1;	cerr<<"\nh="<<h<<" c="<<c;
	int s=0;
	for(int i=1; i<cheo;i++)s+=i;
	if(cheo%2==0)s+=h;
	else s+=c;
	return s;
}
int f(int h, int c)
{
	int cheo=h+c-1;
	int t=0;
	if(cheo<=n)// nho hon duong cheo chinh=> tam giac tren
	{
		t=xx(h,c);
	}
	else//lon hon duong cheo chinh => tam giac duoi
	{
		int chenhlech=cheo-n;// o giua 2 duong nay co bn duong cheo khac
		cheo=n-chenhlech;
		
		if(h==n ||c==n)
		{
			if(h==n)
			{ 
				h=1;c=n-chenhlech;	
			}
			if (c==n)
			{
				c=1;h=n-chenhlech;	
			}
		}
		else{
				c=h-chenhlech;h=cheo-c+1;
			}
		t=(n*n+1)-xx(h,c);
	}
	return t;	
}
int main()
{
    giuncute;
    ios::sync_with_stdio(0);
	cin.tie(0);

	int h=1,c=1;
	string ch;
	cin>>n>>k>>ch;
	long long t=0,sum=1;
	for(int i=0; i<k;i++)
	{
		if(ch[i]=='D'||ch[i]=='d')	t=f(++h,c);
		else if(ch[i]=='R'||ch[i]=='r')t=f(h,++c);
		else if(ch[i]=='L'||ch[i]=='l')	t=f(h,--c);
		else if(ch[i]=='U'||ch[i]=='u')	t=f(--h,c);
	//	cout<<"\nt="<<t;
	//	cout<<endl;
		sum+=t;
		t=0;		
	}	
	cout<<sum;
}
//ok 60 diem => van de o tam giac duoi thui