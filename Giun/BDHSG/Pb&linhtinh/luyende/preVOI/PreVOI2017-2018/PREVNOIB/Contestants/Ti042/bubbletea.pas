uses math;
CONST FI='BUBBLETEA.INP';
      FO='BUBBLETEA.OUT';
var m,n,k:longint;
    X,Y,adj,head,A,D,cha:array[0..1000005] of longint;
    adjc,Z,Hang:array[0..1000005] of int64;
    Free,Cv:array[0..1000005] of boolean;

    F,Dem:array[0..1000005,0..20] of longint;
    Ha:array[0..100005,0..2] of longint;
    C:array[0..1000005,0..20] of int64;
    res,kq:int64;
    log:longint;
procedure doc;
var i,j:longint;
begin
      assign(input,fi);
      reset(input);
      read(n,k);
      for i:=1 to k do
      begin
            read(A[i]);
            Cv[a[i]]:=true;
      end;

      m:=n-1;
      for i:=1 to m do
      begin
            read(x[i],y[i],z[i]);
            res:=Max(res,z[i]);
            inc(head[x[i]]);
            inc(head[y[i]]);
      end;

      for i:=1 to n do head[i]:=head[i]+head[i-1];

      for i:=1 to m do
      begin
            adj[head[x[i]]]:=y[i]; adjc[head[x[i]]]:=z[i];
            adj[head[y[i]]]:=x[i]; adjc[head[y[i]]]:=z[i];
            dec(head[x[i]]);
            dec(head[y[i]]);
      end;

      head[n+1]:=2*m;

      fillchar(Free,sizeof(Free),true);

end;
procedure DFS(u:longint);
var v,iv:longint;
begin
      D[u]:=D[cha[u]]+1;
      Free[u]:=false;
      for iv:=head[u]+1 to head[u+1] do
      begin
            v:=adj[iv];
            if Free[v] then
            begin
                  Cha[v]:=u;
                  C[v,0]:=adjc[iv];
                  DFS(v);
            end;
      end;
end;
function Get(x,y:longint):longint;
begin
       exit(1 and (x shr(y-1) ) );
end;
procedure init;
var i,j:longint;
begin
      log:=20;
      fillchar(Free,sizeof(Free),true);

      DFs(1);
      F[0,0]:=0;
      for i:=1 to n do F[i,0]:=CHa[i];

      for j:=1 to log do
      for i:=1 to n do   F[i,j]:=F[f[i,j-1],j-1];

      for j:=1 to log do
      for i:=1 to n do
      begin
            C[i,j]:=C[i,j-1]+C[f[i,j-1],j-1];
      end;
end;
function LCA(u,v:longint):longint;
var k,i,j,t:longint;
begin
      if d[u] >= d[v] then
         begin
                if d[u] > d[v] then
                begin
                        t:= d[u]- d[v];
                        for k:= log downto 1 do
                        if get(t,k) = 1 then
                        u:= F[u,k-1];
                end;
                for k:= log downto 0 do
                if F[u,k] <> F[v,k] then
                begin
                        u:= F[u,k];
                        v:= F[v,k];
                end
                else lca:= F[u,k];

                if u = v then lca:=u;

         end
         else exit(lca(v,u));
end;
procedure try(x,sl:longint);
var i,j,u,v,tg:longint;
    tmp:int64;
    ok:boolean;
begin
      if x=k div 2+1 then
      begin
            kq:=0;
            for i:=1 to k div 2 do kq:=Max(kq,Hang[i]);
            res:=Min(res,kq);
            exit;
      end;

      for i:=1 to k do
      if Free[a[i]] then
      begin
            Free[a[i]]:=false;
            Ha[x,sl]:=a[i];

            if sl=1 then try(x,sl+1)
            else
            if sl=2 then
            begin
                  ok:=true;
                  tmp:=0;
                  u:=Ha[x,1];
                  v:=Ha[x,2];
                  tg:=LCA(u,v);
                  j:=u;
                  while j<>tg do
                  begin
                        inc(Dem[j,0]);
                        tmp:=tmp+C[j,0];
                        j:=Cha[j];
                        if Dem[j,0]>1 then
                             ok:=false;

                  end;
                  j:=v;
                  while j<>tg do
                  begin
                        inc(Dem[j,0]);
                        tmp:=tmp+C[j,0];
                        j:=cha[j];
                        if Dem[j,0]>1 then ok:=false;
                  end;

                  if ok=false then
                  begin
                        j:=u;
                        while j<>tg do
                        begin
                              dec(Dem[j,0]);
                              j:=Cha[j];
                        end;
                        j:=v;
                        while j<>tg do
                        begin
                              dec(Dem[j,0]);
                              j:=cha[j];
                        end;
                  end
                  else
                  begin
                        Hang[x]:=tmp;

                        try(x+1,1);
                        j:=u;
                        while j<>tg do
                        begin
                              dec(Dem[j,0]);
                              j:=Cha[j];
                        end;
                        j:=v;
                        while j<>tg do
                        begin
                              dec(Dem[j,0]);
                              j:=cha[j];
                        end;
                  end;
            end;

            Free[a[i]]:=true;
      end;
end;
//
procedure inkq;
begin
      assign(output,fo);
      rewrite(output);
      if k=n then write(res)
      else
      begin
            res:=high(int64) div 2;
            fillchar(Free,sizeof(Free),true);
            try(1,1);
            if res<>high(int64) div 2 then writeln(res) else writeln(-1);

      end;
end;
begin
doc;
init;
inkq;
end.








