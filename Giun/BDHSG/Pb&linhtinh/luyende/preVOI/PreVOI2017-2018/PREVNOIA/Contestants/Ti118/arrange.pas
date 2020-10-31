const fi='arrange.inp';
      fo='arrange.out';
var n,i,x,y:longint;
    a:array[1..100000] of int64;
    sum,kq:int64;
begin
    assign(input,fi);  reset(input);
    assign(output,fo); rewrite(output);
    read(n);
    for i:=1 to n do begin read(a[i]); sum:=sum+a[i]; end;
    y:=sum-(sum div n)*n;
    x:=n-y;
    for i:=1 to n do if a[i]>sum div n then
    begin
         if y>0 then
         begin
            dec(y);
            inc(kq,a[i]-(sum div n)-1);
            continue;
         end else  inc(kq,a[i]-sum div n);
    end;
    write(kq);
    {for i:=1 to n do if a[i]>sum div n then begin  inc(cc);  ans[cc]:=i; end;
    for i:=1 to n do
    begin
        if (a[i]<sum div n) then
        begin
            j:=bsl(i,1,cc);
            k:=bsr(i,1,cc);
            if i-ans[j]>=ans[k]-i then
            begin
                while (a[i]<sum div n) and (k<cc) do
                begin
                   res:=a[i]+a[ans[k]];
                   if res>=2*sum div n then
                   begin
                      a[i]:=sum div n;
                      a[ans[k]]:=res-a[i];
                   end else
                   begin
                      a[ans[k]]:=sum div n;
                      a[i]:=res-a[ans[k]];
                      k:=k+1;
                      dd[k]:=-1;
                   end;
                end;
            end else
            begin
                while (a[i]<sum div n) and (j>1) do
                begin
                   res:=a[i]+a[ans[j]];
                   if res>=2*sum div n then
                   begin
                      a[i]:=sum div n;
                      a[ans[j]]:=res-a[i];
                   end else
                   begin
                      a[ans[j]]:=sum div n;
                      a[i]:=res-a[ans[j]];
                      j:=j-1;
                      dd[j]:=-1;
                   end;
                end;
            end;
        end;
    end;}
    close(input);  close(output);
end.





