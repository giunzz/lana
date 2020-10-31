Const fi='gifts.inp';
      fo='gifts.out';
Var f,g:text;
    n,k:longint;
    min:int64;
    a,d:array[0..1000000] of int64;
Procedure inp;
Var i:longint;
 Begin
       Assign(f,fi);
       Reset(f);
       Readln(f,n,k);
       For i:=1 to n do
          Begin
                Read(f,a[i]);
                if i<k then d[i]:=d[i-1]+a[i]
                else d[i]:=d[i-1]+a[i]-a[i-k];
                if d[i]>min then min:=d[i];
          End;
       Close(f);
 End;
Procedure xuly;
var i,j:longint;
    kk:boolean;
 Begin
       For i:=k to n do
          Begin
                 kk:=true;
                 For j:=k-1 to i-k do if d[i]<d[j] then kk:=false;
                 if kk then
                 for j:=i+k to n do if d[i]<d[j] then kk:=false;
                 if kk then
                         if d[i]<min then min:=d[i];
          End;
 End;
Procedure output;
 Begin
       Assign(g,fo);
       rewrite(g);
       Writeln(g,min);
       Close(g);
 End;
Begin
      inp;
      xuly;
      output;
End.
