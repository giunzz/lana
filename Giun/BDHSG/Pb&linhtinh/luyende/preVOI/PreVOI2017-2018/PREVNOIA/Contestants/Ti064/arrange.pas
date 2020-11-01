Const   fi='arrange.inp';
        fo='arrange.out';
        oo=trunc(1e9);
Var     f:text;
        n:Longint;  sol:Int64;
        A:Array[0..100000] of Int64;
Function min(i,j:Longint):Longint; Inline; Begin If i>j then Exit(j); Exit(i); End;
Function max(i,j:Longint):Longint; Inline; Begin If i>j then Exit(i); Exit(j); End;
Procedure Inp;
Var     i:Longint;
Begin
        Assign(f,fi);   Reset(f);
        Read(f,n);
        For i:=1 to n do Read(f,A[i]);
        Close(f);
End;
Procedure sub1;
Var     i,j,o:Longint; k:Int64;
Begin
        o:=0;
        For i:=1 to n do o:=o+A[i];
        k:=o div n;
        For i:=1 to n-1 do If A[i]>k then
        Begin
                Inc(sol,A[i]-k); A[i+1]:=A[i+1]+A[i]-k; A[i]:=k;
        End Else Begin
                Inc(sol,k-A[i]); A[i+1]:=A[i+1]+A[i]-k; A[i]:=k;
        End;
End;
Procedure Sub2;
Var     i,o1,o2,j:Longint;   check:Boolean;  res,p,dem,k,o:Int64;
Begin
        o:=0;
        For i:=1 to n do o:=o+A[i];
        k:=o div n;
        For i:=1 to n do If A[i]<k then
        Begin
                dem:=k-A[i];  o1:=i; o2:=i;
                While (dem>0) do
                Begin
                        If o2<n then Inc(o2);
                        If o1>0 then Dec(o1);
                        If A[o1]>k then If A[o1]-k<dem then
                        Begin Inc(sol,(Int64(i)-o1)*(A[o1]-k)); dem:=dem-A[o1]+k; A[o1]:=k; End
                        Else Begin Inc(sol,(Int64(i)-o1)*dem); A[o1]:=A[o1]-dem; Break; End;
                        If A[o2]>k then If A[o2]-k<dem then
                        Begin Inc(sol,(o2-Int64(i))*(A[o2]-k)); dem:=dem-A[o2]+k; A[o2]:=k; End
                        Else Begin Inc(sol,dem*(o2-Int64(i))); A[o2]:=A[o2]-dem; Break; End;
                End;
                A[i]:=k;
        End;
        For i:=1 to n do If A[i]>k+1 then
        Begin
                o:=A[i]-k-1; res:=oo;
                For j:=max(i-o,1) to min(i+o,n) do
                Begin
                        p:=abs(i-j)*(abs(i-j)+1) div 2;
                        p:=p+(o-abs(i-j))*(o-abs(i-j)+1) div 2;
                        res:=min(res,p);
                End;
                sol:=sol+res;
        End;
End;
Procedure sub3;
Begin
End;
Procedure Main;
Var     i,o,k:Longint;
Begin
        o:=0;
        For i:=1 to n do o:=o+A[i];
        If o mod n=0 then sub1
        Else If n<=2000 then sub2
        Else sub3;
End;
Procedure Outp;
Begin
        Assign(f,fo);   Rewrite(f);
        Write(f,sol);
        Close(f);
End;
BEGIN
        Inp;
        Main;
        Outp;
END.
