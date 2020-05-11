// Vector nghiệm X[1] .. X[2*n]
// Tập ứng cử viên	A = {'(' , ')'};
//		const A:Array[1..2] of char =('(',')');
// Điều kiện: X thỏa đk là xâu dấu ngoặc của bt toán học

const A:Array[1..2] of char =('(',')');
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
end.