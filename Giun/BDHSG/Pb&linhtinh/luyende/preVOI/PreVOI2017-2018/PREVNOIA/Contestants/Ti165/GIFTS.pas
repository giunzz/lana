const nmax=1000000;
      fi='GIFTS.INP'; 
      fo ='GIFTS.OUT';
var n,k:longint;
    f:array[1..nmax] of longint;
    sum:array[0..nmax] of int64;
procedure nhap;
var i,a:longint;
    f1:text;
begin
    sum[0]:=0;
    assign(f1,fi);
    reset(f1);
    readln(f1,n,k);
    for i:=1 to n do 
         begin
             read(f1,a);
            sum[i]:=sum[i-1]+a;
        end;
    close(f1);       
end; 
procedure sort(l,r:longint);
var i,j,p,tg:longint;
begin
    if l>=r then exit;
    i := l;j:=r;
    p := f[(l+r) div 2];
    repeat
        while f[i]<p do  inc(i);
        while f[j]>p do dec(j);
        if i<=j then 
            begin
                tg := f[i];
                f[i]:=f[j];
                f[j]:=tg;
                inc(i); dec(j);
            end;
        
    until i>j ;
    sort(l,j); sort(i,r);
end;
procedure duyet;
var i,cnt:longint;
    f2:text;
begin
    assign(f2,fo);
    rewrite(f2);
    i   := 1;
    cnt := 0;
    while (i+k)<= n do
       begin
           inc(cnt);
           f[cnt]:= sum[k+i-1]-sum[i-1];
           inc(i);
       end;
       sort(1,cnt);
       writeln(f2,f[cnt-1]);
     close(f2);
   
end;
begin
    nhap;
    duyet;
end.   
      