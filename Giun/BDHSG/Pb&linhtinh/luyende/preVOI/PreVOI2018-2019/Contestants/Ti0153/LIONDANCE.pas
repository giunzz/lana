var     f,g:text;
        n,k,i,d,kqq:longint;
        x,a,b,kq:array[1..100] of longint;
        st:ansistring;
function ss(st1,st2:ansistring):boolean;
begin
        while length(st1)<length(st2) do st1:='0'+st1;
        while length(st2)<length(st1) do st2:='0'+st2;
        if st1>st2 then exit(true) else exit(false);
end;
procedure xl2;
var     i,j:longint;
        st1:ansistring;
        aa:array[1..100] of longint;
begin
        d:=0;
        for i:=1 to n do if x[i]=1 then
        begin
                inc(d); aa[d]:=a[i];
        end;
        for i:=2 to d do if abs(aa[i]-aa[i-1])>k then exit();
        i:=1;
        for j:=1 to n do if b[j]=aa[i] then inc(i);
        if i<=d then exit;
        for i:=1 to d do st1:=st1+chr(aa[i]+48);
        if ss(st1,st) then
        begin
                for i:=1 to d do kq[i]:=aa[i];
                kqq:=d; st:=st1;
        end;
end;
procedure xl(i:longint);
var  j:longint;
begin
        for j:=0 to 1 do
        begin
                x[i]:=j;
                if i=n then
                xl2
                else xl(i+1);
        end;
end;
begin
        assign(f,'LIONDANCE.INP'); reset(f);
        assign(g,'LIONDANCE.OUT'); rewrite(g);
        readln(f,n,k);
        for i:=1 to n do read(f,a[i]); readln(f);
        for i:=1 to n do read(f,b[i]);
        xl(1);
        writeln(g,kqq);
        for i:=1 to kqq do write(g,kq[i],' ');
        close(f);
        close(g);
end.