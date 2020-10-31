type
   ptype=record
         x,y,z,r,l:longint;
      end;
const
   fi='teaworld.inp';
   fo='teaworld.out';
   nmax=20000;
var
   f:text;
   kq,n,m,k,nn:longint;
   p:array[1..nmax] of ptype;
procedure doc;
var
   i,x,y,z:longint;
begin
   assign(f,fi);reset(f);
   read(f,m,n,k);
   for i:=1 to m do
      begin
         inc(nn);
         read(f,p[i].x,p[i].y,p[i].z,p[i].r);
         p[i].l:=1;
      end;
   for i:=1 to n do
      begin
         inc(nn);
         read(f,p[nn].x,p[nn].y,p[nn].z,p[nn].r);
         p[nn].l:=2;
      end;

   read(f,x,y,z);
   inc(nn);
   p[nn].x:=x;p[nn].y:=y;p[nn].z:=z;p[nn].l:=3;
   close(f);
end;

procedure quicksort(l,r:longint);
var
   i,j,gi:longint;
   c:ptype;
begin
   i:=l;j:=r;
   gi:=p[(l+r) shr 1].x;
   repeat
      while p[i].x<gi do inc(i);
      while p[j].x>gi do dec(j);
      if i<=j then
         begin
            c:=p[i];p[i]:=p[j];p[j]:=c;
            inc(i);dec(j);
         end;
   until
      i>j;
   if l<j then quicksort(l,j);
   if i<r then quicksort(i,r);
end;

procedure xuli;
var
   i,slk,vtgs,i1:longint;
begin
   quicksort(1,nn);
   kq:=0;
   slk:=0;
   for i:=1 to nn do
      if p[i].l=3 then break;
   vtgs:=i;
   for i:=1 to nn do
      begin
         i1:=vtgs-i;
         if i1>0 then
         if p[i1].l=1 then
            if (slk<k) then inc(slk)
            else
         else
            kq:=kq+p[i1].r;

         i1:=vtgs+i;
         if i1<=nn then
         if p[i1].l=1 then
            if (slk<k) then inc(slk)
            else
         else
            kq:=kq+p[i1].r;
      end;
end;

procedure ghi;
begin
   assign(f,fi);rewrite(f);
   write(f,kq);
   close(f);
end;

begin
   doc;
   xuli;
   ghi;
end.
