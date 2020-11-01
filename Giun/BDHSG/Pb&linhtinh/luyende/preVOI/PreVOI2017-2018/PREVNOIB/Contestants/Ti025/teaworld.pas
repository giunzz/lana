uses	math;
const
	fi='TEAWORLD.inp';
	fo='TEAWORLD.out';
	maxn=15;
	maxm=2000;
type	logs=record
	x,y,z,w,r:longint;
end;
var	ball:array[0..maxm+1] of logs;
	tea:array[1..maxn] of logs;
	sum:array[1..maxm] of longint;
	m,n,k:longint;
	s:logs;
	start:longint;
Function	check(a,b:logs):boolean;
Begin
	if a.x*a.r<b.x*b.r then exit(true);
	exit(false);
End;
Procedure	sort(l,r:longint);
var	i,j:longint;
	tmp,mid:logs;
Begin
	i:=l;j:=r;
	mid:=ball[(l+r) div 2];
	repeat
		while check(ball[i],mid) do inc(i);
		while check(mid,ball[j]) do dec(j);
		if i<=j then
			Begin
				tmp:=ball[i];
				ball[i]:=ball[j];
				ball[j]:=tmp;
				inc(i);
				dec(j);
			End;
	until i>j;
	if i<r then sort(i,r);
	if l<j then sort(l,j);
End;
Procedure	enter;
var	i:longint;
Begin
	read(m,n,k);
	for i:=1 to m do
		with(ball[i]) do
			read(x,y,z,r);
	sort(1,m);
	ball[0].x:=-501;
	ball[m+1].x:=501;
	for i:=1 to n do
		with(tea[i]) do
			read(x,y,z,w);
	read(s.x,s.y,s.z);
	for i:=1 to m do
		if ball[i].x>s.x then
			Begin
				start:=i;
				break
			End;
End;
Procedure	sub1;
var	i,j:longint;
	res:longint;
Begin
	for i:=start-1 downto 1 do
		for j:=1 to n do
			if tea[j].x<s.x then
				if tea[j].x>ball[i-1].x-ball[i-1].r then
					sum[i]:=sum[i]+tea[j].w;
	for i:=start to n do
		for j:=1 to n do
			if tea[j].x>=s.x then
				if tea[j].x<ball[i+1].x-ball[i+1].r then
					sum[i]:=sum[i]+tea[j].w;
	res:=0;
	for i:=start to min(m,start+k-1) do
		res:=max(res,sum[i]+sum[i-max(k-i,1)]);
	writeln(Res);
End;
Procedure	main;
Begin
	assign(input,fi);reset(input);
	assign(output,fo);rewrite(output);
	enter;
	sub1;
	close(input);
	close(output);
End;
BEGIN
	main;
END.
