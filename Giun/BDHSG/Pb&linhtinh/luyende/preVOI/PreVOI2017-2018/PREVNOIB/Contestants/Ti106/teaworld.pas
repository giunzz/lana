const   fi      ='teaworld.inp';
        fo      ='teaworld.out';
        maxn    =2005;

type    point   =record
        x,y,z,e :longint;
        end;

var     f,g     :text;
        a       :array[0..20] of point;
        sl      :array[0..20] of longint;
        xd,c    :array[-505..505] of longint;
        pha     :array[0..15,0..2000] of longint;
        b       :array[0..2004] of point;
        m,n,k,res     :longint;
        xp            :point;

procedure       sort(l,r        :longint);
var     i,j,tg,xx       :longint;
begin
        i:=l; j:=r;
        xx:=b[(i+j) div 2].x;
        repeat
                while b[i].x<xx do inc(i);
                while b[j].x>xx do dec(j);
                if i<=j then
                        begin
                                tg:=b[i].x; b[i].x:=b[j].x; b[j].x:=tg;
                                inc(i); dec(j);
                        end;
        until i>j;
        if i<r then sort(i,r);
        if l<j then sort(l,j);
end;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);   reset(f);
        read(f,m,n,k);
        for i:=1 to m do read(f,b[i].x,b[i].y,b[i].z,b[i].e);
        for i:=1 to n do read(f,a[i].x,a[i].y,a[i].z,a[i].e);
        read(f,xp.x,xp.y,xp.z);
        close(f);
end;

function        get(i,j :longint):longint;
begin
        exit((i shr j) and 1);
end;

procedure       xuli;
var     i,j,m1,m2,kc,so,u,v       :longint;
begin
        res:=0;
        for i:=1 to m do xd[b[i].x]:=i;
        for i:=1 to 1 shl n-1 do
                begin
                        m1:=xp.x; m2:=xp.x; kc:=0;
                        for j:=0 to n-1 do
                        if get(i,j)=1 then
                                begin
                                        kc:=kc+a[j+1].e;
                                        if m1>a[j+1].x then m1:=a[j+1].x;
                                        if m2<a[j+1].x then m2:=a[j+1].x;
                                end;
                       // if m1>xp.x then m1:=xp.x;
                       // if m2<xp.x then m2:=xp.x;
                        so:=0;
                        for j:=1 to m do
                        begin
                                u:=b[j].x-b[j].e; v:=b[j].x+b[j].e;
                                if ((v<=m2) and (v>=m1)) or ((u>=m1) and (u<=m2)) then inc(so);
                                if so>k then break;
                        end;
                        if (so<=k) and (res<kc) then res:=kc;
                end;
end;

procedure       inkq;
begin
        assign(g,fo);   rewrite(g);
        write(g,res);
        close(g);
end;

begin
        nhap;
        xuli;
        inkq;
end.
