program MangDep;
uses Crt;
var n,i,v,max,z,r: longint;
    f    : text;
    A,Q    : array[1..1000]of longint;
const fi='MANGDEP.INP';
      fo='MANGDEP.OUP';

Begin
 Q[1]:=4;Q[2]:=8;Q[3]:=15;Q[4]:=16;Q[5]:=23;Q[6]:=42;v:=1;
 assign(f,fi);
 reset(f);
 readln(f,n);
 for i:=1 to n do read(f,A[i]);
 close(f);
////////////////////////////////////
 assign(f,fo);
 rewrite(f);
 for r:=1 to 1000 do begin
  for i:=1 to n do Begin
    if A[i]=Q[v] then Begin inc(z);inc(v);A[i]:=0 end;
    if z=6 then Begin z:=0;v:=1;inc(max) end;
  End;  end;
  write(f,n-(max*6));
  close(f);
End.