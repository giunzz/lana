Const   fi='bubbletea.inp';
        fo='bubbletea.out';
        oo=trunc(1e9);
Var     f:text;
        Next,Ke,Val:Array[-5000..5000] of Longint;
        Head,D,Pos,Heap,A,L:Array[0..5000] of Longint;
        DD:Array[0..10,0..5000] of Longint;
        Free:Array[0..5000] of Boolean;
        n,k,nheap:Longint;   sol:Longint;
Function min(i,j:Longint):Longint; Inline; Begin If i>j then Exit(j); Exit(i); End;
Function max(i,j:Longint):Longint; Inline; Begin If i>j then Exit(i); Exit(j); End;
Procedure Inp;
Var     i,u,v,c:Longint;
Begin
        Assign(f,fi);   Reset(f);
        Read(f,n,k);
        For i:=1 to k do Read(f,A[i]);
        For i:=1 to n-1 do
        Begin
                Read(f,u,v,c);
                Next[i]:=Head[u]; Head[u]:=i; Ke[i]:=v; Val[i]:=c;
                Next[-i]:=Head[v]; Head[v]:=-i; Ke[-i]:=u; Val[-i]:=c;
        End;
        Close(f);
End;
Procedure Swap(Var i,j:Longint);
Var     tg:Longint;
Begin
        tg:=i; i:=j; j:=tg;
End;
Procedure Upheap(x:Longint);
Begin
        If (x=1) or (D[Heap[x]]>=d[heap[x div 2]]) then Exit
        Else Begin
                Swap(heap[x],heap[x div 2]);
                pos[heap[x]]:=x;
                pos[heap[x div 2]]:=x div 2;
                Upheap(x div 2);
        End;
End;
Procedure Downheap(x:Longint);
Var     vt:Longint;
Begin
        If (x>nheap div 2) then Exit;
        If (d[heap[x*2]]>=d[heap[x*2+1]]) and (x*2+1<=nheap) then vt:=x*2+1 Else vt:=x*2;
        If (d[heap[x]]<=d[heap[vt]]) then Exit
        Else Begin
                Swap(heap[x],heap[vt]);
                pos[heap[x]]:=x;
                pos[heap[vt]]:=vt;
                downheap(vt);
        End;
End;
Function Pop:Longint;
Begin
        Pop:=heap[1];
        heap[1]:=heap[nheap];
        pos[heap[nheap]]:=1;
        Dec(nheap);
        downheap(1);
End;
Procedure Dijkstra(s:Longint);
Var     i,u,v:Longint;
Begin
        For i:=1 to n do
        Begin
                Free[i]:=True; D[i]:=oo;
                Pos[i]:=i; Heap[i]:=i;
        End;
        D[s]:=0;  nheap:=n;
        For i:=nheap div 2 downto 1 do Downheap(i);
        Repeat
                u:=Pop;
                Free[u]:=False;
                i:=Head[u];
                While i<>0 do
                Begin
                        v:=Ke[i];
                        If (Free[v]) and (D[v]>D[u]+Val[i]) then
                        Begin
                                D[v]:=D[u]+Val[i];
                                Upheap(Pos[v]);
                        End;
                        i:=Next[i];
                End;
        Until nheap=0;
End;
Procedure xuli;
Var     i,count,res:Longint;
Begin
        i:=1;  count:=0;   res:=0;
        While count<k div 2 do
        Begin
                Inc(count);
                res:=max(res,DD[L[i],A[L[i+1]]]);
                i:=i+2;
        End;
        sol:=min(sol,res);
End;
Procedure Try(i:Longint);
Var     j:Longint;
Begin
        For j:=1 to k do If Free[j] then
        Begin
                L[i]:=j;
                Free[j]:=False;
                If i<k then Try(i+1) Else xuli;
                Free[j]:=True;
        End;
End;
Procedure sub1;
Var     i,j:Longint;
Begin
        FillChar(DD,sizeof(DD),0);
        For i:=1 to k do
        Begin
                Dijkstra(A[i]);
                For j:=1 to n do DD[i,j]:=D[j];
        End;
        sol:=oo;
        FillChar(Free,sizeof(Free),True);
        Try(1);
End;
Procedure Main;
Begin
        If k<=10 then sub1;
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
