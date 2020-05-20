#include <bits/stdc++.h>
#define ii int
#define ll long long
#define cii const int
#define cll const long long
#define opt ios_base::sync_with_stdio(0); cin.tie(0)
#define lp(a, b, c) for(ll a = b; a <= c; a++)
#define lpd(a, b, c) for(ll a = b; a >= c; a--)
#define lpdk(a, b, c, d) for(ll a = b; c; d) 
#define pp(a, b) pair<a, b>
#define vec(a) vector<a>
#define vecite(a) vector<a>::iterator
#define MOD 1e9 + 7
#define fi first
#define se second
using namespace std;
const string tenfile = "f";
#define file freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

string cvt(char **a, int i){
    string s(a[i]);
    return s;
}

int main(int argc, char **argv){
    opt;
    //file;
    if (argc == 2 && cvt(argv, 1) == "--help"){
        cerr << "-h <name> to push file with name origin\n";
        cerr << "-l <name> to pull file with name origin\n";
        cerr << "-m \"<message>\" to commit file with message ex: gt -m \"sync\" \nIf -m is not found, \"sync\" will default message\n**-m must go with -h";
        return 0;
    }
    else{
        if(cvt(argv, 1) == "-l" && argc == 3) {
            string name = argv[2];
            system(("git pull origin " + name).c_str());
            return 0;
        }
        else{
            int cnt = 0;
            string msg = "sync", name;
            lp(i, 1, argc - 1) if(cvt(argv, i) == "-l" || cvt(argv, i) == "-h") ++cnt;
            if(cnt == 1){
                lp(i, 1, argc - 1) {
                    if(cvt(argv, i) == "-h") name = argv[++i], --cnt;
                    else if(cvt(argv, i) == "-m") {
                        msg = "";
                        if (i == argc - 1) {++cnt; break;}
                        for (int j = i + 1; cvt(argv, j) != "-h" && j < argc; j++) msg += " " + cvt(argv, j);
                    }
                }
                if(!cnt) {
                    system("git add .");
                    system(("git commit -m \"" + msg +"\"").c_str());
                    system(("git push -u origin " + name).c_str());
                    return 0;
                }
            }
        }
        cerr << "Syntax Error!";
    }
}
