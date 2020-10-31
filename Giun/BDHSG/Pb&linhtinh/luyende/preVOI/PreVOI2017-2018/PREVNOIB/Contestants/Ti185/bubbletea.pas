const
        fi='bubbletea.inp';
        fo='bubbletea.out';
        oo=50000000000000;
var
        n,k:longint;
        res,r3,rr:int64;
        KT:Array[0..50001] of boolean;
        Dad,Head,P,P1,NC:Array[0..50001] of longint;
        Adj,Next,W:Array[-50001..50001] of longint;
        KR,KR2:Array[-50001..50001] of boolean;
{------------------------------------}
procedure findroad(fv,u:longint;S:int64);
var j,v,wuv:longint;
        begin
                if u=fv then
                begin
                        rr:=S;
                        exit;
                end;
                j:=Head[u];
                while j<>0 do if not (KR[j] or KR2[j]) then
                begin
                        KR2[-j]:=true;
                        KR2[j]:=true;
                        v:=Adj[j];
                        wuv:=W[j];
                        findroad(fv,v,S+wuv);
                        if rr<>-1 then
                        begin
                                KR[j]:=true;
                                KR[-j]:=true;
                                exit;
                        end;
                end else j:=Next[j];
        end;
{------------------------------------}
procedure doit;
var o:longint;
        begin
                r3:=0;
                fillchar(KR,sizeof(KR),false);
                for o:=1 to k do if o mod 2 = 1 then
                begin
                        rr:=-1;
                        fillchar(KR2,sizeof(KR2),false);
                        findroad(P1[o+1],P1[o],0);
                        if rr=-1 then exit else if r3<rr then r3:=rr;
                        if r3>=res then exit;
                end;
                if res>r3 then res:=r3;
       end;
{------------------------------------}
procedure dfs(vt,ht:longint);
var o:longint;
        begin
                if vt=k+1 then doit;
                if vt mod 2 = 1 then
                begin
                        for o:=1 to k do
                                if KT[P[o]]=false then
                                begin
                                        P1[vt]:=P[o];
                                        KT[P[o]]:=true;
                                        dfs(vt+1,o);
                                        KT[P[o]]:=false;
                                end;
                end else
                for o:=ht+1 to k do if KT[P[o]]=false then
                begin
                        P1[vt]:=P[o];
                        KT[P[o]]:=true;
                        dfs(vt+1,0);
                        KT[P[o]]:=false;
                end;
        end;
{------------------------------------}
procedure sub1;
        begin
                res:=oo;
                dfs(1,0);
                if res=oo then write(-1) else write(Res);
        end;
{------------------------------------}
procedure findnc(u:longint);
var v,j:longint;
        begin
                inc(NC[u]);
                j:=Head[u];
                while j<>0 do
                begin
                        v:=Adj[j];
                        if v<>Dad[u] then
                        begin
                                findnc(v);
                                inc(NC[u],NC[v]);
                        end;
                        j:=Next[j];
                end;
        end;
{------------------------------------}
procedure dfs2(u:longint);
var v,j:longint;
        begin
        end;
{------------------------------------}
procedure sub2;
        begin
                findnc(1);
        end;
{------------------------------------}
procedure add(o,u,v,wuv:longint);
        begin
                Adj[o]:=v;
                W[o]:=wuv;
                Next[o]:=Head[u];
                Head[u]:=o;
        end;
{------------------------------------}
procedure make(u:longint);
var v,j,wuv:longint;
        begin
                j:=Head[u];
                while j<>0 do
                begin
                        v:=Adj[j];
                        wuv:=W[j];
                        if v<>Dad[u] then
                        begin
                                Dad[v]:=u;
                                make(v);
                        end;
                        j:=Next[j];
                end;
        end;
{------------------------------------}
procedure enter;
var o,u,v,wuv:longint;
        begin
                read(n,k);
                for o:=1 to k do read(P[o]);
                for o:=1 to n-1 do
                begin
                        read(u,v,wuv);
                        add(o,u,v,wuv);
                        add(-o,v,u,wuv);
                end;
                make(1);
                if k<=10 then sub1
                else if k = n then sub2;
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.
