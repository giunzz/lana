const   fi      ='arrange.inp';
        fo      ='arrange.out';

var     f,g     :text;
        can,a,vt        :array[0..100005] of longint;
        n       :longint;
        tong    :int64;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi); reset(f);
        readln(f,n);
        for i:=1 to n do read(f,a[i]);
        tong:=0;
        for i:=1 to n do tong:=tong+a[i];
        close(f);
end;

procedure       sub1;
var     so,i,d,c        :longint;
        kq      :int64;
begin
        so:=tong div n;
        kq:=0; d:=1; c:=0;
        for i:=1 to n do if a[i]>so then
                begin
                        while (d<=c) and (a[i]>so) do
                                begin
                                        if a[i]-so<can[d] then
                                                begin
                                                        can[d]:=can[d]-a[i]+so;
                                                        kq:=kq+(a[i]-so)*(i-vt[d]);
                                                        a[i]:=so;
                                                end
                                        else
                                                begin
                                                        kq:=kq+can[d]*(i-vt[d]);
                                                        a[i]:=a[i]-can[d];
                                                        can[d]:=0;
                                                        inc(d);
                                                end;
                                end;
                        if a[i]>so then begin kq:=kq+(a[i]-so); a[i+1]:=a[i+1]+a[i]-so; end;
                end
                else
                begin
                        inc(c); can[c]:=so-a[i]; vt[c]:=i;
                end;
        assign(g,fo); rewrite(g);
        writeln(g,kq);
        close(g);
end;

procedure       tham;
var     ok      :boolean;
        kq      :int64;
        so,i,j,u,d,c    :longint;
begin
        so:=tong div n;
        for i:=1 to n do a[i]:=so-a[i];
        ok:=true;
        assign(g,fo); rewrite(g);
        for i:=1 to n do if (a[i]<>0) and (a[i]<>-1) then begin ok:=false; break; end;
        if ok then begin writeln(g,0); close(g); halt; end;
        kq:=0; d:=1; c:=0;
        for i:=1 to n do if a[i]>0 then
                begin
                        inc(c); vt[c]:=i; can[c]:=a[i];
                end
                else if a[i]<0 then
                begin
                        while (d<=c) and (a[i]<0) do
                                begin
                                        if 0-a[i]<can[d] then
                                                begin
                                                        can[d]:=can[d]+a[i];
                                                        kq:=kq+(a[i])*(i-vt[d]);
                                                        a[vt[d]]:=a[vt[d]]+a[i];
                                                        a[i]:=0;
                                                end
                                        else
                                                begin
                                                        kq:=kq+can[d]*(i-vt[d]);
                                                        a[i]:=a[i]+can[d];
                                                        a[vt[d]]:=a[vt[d]]-can[d];
                                                        can[d]:=0;
                                                        inc(d);
                                                end;
                                end;
                        if a[i]<-1 then begin a[i+1]:=a[i+1]-(-1-a[i]); kq:=kq+(-1-a[i]); a[i]:=-1; end;
                end;
        for i:=1 to n do if a[i]>0 then
                begin
                        for j:=1 to n do
                                begin
                                        u:=i-j;
                                        if (u>=1) and (a[u]=-1) then
                                                begin
                                                        a[u]:=0;
                                                        kq:=kq+j;
                                                        dec(a[i]);
                                                end;
                                        if a[i]=0 then break;
                                        u:=i+j;
                                        if (u<=n) and (a[u]=-1) then
                                                begin
                                                        a[u]:=0;
                                                        kq:=kq+j;
                                                        dec(a[i]);
                                                end;
                                        if a[i]=0 then break;
                                end;
                end;
        writeln(g,kq);
        close(g);
end;

begin
        nhap;
        if tong mod n =0 then sub1 else tham;
end.
