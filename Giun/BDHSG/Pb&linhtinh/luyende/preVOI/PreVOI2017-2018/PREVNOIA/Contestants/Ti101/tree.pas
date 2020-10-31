uses math;
const
   fi='tree.inp';
   fo='tree.out';
   nmax=5010;
var
   f:text;
   kq,stp,n,m:longint;
   gtmax,a,head,slc,tp,topo:array[1..nmax] of longint;
   e:array[1..2*nmax] of record
          x,y:longint;
      end;
   link:array[1..2*nmax] of longint;
   cx:array[1..nmax] of boolean;
   con:array[1..nmax,1..2] of longint;
   q:array[0..nmax,0..nmax] of longint;

procedure doc;
var
   i:longint;
begin
   assign(f,fi);reset(f);
   read(f,n);
   for i:=1 to n do read(f,a[i]);
   m:=(n-1)*2;
   for i:=1 to n-1 do
      begin
         read(f,e[i].x,e[i].y);
         e[m-i+1].x:=e[i].y;
         e[m-i+1].y:=e[i].x;
      end;
   close(f);
end;

procedure init;
var
   i:longint;
begin
   for i:=1 to n do head[i]:=0;
   for i:=1 to m do
      begin
         link[i]:=head[e[i].x];
         head[e[i].x]:=i;
      end;

   for i:=1 to n do
      begin
         cx[i]:=true;
         slc[i]:=0;
         gtmax[i]:=0;
      end;

end;

procedure dfsdc(u:longint);
var
   i:longint;
begin
   cx[u]:=false;
   i:=head[u];
   while i<>0 do
      begin
         if cx[e[i].y] then
            begin
               inc(slc[u]);
               con[u,slc[u]]:=e[i].y;
               dfsdc(e[i].y);
            end;
         i:=link[i];
      end;
end;

procedure dfstp(u:longint);
var
   i:longint;
begin
   for i:=1 to slc[u] do
      dfstp(con[u,i]);

   tp[u]:=stp;
   topo[stp]:=u;

   dec(stp);
end;

procedure xuli;
var
   i,j,nut,j1:longint;
begin
   dfsdc(1);

   stp:=n;
   dfstp(1);

   for i:=n downto 1 do
      begin
         nut:=topo[i];
         if slc[nut]=0 then gtmax[nut]:=1
         else
            gtmax[nut]:=gtmax[con[nut,1]]+gtmax[con[nut,2]];
      end;

   for i:=1 to n do
      for j:=0 to gtmax[i] do q[i,j]:=1000000000;

   for i:=n downto 1 do
      begin
         nut:=topo[i];
         if slc[nut]=0 then
            begin
               q[nut,0]:=a[nut];
               q[nut,1]:=abs(a[nut]-1);
            end
         else
            begin
               for j:=0 to gtmax[nut] do
                  for j1:=0 to min(j,gtmax[con[nut,1]]) do
                     if j-j1<=gtmax[con[nut,2]] then
                     q[nut,j]:=min(q[nut,j],q[con[nut,1],j1]+q[con[nut,2],j-j1]+abs(a[nut]-j));
            end;
      end;

   kq:=maxlongint;
   for i:=0 to gtmax[1] do
      kq:=min(kq,q[1,i]);
end;

procedure ghi;
var
   i:longint;
begin
   assign(f,fo);rewrite(f);
   write(f,kq);
   close(f);
end;

begin
   doc;
   init;
   xuli;
   ghi;
end.
