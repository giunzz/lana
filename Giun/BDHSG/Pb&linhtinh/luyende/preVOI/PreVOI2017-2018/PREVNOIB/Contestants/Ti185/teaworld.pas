const
        fi='teaworld.inp';
        fo='teaworld.out';
type
        cau=record x,y,z,r:longint end;
        cuahang=record x,y,z,e:longint end;
var
        ktsub1,ktsub2:boolean;
        m,n,k,sx,sy,sz,res,mc:longint;
        A:Array[0..2001] of cau;
        B,C:Array[0..16] of cuahang;
{------------------------------------}
procedure swap(var xx1,xx2:longint);
var tg:longint;
        begin
                tg:=xx1;xx1:=xx2;xx2:=tg;
        end;
{------------------------------------}
procedure doit;
var i,j,dem,l,r,td1,td2:longint;
        begin
                dem:=0;
                for i:=1 to m do
                begin
                        l:=A[i].x-A[i].r;
                        r:=A[i].x+A[i].r;
                        for j:=1 to mc do
                        begin
                                td1:=sx;
                                td2:=C[j].x;
                                if td1>td2 then swap(td1,td2);
                                if not (((td1>=l) and (td2<=r)) or (td2<l) or (td1>r)) then
                                begin
                                        inc(dem);
                                        break;
                                end;
                        end;
                end;
                if dem<=k then
                begin
                        dem:=0;
                        for i:=1 to mc do inc(dem,C[i].e);
                        if res<dem then res:=dem;
                end;
        end;
{------------------------------------}
procedure dfs(vt:longint);
var o:longint;
        begin
                doit;
                inc(mc);
                for o:=vt to n do
                begin
                        C[mc]:=B[o];
                        dfs(o+1);
                end;
                dec(mc);
        end;
{------------------------------------}
procedure sub1;
        begin
                dfs(1);
                write(res);
        end;
{------------------------------------}
procedure enter;
var o:longint;
        begin
                ktsub1:=true;
                ktsub2:=true;
                read(m,n,k);
                for o:=1 to m do
                begin
                        read(A[o].x,A[o].y,A[o].z,A[o].r);
                        if (A[o].z<>0) or (A[o].y<>0) then ktsub1:=false;
                        if A[o].z<>0 then ktsub2:=false;
                end;
                for o:=1 to n do
                begin
                        read(B[o].x,B[o].y,B[o].z,B[o].e);
                        if (B[o].z<>0) or (B[o].y<>0) then ktsub1:=false;
                        if B[o].z<>0 then ktsub2:=false;
                end;
                read(sx,sy,sz);
                if (sz<>0) or (sy<>0) then ktsub1:=false;
                if sz<>0 then ktsub2:=false;
                if ktsub1 then sub1 else
                if ktsub2 then sub1 else sub1;
        end;
{------------------------------------}
begin
        assign(input,fi); reset(input);
        assign(output,fo);rewrite(output);
        enter;
end.
