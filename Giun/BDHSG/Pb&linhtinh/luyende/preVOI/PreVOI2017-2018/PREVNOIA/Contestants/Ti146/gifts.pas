const fi='gifts.inp';
      fo='gifts.out';
      oo=2147483646;
type mang=array[0..100000]of longint;
var f:text;
    a,l:mang;
    i,j,n,k,m:longint;
procedure doc;
begin
 assign(f,fi);
 reset(f);
  readln(f,n,k);
  fillchar(l,sizeof(l),0);
  for i:=1 to n do
   begin
     read(f,a[i]);
     if i<k then l[i]:=l[i-1]+a[i]
     else
     l[i]:=l[i-1]-a[i-k]+a[i];
   end;
 close(f);
end;

procedure sub12;
var max1,max:longint; kt:boolean;
begin
 max:=oo;
 for i:=k to n do
  begin
   max1:=l[i]; kt:=true;
   for j:=k to n do
    if abs(i-j)>=k then
     if (max1<l[j]) then begin kt:=false;break;end;
    if kt=true then
   if (max1<max) then max:=max1;
  end;

writeln(f,max);
end;
procedure xuli;
var min,max:longint;
begin
 assign(f,fo);
 rewrite(f);
   sub12;
 close(f);
end;
begin
 doc;
 xuli
end.
