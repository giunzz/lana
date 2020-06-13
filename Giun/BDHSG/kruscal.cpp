#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#define pa "test6\\"
using namespace std;

const int maxm = 100005;
struct edge{
	int u,v,val;
};
edge E[maxm];
bool C[maxm]={false}, D[maxm]={false};
int m,n,t=0;

int compare (const void * a, const void * b)
{
    edge * A = (edge *)a;
    edge * B = (edge *)b;
    return ( A->val - B->val);
}

int find_edge(){
    for (int i=1;i<m;i++) {
        if (!(C[E[i].u] && C[E[i].v])  && (C[E[i].u] || C[E[i].v])){
            return i;
        }
    }
    return -1;
}
void kruskal(){
    qsort(E,m,sizeof(edge),compare);
    C[E[0].u]=true;
    C[E[0].v]=true;
    D[0]=true;
    t=E[0].val;
    int e_num = 1;
    while (e_num < n-1){
        int k = find_edge();
        D[k]=true;
        C[E[k].u]=true;
        C[E[k].v]=true;
        t=t+ E[k].val;
        e_num+=1;
    }
}

int main(){
    freopen(pa"kruskal.inp","r",stdin);
    freopen(pa"kruskal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].val);
    }
    kruskal();
    printf("%d\n",t);
    for (int i=0;i<m;i++){
        if (D[i]) printf("%d %d\n",E[i].u,E[i].v);
    }
    return 0;
}
