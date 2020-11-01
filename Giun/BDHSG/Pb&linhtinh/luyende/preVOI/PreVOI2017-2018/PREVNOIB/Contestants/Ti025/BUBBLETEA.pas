uses	math;
const
	fi='BUBBLETEA.inp';
	fo='BUBBLETEA.out';
	maxn=5000;
	oo=high(longint);
var	a:Array[1..maxn,1..maxn] of longint;
	b,x,sum:Array[1..maxn] of longint;
	free:Array[1..maxn] of boolean;
	d1,d:array[1..maxn] of longint;
	kt:boolean;
	n,k,res,m:longint;
Procedure	enter;
var	i:longint;
	u,v,l:longint;
Begin
	read(n,k);
	for i:=1 to k do
		read(b[k]);
	for i:=1 to n-1 do
		Begin
			read(u,v,l);
			inc(d1[u]);
			inc(d1[v]);
			a[u,v]:=l;
			a[v,u]:=l;
		End;
	for i:=1 to n do
		d1[i]:=d1[i] div 2;
End;
Procedure	DFS(u,j:longint);
var	v:longint;
Begin
	free[u]:=false;
	for v:=1 to n do
		if kt and (a[u,v]<>0) and (free[v]) and (d[v]<=d1[v]) then
			Begin
					sum[v]:=sum[u]+a[u,v];
					inc(d1[v]);
					if v=j then 
						kt:=false;
					DFS(v,j);
					dec(d1[v]);
			End;
End;
Procedure	work;
var	i,j:longint;
	tmp:longint;
Begin
	tmp:=0;
	kt:=true;
	for i:=1 to n do
		d[i]:=0;
	for i:=1 to k do
		Begin
			for j:=1 to n do
				Begin
					free[j]:=true;
					sum[i]:=0;
				End;
			for j:=1 to n do
				if (b[i]<>j) and (x[i]=x[j]) then 
					Begin
						DFS(b[i],j);
						if sum[j]=0 then 
							exit;
						tmp:=max(tmp,sum[j]);
					End;
		End;
	res:=min(res,tmp);
End;
Procedure	try(i:longint);
var	j:longint;
Begin
	for j:=1 to 3 do
		if d[j]<2 then
			Begin
				x[i]:=j;
				inc(d[j]);
				if i=k then 
					work
				else
					try(i+1);
				dec(d[j]);
			End;
End;
Procedure	solve;
var	i:longint;
Begin
	m:=k div 2;
	for i:=1 to m do
		d[m]:=0;
	res:=oo;
	try(1);
	{if res<>oo then
		writeln(res)
	else}
		writeln(-1);
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