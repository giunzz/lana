const
        fi='teaworld.inp';
        fo='teaworld.out';
type    bell=record
        x,y,z,r:longint;
        end;
        shop=record
        x,y,z,e:longint;
        end;
var     m,n,k,res:longint;
        b:array[1..2000]of bell;
        a:array[0..14]of shop;
        c:array[1..2000]of longint;
        g:text;

procedure sub1;
var     i,j:longint;
begin
        for j:=1 to m do
                for i:=0 to n-1 do
                begin
                        if (abs(b[j].x-a[i].x)<=b[j].r) and (abs(b[j].x)<b[j].r)
                        or (abs(b[j].x-a[i].x)>b[j].r) and (abs(b[j].x)>=b[j].r) then inc(c[j],1 shl i)
                        else if (a[i].x-b[j].x)*(b[j].x)<0 then inc(c[j],1 shl i);
                end;
end;

function len2(b:bell ; a:shop):extended;
begin
        len2:=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
end;

function cut(i:shop ; j:bell):boolean;
var     goc:extended;
begin   //y=ax
        goc:=j.r/sqrt(len2(j,i)+j.r*j.r);
        if (i.x<>0) and (j.x<>0) then if (i.y/i.x<j.y/j.x-goc) or (i.y/i.x>j.y/j.x+goc) then exit(true)
        else exit(false);//dong nay con can sua loi
end;

procedure sub2;
var     i,j:longint;
begin
        a[n].x:=0; a[n].y:=0; a[n].z:=0;
        for i:=1 to m do
        begin
                for j:=0 to n-1 do
                begin
                        if (len2(b[i],a[j])<=b[i].r*b[i].r) and (len2(b[i],a[n])>b[i].r*b[i].r)
                        or (len2(b[i],a[j])>b[i].r*b[i].r) and (len2(b[i],a[n])<=b[i].r*b[i].r) then inc(c[i],1 shl j)
                        else if cut(a[j],b[i]) then inc(c[i],1 shl j);
                end;
        end;
end;

procedure sub3;
begin
end;

procedure solve;
var     i,j,x,d,r:longint;
        ok:boolean;
begin
        for i:=1 shl n-1 downto 0 do
        begin
                x:=i; d:=0; ok:=true;
                for j:=1 to m do
                begin
                        if x or c[j]<>i then inc(d);
                        if d>k then begin ok:=false; break; end;
                end;
                if ok then
                begin
                        r:=0;
                        for j:=0 to n-1 do
                        begin
                                if x and 1=0 then inc(r,a[j].e);
                                x:=x shr 1;
                        end;
                        if r>res then res:=r;
                end;
        end;
end;

procedure main;
var     i,xs,ys,zs:longint;
        s1c,s2c:boolean;
begin
        assign(g,fi);
        reset(g);
        read(g,m,n,k);
        s1c:=true; s2c:=true;
        for i:=1 to m do
        begin read(g,b[i].x,b[i].y,b[i].z,b[i].r); if b[i].y<>0 then s1c:=false; if b[i].z<>0 then s2c:=false; end;
        for i:=0 to n-1 do
        begin read(g,a[i].x,a[i].y,a[i].z,a[i].e); if a[i].y<>0 then s1c:=false; if a[i].z<>0 then s2c:=false; end;
        read(g,xs,ys,zs);
        for i:=1 to m do begin dec(b[i].x,xs); dec(b[i].y,ys); dec(b[i].z,zs); end;
        for i:=0 to n-1 do begin dec(a[i].x,xs); dec(a[i].y,ys); dec(a[i].z,zs); end;
        close(g);
        assign(g,fo);
        rewrite(g);
        if s1c and s2c then sub1 else if s2c then sub2 else sub3;
        solve;
        writeln(g,res);
        close(g);
end;

BEGIN
main;
END.
