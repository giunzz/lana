uses math;
CONST FI='TREE.INP';
      FO='TREE.OUT';
var m,n:longint;
    La,A,adj,head,x,y,D,Con,Prev,F,B:array[0..1000000] of longint;
    Free:array[0..1000000] of boolean;
    nl,res:longint;
//
procedure doc;
var i,j:longint;
begin
      assign(input,fi);
      reset(input);
      read(n);
      m:=n-1;
      for i:=1 to n do
      begin
            read(A[i]);
      end;
      for i:=1 to m do
      begin
            read(x[i],y[i]);
            inc(head[x[i]]);

            inc(Con[x[i]]);
      end;

      for i:=1 to n do head[i]:=head[i]+head[i-1];

      for i:=1 to m do
      begin
            adj[head[x[i]]]:=y[i];
            //adj[head[y[i]]]:=x[i];
            dec(head[x[i]]);
            //dec(head[y[i]]);
      end;

      head[n+1]:=m;
end;

procedure init;
var i,j:longint;
begin
      for i:=1 to n do if COn[i]=0 then
      begin
            inc(nl);
            La[nl]:=i;
      end;

      fillchar(Free,sizeof(Free),true);
end;
procedure DFS(u:longint);
var v,iv:longint;
begin
      Free[u]:=false;

      if Con[u]=0 then F[u]:=1 else F[u]:=0;

      for iv:=head[u]+1 to head[u+1] do
      begin
            v:=adj[iv];
            if Free[v] then
            begin
                  PRev[v]:=u;
                  DFS(v);
                  F[u]:=F[u]+F[v];
            end;
      end;
end;

procedure Duc(u:longint);
var v,iv:longint;
begin
      v:=u;
      repeat
             v:=PRev[v];
             if v=0 then break;
             B[v]:=B[v]+B[u];
      until v=0;
end;

function Get(x,y:longint):longint;
begin
      exit( 1 and (x shr(y-1) ) );
end;
procedure sub1;
var i,j,x,tmp:longint;
begin
      res:=maxlongint div 2;
      for x:=1 to (1 shl nl)-1 do
      begin
            for i:=1 to n do B[i]:=0;
            for i:=1 to nl do if Get(x,i)=1 then
            begin
                  B[la[i]]:=1;
            end
            else B[la[i]]:=0;

            for i:=1 to nl do Duc(La[i]);

            tmp:=0;
            for i:=1 to n do tmp:=tmp+abs(A[i]-B[i]);

            res:=Min(res,tmp);
      end;

      writeln(res);
end;

function Cal(x,u:longint):longint;
var v,iv:longint;
    dem,t1,t2,d1,d2:longint;
    ans:longint;
begin
       ans:=abs(A[u]-x);

       dem:=0;
       for iv:=head[u]+1 to head[u+1] do
       begin
             inc(dem);
             if dem=1 then d1:=adj[iv];
             if dem=2 then d2:=adj[iv];
       end;

       if dem=0 then exit(ans);

       if dem=1 then ans:=ans+Cal(x,d1);

       t1:=F[d1];
       t2:=F[d2];


       exit(ans);
end;

procedure sub2;
var i:longint;
begin
      for i:=1 to nl do
      begin
            res:=Min(res,Cal(i,1) );
      end;

      writeln(res);
end;
procedure inkq;
begin
      assign(output,fo);
      rewrite(output);
      if n<=30 then sub1
      else sub2;
end;
begin
doc;
init;
DFS(1);
inkq;
end.



















