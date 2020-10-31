uses math;
const  fi='arrange.inp';
       fo='arrange.out';
       base=1000000000;

var  n,m,kq,u,v,c,t,t1,t2,m1,m2,l1,r1,l2,r2:int64;
     a,s1,s2,d1,d2,s:array[0..1000000] of int64;

     ok:boolean;
     i,j,k,dem1,dem2:longint;


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
     readln(n);
     t:=0;
     for i:=1 to n do begin read(a[i]); t:=t+a[i]; end;
     u:=t div n;
     kq:=0;
     if t mod n<>0 then
     begin
          for i:=1 to n do
           kq:=kq + min(abs(u-a[i]),abs(u+1-a[i]))
     end
     else for i:=1 to n do kq:=kq + abs(u-a[i]);

     writeln(kq);

end;

BEGIN
     openf;
     inkq;
     closef;
END.
