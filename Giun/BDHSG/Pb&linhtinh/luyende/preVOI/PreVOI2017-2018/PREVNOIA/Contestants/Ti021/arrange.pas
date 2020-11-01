{$MODE OBJFPC}
{$OPTIMIZATION LEVEL2}
program arrange;
uses gset;
const
        fi='arrange.inp';
        fo='arrange.out';
        maxn=round(1e5);
        oo=maxlongint;
type
        Comparer=class
                class function c(x,y:longint):boolean;
        end;

        TMySet=specialize TSet<Longint,Comparer>;

        class function Comparer.c(x,y:longint):boolean;
        begin
                exit(x<y);
        end;
var
        f1,f2:text;
        S:TMySet;
        a:array[0..maxn+10] of longint;
        i,n,bs,v1,v2,k,kq,p1,p2:longint;
begin
        assign(f1,fi);  reset(f1);
        assign(f2,fo);  rewrite(f2);
        readln(f1,n);
        for i:=1 to n do
        begin
                read(f1,a[i]);
                bs:=bs+int64(a[i]);
        end;
        bs:=bs div n;
        S:=TMySet.Create;
        for i:=1 to n do
                if a[i]<bs then S.Insert(i);
        for i:=1 to n do
                while (a[i]>bs+1) and not S.IsEmpty do
                begin
                        p1:=i;  p2:=i;
                        if S.FindLess(p1)<>nil then v1:=S.FindLess(p1).Data
                        else v1:=oo;
                        if S.FindGreater(p2)<>nil then v2:=S.FindGreater(p2).Data
                        else v2:=oo;
                        if abs(v1-i)<=abs(v2-i) then k:=v1
                        else k:=v2;
                        if a[i]-bs-1>=bs-a[k] then
                        begin
                                dec(a[i],bs-a[k]);
                                inc(kq,(bs-a[k])*abs(k-i));
                                S.Delete(k);
                                a[k]:=bs;
                        end
                        else
                        begin
                                inc(a[k],a[i]-bs-1);
                                inc(kq,(a[i]-bs-1)*abs(k-i));
                                a[i]:=bs+1;
                        end;
                end;
        S.Free;
        for i:=1 to n do
                if a[i]>bs then S.Insert(i);
        for i:=1 to n do
                while (a[i]<bs) and not S.IsEmpty do
                begin
                        p1:=i;  p2:=i;
                        if S.FindLess(p1)<>nil then v1:=S.FindLess(p1).Data
                        else v1:=oo;
                        if S.FindGreater(p2)<>nil then v2:=S.FindGreater(p2).Data
                        else v2:=oo;
                        if abs(v1-i)<=abs(v2-i) then k:=v1
                        else k:=v2;
                        if a[k]-bs>=bs-a[i] then
                        begin
                                dec(a[k],bs-a[i]);
                                inc(kq,(bs-a[i])*abs(k-i));
                                a[i]:=bs;
                        end
                        else
                        begin
                                inc(a[i],a[k]-bs);
                                inc(kq,(a[k]-bs)*abs(k-i));
                                S.delete(k);
                                a[k]:=bs;
                        end;
                end;
        S.Free;
        write(f2,kq);
        close(f1);      close(f2);
end.
