const
   fi='tree.inp';
   fo='tree.out';
var
   f:text;
   n,dem,sld,kq:longint;
   e,a,y,b,x:array[0..6000]of longint;
   link,head,tp:array[0..6000] of longint;
   dx:array[0..6000] of boolean;
procedure  nhap;
   var i,u,s:longint;
   begin
     assign(F,fi);
     reset(f);
     readln(f,n); s:=0;
     for i:=1 to n do
         read(f,a[i]);
     for i:=1 to n do
         head[i]:=0;
     for i:=1 to n-1 do
         begin
            read(f,u,e[i]);
            link[i]:=head[u];
            head[u]:=i;
         end;
     close(f);
   end;
procedure  init;
   var i:longint;
   begin
     for i:=1 to n do
         dx[i]:=true;
     sld:=0;
     for i:=1 to n do
         if head[i]=0 then
            begin
              inc(sld);
              y[sld]:=i;
            end;
     dem:=n;
     kq:=maxlongint;
   end;
procedure  check;
   var i,j,u,ss:longint;
   begin
      for i:=1 to n do
          b[i]:=0;
      for i:=1 to sld do
          if x[i]=1 then b[y[i]]:=1;
      for i:=n downto  1 do
          begin
            u:=tp[i];
            j:=head[u];
            while j<>0 do
                begin
                  b[u]:=b[u]+b[e[j]];
                  j:=link[j];
                end;
          end;
      ss:=0;
      for i:=1 to n do
          ss:=ss+abs(a[i]-b[i]);
      if ss<kq then kq:=ss;
   end;
procedure  try(i:longint);
   var j:longint;
   begin
     for j:=0 to 1 do
         begin
           x[i]:=j;
           if i=sld then check
           else try(i+1);
         end;
   end;
procedure  DFS(u:longint);
   var  i:longint;
   begin
     dx[u]:=false;
     i:=head[u];
     while i<>0 do
        begin
          if dx[e[i]] then  DFS(e[i]);
          i:=link[i];
        end;
     tp[dem]:=u;
     dec(dem);
   end;
procedure  xuli;
   var  i:longint;
   begin
     DFS(1);
     try(1);
   end;
BEGIN
  nhap;
  init;
  xuli;
  assign(f,fo);
  rewrite(f);
  writeln(f,kq);
  close(F);
END.
5
5 1 3 0 1
1 2
1 3
3 4
3 5
