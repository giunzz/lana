const fi='tree.inp';
      fo='tree.out';
type pre=^tre;
        tre=record
           v:longint;
           next:pre;
        end;
var n,res,m:longint;
    a,b,c,f:array[0..5000] of longint;
    free:array[0..5000] of boolean;
    ds:array[0..10000] of pre;
//--------------
procedure init(u,v:longint);
var tg:pre;
begin
      new(tg);
      tg^.v:=v;
      tg^.next:=ds[u];
      ds[u]:=tg;
end;
//--------------
procedure doc;
var i,u,v:longint;
begin
      read(n);
      for i:=1 to n do read(a[i]);
      for i:=1 to n-1 do
      begin
            read(u,v);
            init(u,v);
            init(v,u);
      end;
end;
//--------------
procedure dfs(u:longint);
var tg:pre;
    v:longint;
    ok:boolean;
begin
      free[u]:=false;
      tg:=ds[u];
      ok:=true;
      while tg<>nil do
      begin
            v:=tg^.v;
            tg:=tg^.next;
            if free[v] then
            begin
                  dfs(v);
                  ok:=false;
            end;
      end;
      if (ok) then
      begin
            inc(m);
            b[m]:=u;
      end;
end;
//--------------
procedure dfs1(u:longint);
var tg:pre;
    v:longint;
    ok:boolean;
begin
      free[u]:=false;
      tg:=ds[u];
      while tg<>nil do
      begin
            v:=tg^.v;
            tg:=tg^.next;
            if free[v] then
            begin
                  dfs1(v);
                  f[u]:=f[u]+f[v];
                  ok:=false;
            end;
      end;
end;
//--------------
procedure check;
var i,tg:longint;
begin
      fillchar(free,sizeof(free),true);
      fillchar(f,sizeof(f),0);
      for i:=1 to m do f[b[i]]:=c[i];
      dfs1(1);
      tg:=0;
      for i:=1 to n do tg:=tg+abs(f[i]-a[i]);
      if res>tg then res:=tg;
end;
//--------------
procedure try(x:longint);
var i:longint;
begin
      for i:=0 to 1 do
      begin
            c[x]:=i;
            if x=m then check
            else try(x+1);
      end;
end;
//--------------
procedure xuli;
begin
      fillchar(free,sizeof(free),true);
      dfs(1);
      res:=maxlongint;
      if m<=20 then
      begin
            try(1);
      end;
      write(res);
end;
//--------------
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      doc;
      xuli;
end.
