const fi='minsum.inp';
      fo='minsum.out';
var o,t,a,b,x,y,i,vtx:longint;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
read(t);
for o:=1 to t do
    begin
    read(a,b);
    x:=a;
    y:=b;
    while x<>y do
          begin
          if x>y then x:=x mod y
          else y:=y mod x;
          if x=0 then x:=y;
          if y=0 then y:=x;
          end;
    a:=a div x;
    b:=b div x;
    for i:=trunc(sqrt(a)) downto 2 do
        begin
        x:=sqr(i);
        while a mod x=0 do a:=a div x;
        end;
    for i:=trunc(sqrt(b)) downto 2 do
        begin
        x:=sqr(i);
        while b mod x=0 do b:=b div x;
        end;
    if a>b then
       begin
       x:=a;
       vtx:=1;
       y:=b;
       end
    else
       begin
       x:=b;
       vtx:=2;
       y:=a;
       end;
    if (x mod 2=0) and (x div 2>y) then
       begin
       x:=x div 2;
       y:=y*2;
       if x<y then
          begin
          t:=x;
          x:=y;
          y:=t;
          if vtx=1 then vtx:=2
          else vtx:=1;
          end;
       end;
    if (x mod 3=0) and (x div 3>y) then
       begin
       x:=x div 3;
       y:=y*3;
       if x<y then
          begin
          t:=x;
          x:=y;
          y:=t;
          if vtx=1 then vtx:=2
          else vtx:=1;
          end;
       end;
    if (x mod 5=0) and (x div 5>y) then
       begin
       x:=x div 5;
       y:=y*5;
       if x<y then
          begin
          t:=x;
          x:=y;
          y:=t;
          if vtx=1 then vtx:=2
          else vtx:=1;
          end;
       end;
    if (x mod 7=0) and (x div 7>y) then
       begin
       x:=x div 7;
       y:=y*7;
       if x<y then
          begin
          t:=x;
          x:=y;
          y:=t;
          if vtx=1 then vtx:=2
          else vtx:=1;
          end;
       end;
    if vtx=1 then
       begin
       a:=x;
       b:=y;
       end
    else
       begin
       b:=x;
       a:=y;
       end;
    while x<>y do
          begin
          if x>y then x:=x mod y
          else y:=y mod x;
          if x=0 then x:=y;
          if y=0 then y:=x;
          end;
    a:=a div x;
    b:=b div x;
    writeln(a,' ',b);
    end;
close(input);
close(output);
end.
