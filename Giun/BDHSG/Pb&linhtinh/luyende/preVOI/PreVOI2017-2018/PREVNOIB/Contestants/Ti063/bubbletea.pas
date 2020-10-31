const fi='bubbletea.inp';
      fo='bubbletea.out';
      maxn=5*trunc(1e4);
      oo=trunc(1e16);
var   n,k,lg:longint;
      a,h,kq,cx:array[0..maxn]of longint;
      tong:array[0..maxn]of int64;
      sol:int64;
      p:array[0..maxn,0..20]of longint;
      next,ke,hd,w:array[-maxn..maxn]of int64;
procedure add(o,u,v,c:longint);
begin
      ke[o]:=v;
      w[o]:=c;
      next[o]:=hd[u];
      hd[u]:=o;
end;
function min(i,j:int64):int64; inline; begin if i>j then exit(j); exit(i); end;
function max(i,j:int64):int64; inline; begin if i>j then exit(i); exit(j); end;
procedure dfs(u:longint);
var j,v:longint;
begin
      for j:=1 to lg do p[u,j]:=p[p[u,j-1],j-1];
      j:=hd[u];
      while j<>0 do
      begin
              v:=ke[j];
              if h[v]=0 then
              begin
                 h[v]:=h[u]+1;
                 p[v,0]:=u;
                 tong[v]:=tong[u]+w[j];
                 dfs(v);
              end;
              j:=next[j];
      end;
end;
procedure swap(var a,b:longint);
var temp:longint;
begin
      temp:=a;
      a:=b;
      b:=temp;
end;
function lca(u,v:longint):longint;
var i,dem:longint;
begin
      if h[u]<h[v] then swap(u,v);
      dem:=trunc(ln(h[u])/ln(2));
      for i:=dem downto 0 do
        if h[u]- 1shl i>=h[v] then u:=p[u,i];
      if u=v then exit(u);
      for i:=dem downto 0 do
        if p[u,i]<>p[v,i] then
        begin
                   u:=p[u,i];
                   v:=p[v,i];
        end;
      exit(p[u,0]);
end;
procedure xuli;
var i,u1,v1,u2,v2,j:longint;
    kt:boolean;
    res:int64;
begin
      for i:=1 to k div 2 do
          for j:=i+1 to k div 2 do
          begin
              u1:=a[kq[2*(i-1)+1]];
              v1:=a[kq[2*(i-1)+2]];
              u2:=a[kq[2*(j-1)+1]];
              v2:=a[kq[2*(j-1)+2]];
              if h[u1]<h[v1] then swap(u1,v1);
              if h[u2]<h[v2] then swap(u2,v2);
              kt:=true;
              if lca(u1,u2)=lca(u1,v1) then
                 if h[lca(u2,v2)]<h[lca(u1,v1)] then begin kt:=false;  end;
              if lca(u1,u2)=lca(u2,v2) then
                 if h[lca(u1,v1)]<h[lca(u2,v2)] then begin kt:=false; end;
              if kt then begin
                           res:=max(res,tong[u1]+tong[v1]-tong[lca(u1,v1)]);
                           res:=max(res,tong[u2]+tong[v2]-tong[lca(u2,v2)]);
                         end;
              if kt then sol:=min(sol,res);
              if not kt then begin sol:=oo; exit; end;
          end;
end;
procedure try(i:longint);
var j:longint;
begin
      for j:=1 to k do if cx[j]=0 then
      begin
          cx[j]:=1;
          kq[i]:=j;
          if i=k then xuli else try(i+1);
          cx[j]:=0;
      end;
end;
procedure sub1;
begin
      sol:=oo;
      try(1);
      if sol=oo then write(-1);
end;
procedure main;
var i,u,v,c:longint;
begin
      read(n,k);
      lg:=trunc(ln(n)/ln(2));
      for i:=1 to k do read(a[i]);
      for i:=1 to n-1 do
      begin
          read(u,v,c);
          add(i,u,v,c);
          add(-i,v,u,c);
      end;
      h[1]:=1;
      p[1,0]:=1;
      dfs(1);
      if k<=10 then sub1 else write(-1);
end;
begin
      assign(input,fi);
      reset(input);
      assign(output,fo);
      rewrite(output);
      main;
end.