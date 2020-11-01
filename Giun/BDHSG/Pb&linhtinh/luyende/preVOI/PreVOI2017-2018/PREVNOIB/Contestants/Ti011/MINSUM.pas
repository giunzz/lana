uses    math;
type    mang=record
                aa,bb:longint;
                end;
const   fi='MINSUM.inp';
        fo='MINSUM.out';
        maxn=5000;
var     A,B:array[1..maxn] of longint;
        t,d,c:longint;
        Q:array[1..maxn] of mang;
        kttt:array[1..maxn,1..maxn] of boolean;
        kt:array[1..maxn] of boolean;
procedure input;
var     f:text;
        i:longint;
begin
        assign(f,fi);
        reset(f);
        read(f,t);
        for i:=1 to t do read(f,A[i],B[i]);
        close(f);
end;
function ktt(i:longint):boolean;
var     j:longint;
begin
        if i=1 then exit(true);
        for j:=2 to i-1 do
                if i mod j=0 then exit(false);
        exit(true);
end;
procedure taomang;
var     i:longint;
begin
        fillchar(kt,sizeof(kt),true);
        for i:=1 to maxn do
        if ktt(i) then kt[i]:=false;
end;
function sub(k:longint):mang;
var     i:longint;
        kq:mang;
begin

        d:=1;
        c:=1;
        fillchar(kttt,sizeof(kttt),true);
        Q[1].aa:=A[k];
        Q[1].bb:=B[k];
        kttt[Q[1].aa,Q[1].bb]:=false;
        while d<=c do
                begin
                        if (kt[Q[d].aa]=true) or (kt[Q[d].bb]=true) then
                        begin
                        for i:=2 to Q[d].aa do
                                if Q[d].aa mod i=0 then
                                        if kttt[Q[d].aa div i,Q[d].bb*i]=true then
                                        begin
                                                inc(c);
                                                Q[c].aa:=Q[d].aa div i;
                                                Q[c].bb:=Q[d].bb*i;
                                                kttt[Q[c].aa,Q[c].bb]:=false;
                                        end;
                        for i:=2 to Q[d].bb do
                                if Q[d].bb mod i=0 then
                                        if kttt[Q[d].aa*i,Q[d].bb div i]=true then
                                        begin
                                                inc(c);
                                                Q[c].aa:=Q[d].aa*i;
                                                Q[c].bb:=Q[d].bb div i;
                                                kttt[Q[c].aa,Q[c].bb]:=false;
                                        end;
                        for i:=2 to min(Q[d].aa,Q[d].bb) do
                                if (Q[d].aa mod i=0) and (Q[d].bb mod i=0) then
                                        if kttt[Q[d].aa div i,Q[d].bb div i]=true then
                                                begin
                                                        inc(c);
                                                        Q[c].aa:=Q[d].aa div i;
                                                        Q[c].bb:=Q[d].bb div i;
                                                        kttt[Q[c].aa,Q[c].bb]:=false;
                                                end;
                        end;
                        inc(d);
                end;
        kq.aa:=A[k];
        kq.bb:=A[k];
        for i:=1 to c do
                if kq.aa+kq.bb>Q[i].aa+Q[i].bb then
                        begin
                                kq.aa:=Q[i].aa;
                                kq.bb:=Q[i].bb;
                        end;
        exit(kq);
end;
procedure output;
var     f:text;
        i:longint;
        kq:mang;
begin
        assign(f,fo);
        rewrite(f);
        for i:=1 to t do
                begin
                        kq:=sub(i);
                        writeln(f,kq.aa,' ',kq.bb);
                end;
        close(f);
end;
begin
        input;
        taomang;
        output;
end.