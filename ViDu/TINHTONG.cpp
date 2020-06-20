#include<bits/stdc++.h>
using namespace std;
#define giuncute ios_base::sync_with_stdio(0) , cin.tie(0)
const string tenfile = "giun";
#define balabalo freopen((tenfile + ".inp").c_str(), "r", stdin); freopen((tenfile + ".out").c_str(), "w", stdout)

void swapPointer( char **a , char **b)
{
    char * t = *a;
    *a = *b;
    *b = t;
}
char* cong( char * a , char *b)
{
    if (strlen(a) < strlen(b) ) swapPointer(&a , &b);
    size_t a_len = strlen(a), b_len = strlen(b);
    char* result = new char[a_len + 2];
    bool remember = false;
    for (int i = 0; i < b_len; i++)
	{
		int temp = *(b + b_len - i - 1) - '0' + *(a + a_len - i - 1) - '0';
		if (remember)
			temp++;
		if (temp > 9)
			remember = true;
		else
			remember = false;
		temp = temp % 10;
		*(result + a_len - i) = temp + '0';
	}
	for (int i = 0; i < a_len - b_len; i++)
	{
		int temp = *(a + a_len - b_len - i - 1) - '0';
		if (remember)
			temp++;
		if (temp > 9)
			remember = true;
		else
			remember = false;
	
		temp = temp % 10;
		*(result + a_len - b_len - i) = temp + '0';
	}
	*(result + a_len + 1) = '\0';
	if (remember)
	{
		*(result) = '1';
	}
	else
	{
		for (int i = 0; i <= a_len; i++)
			*(result + i) = *(result + i + 1);
	}
	return result;
}

char* tru(char* a, char* b)
{
	bool sign = false, remember = false;
	if (strlen(a) < strlen(b))
	{
		sign = true;
		swapPointer(&a, &b);
	}
	else if (strlen(a) == strlen(b))
	{
		for (int i = strlen(a) - 1; i >= 0; i--)
		{
			if (*(a + i) < *(b + i))
			{
				swapPointer(&a, &b);
				sign = true;
			}
		}
	}
	size_t a_len = strlen(a);
	size_t b_len = strlen(b);
	char* result = new char [a_len + 2];
	memset(result, '0', a_len + 2);
	for (int i = 0; i < b_len; i++)
	{
		int temp = *(a + a_len - i - 1) - *(b + b_len - i - 1);
		if (remember)
			temp--;
		if (temp < 0)
		{
			temp += 10;
			remember = true;
		}
		else
			remember = false;
		*(result + a_len - i) = temp + '0';
	}
	for (int i = 0; i < a_len - b_len; i++)
	{
		int temp = *(a + a_len - b_len - i - 1) - '0';
		if (remember == true)
			temp--;
		if (temp < 0)
		{
			temp += 10;
			remember = true;
		}
		else
			remember = false;
		*(result + a_len - b_len - i) = temp + '0';	
	}
	while (*(result) == '0')
	{
		if (*(result + 1) != '0' && sign == true)
		{
			*(result) = '-';
			*(result + a_len + 1) = '\0';
			break;
		}
		for (int i = 0; i < a_len; i++)
		{
			*(result + i) = *(result + i + 1);
		}
		*(result + a_len) = '\0';
	}
	return result;
}

void del( char* &p, int vt)
{
    int last;
    if(vt == strlen(p) - 1)  p[vt] = '\0';
    else {
        for (int i = vt + 1 ; p[i] != '\0' ; i++ ) 
        {
            p[i-1] = p[i], last = i;    
        }
        p[last] = '\0';
    } 
}

char* s1 , s2 , ans;
char  d1 , d2 , d ;
int main()
{
    giuncute;
    balabalo;
    cin >> s1 >> s2;
    if(s1[0] == '-')
    {
        d1 ='-';
        char* tam = new char(strlen(s1)+ 1);
    	strcpy(tam, ((const char*)s1));
    	del(tam,0);
		s1 = tam
    }
    else d1 = '0';
    if(s2[0] == '-')
    {
        d2 ='-';
        char* tam2 = new char(strlen(s2)+ 1);
    	strcpy(tam2, ((const char*)s2));
    	del(tam2,0);
		s2 = tam2
    }
    else d2 = '0';
    while (strlen(s1.c_str()) != strlen(s2.c_str()) ) 
	{
		if ( strlen(s1.c_str()) < strlen(s2.c_str()) ) strcat(s1 , "0");
		else strcat(s2 , "0");
	}
	strcat(s1 , "0");
	strcat(s2 , "0");
	if (d1 == d2)
	{
		d = d1 ;
		ans = cong(s1 , s2);
	}
	else 
	{
		if (strcmp(s1, s2) == 0) 
		{
			d ='0';
			ans = '0';
		}
		else if (strcmp(s1, s2) > 0)
		{
			ans = tru(s1,s2);
			d = d1;
		}
		else 
		{
			ans = tru(s2,s1);
			d = d2;
		}
	}
	char* p = new char(strlen(ans)+ 1);
    strcpy(p, ((const char*)ans));
    while ( strlen(p) > 1 && p[0] == '0'   )
	{
        del(p, 0);
    }
    ans = p;
	if (d == '-') cout << dau << ans;
	else cout << ans;
	return 0;
}