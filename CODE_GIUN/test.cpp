#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int N, x;
    while (scanf("%d", &N) && N) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        for (int i = 0; i < N; ++i) {
            scanf("%d", &x);
            PQ.push(x);
        }
        int cost = 0;
        while (PQ.size() != 1) {
            x = PQ.top(); PQ.pop();
            x += PQ.top(); PQ.pop();
            cost += x;
            PQ.push(x);
        }
        printf("%d\n", cost);
    }
    return 0;
}