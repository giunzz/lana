uses math;
const fi='teaworld.inp';
      fo='teaworld.out';
var x,y,z,t,bd,kt:array[1..1000000] of longint;
    m,n,i,i1,j,dem,a,b,c,kq,d,k,sb,sl,o:longint;
    ok:boolean;

procedure qs(l,r:longint);
var i,j,tg,m:longint;
begin
if l>=r then exit;
i:=l;
j:=r;
m:=x[(l+r) div 2];
repeat
      begin
      while m>x[i] do i:=i+1;
      while m<x[j] do j:=j-1;
      if i<=j then
         begin
         tg:=x[i];
         x[i]:=x[j];
         x[j]:=tg;
         tg:=bd[i];
         bd[i]:=bd[j];
         bd[j]:=tg;
         tg:=kt[i];
         kt[i]:=kt[j];
         kt[j]:=tg;
         tg:=t[i];
         t[i]:=t[j];
         t[j]:=tg;
         i:=i+1;
         j:=j-1;
         end;
      end;
until i>j;
qs(l,j);
qs(i,r);
end;

function bsl(i:longint):longint;
var l,r,mid:longint;
begin
l:=1;
r:=m;
bsl:=0;
while l<=r do
      begin
      mid:=(l+r) div 2;
      if x[mid]>=i then r:=m-1
      else
         begin
         bsl:=mid;
         l:=mid+1;
         end;
      end;
end;

begin

assign(input,fi);
reset(input);
assign(output,fo);
rewrite(output);
readln(m,n,k);
ok:=true;
for i:=1 to m+n do
    begin
    read(x[i],y[i],z[i],t[i]);
    if (y[i]<>0) or (z[i]<>0) then ok:=false;
    end;
read(a,b,c);
if ok then
   begin
   for i:=1 to m do
       begin
       bd[i]:=x[i]-t[i];
       kt[i]:=x[i]+t[i];
       end;
   qs(1,m);
   d:=bsl(a);
   kq:=0;
   for i:=0 to min(d,k) do
       begin
       i1:=k-i;
       dem:=0;
       for j:=m+1 to m+n do
           begin
           ok:=true;
           sb:=min(x[j],a);
           sl:=max(x[j],a);
           for o:=d-i downto 1 do
               if (((bd[o]>=sb) and (bd[o]<=sl)) or ((kt[o]>=sb) and (kt[o]<=sl))) and ((bd[o]<>sb) or (kt[o]<>sl)) then
                  begin
                  ok:=false;
                  break;
                  end;
           for o:=d+i1+1 to m do
               if (((bd[o]>=sb) and (bd[o]<=sl)) or ((kt[o]>=sb) and (kt[o]<=sl))) and ((bd[o]<>sb) or (kt[o]<>sl)) then
                  begin
                  ok:=false;
                  break;
                  end;
           if ok then dem:=dem+t[j];
           end;
       kq:=max(kq,dem);
       end;
   write(kq);
   end;
close(input);
close(output);
end.
