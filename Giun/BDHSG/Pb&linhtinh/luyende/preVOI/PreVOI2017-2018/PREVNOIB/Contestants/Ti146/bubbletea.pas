const fi='bubbletea.inp';
      fo='bubbletea.out';
      oo=2147483646;
type mang=array[0..50000]of longint;
     mang3=array[0..50000,0..100]of longint;
     mang4=array[0..50000]of boolean;
var f:text;
    ke,gtke:mang3;
    d:mang;
    nap:mang4;
    a:mang;
    n,k,i,j,m:longint;
procedure doc;
var x,y,gt:longint;
begin
 assign(f,fi);
 reset(f);
 readln(f,n,k);
  for i:=1 to k do
   read(f,a[i]);
  for i:=1 to n -1 do
   begin
    readln(f,x,y,gt);
     inc(ke[x,0]);ke[x,ke[x,0]]:=y;gtke[x,ke[x,0]]:=gt;
     inc(ke[y,0]);ke[y,ke[y,0]]:=x;gtke[y,ke[x,0]]:=gt;
   end;
 close(f);
end;
procedure xuli;
var max,maxt,dd,i:longint;   kt:boolean;
begin
 assign(f,fo);rewrite(f); maxt:=oo;
  for j:=1 to k do
   begin
     dd:=a[j];
     for i:=0 to n do d[i]:=oo;
     for i:=1 to ke[dd,0] do d[ke[dd,i]]:=gtke[dd,i];
     fillchar(nap,sizeof(nap),true); kt:=true;    nap[dd]:=false;   d[dd]:=0;
      while kt=true do
       begin
          for i:=1 to ke[dd,0] do
           if (d[ke[dd,i]]>d[dd]+gtke[dd,i]) and (nap[ke[dd,i]]=true) then
            d[ke[dd,i]]:=d[dd]+gtke[dd,i];
            dd:=0;kt:=false;
           for i:=1 to n do
            if (d[dd]>d[i]) and (nap[i]=true) then begin dd:=i;kt:=true;end;
             nap[dd]:=false;
       end;
      max:=d[1];
      for i:=1 to n do
       if (max<d[i]) then max:=d[i];
       if max<maxt then maxt:=max;
  end;
 writeln(f,maxt);
 close(f);
end;
begin
 doc;
 xuli;
end.






