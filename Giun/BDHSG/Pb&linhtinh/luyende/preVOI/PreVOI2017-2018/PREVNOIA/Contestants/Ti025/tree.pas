uses	math;
const
	fi='TREE.inp';
	fo='TREE.out';
	maxn=30;
	oo=high(int64);
var	lt:Array[1..maxn,1..maxn] of longint;
	b,d,x,a:array[1..maxn] of longint;
	free:array[1..maxn] of boolean;
	s:Array[1..maxn] of int64;
	res:int64;
	n,m:longint;
Procedure	enter;
var	i,u,v:longint;
Begin
	read(n);
	fillchar(d,sizeof(d),0);
	fillchar(a,sizeof(a),0);
	for i:=1 to n do
		read(a[i]);
	for i:=1 to n-1 do
		Begin
			read(u,v);
			lt[u,v]:=1;
			inc(d[u]);
		End;
	m:=0;
	for i:=1 to n do
		if d[i]=0 then 
			Begin
				inc(m);
				b[m]:=i;
			End;
End;
Procedure	DFS(u:longint);
var	i:longint;
Begin
	free[u]:=false;
	for i:=1 to n do
		if free[i] and (lt[u,i]=1) then 
			Begin
				DFS(i);
				s[u]:=s[u]+s[i];
			End;
End;
Procedure	work;
var	i:longint;
	tmp:int64;
Begin
	for i:=1 to n do
		Begin
			free[i]:=true;
			s[i]:=0;
		End;
	for i:=1 to m do
		s[b[i]]:=x[i];
	DFS(1);
	tmp:=0;
	for i:=1 to n do
		tmp:=tmp+abs(a[i]-s[i]);
	res:=min(res,tmp);
End;
Procedure	try(i:longint);
var	j:longint;
Begin
	for j:=0 to 1 do
		Begin
			x[i]:=j;
			if i=m then
				work
			else
				try(i+1);
		End;
End;
Procedure	solve;
Begin
	res:=oo;
	try(1);
	if res=oo then 
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