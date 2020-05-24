#include<bits/stdc++.h>
using namespace std;
const string tenfile = "BAI29";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0);

int X[maxn], n; 
bool C[maxn]={false}, CC[maxn]={false},CP[maxn]={false};
bool VoNghiem=true;
int doi(int a){
	return a+n;
}

bool DieuKien(int i, int j)
{
	return (!C[j] && !CC[doi(i-j)] && !CP[i+j]);
}

void Ghinghiem()
{
	for (int i=1;i<=n;i++) cout << X[i] << " ";
	cout << endl;
	VoNghiem = false;
}

void Try(int i){
	for (int j=1;j<=n;j++){
		if (DieuKien(i,j)) {
			X[i]=j;
			C[j]=true;
			CC[doi(i-j)]=true;
			CP[i+j]=true;
			if (i==n) Ghinghiem();
			else Try(i+1);
			C[j]=false;
			CC[doi(i-j)]=false;
			CP[i+j]=false;
		}
	}
}
int main(){
	cin >> n;
	Try(1);
	if (VoNghiem) cout << -1;
	return 0;
}
