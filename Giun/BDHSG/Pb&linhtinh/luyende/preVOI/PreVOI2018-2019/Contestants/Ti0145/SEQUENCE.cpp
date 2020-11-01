#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define PB push_back
#define FOR(i, u, v) for (int i = u; i <= v; i++)
#define FORD(i, v, u) for (int i = v; i >= u; i--)
#define N 3005
#define maxc 1000000007
#define BASE 97


using namespace std;

int n, m, k, a[N], b[N], rr[N*2], cur, numSeq, seqA[N], seqB[N];
int nxt[2][N][2*N], dp[N][N];
long long H[2][N], B[N];
vector<int> Seq[N];

void setup()
{
    cin >> n >> m >> k;
    FOR(i, 1, n) cin >> a[i], rr[++cur] = a[i];
    FOR(i, 1, m) cin >> b[i], rr[++cur] = b[i];
    sort(rr+1, rr+cur+1);
    cur = unique(rr+1, rr+cur+1) - rr - 1;
    FOR(i, 1, n)
        a[i] = lower_bound(rr+1, rr+cur+1, a[i]) - rr;
    FOR(i, 1, m)
        b[i] = lower_bound(rr+1, rr+cur+1, b[i]) - rr;
}
void prepare()
{
    FOR(i, 1, cur) nxt[0][n+1][i] = n+1, nxt[1][m+1][i] = m+1;
    FORD(i, n, 1)
    {
        FOR(j, 1, cur) nxt[0][i][j] = nxt[0][i+1][j];
        nxt[0][i][a[i]] = i;
    }
    FORD(i, m, 1)
    {
        FOR(j, 1, cur) nxt[1][i][j] = nxt[1][i+1][j];
        nxt[1][i][b[i]] = i;
    }
}
void preCalc(int lenA, int lenB)
{
    FOR(i, 1, lenA)
        H[0][i] = H[0][i-1]*BASE + seqA[i];
    FOR(i, 1, lenB)
        H[1][i] = H[1][i-1]*BASE + seqB[i];
    B[0] = 1;
    FOR(i, 1, N-1) B[i] = B[i-1]*BASE;
}
int getHash(int id, int L, int R)
{
    return H[id][R] - H[id][L-1]*B[R - L + 1];
}
int get(int lenA, int lenB, int posA, int posB)
{
    int l = 1, r = min(lenA - posA, lenB - posB) + 2;
    while (r - l > 1)
    {
        int mid = (r + l)/2;
        if (getHash(0, posA, posA + mid - 1) == getHash(1, posB, posB + mid - 1))
            l = mid;
        else r = mid;
    }
    return l;
}
void Merge(int lenA, int lenB)
{
    numSeq++;
    Seq[numSeq].resize(k);
    preCalc(lenA, lenB);
    int pos = 0, posA = 1, posB = 1;
    while (posA <= lenA && posB <= lenB)
    {
        if (seqA[posA] < seqB[posB])
            Seq[numSeq][pos++] = seqA[posA++];
        else if (seqA[posA] > seqB[posB])
            Seq[numSeq][pos++] = seqB[posB++];
        else
        {
            int len = get(lenA, lenB, posA, posB);
            if (seqA[posA + len] < seqB[posB + len])
                 Seq[numSeq][pos++] = seqA[posA++];
            else Seq[numSeq][pos++] = seqB[posB++];
        }
    }
    while (posA <= lenA)
        Seq[numSeq][pos++] = seqA[posA++];
    while (posB <= lenB)
        Seq[numSeq][pos++] = seqB[posB++];
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    setup();
    prepare();

    FOR(lenA, 1, min(n, k))
    {
        int lenB = k - lenA;
        if (lenB > m) continue;
        int posA = 1, posB = 1;
        FOR(i, 1, lenA)
        {
            FOR(j, 1, cur)
                if (n - nxt[0][posA][j] >= lenA - i)
                {
                    seqA[i] = j;
                    posA = nxt[0][posA][j]+1;
                    break;
                }
        }
        FOR(i, 1, lenB)
        {
            FOR(j, 1, cur)
                if (m - nxt[1][posB][j] >= lenB - i)
                {
                    seqB[i] = j;
                    posB = nxt[1][posB][j]+1;
                    break;
                }
        }
        seqA[lenA+1] = 0, seqB[lenB+1] = 0;
        Merge(lenA, lenB);
    }
    sort(Seq+1, Seq+numSeq+1);
    FOR(i, 0, k-1) cout <<rr[Seq[1][i]]<<' ';
}
