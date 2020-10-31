Const   fi='teaworld.inp';
        fo='teaworld.out';
Type    Bong=Record x,y,z,r:Longint; End;
        Tea=Record x,y,z,val:Longint; End;
        Point=Record x,y,z:Longint; End;
Var     f:text;
        n,m,k:Longint;  vt:point;  sol:Longint;
        A:Array[0..15] of tea;
        B:Array[0..2000] of bong;
        D,S:Array[-2000..2000] of Longint;
        L:Array[0..2000,0..15] of Longint;
Function max(i,j:Longint):Longint; Inline; Begin If i>j then Exit(i); Exit(j); End;
Procedure Inp;
Var     i:Longint;
Begin
        Assign(f,fi);   Reset(f);
        Read(f,m,n,k);
        For i:=1 to m do Read(f,B[i].x,B[i].y,B[i].z,B[i].r);
        For i:=1 to n do Read(f,A[i].x,A[i].y,A[i].z,A[i].val);
        Read(f,vt.x,vt.y,vt.z);
        Close(f);
End;
Procedure Swap(Var i,j:tea);
Var     tg:tea;
Begin
        tg:=i; i:=j; j:=tg;
End;
Procedure QS(l,r:Longint);
Var     i,j:Longint;  mid:tea;
Begin
        If l>=r then Exit;
        mid:=A[random(r-l+1)+l];
        i:=l; j:=r;
        Repeat
                While A[i].x<mid.x do Inc(i);
                While A[j].x>mid.x do Dec(j);
                If i<=j then
                Begin
                        If i<j then Swap(A[i],A[j]);
                        Inc(i); Dec(j);
                End;
        Until i>j;
        QS(i,r); QS(l,j);
End;
Procedure Sub1;
Var     i,j,res,o:Longint;
Begin
        QS(1,n);
        For i:=1 to m do
        Begin
                If (B[i].x-B[i].r=vt.x) then Begin Dec(D[B[i].x-B[i].r-1]); Inc(D[B[i].x+B[i].r+1]); End;
                If (B[i].x+B[i].r=vt.x) then Begin Inc(D[B[i].x+B[i].r+1]); Dec(D[B[i].x-B[i].r-1]); End;
                If (B[i].x-B[i].r<vt.x) and (B[i].x+B[i].r>vt.x) then Begin Inc(D[B[i].x+B[i].r]); Dec(D[B[i].x-B[i].r]); End;
                If B[i].x+B[i].r<vt.x then Dec(D[B[i].x+B[i].r]);
                If B[i].x-B[i].r>vt.x then Inc(D[B[i].x-B[i].r]);
        End;
        For i:=vt.x+1 to 500 do D[i]:=D[i-1]+D[i];
        For i:=vt.x-1 downto -500 do D[i]:=D[i+1]+D[i];
        i:=1;
        While i<n do
        Begin
                j:=i+1; o:=A[i].val;
                While D[A[j].x]=D[A[i].x] do
                Begin
                        o:=o+A[j].val;
                        Inc(j);
                End;
                For res:=i to j-1 do S[res]:=o;
                i:=j;
        End;
        For i:=1 to n do
        Begin
                For j:=1 to k do If abs(abs(D[A[i].x])-D[vt.x])<=j then
                Begin
                        L[i,j]:=max(L[i,j],L[i-1,j-1]+S[i]);
                End;
        End;
        For i:=1 to n do sol:=max(sol,L[i,k]);
        For i:=1 to n do If D[A[i].x]=0 then Inc(sol,A[i].val);
End;
Procedure Main;
Var     i,j:Longint;  kt1,kt2:Boolean;
Begin
        sol:=0;
        If k=m then Begin For i:=1 to n do Inc(sol,A[i].val); Exit; End;
        kt1:=True; kt2:=True;
        If vt.y<>0 then kt1:=False;
        If vt.z<>0 then kt2:=False;
        For i:=1 to m do
        Begin
                If (B[i].y<>0) then kt1:=False;
                If (B[i].z<>0) then kt2:=False;
        End;
        For i:=1 to n do
        Begin
                If (A[i].y<>0) then kt1:=False;
                If (A[i].z<>0) then kt2:=False;
        End;
        If kt1 and kt2 then sub1;
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
