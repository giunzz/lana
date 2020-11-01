const
fi='ARRANGE.inp';
fo='ARRANGE.out';
var
a,st,st2:array[0..100000] of longint;
n:longint;
kt:Array[1..100000] of boolean;
time:int64;
procedure enter;
var i:longint;
last,last2,s,tg,tg1:longint;
begin
        assign(input,fi);reset(input);
        assign(output,fo);rewrite(Output);
        readln(n);
        s:=0;
        time:=0;
        for i:=1 to n do begin read(a[i]);s:=s+a[i];end;
        s:=s div n;
        //first:=1; first2:=n;
        last:=0;last2:=n+1;
        for i:=n downto 1 do
        begin
        if a[i]>s then begin dec(last2);st2[last2]:=i;end;
        end;
        for i:=1 to n do
        if a[i]>s then
                begin while (st2[last2]<=i) and (last2<n+1) do inc(last2);inc(last);st[last]:=i;end
        else
                if a[i]<s then
                begin
                while (st2[last2]<=i) and (last2<n+1) do inc(last2);
                while a[i]<s do
                        begin
                        if last2=n+1 then tg:=st[last]
                        else
                        if last=0 then tg:=st2[last2]
                        else
                        if st2[last2]-i<i-st[last] then tg:=st2[last2]
                        else tg:=st[last];
                        tg1:=a[tg]-s;
                        if a[i]+tg1>s then tg1:=s-a[i];
                        dec(a[tg],tg1);
                        time:=time+tg1*abs((tg-i));
                        a[i]:=a[i]+tg1;
                        if (a[st[last]]<=s) and (last>=1) then dec(last);
                        if (a[st2[last2]]<=s) and (last2<n+1)then inc(last2);
                        end;
                end;
        //for i:=1 to n do write(a[i],' ');
        //writeln;
        //writeln(time);
        fillchar(kt,sizeof(kt),true);
        for i:=1 to last do kt[st[i]]:=false;
        for i:=1 to last do
        begin
        tg:=st[i];tg1:=st[i];
        while a[st[i]]>s+1 do
        begin
        while (tg>1) and (not kt[tg]) do dec(tg);
        while (tg1<n) and (not kt[tg1]) do inc(tg1);
        if kt[tg] and (a[st[i]]>s) then begin dec(a[st[i]]);time:=time+(st[i]-tg);kt[tg]:=false;end;
        if (kt[tg1]) and (a[st[i]]>s) then begin dec(a[st[i]]);time:=time+(tg1-st[i]);kt[tg1]:=false;end;
        end;
        end;
        writeln(time);
end;
begin
        enter;
        close(input);close(output);
end.



















