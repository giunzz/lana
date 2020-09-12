const 	fi='giun.inp';
		fo='giun.out';
var t,l,r,m,n,ans:longint;
	A:array[1..1000000] of longint;
	
procedure timlongchao(k:longint);
begin
	l:=k;
	r:=k;
	m:=k;
	while (l-1>=1) and A[l]<A[l-1] do l:=l-1;
	while (r+1<=n) and A[r]<A[r+1] do r:=r+1;
	for m:=l+1 to r-1 do 
		if A[m]<A[m-1] and A[m]<A[m+1] then break;
end;
BEGIN
	assign(input,fi); reset(input);
	assign(output,fo); rewrite(output);
	readln(input,n);
	r:=0;
	ans:=0;
	for i:=1 to n do read(input,A[i]);
	while r<n do
	begin
		timlongchao(r+1);
		t:=(A[r]-A[m]) - (A[l]-A[m]);
		if t<0 then t:=0;
		ans:=ans + t;
	end;
	write(output,ans);
	close(input); 
	close(output);
END.