Const fi='minsum.inp';
      fo='minsum.out';
Var f,g:text;
    t,i,m,n,x,y:longint;
Function uc(a,b:longint):longint;
 Begin
       if a mod b=0 then exit(b) else exit(uc(b,a mod b));
 ENd;
Procedure inp;
 Begin
       Readln(f,m,n);
 ENd;
Procedure xuly;
var i,best,aa,bb:longint;
 Begin
        aa:=uc(m,n);
        best:=m+n;
        x:=m;
        y:=n;
        While (aa>1) or ((m<>1) and (n<>1)) do
          Begin
                 m:=m div aa;
                 n:=n div aa;
                 if m+n<best then
                   Begin
                         best:=m+n;
                         x:=m;
                         y:=n;
                   End;
                 if (m mod 2<>0) and (n mod 2<>0) then break;
                 if (m<>1) and (n<>1) then
                   Begin
                         if m mod 2=0 then

                              Begin
                                    m:=m div 2;
                                    n:=n*2;
                              End else
                         if n mod 2=0 then
                              Begin
                                    n:=n div 2;
                                    m:=m*2;
                              ENd;
                   End;
                 aa:=uc(m,n);
                 if m+n<best then
                   Begin
                          best:=m+n;
                          x:=m;
                          y:=n;
                   ENd;
          ENd;
        bb:=(m*n) div 2;
        for i:=2 to bb do
           if (m*n) mod i=0 then
             if ((m*n) div i)+i<best then
               Begin
                    best:=((m*n) div i)+i;
                    x:=m*n div i;
                    y:=i;
               End;
 End;
Procedure output;
 Begin
        Writeln(g,x,' ',y);
 ENd;
Begin
      Assign(f,fi);
      Assign(g,fo);
      reset(f);
      Rewrite(g);
      Readln(f,t);
      For i:=1 to t do
         Begin
                inp;
                xuly;
                output;
         ENd;
      Close(f);
      Close(g);
ENd.
