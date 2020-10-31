uses    math;
type    mang=record
                sl,gt:longint;
                end;
const   fi='TEAWORLD.inp';
        fo='TEAWORLD.out';
        maxn=5000;
var     X1,Y1,Z1,R,X2,Y2,Z2,E,X:array[1..maxn] of longint;
        kt:array[1..maxn] of boolean;
        a,b,c,kq,m,n,k,i:longint;
procedure input;
var     f:text;
        i:longint;
begin
        assign(f,fi);
        reset(f);
        read(f,m,n,k);
        for i:=1 to m do
                read(f,X1[i],Y1[i],Z1[i],R[i]);
        for i:=1 to n do
                read(f,X2[i],Y2[i],Z2[i],E[i]);
        read(f,a,b,c);
        close(f);
end;
function ktt(i,j:longint):boolean;
var     ktt1,ktt2:boolean;
begin
        ktt1:=false;
        ktt2:=false;
        if ((X1[j]<X2[i]) and (X1[j]<a)) or ((X1[j]>X2[i]) and (X1[j]>a)) then ktt1:=true;
        if ((Y1[j]<Y2[i]) and (Y1[j]<b)) or ((Y1[j]>Y2[i]) and (Y1[j]>b)) then ktt2:=true;
        if (ktt1) and (ktt2) then exit(true);
        exit(false);
end;
function check(i,j:longint):boolean;
var     aa,bb,cc,tg1,tg2,tg3,tg4:longint;
begin
        aa:=b-Y2[i];
        bb:=X2[i]-a;
        cc:=-aa*X2[i]-bb*Y2[i];
        tg1:=sqr(X2[i]-X1[j]);
        tg2:=sqr(Y2[i]-Y1[j]);
        tg3:=sqr(a-X1[j]);
        tg4:=sqr(b-Y1[j]);
        if (tg1+tg2<=sqr(R[j])) and (tg3+tg4<=sqr(R[j])) then exit(false);
        if (tg1+tg2=sqr(R[j])) and (tg3+tg4>sqr(R[j])) then exit(true);
        if (tg1+tg2>sqr(R[j])) and (tg3+tg4=sqr(R[j])) then exit(true);
        if (tg1+tg2>sqr(R[j])) and (tg3+tg4<sqr(R[j])) then exit(true);
        if (tg1+tg2<sqr(R[j])) and (tg3+tg4>sqr(R[j])) then exit(true);
        if (sqr(aa*X1[j]+bb*Y1[j]+cc)>(sqr(aa)+sqr(bb))*sqr(R[j])) then exit(false);
        if ktt(i,j) then exit(false);
        exit(true);
end;
procedure sub;
var     i,s,t,j:longint;
begin
        s:=0;
        t:=0;
        fillchar(kt,sizeof(kt),true);
        for i:=1 to n do
                if X[i]=1 then
                        begin
                                for j:=1 to m do
                                        if check(i,j) then
                                                kt[j]:=false;
                                s:=s+E[i];
                        end;
        for i:=1 to m do
                if kt[i]=false then inc(t);
        if t>k then exit;
        kq:=max(kq,s);
end;
procedure tryTEA(i:longint);
var     j:longint;
begin
        for j:=0 to 1 do
                begin
                        X[i]:=j;
                        if i=n then sub
                        else tryTEA(i+1);
                end;
end;
procedure output;
var     f:text;
begin
        assign(f,fo);
        rewrite(f);
        write(f,kq);
        close(f);
end;
begin
        input;
        fillchar(X,sizeof(X),0);
        tryTEA(1);
        output;
end.
