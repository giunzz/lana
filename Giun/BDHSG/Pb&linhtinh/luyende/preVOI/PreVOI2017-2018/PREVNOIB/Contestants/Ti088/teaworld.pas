const   fi      ='teaworld.inp';
        fo      ='teaworld.out';
type    point   =record
        x,y,z,r :longint;
        end;
var     f,g     :text;
        m,n,k,dem,kq1   :longint;
        ok,ok1  :boolean;
        a       :array[0..16] of point;
        b       :array[0..2005] of point;
        dd,sl,tt,cl     :array[0..2005] of longint;
        xd      :array[0..21,0..2005] of longint;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi); reset(f);
        readln(f,m,n,k);
        ok:=true; ok1:=true;
        for i:=1 to m do
                begin
                        read(f,b[i].x,b[i].y,b[i].z,b[i].r);
                        if b[i].z<>0 then ok:=false;
                        if b[i].y<>0 then ok1:=false;
                end;
        for i:=1 to n do
                begin
                        read(f,a[i].x,a[i].y,a[i].z,a[i].r);
                        if a[i].z<>0 then ok:=false;
                        if a[i].y<>0 then ok1:=false;
                end;
        read(f,a[0].x,a[0].y,a[0].z);
        if a[0].z<>0 then ok:=false;
        if a[0].y<>0 then ok1:=false;
        close(f);
end;

function        kc(i,j  :longint):real;
begin
        kc:=sqrt(sqr(a[i].x-b[j].x)+sqr(a[i].y-b[j].y));
end;

procedure       ktra;
var     so,sll,dem1,i,j :longint;
begin
        inc(dem);
        so:=0; sll:=0; dem1:=0;
        for i:=1 to n do if cl[i]=1 then
                begin
                        inc(sll);
                        if dd[sll]=0 then continue;
                        for j:=1 to sl[i] do if tt[xd[i,j]]<>dem then begin inc(dem1); tt[xd[i,j]]:=dem; end;
                        so:=so+a[i].r;
                end;
        if (dem1<=k) and (so>kq1) then kq1:=so;
end;

procedure       di(i    :longint);
var     j       :longint;
begin
        for j:=0 to 1 do
                begin
                        dd[i]:=j;
                        if i=m then ktra else di(i+1);
                end;
end;

procedure       sub1;
var     mm,i,j,so1,so2  :longint;
        kq      :longint;
begin
        mm:=0; dem:=0; kq:=0;
        for i:=1 to n do
                begin
                        sl[i]:=0;
                        for j:=1 to m do
                        begin
                                so1:=abs(b[j].x-a[i].x);
                                so2:=abs(b[j].x-a[0].x);
                                if (so1<=b[j].r) and (so2<=b[j].r) then continue;
                                if ((so1<=b[j].r) and (so2>b[j].r)) or ((so1>b[j].r) and (so2<=b[j].r)) then
                                        begin
                                                inc(sl[i]);
                                                xd[i,sl[i]]:=j;
                                                continue;
                                        end;
                                if (a[i].x-b[j].x)*(a[0].x-b[j].x)<0 then
                                        begin
                                                inc(sl[i]);
                                                xd[i,sl[i]]:=j;
                                        end;
                        end;
                        if sl[i]=0 then kq:=kq+a[i].r else begin inc(mm); cl[i]:=1; end;
                end;
        m:=mm; kq1:=0;
        if n>0 then di(1);
        assign(g,fo); rewrite(g);
        writeln(g,kq+kq1);
        close(g);
end;

procedure       sub2;
var     mm,i,j,aa,bb,cc,so3,so4,mx,my,u,vv  :longint;
        so,so1,so2,v:real;
        kq      :longint;
        ok2     :boolean;
begin
        mm:=0; dem:=0; kq:=0;
        for i:=1 to n do
                begin
                        sl[i]:=0;
                        so3:=a[i].x-a[0].x; so4:=a[i].y-a[0].y;
                        aa:=-so4; bb:=so3;
                        cc:=-aa*a[0].x-bb*b[0].x;
                        if a[i].x<a[0].x then begin mx:=a[i].x; my:=a[0].x; end else begin mx:=a[0].x; my:=a[i].x; end;
                        for j:=1 to m do
                        begin
                                so1:=kc(i,j);
                                so2:=kc(0,j);
                                if (so1<=b[j].r) and (so2<=b[j].r) then continue;
                                if ((so1<=b[j].r) and (so2>b[j].r)) or ((so1>b[j].r) and (so2<=b[j].r)) then
                                        begin
                                                inc(sl[i]);
                                                xd[i,sl[i]]:=j;
                                                continue;
                                        end;
                                so:=abs(aa*b[j].x+bb*b[j].y+cc);
                                so:=so/sqrt(sqr(aa)+sqr(bb));
                                if so<=b[i].r then
                                        begin
                                                v:=sqrt(sqr(a[i].x-a[0].x)+sqr(a[i].y-a[0].y));
                                                if (v<so1-b[i].r) and (v<so2-b[i].r) then continue;
                                                inc(sl[i]);
                                                xd[i,sl[i]]:=j;
                                        end;
                        end;
                        if sl[i]=0 then kq:=kq+a[i].r else begin inc(mm); cl[i]:=1; end;
                end;
        m:=mm; kq1:=0;
        if n>0 then di(1);
        assign(g,fo); rewrite(g);
        writeln(g,kq+kq1);
        close(g);
end;

begin
        nhap;
        if (ok) and (ok1) then sub1 else
        sub2;
end.