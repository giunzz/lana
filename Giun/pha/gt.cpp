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

map<string, ii> mp;
ii tt = 0;

string cvt(char **a, int i){
    string s(a[i]);
    return s;
}

int fd(char **a, string b, int argc){
    lp(i, 1, argc - 1) if (cvt(a, i) == b) return i;
    return 0;
}

void errorErr(){
    cerr << "Syntax Error!";
}

int main(int argc, char **argv){
    opt;
    //file;
    lp(i, 1, argc - 1) if(cvt(argv, i) == "-h" || cvt(argv, i) == "-m" || cvt(argv, i) == "-l" || cvt(argv, i) == "--help") ++mp[cvt(argv, i)], ++tt;
    if (tt == 1 && cvt(argv, 1) == "--help"){
        cerr << "**Add all file is default and auto in this tool\n";
        cerr << "-h <name> to push file with name origin\n";
        cerr << "-l <name> to pull file with name origin\n";
        cerr << "-m \"<message>\" to commit file with message ex: gt -m \"sync\" \nIf -m is not found, \"sync\" will default message";
        return 0;
    }
    if((mp["-l"] && tt > 1) || (mp["--help"] && tt > 1) || tt > 2) {errorErr(); return 0;}
    if(mp["-l"]) {
        if(fd(argv, "-l", argc) == (argc - 1)) {errorErr(); return 0;}
        system(("git pull origin " + cvt(argv, fd(argv, "-l", argc) + 1)).c_str()); 
        return 0;
    }
    string msg = "sync", name;
    if(mp["-m"]) {
        if(fd(argv, "-m", argc) == (argc - 1) || cvt(argv, fd(argv, "-m", argc) + 1) == "-h") {errorErr(); return 0;}
        msg = "";
        for (int j = fd(argv, "-m", argc) + 1; j < argc && cvt(argv, j) != "-h"; j++) msg += cvt(argv, j) + " ";
    }
    if(mp["-h"]){
        if(fd(argv, "-h", argc) == (argc - 1) || cvt(argv, fd(argv, "-h", argc) + 1) == "-m") {errorErr(); return 0;}
        name = cvt(argv, fd(argv, "-h", argc) + 1);
    }
    system("git add .");
    system(("git commit -m \"" + msg +"\"").c_str());
    if(mp["-h"]) 
        system(("git push -u origin " + name).c_str());
}
