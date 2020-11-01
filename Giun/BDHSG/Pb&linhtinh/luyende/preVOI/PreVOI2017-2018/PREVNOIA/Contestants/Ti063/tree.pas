const fi='tree.inp';
      fo='tree.out';
      oo=trunc(1e9);
var   n,gt,sol:longint;
      a,deg:array[0..5001]of longint;
      f:array[0..5001,0..5001]of longint;
      l,r:array[0..5001]of longint;
function min(i,j:longint):longint; inline; begin if i<j then exit(i); exit(j); end;
function max(i,j:longint):longint; inline; begin if i>j then exit(i); exit(j); end;
function try(u,x:longint):longint;
var i,val1,val2,con,res:longint;
begin
      if f[u,x]<>oo then exit(f[u,x]);
      if x>(1 shl trunc(ln(deg[u])/ln(2))) then exit(oo);
      res:=oo;
      if (l[u]<>0) and (r[u]<>0) then
      begin
          for i:=0 to x do
          begin
               val1:=try(l[u],i);
               val2:=try(r[u],x-i);
               res:=min(res,val1+val2+abs(a[u]-x));
          end;
      end else
      begin
          if l[u]<>0 then con:=l[u] else con:=r[u];
          res:=min(res,try(con,x)+abs(a[u]-x));
      end;
      f[u,x]:=res;
      exit(f[u,x]);
end;
procedure dfs(u:longint);
var v:longint;
begin
      deg[u]:=1;
      if l[u]<>0 then
      begin
          dfs(l[u]);
          deg[u]:=deg[u]+deg[l[u]];
      end;
      if r[u]<>0 then
      begin
          dfs(r[u]);
          deg[u]:=deg[u]+deg[r[u]];
      end;
end;
procedure main;
var i,j,u,v:longint;
begin
      read(n);
      for i:=1 to n do read(a[i]);
      gt:=1 shl trunc(ln(n)/ln(2));
      for i:=1 to n-1 do
      begin
          read(u,v);
          if l[u]=0 then l[u]:=v else r[u]:=v;
      end;
      dfs(1);
      for i:=0 to n do
          for j:=0 to gt do f[i,j]:=oo;
      sol:=oo;
      for i:=1 to n do if (l[i]=0)and(r[i]=0) then
      begin
          f[i,1]:=abs(1-a[i]);
          f[i,0]:=abs(0-a[i]);
      end;
      for i:=0 to gt do sol:=min(sol,try(1,i));
      write(sol);
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.
