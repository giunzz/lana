#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'mostBalancedPartition' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY parent
 *  2. INTEGER_ARRAY files_size
 */
//  #define int long long
 const int maxn = 1e5+7;
 long long dd[maxn]={0} , Fd[maxn] ={0} , Fu[maxn]={0}, ans = 1e18;
 vector<int>G[(int) 1e5+7], fsize;
void DFS (int u)
{
    Fd[u] = fsize[u];
    for (int v : G[u]) 
    {
        if (!dd[v]) DFS(v), Fd[u] += Fd[v];
    }
}
void DFS2 (int u)
{
    if(u == 0){
        for(int v : G[u]){
            ans = min(ans, abs(Fd[v] - (Fd[u] - Fd[v])));
            Fu[v] = Fd[u] - Fd[v] + fsize[v];
            DFS2(v);
        }       
    }
    else{
        for(int v : G[u]){
            ans = min(ans,abs(Fd[v]-(Fu[u] + Fd[u] - Fd[v] - fsize[u])));
            Fu[v] = Fu[u] + Fd[u] - Fd[v] - fsize[u] + fsize[v];
            DFS2(v);
        }
    }
}
int mostBalancedPartition(vector<int> parent, vector<int> files_size) {
    for (int i = 1 ; i < (int)parent.size() ; i++)
    {
        G[parent[i]].push_back(i);
    }
    fsize  =files_size;
    DFS(0);
    memset(dd, 0, sizeof dd);
    DFS2(0);
    return ans;
}

signed main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string parent_count_temp;
    getline(cin, parent_count_temp);

    int parent_count = stoi(ltrim(rtrim(parent_count_temp)));

    vector<int> parent(parent_count);

    for (int i = 0; i < parent_count; i++) {
        string parent_item_temp;
        getline(cin, parent_item_temp);

        int parent_item = stoi(ltrim(rtrim(parent_item_temp)));

        parent[i] = parent_item;
    }

    string files_size_count_temp;
    getline(cin, files_size_count_temp);

    int files_size_count = stoi(ltrim(rtrim(files_size_count_temp)));

    vector<int> files_size(files_size_count);

    for (int i = 0; i < files_size_count; i++) {
        string files_size_item_temp;
        getline(cin, files_size_item_temp);

        int files_size_item = stoi(ltrim(rtrim(files_size_item_temp)));

        files_size[i] = files_size_item;
    }

    int result = mostBalancedPartition(parent, files_size);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
