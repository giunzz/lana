const fi='TABLE.inp';
      fo='TABLE.out';
      maxn=1000000000000000;
var a,f,g:array[0..301,0..301] of int64;
    kq:int64;
    n,m,k:longint;
Function min(x,y:int64):int64;
   begin
   if x<=y then exit(x);
   exit(y);
   End;
Function max(x,y:int64):int64;
   begin
   if x>=y then exit(x);
   exit(y);
   End;
procedure enter;
var i,j:longint;
   begin
   assign(input,fi); reset(input);
   assign(output,fo); rewrite(output);
   read(n,m,k);
   for i:=1 to n do
   for j:=1 to m do read(a[i,j]);
   End;
procedure main;
var i,j,l,u,v,p,q,r,ll:longint;
    tg:int64;
   begin
   if (n<=30)and(m<=30)and(k<=30) then
      begin
       for ll:=1 to k do
          begin
          read(u,v,p,q);
          for i:=u to p do
          for j:=v to q do
          if ((i<>u)or(j<>v))and((i<>p)or(j<>q)) then
             begin
             f[u,v]:=a[u,v]; f[i,j]:=-maxn;
             for l:=u to p do
             for r:=v to q do
             if ((l<>i)or(r<>j))and((l<>u)or(r<>v)) then
               begin
               f[l,r]:=0;
               if l>u then f[l,r]:=max(f[l,r],f[l-1,r]+a[l,r]);
               if r>v then f[l,r]:=max(f[l,r],f[l,r-1]+a[l,r]);
               End;
             End;
          writeln(f[p,q]);
          End;
       exit;
       End;
   for l:=1 to k do
      begin
      read(u,v,p,q);
      f[u,v]:=a[u,v]; g[u,v]:=maxn;
      for i:=u to p do
      for j:=v to q do
      if (i<>u)or(j<>v) then
         begin
         f[i,j]:=0;
         if i>u then f[i,j]:=max(f[i,j],f[i-1,j]+a[i,j]);
         if j>v then f[i,j]:=max(f[i,j],f[i,j-1]+a[i,j]);   if i>u then f[i,j]:=max(f[i,j],f[i-1,j]+a[i,j]);
         if j>v then f[i,j]:=max(f[i,j],f[i,j-1]+a[i,j]);
         g[i,j]:=maxn;
         if i>u then g[i,j]:=min(g[i,j],f[i-1,j]+a[i,j]);
         if j>v then g[i,j]:=min(g[i,j],f[i,j-1]+a[i,j]);
         tg:=0;
         if i>u then tg:=max(g[i-1,j],tg);
         if j>v then tg:=max(tg,g[i,j-1]);
         g[i,j]:=min(tg+a[i,j],g[i,j]);
         End;
      kq:=g[p,q];
      writeln(kq);
      End;
   close(input);
   close(output);
   End;
begin
enter;
main;
End.
