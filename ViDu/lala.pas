const pa = '';
Var A,B,C:string;
dau1, dau2,dau:char;
function Tong(A,B:string):string;
var C:string;
	n,i,nho:integer;
begin
	n:=length(A);
	C:='';
	for i:=1 to n do C:= C + '0';
	nho:=0;
	for i:=n downto 1 do 
	begin
		c[i]:= chr(48 + (nho + (ord(A[i])-48) + (ord(B[i])-48)) mod 10);
		nho:= (nho + (ord(A[i])-48) + (ord(B[i])-48)) div 10;
	end;
	exit(C);
end;
function Hieu(A,B:string):string;
var C:string;
	n,i,nho,x,y,z:integer;
begin
	n:=length(A);
	C:='';
	for i:=1 to n do C:= C + '0';
	nho:=0;
	for i:=n downto 1 do 
	begin
		x:= ord(A[i])-48;
		y:= ord(B[i])-48;
		if (x < (y + nho)) then
		begin
			z:= x+10 - (y + nho);
			C[i]:= chr(z + 48);
			nho:=1;
		end 
		else 
		begin
			z:= x-(y + nho);
			C[i]:= chr(z + 48);
			nho:=0;
		end;
	end;
	exit(C);
end;
begin
	assign(input, pa +'TINHTONG.INP'); reset(input);
	assign(output, pa +'TINHTONG.OUT'); rewrite(output);
	readln(input, A);
	readln(input, B);
	if A[1]='-' then 
	begin
		dau1:= '-';
		A:=copy(A,2,length(A)-1); // dịch dòng này cho tui 
	end
	else dau1:='0';
	if B[1]='-' then 
	begin
		dau2:= '-';
		B:=copy(B,2,length(B)-1);
	end
	else dau2:='0';
	while (length(A)<>length(B)) do
		if length(A) < length(B) then A:='0'+A
		else B:='0'+B;
	A:='0'+A; B:='0'+B;
	if dau1 = dau2 then
	begin
		dau:=dau1;
		C:=Tong(A,B);
	end
	else 
	begin
		if A=B then 
		begin
			C:='0';
			dau:='0';
		end
		else if A>B then
		begin
			C:=Hieu(A,B);
			dau:=dau1;
		end 
		else begin
			C:=Hieu(B,A);
			dau:=dau2;
		end;
	end;
	while (C[1]='0') and (length(C)>1) do delete(C,1,1);
	if dau='-' then write(output,dau,C)
	else write(output,C);
	close(input);
	close(output);
end.