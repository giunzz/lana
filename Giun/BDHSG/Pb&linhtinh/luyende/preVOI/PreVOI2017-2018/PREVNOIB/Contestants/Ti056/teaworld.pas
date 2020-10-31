const fi='teaworld.inp';
      fo='teaworld.out';
Var f,g:text;
    m,n,k,xs,ys,zs,s,best:longint;
    x,y,z,a,b,c,e,r:array[0..2000] of longint;
    s1:array[-501..501] of boolean;
    tw:array[0..16,0..2000] of longint;
Function min(a,b:longint):longint;
 Begin
       if a<b then exit(a) else exit(b);
 End;
Function max(a,b:longint):longint;
 Begin
       if a>b then exit(a) else exit(b);
 End;
Procedure inp;
var i:longint;
 Begin
       Assign(f,fi);
       Reset(f);
       readln(f,m,n,k);
       For i:=1 to m do
          Begin
                readln(f,x[i],y[i],z[i],r[i]);

                s1[x[i]]:=true;
          End;
       For i:=1 to n do
                readln(f,a[i],b[i],c[i],e[i]);
       Readln(f,xs,ys,zs);
       Close(f);
 ENd;
Procedure sub1(i,j:longint);
var l,dem,tmp:longint;
    xx:array[0..2000] of longint;
 Begin
       if s>best then best:=s;
       if i=n+1 then exit;
       sub1(i+1,j);
       dem:=0;
       for l:=min(xs,a[i]) to max(a[i],xs) do
          if s1[l]=true then
            Begin
                  inc(dem);
                  xx[dem]:=l;
            End;
       if j+dem<=k then
         Begin
               for l:=1 to dem do s1[xx[l]]:=false;
               s:=s+e[i];
               sub1(i+1,j+dem);
               s:=s-e[i];
               for l:=1 to dem do s1[xx[l]]:=true;
         End;
 ENd;
Procedure output;
 Begin
        assign(g,fo);
        rewrite(g);
        s:=0;
        sub1(1,0);
        Writeln(g,best);
        Close(g);
 End;
Begin
       inp;
       output;
End.
