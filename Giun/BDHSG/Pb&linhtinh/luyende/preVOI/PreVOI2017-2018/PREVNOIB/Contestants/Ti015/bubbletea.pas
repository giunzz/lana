uses math;
const oo=high(int64);
var ke,next,head,ts,f,a,free,x:array[-100000..100000] of longint;
    d:array[0..100000] of int64;
    dd:array[0..11,0..100000] of int64;
    ff:array[0..11,0..100000] of longint;
    res:int64;
    n,k:longint;
procedure add(i,u,v,c:longint);
begin
 ke[i]:=v;
 next[i]:=head[u];
 head[u]:=i;
 ts[i]:=c;
 ke[-i]:=u;
 next[-i]:=head[v];
 head[v]:=-i;
 ts[-i]:=c;
end;
procedure nhap;
var i,u,v,c:longint;
begin
 read(n,k);
 for i:=1 to k do read(a[i]);
 for i:=1 to n-1 do
  begin
   read(u,v,c);
   add(i,u,v,c);
  end;
 res:=oo;
end;
procedure DFS(u,p:longint);
var j,v:longint;
begin
 j:=head[u];
 while j<>0 do
  begin
   v:=ke[j];
   if v<>p then
    begin
     d[v]:=d[u]+ts[j];
     f[v]:=f[u]+1;
     DFS(v,u);
    end;
   j:=next[j];
  end;
end;
procedure xuli;
var i,j:longint;
begin
 for i:=1 to k do
  begin
   DFS(a[i],-1);
   for j:=1 to n do
    begin
     dd[i,j]:=d[j];
     d[j]:=0;
     ff[i,j]:=f[j];
     f[j]:=0;
    end;
  end;
end;
procedure inkq;
var i,j,tmp,tmp1,tg,tg1:longint; kq:int64;
begin
 i:=1;
 while i<=n do
  begin
   tmp:=a[x[i]];
   tmp1:=a[x[i+1]];
   j:=1;
   while j<=n do
    begin
     if j=i then
      begin
       j:=j+2;
       continue;
      end;
     tg:=a[x[j]];
     tg1:=a[x[j+1]];
     if ff[x[i],tg]=ff[x[i],tmp1]+ff[x[i+1],tg] then
      if ff[x[i],tg1]<>ff[x[i],tmp1]+ff[x[i+1],tg1] then exit;
     if ff[x[i+1],tg]=ff[x[i+1],tmp]+ff[x[i],tg] then
      if ff[x[i+1],tg1]<>Ff[x[i+1],tmp]+ff[x[i],tg1] then exit;

     if ff[x[i],tg1]=ff[x[i],tmp1]+ff[x[i+1],tg1] then
      if ff[x[i],tg]<>ff[x[i],tmp1]+ff[x[i+1],tg] then exit;
     if ff[x[i+1],tg1]=ff[x[i+1],tmp]+ff[x[i],tg1] then
      if ff[x[i+1],tg]<>Ff[x[i+1],tmp]+ff[x[i],tg] then exit;
     j:=j+2;
    end;
   i:=i+2;
  end;
 i:=1;
 kq:=0;
 while i<=n do
  begin
   kq:=max(kq,dd[x[i],a[x[i+1]]]);
   i:=i+2;
  end;
 res:=min(res,kq);
end;
procedure duyet(i:longint);
var j:longint;
begin
 if i=k+1 then inkq
 else
  for j:=1 to k do
   if free[j]=0 then
    begin
     x[i]:=j;
     free[j]:=1;
     duyet(i+1);
     free[j]:=0;
    end;
end;
begin
 assign(input,'bubbletea.inp');reset(input);
 assign(output,'bubbletea.out');rewrite(output);
 nhap;
 xuli;
 duyet(1);
 write(Res);
 close(input); close(output);
end.
