uses	math;
const
	fi='MINSUM.inp';
	fo='MINSUM.out';
	maxn=500000;
type	logs=record
	a,b:longint;
End;
var	p,nt:array[1..maxn] of longint;
	d:Array[1..maxn] of logs;
	m:longint;
Procedure sang(n:longint);
var		i:longint;
		j:qword	;
Begin
	for i:=2 to n do
			p[i]:=i;
	for i:=2 to trunc(sqrt(n)) do
		if p[i]=i then
			Begin
				j:=i*i;
				inc(m);
				nt[m]:=i;
				while (j<=n) do
					Begin
						p[j]:=i;
						j:=j+i;
					End;
			End;
End;
Function	mul(a,b:longint):longint;
var	tmp:longint;
Begin
	if b=1 then exit(a);
	tmp:=mul(a,b div 2);
	if b div 2 =0 then
		exit(tmp);
	exit(tmp*a);
End;
Procedure	solve(x,y:longint);
var	i,j,cnt,tmp:longint;
Begin
	for i:=1 to m do
		Begin
			d[i].a:=0;
			d[i].b:=0;
		End;
	tmp:=x;
	i:=1;
	while (tmp<>1) and (i<=m) do
		Begin	
			while (tmp mod nt[i] <>0)  do
				inc(i);
			inc(d[i].a);
			tmp:=tmp div nt[i];
		End;
	tmp:=y;
	i:=1;
	while (tmp<>1) and (i<=m) do
		Begin	
			while tmp mod nt[i] <>0 do
				inc(i);
			inc(d[i].b);
			tmp:=tmp div nt[i];
		End;
	for i:=1 to m do
		Begin
			tmp:=0;
			tmp:=min(d[i].a,d[i].b);
			if tmp<>0 then 
				Begin
					x:=x div(tmp*nt[i]);
					y:=y div(tmp*nt[i]);
					d[i].a:=d[i].a-tmp;
					d[i].b:=d[i].b-tmp;
				End;
		End;
	for i:=1 to m do
		if d[i].a<>0 then
			Begin
				cnt:=1;
				for j:=1 to d[i].a do
					Begin
						tmp:=0;
						tmp:=(y*nt[i]*cnt)+(x div (cnt*nt[i]));
						if tmp<x+y then
							inc(cnt)
						else
							break;
					End;
				if cnt>1 then
					Begin 
						d[i].a:=d[i].a-(cnt-1);
						d[i].b:=d[i].b+(cnt-1);
						x:=x div (mul(nt[i],cnt));
						y:=y*mul(nt[i],cnt);
					End;
			End;
	for i:=1 to m do
		if d[i].b<>0 then
			Begin
				cnt:=1;
				for j:=1 to d[i].b do
					Begin
						tmp:=0;
						tmp:=(x*nt[i]*cnt)+(y div (cnt*nt[i]));
						if tmp<x+y then
							inc(cnt)
						else
							break;
					End;
				if cnt>1 then
					Begin 
						d[i].b:=d[i].b-(cnt-1);
						d[i].a:=d[i].a+(cnt-1);
						y:=y div (mul(nt[i],cnt));
						x:=x*mul(nt[i],cnt);
					End;
			End;
	writeln(x,' ',y);
End;
Procedure	enter;
var	i,x,y:longint;
	t:longint;
Begin
	read(t);
	for i:=1 to t do
		Begin
			read(x,y);
			solve(x,y);
		End;
End;
Procedure	main;
Begin  
	assign(input,fi);reset(input);
	assign(output,fo);rewrite(output);
	sang(maxn);
	enter;
	close(input);
	close(output);
End;
BEGIN
	main;
END.