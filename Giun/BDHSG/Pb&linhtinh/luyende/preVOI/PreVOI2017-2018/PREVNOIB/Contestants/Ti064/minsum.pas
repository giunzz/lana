Const   fi='minsum.inp';
        fo='minsum.out';
Var     f,f1:text;
        test,a,b:Longint;  res,x,y:Int64;
Procedure Swap(Var i,j:Int64);   Inline;
Var     tg:Int64;
Begin
        tg:=i; i:=j; j:=tg;
End;
Function gcd(a,b:Int64):Int64; Inline;
Begin
        While b>0 do
        Begin
                a:=a mod b;
                Swap(a,b);
        End;
        Exit(a);
End;
Procedure Try(a,b:Int64; count:Longint);
Var     i,j:Longint;
Begin
        If count=5 then Exit;
        j:=Gcd(a,b);
        IF j<>1 then Try(a div j, b div j, count+1);
        If res>(a div j)+(b div j) then Begin x:=a div j; y:=b div j; res:=x+y; End;
        For j:=2 to trunc(sqrt(a)) do
                If a mod j=0 then
                Begin
                        Try(a div j,b*j,count+1);
                        If res>(a div j)+(b*j) then Begin x:=a div j; y:=b*j; res:=x+y; End;
                End;
        For j:=2 to trunc(sqrt(b)) do
                If b mod j=0 then
                Begin
                        Try(a*j, b div j,count+1);
                        If res>(b div j)+(a*j) then Begin x:=a*j; y:=b div j; res:=x+y; End;
                End;
End;
Procedure Solve;
Begin
        Read(f,a,b);   res:=trunc(1e9); x:=0; y:=0;
        If a=b then Writeln(f1,1,' ',1)
        Else Begin Try(a,b,0); Writeln(f1,x,' ',y); End;
End;
Procedure Main;
Var     i:Longint;
Begin
        Assign(f,fi);   Reset(f);
        Assign(f1,fo);  Rewrite(f1);
        Read(f,test);
        For i:=1 to test do Solve;
        Close(f);       Close(f1);
End;
BEGIN
        Main;
END.
