const fi='minsum.inp';
      fo='minsum.out';
var a,b,res,i,j,t:longint;
begin
  assign(input,fi);  reset(input);
  assign(output,fo); rewrite(output);
  read(t);
  for j:=1 to t do
  begin
    read(a,b);
    if a>b then res:=a else res:=b;
    for i:=1 to trunc(sqrt(res)) do if (a mod i=0) and (b mod i=0) then
    begin
        a:=a div i;
        b:=b div i;
    end;
    res:=a;
    for i:=2 to trunc(sqrt(res)) do
    begin
       if i<a then while a mod (i*i)=0 do a:=a div (i*i) else break;
    end;
    res:=b;
    for i:=2 to trunc(sqrt(res)) do
    begin
       if i<b then while b mod (i*i)=0 do b:=b div (i*i) else break;
    end;
    writeln(a,' ',b);
  end;
    close(input);  close(output);
end.
