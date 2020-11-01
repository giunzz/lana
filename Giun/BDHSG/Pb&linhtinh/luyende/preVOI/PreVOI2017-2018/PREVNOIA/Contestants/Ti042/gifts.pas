uses math;
const  fi='gifts.inp';
       fo='gifts.out';
       base=1000000000;

var  n,m,kq,u,v,c:int64;
     a,f,g,h:array[0..1000005] of int64;
     s:ansistring;
     ok:boolean;
     i,j,k:longint;

procedure openf;
begin
     assign(input,fi);  assign(output,fo);
     reset(input);      rewrite(output);
end;

procedure closef;
begin
     close(input);  close(output);
end;

procedure inkq;
begin
     readln(n,k);
     for i:=1 to n do read(a[i]);
     for i:=1 to k do f[k]:=f[k]+a[i];
     g[k]:=f[k];
     for i:=k+1 to n do begin f[i]:=f[i-1]+a[i]-a[i-k]; g[i]:=max(g[i-1],f[i]); end;
     for i:=n downto k do h[i]:=max(h[i+1],f[i]);

     kq:=high(int64);
     for i:=k to n do kq:=min(kq,max(g[i-k],h[i+1]));
     writeln(kq);

end;

BEGIN
     openf;
     inkq;
     closef;
END.
