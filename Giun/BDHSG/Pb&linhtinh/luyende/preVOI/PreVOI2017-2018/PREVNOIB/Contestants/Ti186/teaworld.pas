const   fi='teaworld.inp';
        fo='teaworld.out';
        maxn=round(2000);
        maxd=round(1e6);
var
        m,n,k:longint;
        x,y,z,a:array[0..maxn]of longint;
        x2,y2,z2,a2:array[0..20]of longint;
        f1,f2:array[-500..500,1..2]of int64;
        xd:array[-500..500]of longint;
        u,v,t:longint;
procedure nhap;
var     i:longint;
begin
        assign(input,fi);reset(input);
        read(m,n,k);
        for i:=1 to m do read(x[i],y[i],z[i],a[i]);
        for i:=1 to n do read(x2[i],y2[i],z2[i],a2[i]);
        read(u,v,t);
end;
procedure xay1;
var     i,j:longint ;
begin
         for i:=u to 10 do
                begin
                if xd[i]=1 then inc(f1[i,1]);
                        f1[i,1]:=f1[i-1,1]+f1[i,1];
                if xd[i]<0 then inc(f1[i,2],xd[i]);
                        f1[i,2]:=f1[i-1,2]+f1[i,2];
                end;
        for i:=u downto -10 do
                begin
                if xd[i]=1 then inc(f2[i,1]);
                        f2[i,1]:=f2[i+1,1]+f2[i,1];
                if xd[i]<0 then inc(f2[i,2],xd[i]);
                        f2[i,2]:=f2[i+1,2]+f2[i,2];
                end;
end;
procedure xuli1;
var     i,j,s:longint;
        res,s1,s2,t1,t2:longint;
begin
        assign(output,fo);rewrite(output);
        res:=0;
        for i:=1 to m do
                begin
                xd[x[i]]:=1;
                end;
        for i:=1 to n do
                xd[x2[i]]:=-a2[i];
        s:=0;
        xay1;

        for i:=u to 10 do
                for j:= u downto -10 do
                        if f1[i,1]+f2[j,1]<=k then
                                begin
                                if (res<abs(f1[i,2]+f2[j,2]))and(f2[j,2]<>f2[j-1,2])or(f1[i,2]<>f1[i,2]) then res:=abs(f1[i,2]+f2[j,2]);
                                end
                                else break;
        write(res);
end;
begin
        nhap;
        xuli1;
end.














