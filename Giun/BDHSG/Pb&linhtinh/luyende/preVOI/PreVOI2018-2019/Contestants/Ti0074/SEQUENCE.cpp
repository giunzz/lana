#include <bits/stdc++.h>

using namespace std;

void upfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQUENCE.INP","r",stdin);
    freopen("SEQUENCE.OUT","w",stdout);
}

const int maxN = 111;

int m, n, k, a[maxN], b[maxN];

vector <int> ans;

vector <int> Min(vector<int> a, vector<int> b)
{
    int r = a.size();
    for (int i=0; i<r; ++i)
        if (a[i] < b[i])
            return a;
        else if (b[i] < a[i])
            return b;
    return a;
}

int main()
{
    upfile();
    cin >> m >> n >> k;
    k = m + n - k;
    for (int i=1; i<=m; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i)
        cin >> b[i];
    for (int t=1; t<=min(m, k); ++t)
    {
        if (k - t > n)
            continue;
        deque <int> s1, s2;
        int l;
        l = t;
        for (int i=1; i<=m; ++i)
        {
            while (!s1.empty() && s1.back() > a[i] && l > 0)
            {
                s1.pop_back();
                --l;
            }
            s1.push_back(a[i]);
        }
        l = k - t;
        for (int i=1; i<=n; ++i)
        {
            while (!s2.empty() && s2.back() > b[i] && l > 0)
            {
                s2.pop_back();
                --l;
            }
            s2.push_back(b[i]);
        }
        vector <int> v;
        while (!s1.empty() || !s2.empty())
        {
            if (s1.empty())
            {
                v.push_back(s2.front());
                s2.pop_front();
            }
            else if (s2.empty())
            {
                v.push_back(s1.front());
                s1.pop_front();
            }
            else
            {
                if (s1.front() <= s2.front())
                {
                    v.push_back(s1.front());
                    s1.pop_front();
                }
                else
                {
                    v.push_back(s2.front());
                    s2.pop_front();
                }
            }
        }
        if (ans.empty())
            ans = v;
        ans = Min(ans, v);
        v.clear();
    }
    for (int i: ans)
        cout << i << " ";
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
 *tti.                        ...::::::..,.        :GEEEKKKKKKKKKKKKWWWWW##WWWWWWWWW##WKWK#W#W####WWKEEv.....G.DDti,.....KKEEEEEEDWGDf.,...iKDEEEWWEEEEEEEEEEEW#WEEEEEDDDGL           .,;tjLLGGDDDDDDDDDDD *
 *tti.                         ....::::::,.        GDEEKKKKKKKKKKKKKWWWW###WWWWWWWWWW#WWWK###W#####WKEKv.....jDDL;;......KKEEEEEEEEEDi.f...;KDEEEWWEEEEEEEEEEEWWWWEEEEEDDGf           .,;tjLLGGDDDDDDDDDDD *
 *tti.                           ....:::,,.       .LEEEKKKKKWKKKKKWWWWWW###WWWWWWWWWW#WWKW#WW##W#WWWKEKD:....:DD:;......;KEEEEEEEKiDD..f...,KKEEEWWEEEEEEEEEEEWWWWEEEEEDDDf           .:;tjLLGGGDDDDDDDDDD *
 *tti.                             ...::,,,:.     GDEEKKKKKKKKKKKKWWWWWWW#WWWWWWWWWWW#KjKWWWWWWWWWWWWEv.j,..;fD.;.......fKEEEEEDKG:Di..,....DKEEEWWEEEEEEKEKKKWWWWEEEEEEDDf           .:;tjLLGGDDDDDDDDDDD *
 *jti.                              ...::,,,,:.  .fEEEKKKKKWKKKKKKWWWWWWW#WWWWWWWWWWK#KKKWWWWWWWWWWWWWv..f:.:G.,:.......EKEEEEEKK;:E:.......fKEEEWWKEKEKKKKKKKW#WWEEEEEEDDf:          .,;tfLLGGDDDDDDDDDDD *
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
 *jji.                                ..L:iDEEKKKWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKKi.i;..................................  . KKKWWWWWWWWv..DGiWWWWWKK##WWW#####W#WWKKKjEKEL,        .:;tfGGGDDDDDDDDDDDD *
 *jji.                               .f:::EEEKKKWWWKKKKKWWWWWWWWWWWW#####WWWWWKWKKKKK;.i,.................................::  KKEKWWWWWWfWv..EiiWWWWWKWW#WW##########KKKD,KELj        .:;tfGGDDDDDDDDDDDDD *
 *jji.                             .t::::,DEEKKKWWKKKKWWWWWWWWW#WWWW#####WWWWKKWKKKEK;.i:.................................GDDEEEKKKWWWWWtWWD.E;iWWWWWW###WW#########WWKKv.EEDG        .:;tfGGGDDDDDDDDDDDD *
 *jji.                          . j..::::EKEKKKWWWKKKKWWWWWWWWW#WWW######WWWWKKWKKKEK;.t:.................................ELLEDDEEEWWWWEtWK,.KiiWWWWWW###W##########WWKKK:EEEG     .;tjfLLGDDDDDDDDDDDDDDD *
 *jji.                          i.::::::,EEEKKWWWKKKKKWWWWWWWWW#WWW#####WWWWWKWKKKKEE,.t..................................DfiEGDDDEEKKKttKWG.KiiWWWWW##WWW##########WWKKK:fEEL  ,fGGGDDDDDDDDEEEDDDDDDDDDD *
 *jji.                        .;:..:::::DEEEKKWWWKKKKKWWWWWWWWW#WWWW####WWWWWWWKKKKED,.t..................................ifjDDGGEGDKv.ttKKE.DiWWWWW###WW##########WWWKKK:.KELiLGGGGDDDDDDDDDDDDEEEDDDDDDD *
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
