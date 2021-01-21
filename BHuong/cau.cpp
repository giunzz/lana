#include <iostream>

#include <fstream>
#define maxN 51
#define maxM 2501
#define min(a,b) (a<b)?a:b
using namespace std;
ifstream fi (“cau_khop.inp”);
ofstream fo (“cau_khop.out”);
int N, M, time_;
int parent[maxN], Number[maxN], Low[maxN], nChildren[maxN];
bool A[maxN][maxN];
void read_input(){
int u, v;
fi >> N >> M;
for (int i=1; i<=N; i++)
for (int j=1; j<=N; j++) A[i][j]=false;
for (int i=1; i<=M; i++) {
fi >> u >> v;
A[u][v] = true; A[v][u]=true;
}
}
void DFS(int u) {
int v;
time_++;
Number[u]=time_; //Đánh số u theo thứ tự duyệt đến
Low[u]=maxN+1;
for (int v=1; v<=N; v++)
if (A[u][v]) { //Đỉnh v kề với đỉnh u
A[v][u]=false; //Định chiều cạnh (u;v) thành cung (u;v)
if (parent[v]==0) {//Nếu đỉnh v chưa thăm
parent[v]=u; // Xác nhận Cung (u,v) là một cung trên cây DFS
DFS(v); //Thăm tiếp từ v

//Sau khi thăm xong v thì cực tiểu hóa Low[u] theo Low[v]
Low[u] = min(Low[u], Low[v]);
} else //Cực tiểu hóa Low[u] theo Number[v]

{ Low[u]=min(Low[u], Number[v]);}
}
}
void process() {
int u, v;
bool IsArticulation[maxN];
for (int u=1; u<=N; u++)
if (parent[u]==0) {
parent[u]=-1;
DFS(u);
}