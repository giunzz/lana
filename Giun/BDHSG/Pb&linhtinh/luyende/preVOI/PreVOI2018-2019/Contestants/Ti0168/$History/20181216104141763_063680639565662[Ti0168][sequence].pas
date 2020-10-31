const fi='SEQUENCE.inp';
      fo='SEQUENCE.out';
var n,m,k,nu,nv:longint;
    a,b,q,kq,u,v:array[0..3000] of longint;
    f,g:array[0..3000,0..3000] of longint;
procedure enter;
var i:longint;
   begin
   assign(input,fi); reset(input);
   read(n,m,k);
   For i:=1 to n do read(a[i]);
   for i:=1 to m do read(b[i]);
   close(input);
   End;
Function ktr(x,y:longint):boolean;
var tg,i:longint;
   begin
   tg:=nu-x+1;
   if tg>nv-y+1 then tg:=nv-y+1;
   for i:=0 to tg do
     begin
     if u[x+i]<v[y+i] then exit(true);
     if u[x+i]>v[y+i] then exit(false);
     End;
   if nu-x<nv-y then exit(true);
   exit(false);
   End;
Function ktt:boolean;
var i:longint;
   begin
   for i:=1 to k do
      begin
      if q[i]<kq[i] then exit(true);
      if q[i]>kq[i] then exit(False);
      End;
   exit(false);
   End;
Procedure main;
var kt:boolean;
    i,j,tg,vt,l,tu,tv,jj:longint;
   begin
   for i:=1 to n do
      begin
      f[i,i]:=i; tg:=a[i]; vt:=i;
      for j:=i+1 to n do
         begin
         if a[j]<tg then
            begin
            tg:=a[j];
            vt:=j;
            End;
         f[i,j]:=vt;
         End;
      End;
   for i:=1 to m do
      begin
      g[i,i]:=i; tg:=b[i]; vt:=i;
      for j:=i+1 to m do
         begin
         if b[j]<tg then
            begin
            tg:=a[j];
            vt:=j;
            End;
         g[i,j]:=vt;
         End;
      End;
   kt:=false;
   for i:=0 to n do
      begin
      if i>k then break;
      if k-i>m then continue;
      if i<>0 then
         begin
         l:=1; nu:=0;
         for j:=i downto 1 do
            begin
            tg:=f[l,n-j+1];
            inc(nu); u[nu]:=a[tg];
            l:=tg+1;
            End;
         End;
      if k-i<>0 then
         begin
         l:=1; nv:=0;
         for j:=k-i downto 1 do
            begin
            tg:=g[l,m-j+1];
            inc(nv); v[nv]:=b[tg];
            l:=tg+1;
            End;
         End;
      u[nu+1]:=maxlongint;
      v[nv+1]:=maxlongint;
      tu:=1; tv:=1;
      for j:=1 to k do
         begin
         if ktr(tu,tv) then
            begin
            q[j]:=u[tu]; inc(tu);
            End
         else
            begin
            q[j]:=v[tv]; inc(tv);
            End;
         End;
      if kt then
         begin
         if ktt then for j:=1 to k do kq[j]:=q[j];
         End
      else
         begin
         for j:=1 to k do kq[j]:=q[j];
         kt:=true;
         End;
      End;
   End;
Procedure print;
var i:longint;
   begin
   assign(output,fo); rewrite(output);
   for i:=1 to k do write(kq[i],' ');
   close(output);
   End;
begin
enter;
main;
print;
End.