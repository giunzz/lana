{$MODE OBJFPC}
{$N+}
program teaworld;
uses math;
const
        fi='teaworld.inp';
        fo='teaworld.out';
        maxn=15;
        maxm=round(2e3);
        esp=1e-4;
var
        f1,f2:text;
        i,x,y,z,n,m,k,bit,bs,count,num,d:longint;
        tx,ty,tz,te:array[0..maxn+10] of longint;
        cx,cy,cz,cr:array[0..maxm+10] of longint;
        free:array[0..maxm+10] of boolean;
function getbit(k,x:longint):longint;
begin
        result:=(x shr (k-1)) and 1;
end;
procedure cal(k:longint);
        function Check(a,b,c,x,y,r:longint):boolean;
        var
                p:double;
        begin
                p:=abs(a*x+b*y+c)/Sqrt(Sqr(a)+ Sqr(b));
                if p>r then exit(true);
                exit(false);
        end;
        function dis(x1,y1,x2,y2:longint):double;
        begin
                result:=sqrt(sqr(x1-x2)+sqr(y1-y2));
        end;
        function check2(a,b,c,Ox,Oy,Ax,Ay,Bx,By:longint):boolean;
        var
                OA,OB,AB,OH:double;
        begin
                OA:=dis(Ox,Oy,Ax,Ay);
                OB:=dis(Ox,Oy,Bx,By);
                AB:=dis(Ax,Ay,Bx,By);
                OH:=abs(a*Ox+b*Oy+c)/Sqrt(Sqr(a)+ Sqr(b));
                if abs(sqrt(sqr(OA)+sqr(OH))+sqrt(sqr(OH)+sqr(OB))-AB)<esp then exit(true);
                exit(false);
        end;
var
        i,a,b,c:longint;
begin
        {
        a:=ty[k]-y;
        b:=x-tx[k];
        c:=-a*x-b*y;
        for i:=1 to m do
                if free[i] and check2(a,b,c,cx[i],cy[i],x,y,tx[k],ty[k]) and not check(a,b,c,cx[i],cy[i],cr[i]) then free[i]:=false;
        }

        for i:=1 to m do
                if free[i] and (abs(cx[i]-x)<=abs(tx[i]-x)) then free[i]:=false;
end;
begin
        assign(f1,fi);  reset(f1);
        assign(f2,fo);  rewrite(f2);
        readln(f1,m,n,k);
        for i:=1 to m do readln(f1,cx[i],cy[i],cz[i],cr[i]);
        for i:=1 to n do readln(f1,tx[i],ty[i],tz[i],te[i]);
        readln(f1,x,y,z);
        bs:=0;
        for bit:=1 shl n-1 downto 1 do
        begin
                count:=0;
                for num:=1 to n do
                        if getbit(num,bit)=1 then inc(count,te[num]);
                if count<=bs then continue;
                for i:=1 to m do free[i]:=true;
                for num:=1 to n do
                        if getbit(num,bit)=1 then cal(num);
                d:=0;
                for i:=1 to m do
                        if not free[i] then inc(d);
                if d<=k then bs:=max(bs,count);
        end;
        write(f2,bs);
        close(f1);      close(f2);
end.
