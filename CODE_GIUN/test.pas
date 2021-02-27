uses math;
const fi='chiaqua.inp';
	  fo='chiaqua.out';
var f:text; N,i:Integer; kq:Int64; conghiem:Boolean;
	a,s:array[1..15] of Longint;

procedure ghinghiem;
var i:Integer; nho,lonnhat:longint; t1,t2,t3:int64;
begin
	t1:=0; t2:=0; t3:=0;
	for i:=1 to N do 
	begin
		if s[i]=1 then t1:=t1+a[i];
		if s[i]=2 then t2:=t2+a[i];
		if s[i]=3 then t3:=t3+a[i];
	end;
	if (t1<>0) and (t2<>0) and (t3<>0) then 
	begin  
		nho:=min(min(t1,t2),t3);
		lonnhat:=max(max(t1,t2),t3);
		if ((lonnhat - nho) < kq) then 
		begin 
			conghiem:=true; kq:= (lonnhat - nho);
		end;
	end;
end;

procedure chon(i:Integer);
var j:Integer;
begin
	for j:=1 to 3 do 
	begin
		s[i]:=j;
		if (i=n) then ghinghiem else chon(i+1);
	end;
end;

begin
	assign(f,fi); reset(f);
	readln(f,N);
	for i:=1 to N do read(f,A[i]);
	close(f);

	assign(f,fo); rewrite(f);
	conghiem:=false;
	fillbyte(s,sizeof(s),0);
	kq:=15000000000;
	chon(1);
	if conghiem=false then write(f,-1) else write(f,kq);
	close(f);
end.