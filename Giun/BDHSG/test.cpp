#include <iostream>
#include <string>
using namespace std;

int main() 
{
	//int T,i,lo,index_A = 0,index_B = 0,len_A,len_B;
	//string A,B,small;
	//char final[200010];
	int T,i;
	cin>>T;
	for(i=0;i<T;i++)
	{
		int T,i,lo,index_A = 0,index_B = 0,len_A,len_B,n;
		string A,B,small;
		char final[200010];
		cin>>A>>B;
		len_A = A.length();
		len_B = B.length();
		A.push_back('a');
		B.push_back('b');
		//lo = len_A < len_B ? len_A : len_B;
		//small = len_A < len_B ? A : B;
		for(i = 0 ; i < len_A + len_B ; i++)
		{
			if((int)A[index_A] < (int)B[index_B])
			{
				final[i] = A[index_A];
				index_A ++;
			}
			else if((int)A[index_A] > (int)B[index_B])
			{
				final[i] = B[index_B];
				index_B ++;
			}
			else
			{
				n = 0;
				while((int)A[index_A] == (int)B[index_B])
				{
					index_A ++;
					index_B ++;
					n++;
				}
				if((int)A[index_A] < (int)B[index_B])
				{
					index_A -= n;
					index_B -= n;
					final[i] = A[index_A];
					index_A ++;
				}
				else if((int)A[index_A] > (int)B[index_B])
				{
					index_A -= n;
					index_B -= n;
					final[i] = B[index_B];
					index_B ++;
				}
                cerr << index_A << ' ' << index_B << '\n';
			}
		}
		for(i = 0 ; i < len_A + len_B ; i++)
		{
			cout<<final[i];
		}
		cout<<endl;
	}
	return 0;
}