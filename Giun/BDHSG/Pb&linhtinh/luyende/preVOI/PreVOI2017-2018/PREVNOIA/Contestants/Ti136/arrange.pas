const   fi      ='arrange.inp';
        fo      ='arrange.out';

var     n       :longint;
        f,g     :text;
        a       :array[0..100005] of longint;
        sum     :int64;

procedure       nhap;
var     i       :longint;
begin
        assign(f,fi);reset(f);
        readln(f,n);
        sum:=0;
        for i:=1 to n do
        begin
                read(f,a[i]);
                sum:=sum+a[i];
        end;
        close(f);
end;

function        max(i,j :longint):longint;
begin
        if i>j then exit(i) else exit(j)
end;

procedure       xl1;
var     tg,res  :int64;
        i,j,k   :longint;
        so      :longint;
begin
        tg:=sum div n;
        res:=0;
        for i:=1 to n do
                if a[i]>tg then
                begin
                        so:=a[i]-tg;
                        for j:=1 to max(n-i,i-1) do
                        begin
                                k:=i+j;
                                if k<=n then
                                if a[k]<tg then
                                begin
                                        if tg-a[k]<so then begin res:=res+(tg-a[k])*abs(i-k);dec(so,tg-a[k]);a[k]:=tg;end
                                                else begin res:=res+so*abs(i-k);inc(a[k],so);so:=0;end;
                                end;
                                if so=0 then break;
                                k:=i-j;
                                if k>=1 then
                                        if a[k]<tg then
                                        begin
                                                if tg-a[k]<so then begin res:=res+(tg-a[k])*abs(i-k);dec(so,tg-a[k]);a[k]:=tg;end
                                                        else begin res:=res+so*abs(i-k);inc(a[k],so);so:=0;end;
                                        end;
                                if so=0 then break;
                        end;
                        a[i]:=tg;
                end;
        write(g,res);
end;

procedure       xl2;
var     res,tg    :int64;
        i,j,k   :longint;
        so      :longint;
begin
        tg:=sum div n;
        res:=0;
        for i:=1 to n do
                if a[i]<tg then
                begin
                        so:=tg-a[i];
                        for j:=1 to max(n-i,i-1) do
                        begin
                                k:=i+j;
                                if k<=n then
                                if a[k]>tg then
                                begin
                                        if a[k]-tg<so then begin res:=res+(a[k]-tg)*abs(i-k);dec(so,a[k]-tg);a[k]:=tg;end
                                                else begin res:=res+so*abs(i-k);dec(a[k],so);so:=0;end;
                                end;
                                if so=0 then break;
                                k:=i-j;
                                if k>=1 then
                                        if a[k]>tg then
                                        begin
                                                if a[k]-tg<so then begin res:=res+(a[k]-tg)*abs(i-k);dec(so,a[k]-tg);a[k]:=tg;end
                                                        else begin res:=res+so*abs(i-k);dec(a[k],so);so:=0;end;
                                        end;
                                if so=0 then break;
                        end;
                        a[i]:=tg;
                end;
        for i:=1 to n do
                if a[i]>tg+1 then
                begin
                        so:=a[i]-tg-1;
                        for j:=1 to max(n-i,i-1) do
                        begin
                                k:=i+j;
                                if k<=n then
                                        if a[k]<tg+1 then begin dec(so);inc(a[k]);res:=res+abs(i-k);end;
                                if so=0 then break;
                                k:=i-j;
                                if k>=1 then
                                        if a[k]<tg+1 then begin dec(so);inc(a[k]);res:=res+abs(i-k);end;
                                if so=0 then break;
                        end;
                        a[i]:=tg+1;
                end;
        write(g,res);
end;

begin
        nhap;
        assign(g,fo);rewrite(g);
        if sum mod n =0 then xl1 else xl2;
        close(g);
end.

