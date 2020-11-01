const fi='LIONDANCE.inp';
      fo='LIONDANCE.out';
var n,k,kq,v1,v2:longint;
    a,b:array[0..100000] of longint;
    f,t1,t2:array[0..4000,0..4000] of longint;
procedure enter;
var i:longint;
   begin
   assign(input,fi); reset(input);
   read(n,k);
   for i:=1 to n do read(a[i]);
   for i:=1 to n do read(b[i]);
   close(input);
   End;
procedure main;
var i,j,u,v,tg1,tg2,tg:longint;
   begin
   kq:=0;
   for i:=n downto 1 do
   for j:=n downto 1 do
   if a[i]=b[j] then
       begin
       tg:=0;
       for u:=i+1 to n do
       if (abs(a[u]-a[i])<=k) then
          begin
       for v:=j+1 to n do
       if (a[u]=b[v]) then
          begin
          if (f[u,v]>tg)or((f[u,v]=tg)and(a[u]>a[tg1])) then
             begin
             tg:=f[u,v];
             tg1:=u;
             tg2:=v;
             End;
          End;
       f[i,j]:=tg+1; t1[i,j]:=tg1;t2[i,j]:=tg2;
       if (kq<tg+1)or((kq=tg)and(a[v1]<a[i])) then
          begin
          kq:=tg+1;
          v1:=i; v2:=j;
          End;
       End;
       End;
   End;
procedure print;
var i,tg1,tg2:longint;
   begin
   assign(output,fo); rewrite(output);
   writeln(kq);
   for i:=1 to kq do
      begin
      write(a[v1],' ');
      tg1:=v1; tg2:=v2;
      v1:=t1[tg1,tg2];
      v2:=t2[tg1,tg2];
      End;
   close(output);
   End;
begin
enter;
main;
print;
End.