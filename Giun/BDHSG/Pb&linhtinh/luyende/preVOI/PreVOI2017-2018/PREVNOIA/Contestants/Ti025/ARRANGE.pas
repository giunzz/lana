uses	math;
const
	fi='ARRANGE.inp';
	fo='ARRANGE.out';
	maxn=trunc(1e5);
	oo=trunc(1e5);
var	a:array[1..maxn] of longint;
	m1,m2,n:longint;
Procedure	enter;
var	i:longint;
	s:int64;
Begin
	read(n);
	s:=0;
	for i:=1 to n do
		Begin
			read(A[i]);
			s:=s+a[i];
		End;
	m1:=s div n;
	if s mod n=0 then
		m2:=m1
	else
		m2:=m1+1;
End;
Function	find(i:longint):longint;
var	j:longint;
	tmp1,tmp2:longint;
Begin
	tmp1:=oo;
	tmp2:=-oo;
	for j:=i+1 to n do
		if a[j]>m1 then
			Begin
				tmp1:=j;
				break;
			End;
	for j:=i-1 downto 1 do
		if a[j]>m1 then
			Begin
				tmp2:=j;
				break;
			End;
	if tmp1-i>i-tmp2 then
		exit(tmp2);
	exit(tmp1);
End;
Function	find2(i:longint):longint;
var	j:longint;
	tmp1,tmp2:longint;
Begin
	tmp1:=oo;
	tmp2:=-oo;
	for j:=i+1 to n do
		if a[j]<m2 then
			Begin
				tmp1:=j;
				break;
			End;
	for j:=i-1 downto 1 do
		if a[j]<m2 then
			Begin
				tmp2:=j;
				break;
			End;
	if tmp1-i>i-tmp2 then
		exit(tmp2);
	exit(tmp1);
End;
Procedure	sub2;
var	i,j,tmp:longint;
	res:int64;
Begin
	res:=0;
	for i:=1 to n do
		while a[i]<m1 do
			Begin
				j:=find(i);
				tmp:=min(a[j]-m1,m1-a[i]);
				a[i]:=a[i]+tmp;
				a[j]:=a[j]-tmp;
				res:=res+tmp*abs(i-j);
			End;
	for i:=1 to n do
		while a[i]>m2 do
			Begin
				j:=find2(i);
				tmp:=min(a[i]-m2,m2-a[j]);
				a[j]:=a[j]+tmp;
				a[i]:=a[i]-tmp;
				res:=res+tmp*abs(i-j);
			End;
	writeln(Res);
End;
Procedure	main;
Begin
	assign(input,fi);reset(input);
	assign(output,fo);rewrite(output);
	enter;
	sub2;
	close(input);
	close(output);
End;
BEGIN
	main;
END.
