const fi='MINSUM.inp';
      fo='MINSUM.out';
var s,sl:array[1..1000000] of longint;
Function uc(x,y:longint):longint;
var t:longint;
   begin
   if x mod y=0 then exit(y);
   if y mod x=0 then exit(x);
   While y>0 do
      begin
      t:=x mod y;
      x:=y;
      y:=t;
      End;
   exit(x);
   End;
Procedure main;
var t,l,i,cs,x,a,b,tg:longint;
   begin
   assign(input,fi); reset(input);
   assign(output,fo); rewrite(output);
   readln(t);
   For l:=1 to t do
      begin
      readln(a,b);
      tg:=uc(a,b);
      a:=a div tg; b:=b div tg;
      x:=a; i:=2; cs:=0;
      While x>2 do
         begin
         tg:=trunc(sqrt(x));
         While (x mod i<>0)and(i<tg) do inc(i);
         if x mod i<>0 then break;
         inc(cs); s[cs]:=i; sl[cs]:=0;
         While x mod i=0 do begin inc(sl[cs]); x:=x div i; End;
         inc(i);
         End;
      For i:=1 to cs do
      if sl[i]>1 then
        begin
        if sl[i] mod 2=1 then dec(sl[i]);
        While sl[i]>0 do begin a:=a div s[i]; dec(sl[i]); End;
        End;
      x:=b; i:=2; cs:=0;
      While x>2 do
         begin
         tg:=trunc(sqrt(x));
         While (x mod i<>0)and(i<tg) do inc(i);
         if x mod i<>0 then break;
         inc(cs); s[cs]:=i; sl[cs]:=0;
         While x mod i=0 do begin inc(sl[cs]); x:=x div i; End;
         inc(i);
         End;
      For i:=1 to cs do
      if sl[i]>1 then
        begin
        if sl[i] mod 2=1 then dec(sl[i]);
        While sl[i]>0 do begin b:=b div s[i]; dec(sl[i]); End;
        End;
      writeln(a,' ',b);
      End;
   close(input);
   close(output);
   End;
Begin
main;
End.
