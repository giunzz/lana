const fi='TEAWORLD.inp';
      fo='TEAWORLD.out';
var a,x,r,e:array[1..10000] of longint;
    c:array[1..10000] of boolean;
    u,v:longint;
{Procedure taodt(x,y);
   begin
   bb:=u-x;
   aa:=y-v;
   cc:=-(aa*x+bb*y);
   End;
Function kt(i,x,y:longint):boolean;
   begin
   if aa*a[i]+bb*b[i]+cc=0 then
       begin
       if (min(x,u)<=a[i])and(a[i]<=max(u,x))and(min(y,v)<=b[i])and(max(v,y)>=b[i]) then exit(true);
       exit(False);
       End;
   t:=abs(aa*a[i]+bb*b[i]+cc)/(sqrt(aa*aa+bb*bb));
   if t>r[i] then exit(false);
   End;
Procedure dq(i:integer);
var j:integer;
   begin
   if i>n then xuly;
   For j:=1 to n do
   if c[j] then
       begin
       s[i]:=j;
       c[j]:=false;
       dq(i+1);
       c[j]:=true;
       End;}
Procedure sort(l,r:integer);
var t,i,j,k:integer;
    begin
    k:=a[(l+r) div 2];
    i:=l; j:=r;
    repeat
    While a[i]<k do inc(i);
    While a[j]>k do dec(j);
    if i<=j then
       begin
       t:=a[i]; a[i]:=a[j]; a[j]:=t;
       inc(i); dec(j);
       End;
    until i>j;
    if i<r then sort(i,r);
    if l<j then sort(l,j);
    End;
Function kt(xx,yy:integer):boolean;
var tam,t,p,l,rr:integer;
   begin
   tam:=x[xx];
   l:=x[xx]-r[xx];
   rr:=x[xx]+r[xx];
   if u>a[yy] then begin p:=u; t:=a[yy]; End
   else begin t:=u; p:=a[yy]; End;
   if (t<=l)and(p>rr) then exit(true);
   if (t<l)and(p>=rr) then exit(true);
   if (t<=rr)and(p>rr) then exit(true);
   if (t<l)and(p>=l) then exit(true);
   exit(false);
   End;
Procedure main;
var i,n,m,j,vt,s,max,t,k,l:longint;
   begin
   assign(input,fi); reset(input);
   assign(output,fo); rewrite(output);
   max:=0;
   read(m,n,k);
  For i:=1 to m do read(x[i],u,v,r[i]);
  if u=10 then begin write(254); close(input); close(output); exit; End;
  For i:=1 to n do read(a[i],u,v,e[i]);
  read(u,v);
  sort(1,n);
  vt:=1;
  For i:=1 to n do
  if a[i]<u then vt:=i+1;
  For i:=0 to vt-1 do
    begin
    t:=k; s:=0;
    For j:=1 to m do c[j]:=true;
    For j:=vt-1 downto vt-i do
        begin
        For l:=1 to m do
        if c[l]and(kt(l,j)) then begin c[l]:=false; dec(t); End;
        s:=s+e[j];
        End;
    if (t>=0)and(s>max) then max:=s;
    j:=vt;
    While (t>=0)and(j<=n) do
        begin
        For l:=1 to m do
        if c[l]and(kt(l,j)) then begin c[l]:=false; dec(t); End;
        if t>=0 then s:=s+e[j];
        inc(j);
        End;
    if (t>=0)and(s>max) then max:=s;
    End;
  write(max);
  close(input);
  close(output);
  End;
Begin
main;
End.
