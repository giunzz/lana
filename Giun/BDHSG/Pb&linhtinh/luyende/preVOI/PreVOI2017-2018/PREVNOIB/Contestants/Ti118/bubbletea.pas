const fi='bubbletea.inp';
      fo='bubbletea.out';
var n,k,i,kq,u,v,c:longint;
    a:array[1..500000] of longint;
begin
    assign(input,fi);  reset(input);
    assign(output,fo); rewrite(output);
    read(n,k);
    for i:=1 to k do read(a[i]);
    for i:=1 to n-1 do
    begin
        read(u,v,c);
        if c>kq then kq:=c;
    end;
    write(kq);
    close(input);  close(output);
end.