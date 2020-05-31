#include <bits/stdc++.h>
#include <sstream>
#include <dir.h>
//#include <experimental/filesystem>
#define task "/onadp"
using namespace std;
int n;
int main()
{
	srand(time(0));
	string s;
	for(int t=0;t<10;t++)
	{
		stringstream ss;
		ss<<t;
		s=ss.str();
		if(t<10) s='0'+s;

		s="onadp/test"+s;
		mkdir(s.c_str());
		string si=s+task".inp";

		ofstream fi(si.c_str());

		//print input/output below
		n=t+1;
		fi<<n<<endl;
		for(int i=2;i<=(1<<(n+1))-1;i++)
            fi<<rand()%(t+10)+1<<" ";
        fi.close();
	}
}
