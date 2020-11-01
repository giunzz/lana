uses math;
const oo=maxlongint;
var ke,next,head,a,cha,deg:array[-5000..5000] of longint;
    f:array[0..500,0..500] of longint;
    n,res:longint;
procedure add(i,u,v:longint);
begin
 ke[i]:=v;
 next[i]:=head[u];
 head[u]:=i;
 ke[-i]:=u;
 next[-i]:=head[v];
 head[v]:=-i;
end;
procedure nhap;
var  i,u,v :longint;
begin
 read(n);
 for i:=1 to n do read(A[i]);
 for i:=1 to n-1 do
  begin
   read(u,v);
   cha[v]:=u;
   inc(Deg[u]); inc(DEg[v]);
   add(i,u,v);
  end;
end;
procedure DFS(u:longint);
var j,v,i,dem:longint;
    b:array[0..2] of longint;
begin
 if (deg[u]=1) and (u<>1) then
  begin
   f[u,a[u]]:=0;
   f[u,1-a[u]]:=1;
  end;
 j:=head[u];  dem:=0;
 while j<>0 do
  begin
   v:=ke[j];
   if v<>cha[u] then
    begin
     inc(Dem); b[dem]:=v;
     DFS(V);
    end;
   j:=next[j];
  end;
 if dem=1 then
   for i:=0 to 400 do
    if f[b[1],i]<>oo then f[u,i]:=f[b[1],i]+abs(a[u]-i);
 if dem=2 then
  for i:=0 to 400 do
   if f[b[1],i]<>oo then
    for j:=0 to 400 do
     if f[b[2],j]<>oo then f[u,i+j]:=min(f[u,i+j],f[b[1],i]+f[b[2],j]+abs(A[u]-i-j));
end;
procedure xuli;
var i,j:longint;
begin
 for i:=1 to  n do
  for j:=0 to 400 do f[i,j]:=oo;
 res:=oo;
 DFS(1);
 for i:=1 to 400 do res:=min(Res,f[1,i]);
 write(Res);
end;
begin
 assign(input,'tree.inp');reset(input);
 assign(output,'tree.out');rewrite(output);
 nhap;
 xuli;
 close(input); close(output);
end.
