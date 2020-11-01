uses	math;
const	
	fi='GIFTS.inp';
	fo='GIFTS.out';
	maxn=5000;
var	a:array[1..maxn] of longint;
	s:Array[0..maxn] of int64;
	n,k:longint;
Procedure	enter;
var	i:longint;
Begin
	read(n,k);
	for i:=1 to n do
		Begin
			read(a[i]);
			s[i]:=s[i-1]+a[i];
		End;
End;
Function	check(x:longint):boolean;
var	i:longint;
	save:longint;
Begin
	save:=0;
	for i:=1 to n-k+1 do
		if s[i+k-1]-s[i-1]>x then 
			Begin
				save:=i;
				break;
			End;
	for i:=save to n-k+1 do
		if s[i+k-1]-s[i-1]>x then 
			if i>save then
				exit(false);
	exit(true);
End;
Procedure	solve;
var	l,r:longint;
	mid:longint;
	res:longint;
Begin
	res:=trunc(1e9);
	l:=1;r:=trunc(1e9);
	while l<=r do
		Begin
			mid:=(l+r) div 2;
			if check(mid) then 
				Begin
					res:=min(res,mid);
					r:=mid-1;
				End
			else
				l:=mid+1;
		End;
	if res=trunc(1e9) then
		writeln(0)
	else
		writeln(res);
End;
Procedure	main;
Begin  
	assign(input,fi);reset(input);
	assign(output,fo);rewrite(output);
	enter;		
	solve;
	close(input);
	close(output);
End;
BEGIN
	main;
END.