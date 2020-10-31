uses math;
const
   fi='bubbletea.inp';
   fo='bubbletea.out';
   nmax=50010;
   mmax=2*nmax;
var
   f:text;
   kq,n,k,m:longint;
   sl,trc,d,gl,head:array[1..nmax] of longint;
   link:array[1..mmax] of longint;
   e:array[1..mmax] of record
          x,y,w:longint;
      end;

   dd:array[1..mmax] of boolean;
   hang:array[1..nmax,1..2] of longint;
procedure doc;
var
   i:longint;
begin
   assign(f,fi);reset(f);
   read(f,n,k);
   for i:=1 to k do read(f,gl[i]);

   m:=n-1;
   for i:=1 to n-1 do
      begin
         read(f,e[i].x,e[i].y,e[i].w);
         e[2*m-i+1].x:=e[i].y;
         e[2*m-i+1].y:=e[i].x;
         e[2*m-i+1].w:=e[i].w;
      end;
   m:=m*2;
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
end;

procedure dfs(u:longint);
var
   i:longint;
begin
   i:=head[u];
   while i<>0 do
      begin
         if dd[i] then
         if d[e[i].y]=0 then
            begin
               d[e[i].y]:=d[u]+e[i].w;
               trc[e[i].y]:=i;
               dfs(e[i].y);

            end;
         i:=link[i];
      end;
end;

procedure truynguoc(u,v:longint);
var
   i,j,canh:longint;
begin
   i:=v;
   while i<>u do
      begin
         canh:=trc[i];
         dd[canh]:=false;
         dd[m-canh+1]:=false;
         i:=e[canh].x;
      end;
end;

procedure ktra;
var
   i,j,kq1:longint;
begin
   kq1:=0;
   for i:=1 to m do dd[i]:=true;
   for i:=1 to k div 2 do
      begin
         for j:=1 to n do d[j]:=0;
         d[hang[i,1]]:=1;
         dfs(hang[i,1]);
         if d[hang[i,2]]=0 then exit;
         kq1:=max(kq1,d[hang[i,2]]);
         truynguoc(hang[i,1],hang[i,2]);
      end;
   kq:=min(kq,kq1);
end;

procedure try(u:longint);
var
   i:longint;
begin
   if u>k then ktra
   else
   for i:=1 to k div 2 do
      if sl[i]<2 then
         begin
            inc(sl[i]);
            hang[i,sl[i]]:=gl[u];
            try(u+1);
            dec(sl[i]);
         end;
end;

procedure sub1;
var
   i:longint;
begin
   kq:=maxlongint;
   for i:=1 to k div 2 do sl[i]:=0;
   try(1);
end;

procedure xuli;
var
   i:longint;
begin
   kq:=maxlongint;
end;

procedure ghi;
var
   i:longint;
begin
   assign(f,fo);rewrite(f);
   if kq=maxlongint then write(f,-1) else write(f,kq-1);
   close(F);
end;

begin
   doc;
   init;
   if k<=10 then sub1
   else
      xuli;
   ghi;
end.
