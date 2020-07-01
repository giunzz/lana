#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;
char const mon[12][15] = {"Toan", "Li", "Hoa", "Van", "Anh", "Sinh", "Su", "Dia", "CNghe", "GDCD", "GDQP", "Tin"};
static bool checkMon[12];
static int dem;

class manageScore
{
public:
    void themDiem(int vitri);
    void xoaDiem(int vitri);
    void mainShowDiem(int vitri);
    void update_diem();
protected:
    void readDiem(int vitri);
    void writeDiem(int vitri);
    float diem[4][6] = {{-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}, {-1, -1, -1, -1, -1, -1}};
    float dtb = 0;
    char filesub[1] = "";
};

class extraFunc: public manageScore
{
public:
    void readSubject(void); //đọc môn trong file môn
    void QuanLiDiem(void);
    void showDiem(int vitri);
    void allScore(void);
protected:
    void writeSubject(void); //chỉnh sửa môn
    void edit_checkMon(bool check);
    void chinhFileMon(int i, bool check);
};

class mainFunc: public extraFunc
{
public:
    void mainFeature(void); //chức năng: QuanLiMon, QuanLiDiem
private:
    void mainScreen(void); //hiện các môn đã có
    void QuanLiMon(void); //chức năng: ThemMon, XoaMon
};

void manageScore::update_diem()
{
    for (int m = 0; m != 4; ++m)
        for (int n = 0; n != 6; ++n)
            diem[m][n] = -1;
}

void manageScore::mainShowDiem(int vitri)
{
    system("CLS");
    cout << "DIEM THANH PHAN\n" << "Mon " << mon[vitri] << endl;
    readDiem(vitri);
    cout << setiosflags(ios::showpoint) << setprecision(3);
    for (int m = 0; m != 4; ++m)
    {
        if (m == 0) cout << "Diem mieng: ";
        if (m == 1) cout << "Diem 15p: ";
        if (m == 2) cout << "Diem 45p: ";
        if (m == 3) cout << "Diem HK: ";
        for (int n = 0; n != 6; ++n)
        {
            if (diem[m][n] != -1)
                cout << diem[m][n] << " ";
            if (n == 5) cout << endl;
        }
    }
    cout << "Diem trung binh mon: " << dtb << endl;
}

void manageScore::themDiem(int vitri)
{
    mainShowDiem(vitri); int i; float score;
    cout << "Loai diem muon them:\n" << "0. Diem mieng\n" << "1. Diem 15p\n" << "2. Diem 45p\n" << "3. Diem hoc ki\n" << "4. Quay lai\n";
    while(true)
    {
        cout << "Chon loai them diem: ";
        cin >> i;
        if (i == 4) break;
        if (i < 0 || i > 4)
        {
            cout << "Loai diem khong hop le!\n";
            continue;
        }
        cout << "Them diem: ";
        cin >> score;
        if (score < 0 || score > 10)
        {
            cout << "Diem khong hop le!\n";
            continue;
        }
        for(int j = 0; j != 6; ++j)
            if (diem[i][j] == -1)
            {
                diem[i][j] = score;
                return;
            }
    }
}

void manageScore::xoaDiem(int vitri)
{
    mainShowDiem(vitri); int i; float score;
    cout << "Loai diem muon xoa:\n" << "0. Diem mieng\n" << "1. Diem 15p\n" << "2. Diem 45p\n" << "3. Diem hoc ki\n" << "4. Quay lai\n";
    while(true)
    {
        laplai: cout << "Chon loai xoa diem: ";
        cin >> i;
        if (i == 4) break;
        if (i < 0 || i > 4)
        {
            cout << "Loai diem khong hop le!\n";
            continue;
        }
        cout << "Xoa diem: ";
        cin >> score;
        if (score < 0 || score > 10)
        {
            cout << "Diem khong hop le!\n";
            continue;
        }
        if (diem[i][5] == score) diem[i][5] = -1;
        else for(int j = 0; j != 5; ++j)
        {
            if (diem[i][j] == score)
            {
                if (score == -1) break;
                if (diem[i][j + 1] != -1) diem[i][j] = diem[i][j + 1];
                else diem[i][j] = -1;
                score = diem[i][j];
            }
            else if (j == 4)
            {
                cout << "Diem khong ton tai!\n";
                goto laplai;
            }
        }
        break;
    }
}

void manageScore::readDiem(int vitri)
{
    strcpy(filesub, mon[vitri]);
    strcat(filesub, ".txt");
    dtb = 0;
    int i = 20, m = -1, n = -1, sldiem = 0; float check = 0;
    ifstream file;
    file.open(filesub);
    while (file >> check)
    {
        if (check == i) ++i, ++m, n = 0;
        else diem[m][n] = check, ++n;
    }
    for (m = 0; m != 4; ++m)
        for (n = 0; n != 6; ++n)
        {
            if(diem[m][n] != -1 && m == 0)
            {
                ++sldiem;
                dtb += diem[m][n];
            }
            if(diem[m][n] != -1 && m != 0)
            {
                sldiem += m;
                dtb += diem[m][n] * m;
            }
        }
    if (sldiem != 0) dtb /= sldiem;
}

void manageScore::writeDiem(int vitri)
{
    ofstream file; int i, j, moc = 20;
    file.open(filesub);
    for (i = 0; i != 4; ++i)
    {
        file << moc << " "; ++moc;
        for (j = 0; j != 6; ++j)
            file << diem[i][j] << " ";
    }
}

void extraFunc::allScore(void)
{
    system("CLS"); int choose;
    cout << "SHOW DIEM CAC MON\n";
    // cout << "Mon" <<
    for (int i = 0; i != 12; ++i)
    {
        if (checkMon[i] == 1)
        {
            cout << "Mon " << mon[i] << endl;
            readDiem(i);
        }
        update_diem();
    }
    laplai: cout << "Chuc nang:\n" << "0. Quay lai\n" << "Chon: ";
    cin >> choose;
    if (choose != 0)
    {
        cout << "Chon chuc nang khong hop le!\n";
        goto laplai;
    }
}

void extraFunc::showDiem(int vitri)
{
    laplai: mainShowDiem(vitri);
    int i;
    cout << "Cac chuc nang:\n" << "1. Them diem\n" << "2. Xoa diem\n" << "3. Quay lai\n";
    while(true)
    {
        cout << "Chon chuc nang: ";
        cin >> i;
        switch(i)
        {
        case 1:
            themDiem(vitri);
            writeDiem(vitri);
            strcpy(filesub, "");
            goto laplai;
        case 2:
            xoaDiem(vitri);
            writeDiem(vitri);
            strcpy(filesub, "");
            goto laplai;
        case 3:
            return;
        default:
            cout << "Chuc nang khong hop le!\n";
            continue;

        }
    }
}

void extraFunc::chinhFileMon(int i, bool check)
{
    char filemon[] = "";
    strcat(filemon, mon[i]);
    strcat(filemon, ".txt");
    ofstream trofile;
    if (check == 1)
    {
        trofile.open(filemon);
        trofile << "20 21 22 23 ";
    }
    else remove(filemon);
}

void extraFunc::edit_checkMon(bool check)
{
    system("CLS"); int i;
    char dien1[5], dien2[5];
    strcpy(dien1, (check == 1) ? "Them" : "Xoa");
    strcpy(dien2 , (check == 1) ? "da" : "chua");
    cout << "CHINH SUA MON\n" << "Tat ca cac mon:\n";
    for (int i = 0; i != 12; ++i)
        cout << i << ". " << mon[i] << endl;
    cout << "12. Quay lai" << endl;
    while(true)
    {
        cout << dien1 << " mon: ";
        cin >> i;
        if (i == 12) break;
        if (i < 0 || i > 11)
        {
            cout << "Mon khong hop le!\n";
            continue;
        }
        if (checkMon[i] != check)
        {
            checkMon[i] = check;
            chinhFileMon(i, check);
        }
        else cout << "Mon " << dien2 << " ton tai!" << endl;
    }
}

void extraFunc::readSubject()
{
    int i = 0;
    dem = 0;
    ifstream file;
    file.open("mon.txt");
    while(i != 12 && file >> checkMon[i]) ++i;
    file.close();

    for(i = 0; i != 12; ++i)
        if (checkMon[i] == true)
        {
            cout << dem << ". " << mon[i] << endl;
            ++dem;
        }
}

void extraFunc::QuanLiDiem()
{
    laplai: system("CLS");
    int j, setmon, vitrimon = -1;
    cout << "CHUONG TRINH QUAN LI DIEM: \n" << "Cac mon hien co:\n";
    readSubject();
    cout << dem + 1 << ". Tat ca mon\n" << dem + 2 << ". Quay lai\n";
    while(true)
    {
        cout << "Chon mon: ";
        cin >> setmon;
        if (setmon == dem + 2) break;
        if (setmon == dem + 1)
        {
            allScore();
            goto laplai;
        }
        if (setmon < 0 || setmon >= dem)
        {
            cout << "Mon khong hop le!\n";
            continue;
        }
        for (j = 0; j != 12; ++j)
        {
            if (checkMon[j] == 1) ++vitrimon;
            if (vitrimon == setmon)
            {
                vitrimon = j;
                break;
            }
        }
        showDiem(vitrimon);
        update_diem();
        goto laplai;
    }
}

void extraFunc::writeSubject()
{
    ofstream file;
    file.open("mon.txt");
    int i = 0;
    while(i != 12 && file << checkMon[i] << " ") ++i;
    file.close();
}

void mainFunc::QuanLiMon()
{
    laplai: system("CLS");
    int i;
    mainScreen();
    cout << "Cac chuc nang quan li mon:\n" << "1. Them mon\n2. Xoa mon\n3. Quay lai\n";
    while(true)
    {
        cout << "Chon chuc nang: ";
        cin >> i;

        switch(i)
        {
        case 1:
            edit_checkMon(1);
            writeSubject();
            goto laplai;
        case 2:
            edit_checkMon(0);
            writeSubject();
            goto laplai;
        case 3:
            return;
        default:
            cout << "Chuc nang ko hop le!\n";
        }
    }
}

void mainFunc::mainScreen()
{
    cout << "CHUONG TRINH QUAN LI DIEM: \n" << "Cac mon hien co:\n";
    readSubject();
}

void mainFunc::mainFeature()
{
    laplai: system("CLS");
    mainScreen();
    int i;

    cout << "Chuc nang:\n" << "1. Quan Li Mon \n2. Quan Li Diem\n3. Thoat\n";
    while(true)
    {
        cout << "Chon chuc nang: ";
        cin >> i;

        switch(i)
        {
        case 1:
            QuanLiMon();
            goto laplai;
        case 2:
            QuanLiDiem();
            goto laplai;
        case 3:
            return;
        default:
            cout << "Chuc nang ko hop le!\n";
        }
    }
}

int main()
{
    mainFunc ct;
    ct.mainFeature();
    return 0;
}
