Const   fi='gifts.inp';
        fo='gifts.out';
Var     f:text;
        n,k:Int64;  sol:Int64;
        A,S,L,R,C:Array[0..1000000] of Int64;
Function min(i,j:Int64):Int64; Inline; Begin If i>j then Exit(j); Exit(i); End;
Function max(i,j:Int64):Int64; Inline; Begin If i>j then Exit(i); Exit(j); End;
Procedure Inp;
Var     i:Longint;
Begin
        Assign(f,fi);   Reset(f);
        Read(f,n,k);
        For i:=1 to n do Read(f,A[i]);
        Close(f);
End;
Procedure Solve;
Var     i,j,o:Longint;
Begin
        o:=0;   sol:=0;
        For i:=1 to n do C[i]:=C[i-1]+A[i];
        For i:=1 to n do S[i]:=C[i]-C[max(i-k,0)];
        For i:=1 to n do L[i]:=max(L[i-1],S[i]);
        For i:=n downto 1 do R[i]:=max(R[i+1],S[i]);
        For i:=k to n-k do sol:=max(sol,min(L[i],R[i+1]));
End;
Procedure Outp;
Begin
        Assign(f,fo);   Rewrite(f);
        Write(f,sol);
        Close(f);
End;
BEGIN
        Inp;
        Solve;
        Outp;
END.
