uses math;
const fi='gifts.inp';
      fo='gifts.out';
var a,s,t,s1,t1:array[0..100001] of int64;
    i,n,k:longint;
    b,c,kq:int64;
begin
    assign(input,fi);  reset(input);
    assign(output,fo); rewrite(output);
    read(n,k); kq:=high(int64);
    for i:=1 to n do
    begin
         read(a[i]);
         t[i]:=t[i-1]+a[i];
         if i>=k then t1[i]:=max(t1[i-1],t[i]-t[i-k]);
    end;
    for i:=n downto 1 do
    begin
         s[i]:=s[i+1]+a[i];
         if i+k<=n+1 then s1[i]:=max(s1[i+1],s[i]-s[i+k]);
    end;
    for i:=1 to n-k+1 do kq:=min(kq,max(t1[i-1],s1[i+k]));
    write(kq);
    close(input);   close(output);
end.
