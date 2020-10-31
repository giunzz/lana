uses    math;

var     n,k:longint;
        s,m,kq,x,cc:int64;
        a,t:array[0..1000000] of int64;
        b:array[1..6000000] of int64;

procedure MoFile;
begin
        assign(input,'GIFTS.inp');
        assign(output,'GIFTS.out');
        reset(input);
        rewrite(output);
end;

procedure DongFile;
begin
        close(input);
        close(output);
end;

procedure Doc;
var     i:longint;
begin
        read(n,k);
        for i:=1 to n do
        begin
            read(a[i]);
            t[i]:=t[i-1]+a[i];
        end;
end;

procedure SUB1;
var     i,j:longint;
        ok:boolean;
begin
        x:=high(int64);
        for i:=k to n do
        begin
            s:=t[i]-t[i-k];
            cc:=max(cc,s);
            kq:=0;
            ok:=true;
            for j:=k to n do
            begin
                if (i-k<j) and (j<=i) then continue;
                m:=t[j]-t[j-k];
                if m>s then
                begin
                    ok:=false;
                    break;
                end;
                kq:=max(kq,m);
            end;
            if ok then x:=min(x,kq);
        end;
        if x=high(int64) then x:=cc;
        writeln(x);
        halt;
end;

procedure Update(k,L,R,i,j:longint;w:int64);
var     M,luu:longint;
begin
        if (R<i) or (j<L) then exit;
        if (i<=L) and (R<=j) then
        begin
            b[k]:=max(b[k],w);
            exit;
        end;
        M:=(L+R) div 2;
        Update(2*k,L,M,i,j,w);
        Update(2*k+1,M+1,R,i,j,w);
        b[k]:=max(b[2*k],b[2*k+1]);
end;

procedure Find(k,L,R,i,j:longint);
var     M,luu:longint;
begin
        if i>j then exit;
        if (R<i) or (j<L) then exit;
        if (i<=L) and (R<=j) then
        begin
            kq:=max(kq,b[k]);
            exit;
        end;
        M:=(L+R) div 2;
        Find(2*k,L,M,i,j);
        Find(2*k+1,M+1,R,i,j);
end;

procedure SUB2;
var     i,j:longint;
begin
        x:=high(int64);
        for i:=k to n do Update(1,1,n,i,i,t[i]-t[i-k]);
        for i:=k to n do
        begin
            s:=t[i]-t[i-k];
            cc:=max(cc,s);
            kq:=0;
            Find(1,1,n,k,i-k);
            Find(1,1,n,i+1,n);
            if kq<=s then x:=min(x,kq);
        end;
        if x=high(int64) then x:=cc;
        writeln(x);
end;

procedure Xuly;
var     i:longint;
begin
        if n<=5000 then SUB1;
        SUB2;
end;

BEGIN
        MoFile;
        Doc;
        XuLy;
        DongFile;
END.
