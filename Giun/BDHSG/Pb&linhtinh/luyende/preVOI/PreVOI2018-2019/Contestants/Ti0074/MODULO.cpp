#include <bits/stdc++.h>

using namespace std;

void upfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MODULO.INP","r",stdin);
    freopen("MODULO.OUT","w",stdout);
}

int n, a, b, k;

long long d, sum = 0, dl;

struct neko
{
    long long val;
    deque <int> trace;
};

vector <neko> v[3];

deque <int> s;

unsigned long long Mul(unsigned long long x, unsigned long long y)
{
    x %= d;
    y %= d;
    unsigned long long q = (long double) x * y / d;
    long long r = (long long) (x * y - q * d) % (long long)d;
    if (r < 0) r += d;
    return r;
}

void quaylui(int u, int r)
{
    if (u == 0)
    {
        if (r == 1)
            sum = Mul(sum, dl);
        v[r].push_back({sum, s});
        return;
    }

    long long t = sum;

    sum = (t * 10 + a) % d;
    s.push_back(a);
    quaylui(u-1, r);
    s.pop_back();

    sum = (t * 10 + b) % d;
    s.push_back(b);
    quaylui(u-1, r);
    s.pop_back();

    sum = t;
}

int BS(long long u)
{
    int low = 0;
    int hig = v[1].size() - 1;
    int mid;
    while (low <= hig)
    {
        mid = (low + hig) / 2;
        if (v[1][mid].val < u)
            low = mid + 1;
        else
            hig = mid - 1;
    }
    if (v[1][low].val != u)
        low = n+1;
    return low;
}

int main()
{
    upfile();
    cin >> a >> b >> n >> k;
    d = 1;
    for (int i=1; i<=n; ++i)
        d *= 2;
    dl = 1;
    for (int i=1; i<=n - n/2; ++i)
        dl = (dl * 10) % d;
    quaylui(n/2, 1);
    quaylui(n - n/2, 2);
    sort(v[1].begin(), v[1].end(), [](neko a, neko b)
         {
             return a.val < b.val;
         });
    for (neko i: v[2])
    {
        int k = BS((k + d - i.val) % d);
        if (k < v[1].size())
        {
            for (int j: v[1][k].trace)
                s.push_front(j);
            for (int j: i.trace)
                s.push_front(j);
            for (int j: s)
                cout << j;
            exit(0);
        }
    }
    cout << -1;
}

/*********************************************************************************************************************************************************************************************************
 * ti;.                               .:,:i:         :,;;itt;.        fDDEDDEEEEEEKEEEEEKEEEEEEEEEEEEEEEEE###WKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWW#WWWWWKKKKKEE      :,:.    f::::. .,ijLGDDDDDDDEEEEEEE*
 *ti;.                               .:,:i:          .:,;itt;:      GLDEEGEEEEEEEEEEEEEEEEEEDEEEEEEEEEEE#W#WEKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWKKKKKKG.     .::.      f:,...,ijLGDDDDDDDDEEEEEE *
 *ti;.                               .:,:i:            :,;;iti,    :fDDEEEEEEEEEEEEEEEKEEEEDEEEEEEEEEEEW##WEEEKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWWKKKKKKEG     .::.       .f,::,ijLGDDDDDDDDEEEEEE *
 *ti;.                               .:,:i:             .,,;iti;.  LDDEEEEEEEEEEKEEEEWEEEDDEEEEEEEEEEE#WWWEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWWWWWKKKKKEDj    .::.        .:L;;ijfGDDDDDDDDDEEEEE *
 *ti;.                               .:,:i:              .:,;;iii:LLDEEEEEEEEEEEKEEEEEEEEDEEEEEEEEEEEW#WWEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKWWKWWWWWWWWWWWWWWKKKKKKKEL    .::.         .:;LijLGGDDDDDDDDEEEEE *
 *ti;.                               .:,:;:                :,;;ittfDEEEEEEEEEEEEEEEEKEEEGEEEEEEEEEEEKWWWEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWWWWKKKKKKKELj   .::.          :,;jffGGDDDDDDDDDEEEE *
 *ti;.                               .:,:i:                 .,;;tGGDEEEEEEEEEEEKEEEKEEEDEEEEEEEEEEEEWWWEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWKWWWWWWKKKKKKKEEL   .::.          .:;itDGGDDDDDDDDDEEEE *
 *ti;.                               .:::;:                   :;ifDEEEEEEEEEEEEKEEEKEEEEEEEEEEEEEEEWWWEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WWWKKKKKKKKEEf   .::.           :,itfGEDDDDDDDDDDDEE *
 *ti;.                               .:::;:                    :GGEEEEEEEEEEEKEKEEKEEEEEEEEEEEEEEEEWWEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKKKKEEDG  .::.           .,;jfLGKDLDDDDDDEEDD *
 *ti;.                               .:::;:                     fDEEEEEEKKKKKKKKKEKEEEEEEEEEEEEEEE#WEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#KKKKKKKKKKEEf .:::.           .,;tfLGDEDDDDDDDDEEE *
 *ti;.                                :::;:                    fDEEEEEEKKKKKKKKKKWKEEEEEEEEEEEEEEEWKEEEEEEEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKW##KKKKKKKKKEEft :::.           .,;tfLGDDDKDDDDDDDDD *
 *ti;.                                .::;:                    fDEEEEEEKKKKKKKWKKKKKEEEEEEEEEEEEE#WEEWEEEEEDEEDEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKKKEEGG :,:.           .,;tfLGGDDDKDDDDDDDD *
 *ti;.                                .:.;:                   tGDEEEEKKKKKKKKKKKKKKKKKEEEEEEEEEEEWEEKWEEEEEEEDEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKWWWKKKKKKKEEDf :::.           .,;tfLGGDDDDEDDDDDDD *
 *ti;.                                .::;:                   fDEEEEEKKKKKKKKKKKWKKKKKKKKEEEEEEEWWEEWEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKW##KKKKKKKEEEft.::.           .,;tfLGGDDDDDDEDDDDD *
 *ti;.                                .:.;:                  tGDEEEKKKKKKKKKKKKKKKKKKKKKKEKEEEEE#EEWWEEEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKW#WKKKKKKEEEGD:::.           .,;tfLGGDDDDDDDEDDDD *
 *ti;.                                .:.,.                  LDEEEEKKKKKKKKKKWKWKKKKKKKKKKKKEEEKWEKW#EEEEEEEEEEEEEEEEKEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKW##KKKKKKEEEEf,,:.           .,;tfLGGDDDDDDDDEDDD *
 *ti;.                               ..:.,.                 LGDEEEEKKKKKKKKKKWKKKKKKKKKKKKKKKKKWEEW#WEEEEEEEEEEEEEEEKEEEEEEEEEEEEEEEEEEEKEKKKKKKKKKKKKKKKK##KKKKKEEEEEfi;,.           .,;tfLGGDDDDDDDDDKDD *
 *tt;.                                .:.,:                 jDEEEEKKKKKKKKKKWWKKKKKKKKKKKKKKKKKWKE#WWEEEEEEEEEEEEEEWEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKKKKKKWWKKKKEEEEDfG;,:           .,;tfLGGDDDDDDDDDDKD *
 *tii,.                               .:.,.                tGDEEEEKKKKKKKKKKWWWKKKKKKKKKKKKKKKWKKWWWKEEEEEEEEEEEEEKEEEEEEEEEEEEEEEEEEEEEEEEEEEEEKKKKKKKKKKKW#KKKKEEEEDGGi;,.          .,;tfLGGDDDDDDDDDDDE *
 *ti;;,:.                             .:.,:                fDEEEEKKKKKKKKKKKWKKKKKKKKKKKKKKKKKWEK#WWKEEEEEEEEEEEEDEEEEEEEEEEEEEEGEEEEEEEEEEEEEEEEEEEKKKKKKKWWKKEEEEEEDDf;;;,.         .,;tfLGGDDDDDDDDDDDD *
 *tii;,,:..                           ...,.               ;LEEEEEKKKKKKWKKKKWKKKKKKKKKKKKKKKKKEKKW#WEEEEEEEEEEEEEjEEEEEEEEEKEEEEGEEEEEEEEEKEEEEEEEEEEEEEEEEE#WKEEEEEEDDf;;;;,:        .,itfLGGDDDDDDDDDDDD *
 *ti;,,,,,:.                          ...,.               LDEEEEKKKKKKKKKKKWWWKKKKKKKKKKKKKKKWKK#W#WEEEEEEEEEEEDDLEEEEEEEEEWEEEEDEEEEEEEEEKEEEEEEEEEEEEEEEEEWWEEEEEEEDDfj,,,,,:.      .,itfGGGDDDDDDDDDDDD *
 *tii,,,,::::.                        ...,:              .fDEEEEKKKKKKWKKKKWWWKKKKKKKKKKKKKKKEKKW#WWEEEEEEEEEEEKiKEEKEEEEEEWEEEEDEEEEEEEEEEEEEEEEEEEEEEEEEEEWWEEEEEEEDDLD:::,,,:.     .,ijfGGGDDDDDDDDDDDD *
 *ti;:::::::::..                      .:.,:              LDEEEEKKKKKKKWKKKKWWKKKKKKKKKKKKKKKKtKKWWWWKEEEEEEEEEDiiDEEEEEEEEWWEEEEEEDEEEEEEEEEEEEEEEEEEEEEEEEEEWKEEEEEDDDGL:. .:,,,:    .,ijLGGGDDDDDDDDDDDD *
 *tt;. .::::::::..                    ...,:             :fDEEEKKKKKKKKKKKKWW#KKKKKKKKKKKKKKKKfKKWWWWKEEEEEEEEDti,DEKEEEEEEWWEEEDEEEEEEEEEKEEEEEEEEEEEEEDEEEEE#WEEEEEGGDGf:.  .:,;,:.  .,ijLGGDDDDDDDDDDDDD *
 *tt;.   .:::::::..                   ...,:             GDEEEKKKKKKKKWKKKKWWWKKKWKKKKKKKWWWKDEKLWWWWKKEEEEEEDEi,LDEEEEEEEEWWEEEEEEEEEEEEEEEEEEEEEEEEEDEDEEEEEW#EEEEDDDDGf,.    :,,,:...,ijLGGGDDDDDDDDDDDD *
 *tt;.    .....::::..                 ...,:             fDEEEKKKKKKKKWKKKKWWWWKKKWKKKKKKKKKKfWKiWWW#KKEEEEEEEi;.EDfEEEDEEiWWEEEEEEEEEEEEDGKEEEEEEEEEEDEEEEEEEWWEEEEDDDGGLi.     .,;,:::,ijLGGGDDDDDDDDDDDD *
 *tt;.      ....:::::.                ...,.            iDEEEEKKKKKKKKWKKWKWWWWWKKWWWKKKKKKKKtWKt#WWWKKEEEEEDji..DDKDDEDEGiWKEEEEEEEEEEDDEjEEEEEEEEEEEDEEEEEEEKWKEEDDDDGGff.      .:,;,,;ijLGGGDDDDDDDDDDDD *
 *tt;.        ....::::..              .:.,:           .LDEEEKKKKKKKKKKKKWWWWKWWWWWWWWWWKKKKWtKKiDWWWKKKEEEEKi:..DEDDDDDDiiWKEEEEEEEEEEDDEijDEEEEEKEEEEEEEEEEEEWWEEGDDDGGLG.       .:,;;iijLGGGDDDDDDDDDDDD *
 *tt;.          .....:::..            ...,.           .fEEEEKKKKKKKKWKKKKWWWWWWWWWWWWWWKWKKKiKDiLWWWWKEEEEEi,..fD:DDDDDti;WEEEEEEEEEEKDDi:iDDEEEEWEEEEEEEEEEEE#WEEGDDDDGGG.         :,iitjLGGGDDDDDDDDDDDD *
 *tti.            .....:::..          ...,.           GDEEEKKKKKKKKKWKKKWWW#WWWWWWWWWWWKWKKjiEjitWWWKKWEEEDi...DDLDDDDji;;WEEEEEEEEEEEDEj.iDDEEEEWEEEEEEEEEEEEWWEEDDDDDDGf.          .,;tjfLGGDDDDDDDDDDDD *
 *tti.              ....::::..        ...,.           fEEEKKKKKKKKKKKKKKKW#WWWWWWWWWWWWWWWWtiEiiiWWWKKEWKEi....D.EDDDEi;.fWEEEEEEEEEEDDfL.;EDDEEEWEEEEEEEEEEEEWWEEEDDDDDGf.           :;ijfLGGDDDDDDDDDDDD *
 *tti.                ....::::..      ...,.          LDEEEKKKKKKKKKKKKKKWWWWWWWWWWWWWWWW####WKiiiWWWKKKEEK,...:E:DDDEii..GWEEEEEEEEDWDDiL.,KDDEEEWEEEEEEEEEEEEWWKEEDDDDDGf:           .,itfLGGDDDDDDDDDDDD *
 *tti.                 .....:::..     ...,.          fDEEEKKKKKKKKKWKKKKWWWWWWWWWWWWW########WLiiWWWKKKEEjD...G,DDDDi;...EWEEEEEEEEDKDEii..LDDEEEWEEEEEEEEEEEEWWWEEDDDDDGfi           .,;tfLGGGDDDDDDDDDDD *
 *tti.                   .....:::..   ...,.         iGEEEKKKKKKKKKKWKKKKWWWWWWWWWWWW###########KiWWWKKEEE,.D..D.DDDii:...KKEEEEEEEEEDDj:...tEDEEEWEEEEEEEEEEEEWWWEEEDDDDDLL           .,;tjLLGGDDDDDDDDDDD *
 *tti.                     ....::::......:.         LEEEKKKKKKKKKKWWKKKWWW#KWWWWWWWW#####W####W##KWWKKEEL..:D.jjDDi;,....KKEEEEEEEDfDDi...:iKDEEEWKEEEEEEEEEEEWWWEEEEDDDDLG           .,;tjLLGGDDDDDDDDDDD *
 *tti.                        ...::::::..,.        :GEEEKKKKKKKKKKKKWWWWW##WWWWWWWWW##WKWK#W#W####WWKEEK.....G.DDti,.....KKEEEEEEDWGDf.,...iKDEEEWWEEEEEEEEEEEW#WEEEEEDDDGL           .,;tjLLGGDDDDDDDDDDD *
 *tti.                         ....::::::,.        GDEEKKKKKKKKKKKKKWWWW###WWWWWWWWWW#WWWK###W#####WKEKK.....jDDL;;......KKEEEEEEEEEDi.f...;KDEEEWWEEEEEEEEEEEWWWWEEEEEDDGf           .,;tjLLGGDDDDDDDDDDD *
 *tti.                           ....:::,,.       .LEEEKKKKKWKKKKKWWWWWW###WWWWWWWWWW#WWKW#WW##W#WWWKEKD:....:DD:;......;KEEEEEEEKiDD..f...,KKEEEWWEEEEEEEEEEEWWWWEEEEEDDDf           .:;tjLLGGGDDDDDDDDDD *
 *tti.                             ...::,,,:.     GDEEKKKKKKKKKKKKWWWWWWW#WWWWWWWWWWW#KjKWWWWWWWWWWWWEK.j,..;fD.;.......fKEEEEEDKG:Di..,....DKEEEWWEEEEEEKEKKKWWWWEEEEEEDDf           .:;tjLLGGDDDDDDDDDDD *
 *jti.                              ...::,,,,:.  .fEEEKKKKKWKKKKKKWWWWWWW#WWWWWWWWWWK#KKKWWWWWWWWWWWWWK..f:.:G.,:.......EKEEEEEKK;:E:.......fKEEEWWKEKEKKKKKKKW#WWEEEEEEDDf:          .,;tfLLGGDDDDDDDDDDD *
 *tti.                               ...:,,,;;,: iDEEKKKKKWKKKKKKKWWWWWWW#WWWWWWWWWWK#WDKWWKKWWWWWWWWWE..;G:G..,........KKEEEEEKi.Gi..:.....tKEEKWWWKKKKKKKKKKW##WKEEEEEEDfi          .,;tfLLGGGDDDDDDDDDD *
 *tti.                               ....::,,;;;,LEEKKKKKKWKKKKKWWWWWWW###WWWWWWWWWWKWWDKWEEEWKKWWWWWKKj.:LG..;.........EKEEEEKG;.G...;.....;KKEKWWWKKKKKKKKKKW##WWKEEEEEDfL          .,;tfLGGGDDDDDDDDDDD *
 *jti.                                ...::::,;ijDEEKKKKKWKKKKKKWKWWWWW##WWWWWWWWWWWKK#KKGDGDWEEWKKWKKGE,.i;.:.........:EKEEEKE;.:L...j.....,KWEKWWWKKKKKKKKKK####WKKEEEEDLG          .,;tfLGGGGDDDDDDDDDD *
 *jti.                                ...:...,,;GEEKKKKKWWKKKKKWWWWWWWW###WWWWWWWWWKKKWWKiLGGEDEDEKGKKiEG..;...........jKEEEKK;:.G....,.....:KKEWWWWKKKKKKKWKK####WKKKKEEEGL          .,;tfLGGGGDDDDDDDDDD *
 *jti.                                ...:.  .:,GEEKKKKKWKKKKKWWWWWWWW####WWWWWWWWWKKKWWKii;fDLGDK: EEi:E:.............EKEEKK;;..L...........KKKWWWWKKKKKKKWKK####WKKKWKEEDf          .,;tfGGGGDDDDDDDDDDD *
 *jti.                                ...:.    ,EEKKKKKWWKKKKKWWWWWWWWW###WWWWWWWWKKKKfWWLt;i,. fi  EG..D:.............EKEKK;;..t....:.......KWKWWWWKKKKKKKWKK####WKKKWEEEDf:.        .,;tfGGGGDDDDDDDDDDD *
 *jti.                                ...:.    GEEKKKKKWKKKKKWWWWWWWWW####WWWWWWWKKKKKt;KKEfff     .;t.................KKKKi;:..GtGGfG.......KWWWWWWKKKKKKKWKK###WWWKKKKEEEf,,:       .,;tfGGGGDDDDDDDDDDD *
 *jti.                                ...:.    GEKKKKKWWKKKKKWWWWWWWWWW##WWWWWWWKKKKKKt;EiKKKK,   ...t................jEKKG;;..,.....,LGi....KWWWWWWKKKKKKWKKKW####WKKKKKEEL,,,:.     .,;tfGGGDDDDDDDDDDDD *
 *jti.                                ...:.  .GEEKKKKKWKKKKKWWWWWWWWWW###WWWWWWWKKKKKKtiE::tGG........................EEEj;;...,.........:D..DKWWWWWWKKKKK#KKW###W#WKKKKKEEfj:,,,:.   .,;tfGGGDDDDDDDDDDDD *
 *jti.                                ...:.   DEKKKKKWWKKKKKWWWWWWWWW####WWWWWWWKKKKKKiiE:::.::.......................EEi;;...j.....f......:iDKWWWWWWKKKKK#WW######WKKKKKEELG :,,,,:. .,;tfGGGDDDDDDDDDDDD *
 *jti.                                ...:.  fEEKKKKWWKKKKWWWWWWWWWWW###WWWWWWWWKKKKKK;tE::..........................DD;.;,.::......;........EWWWWWWWKKKKW#WW#####WWKKKWKKELG  .:,,,:::,;tfGGGDDDDDDDDDDDD *
 *jti.                                ...:. .DEKEKKKWWKKKKWWWWWWWWWWW###WWWWWWWWKKKKKE,iD::..........................D..,;.,;tLffi...........DWDWWWW#KKKWWWWW#####W#KKKWKEEGL    .:,;,,,;tfGGGDDDDDDDDDDDD *
 *jti.                                ...:. ;EEKKKKWWKKKKKWWWWWW#WWWW####WWWWWWKKKKKEL:iD:..........................j ..;..;;:.....i,........DKtWWWWWKKWWWWWW#####WWWKKKEKEDf     .:,;;;itfGGGDDDDDDDDDDDD *
 *jti.                                ...:. DEKKKKKWWKKKKWWWWWWW#WWWW####WWWWWWKKKKKEj:iG...............................:....................GKiWWWWWKKWW#WWW######WWKKKKKEEf       .,;iitfGGGDDDDDDDDDDDD *
 *jti.                                ...:.:EKKKKKWWKKKKKWWWWWWW#WWW#####WWWWWKWKKKKEi:if:.................................iEKEKKKKKKDj......DKiWWWWWKWK##WW#######WWKKK:KEEL        .:;itfGGGDDDDDDDDDDDD *
 *jji.                                ...:,DEEKKKWWWKWKKWWWWWWWWWWWW#####WWWWWWWKKKKEi:it..................................j.  KKKKKKKKKKKf..DKiWWWWWKWW##WW#######WWKKK,KEEf         .,;tfGGGDDDDDDDDDDDD *
 *jji.                                ..L:iDEEKKKWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKKi.i;..................................  . KKKWWWWWWWWK..DGiWWWWWKK##WWW#####W#WWKKKjEKEL,        .:;tfGGGDDDDDDDDDDDD *
 *jji.                               .f:::EEEKKKWWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKK;.i,.................................::  KKEKWWWWWWfWK..EiiWWWWWKWW#WW##########KKKD,KELj        .:;tfGGDDDDDDDDDDDDD *
 *jji.                             .t::::,DEEKKKWWKKKKWWWWWWWWW#WWWW#####WWWWKKWKKKEK;.i:.................................GDDEEEKKKWWWWWtWWD.E;iWWWWWW###WW#########WWKKK.EEDG        .:;tfGGGDDDDDDDDDDDD *
 *jji.                          . j..::::EKEKKKWWWKKKKWWWWWWWWW#WWW######WWWWKKWKKKEK;.t:.................................ELLEDDEEEWWWWEtWK,.KiiWWWWWW###W##########WWKKK:EEEG     .;tjfLLGDDDDDDDDDDDDDDD *
 *jji.                          i.::::::,EEEKKWWWKKKKKWWWWWWWWW#WWW#####WWWWWKWKKKKEE,.t..................................DfiEGDDDEEKKKttKWG.KiiWWWWW##WWW##########WWKKK:fEEL  ,fGGGDDDDDDDDEEEDDDDDDDDDD *
 *jji.                        .;:..:::::DEEEKKWWWKKKKKWWWWWWWWW#WWWW####WWWWWWWKKKKED,.t..................................ifjDDGGEGDKK.ttKKE.DiWWWWW###WW##########WWWKKK:.KELiLGGGGDDDDDDDDDDDDEEEDDDDDDD *
 *jji.                       i.:.::::::,KEEKKWWWKKKKKKWWWWWWWWW#WWWW####WWWWWWWKKKKEL:.j..................................GGf,;ifLLED .iiKKi:fWWWWWW##W#W##########WWWKKK:.KKLGGDDDDDDDDDDDDDDDDEDDEEDDDDD *
 *jji.                     .j:.::::::::EEEKKKWWWKKKKKKWWWWWWWW##WWW#####WWWWWWWKKKKKf:.f..................................:EEfftf .,. ;iE,..jWWWWWWW###W############WWKKK,:KKGDDDDDDDDDDDDDDDDDDDDDDDEDDDD *
 *jji.                    .:.::::::::,,EEEKKWWWKKKKKKKWWWWWWWW##WWW#####WWWWWWWKKKKKt..G....................................EEELL;   .j....tKWWWWWWW################WWWKKtfGKGEDDDDDDDDDDDDDDDDDDDDDDDEEDD *
 *jji.                   :...:::::::,,jEEKKWWWWKKKKKKWWWWWWWWW##KWW#####KWWWWWWKKKKEi..D....................................:jEEE.........;KKWWWWWWWW#WW##W##########WWKKDLGKEKDDDDDDDDDDDDDDDDDDDDDDDDDED *
 *jji.                  i:.::::::::,,,EEEKKWWWWKKKKKWWWWWWWWWW##WWW#####WWWWWWWKKKKKi..D......................................:::::......,KKKWWWWWWWWW#####W########WWWKKKGGKKEGGGGGGGGDDDDDDDDDDDDDDDDDDE *
 *jji.                 i..:::::::::,,tEEKKWWWWKKKKKWWWWWWWWWWW##WW######WWWWWWWKKKKKi..D......................................::::......:EKKKWWWWWWWWWWW##WW########W#WKKWGGKKGGGGGGGGGGGGGGGDDDDDDDDDDDDD *
 *jji.                .:::::::::::,,,EEEKKWWWWKKKKKWWWWWWWWWWW##WW#####WWWWWWWWKKKKKi..D....................................:::::::::..tELii;KWWWWWWWWWW##WW######WWWWWWKWGGGKGGGGGGGGGGGGGGGGGGGGGGGGGGDG *
 *jjt.                :.::::::::,,,,fEEKKWWWWKKKKKKWWWWWWWWWW###WW####WWWWWWW#WKKKKKi..D....................................:::::::.:.,;;;;;;,KKWWWWWWWWW#WW########WWWKKWGGGKGGGGGGGGGGGGGGGGGGGGGGGGGGGG *
 *jji.               ;.::::::::,,,,;EEEKWWWWWKKKKKWWWWWWWWWWWW##WW###WKWWWWWK#WKKKKKi..G......................................:::::::,;;;;:...KKKWWWWWWWWWKWW#######WWWWKKGLGKDGGGGGGLLGGGGGGGGGGGGGGGGGGG *
 *jjt.              f.:::::::::,,,,fEEKKWWWWWKKKKKWWWWWWWWWWW###WW##WKKWWWWWW#WKKKKK;.jt........i.............................:::::::;j;;....:E.KKKWWWWWWWKWW#####W#WWWWKKLLGWEEGGGGGLGGGGGGGGGGGGGGGGGGGG *
 *jjt.             ...:::::::,,,,,;DEEKWWWWWKKKKKWWWWWWWWWWWW####WWWKKKWWWWWWWWKKKKK;.E;.........t.............................:::::ii;;.....D...KKWWWWWWWKWW#####WWEWWWKKGGGEKKGGGGGLGGGGGGGGGGGGGLGGGGGG *
 *fji.             ;.:::::::,,,,,;LEEKKWWWWWKKKKKWWWWWWWWWWWW####KWKKKKWWWWWWWWKKKKKi.D;..........j.............................:::tt;,.....:.....KKWWWWWWKWWWW##WWWGWWWKKGGGGKEGGGGGGGGGGGGGGGGGGGLLGGGGL *
 *fji.            t::::::::,,,,,,;EEEKWWWWWKKKKKKKWWWWWWWWWWW##WKWKKKKKWWWWWWWWKKKKKi:D;............j...........................::LL;,.............KKWWWWWKWWWWWWWWWGWWWKKGGGGKGGGGGGGGGGGGGGGGGGGGLLGGGGL *
 *fjt:            .:::::::,,,,,,,DEEKWWWWWWKKKKKKKWWWWWWWWWWWWKKWKKKKKKWWWWK#WWKKKKWitE;........... ............................:G;;:...............KKKWWKKWWWWWWWWWGWWWKKGGGGWGGGGGGGGGGGGGGGGGGGGGGGGGGL *
 *fjji;:.       .f:::::::,,,,,,,;EEEKWWWWWWKKKKKKWWWWWWWWWWWKKKKKKKKKKKWWKWWWWWKKKKWGKD;........................................L;;..................DKKWKKWWWWWWWWWGWWWKKDGGGKDGGGGGGGGGGGGGGGGGGGGGGGGGG *
 *fjjtii;,:.     :::::::,,,,,,,;EEEKWWWWWWKKKKKKWWWWWWWWWWKKKKKKKKKKKKWWWWWW#WWKKKKWiEj;......................................:i,;....,...............;KKEKWWWWWWWWWGKWWKKDDGGDEGGGDGGGGGDGGGGGGGGGGGGGGGG *
 *fjtiiiii;;:.  j::::::,,,,,,,;;EEEKWWWWW#KKKKKWWWWWWWWWKKKKKKWKKKKKKKWWWWWWWWWKKKKWtEL;:....................................;;;:...,;j................:KEEWWWWWWWWWDDWWKKDDDDDKDDDDDDDDDDDDDDDGGGGGGGGGGG *
 *fjti;;iiii;;,:::::::,,,,,,,,;EEEKWWWWWWWKKKKWWWWWWWWKKKKKKKWKKKKKKKWWWWWWW#W#KKKKWEEii;...................................f;:....,;L...................EEKWWWWWWWWDDWWKKDDDDDKEDDDDDDDDDDDDDDDDDDDDDGGGG *
 *fjt,,,;;;;ii;f::::::,,,,,,,;;EEKWWWWWWWKKKKKWWWKWWKKKKKKKKKKKKKKKKKWWWWWWW#W#KKKKWKEij;:...............................:G;,.....,;f....................:tKKWWWWWWWDDWWKKDDDDDKKDDDDDDDDDDDDDDDDDDDDDDDDD *
 *jjt. ..:,;;;;,::::,,,,,,,,;;GEEWWWWWWWWKKKKWKKWKKKKKKKKKKKKKKKKKKKKWWWWWWW#W#KKKKWEDi;j;............................,Li;L;;;..,;;f........................KKKKWWWKDDWWKKDDDGDKKGGGGGGGGDGDDDDDDDDDDDDDDD *
 *fjt.    .:,,,:::::,,,,,,,;;;EEKWWWWWWWKKKKKKWKKKKKKKKKKKKKKKKKKKKKWKKKWKW##W#KKKKWEti;;G;........................tEEEL;;;;;;;;;;L..........................DKKKKKEDDWWKEDGftiLE;;;;itjLGGGGGGDDDDDDDDDDD *
 *fjt.       .j::::,,,,,,,;;;DEEWWWWWWWWKKKKWKKKKKKKKKKKKKKKKKKKKKKKWKKWWWK##W#KKKKKEii;;;L;...................iDEEEEEEKKi;j;;;;jD.....:......................,KKKKDGGEKKE:::::;E::::::::::,tLGGDDDDDDDDDD *
 *fjt.       .;:::,,,,,,,;;;;EEKWWWWWWWWKWKKKKKKKKKKKKKKKWKKKKKKKKKKWKKWWWW#WW#KKKKKKii;;;;f;.............:tDEEEEEKKKKKKKKEti;;;L...............................EEKf;:iKKE::::::E::::::::::::::ifDDDDDDDDD *
 *fjt:        :::,,,,,,,,;;;DEEWWWWWWWWWEKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKWWWW####KKKKKEiii;;;;f,.........iDEEEEKKKKKKKKKKKKKKKf;iG......i..........................fK::::KKE::::::E::::::::::::::::,tGGDDDDD *
 *fjt:       t:::,,,,,,;;;;iDEKWWWWWWKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKWWWW####WKKKKLiii;;;;;L,....,Li;EDEEEEKKKKKKKKKKKKKKKKiG......;:...........................:i:::KKE:::::,E,::::::::::::::::::iGDDDD *
 *jjt.       f::,,,,,,,;;;;GEEWWWWKEEKEKKKKKKKKKKKKKKKKWKKKKKKKKKKKWWKWWWWW###WWKKKKiii;;;;;;;G,;L;;iiEEEEEEEKKKKKKKKKKKKKWWKE......;t.........:....................j::KEE:,::,,D,,::::,,,,,,:::::::::tDDD *
 *fjt:.      ,::,,,,,,,;;;;EEWWKEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKWWKKWWWWW#W#KKKKKKiiiiii;;;;;i;;iiiEEKEEKKWKKKKKKKWKKKKKWWWGi;...;t......,;;;;,....................:,EEE,,,,,,D,,,,,,,,,,,,,,,,::,::::tG *
 *fjt:.     ,::,,,,,,,;;;;DEKEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWW#W#KKKKKKiiiii;;i;;;;;iiiKKKEKKKKWWKWWWWWWKKKKWWWWW;;;:;L.....;;;;;;;;;....................,KEE,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,; *
 *fjt:.     f:,,,,,,,;;;;jEDEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWW#W##KKKKKKiiiiiiii;i;;iiiEKKKKKKKKWKWWWWWWWWKKKWWWWWKi;;i.....,jEEfGi;;;;;...................EED,,,,,,E,,,,,,,,,,,,,,,,,,,,,,,,, *
 *fjt:.    .f::,,,,,,;;jEEDEEEEEEEEEEKKKKKKKKKKKKKKKWKKKKKKKKKKKKKWWWKWWWWW###KKKKKLiiiiiiiiiiiiiiEEKKKKKKKKWWWWWWWWWWWWKWWWWWWGi;i;,..;jDDDKEGi;;;;;;:................EED,,,,,,D,,,,,,,,,,,,,,,,,,,,,,,,, *
 *fjt:.  .. ;::,,,,,;;EDDEEEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWKKW#WW####KWKKKiiiiiiiiiiiiijKKKKKKKKKKWWWWWWWWWWWWWWWWWWWWWt;i;;;;i;DDDDDDGi;;;;;;;;:.............EDf;,,,;,G;;;;;;;;;;;;;;;,,,,,,,,,, *
 *fjt:......:,,,,,,;LDDDEEEEEEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKKKWWWWKWWWW####KKKKKiiiiiiiiiiijKEKKWKKKKKKKWWWWWWWWWWWWWWWWWWWWWWiLiii;i;DEEEEDDE;i;;;;;;;;;:..........EDi,;;;;;L;;;;;;;;;;;;;;;;;;,,,,,,, *
 *fjt:......:,,,,,;EDDDEEKEEEEEEEEEKKKKKKKKKKKKKKKWKKKKKKKKKKKKKKWWWWKKWWW##W#KWKKWEiiiiiijGKKKKKWWKKKKKKKKWWWWWWWWWWWWWWWWWWWWWWKi;iiiiDDEEEEEEDEi;;;;;;;;;;;;;,:.....ED;;;;;;;j;;;;;;;;;;;;;;;;;;;;;;;,, *
 *fjt:.....t,,,,,;DDDDEEEKEEEEEEEEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWKKKWWWW##WKWKKWKiiiKKKKKKKKKWWKKKKKKKKWWWWWWWWWWWWWWW#WWWWWWWWWiiiiifLEEEEEEEEDi;i;;;;;;;;;;;;.....DD;;;;;;;i;;;;;;;;;;;;;;;;;;;;;;;;; *
 *fjt:.....G,,,,,GDDDEEEEEEEEEEEEKKKKKKKKKKKKKKKKWKKKKKKKKKKKKKKKWWWKKKWWW###WKWKKWKitKKKKKKKKKWKKKKKKKKKKWWWWWWWWWWWWWW###WWWWWWWWEiiiiiiiEEEEEEEEDGiiii;;;;;;;;;.....GD;;;;;;;i;;;;;;;;;;;;;;;;;;;;;;;;; *
 *fjt:.....L,,,,;GDDDEEEEEEEEEEKEKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKWWWWWDGWWW###KKWWKWKKKKKKKKKKKKKKKKKKKKKKKWWWWWWWWWWWWW####WWWWWWWWWiiiiiiiiEEEEEEEEEEDi;i;;;;;;;;.....Lj;;;;;;i;iiiiii;;;;;;ii;;;;;;;;;;; *
 ***********************************************************************************************************************************************************************************************************/
