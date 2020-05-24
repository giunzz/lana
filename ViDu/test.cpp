// Vector nghiệm X[1] .. X[2*n]
// Tập ứng cử viên	A = {'(' , ')'};
//		const A:Array[1..2] of char =('(',')');
// Điều kiện: X thỏa đk là xâu dấu ngoặc của bt toán học

/*const A:Array[1..2] of char =('(',')');
var X:string;
	n,i:integer;

function thoadk:boolean;
var i,d:integer;
begin
	d:=0;
	for i:=1 to 2*n do
	begin
		if (X[i]='(') then inc(d)
		else dec(d);
		if (d<0) then exit(false);
	end;
	exit(d=0);
end;
procedure Chon(i:integer);
var j:integer;
begin
	for j:=1 to 2 do
	begin
		X[i]:=A[j];
		if i=2*n then 
		begin
			if thoadk then writeln(output,X);
		end
		else Chon(i+1);
	end;
end;
begin
	assign(input,'BAI47QL.INP'); reset(input);
	assign(output,'BAI47QL.OUT'); rewrite(output);
	readln(input, n);
	for i:=1 to 2*n do X:=X+'(';
	Chon(1);
	close(input);
	close(output);
end.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

	cerr<< 20/10; 
}

/*char* addBigNumber(char* a, char* b)
{
	if (strlen(a) < strlen(b))
	{
		swapPointer(&a, &b);
	}
 
	size_t a_len = strlen(a), b_len = strlen(b);
	char* result = new char[a_len + 2];
	memset(result, '0', a_len);
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
}*/
