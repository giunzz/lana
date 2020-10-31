uses math;
const  fi='minsum.inp';
       fo='minsum.out';


var  n,m,k,kq,u,np,na,nb:int64;
     da,db,ma,mb,e,p,d,mu:array[0..1000005] of int64;
     s:ansistring;
     ok:boolean;
     a,b,r:int64;
     i,j:longint;

procedure openf;
begin
     assign(input,fi);  assign(output,fo);
     reset(input);      rewrite(output);
end;

procedure closef;
begin
     close(input);  close(output);
end;

procedure sangNT(x:int64);
begin
      for i:=1 to x do E[i]:=i;
      for i:=2 to x do if E[i]=i then
      begin
           inc(nP);
           P[nP]:=i;
           j:=2;
           while j<= x/i do
           begin
                E[i*j]:=i;
                inc(j);
           end;
      end;
end;

procedure pt(x:int64);
begin
     for i:=1 to nP do if p[i]>trunc(sqrt(x)) then break else
     if x mod p[i]=0 then
     begin
          inc(m);  d[m]:=p[i];  mu[m]:=0;
          while x mod p[i]=0 do begin inc(mu[m]); x:=x div p[i]; end;
          if x<=1000000 then if e[x]=x then break;
     end;

     if x>1 then
     begin
          inc(m);  d[m]:=x; mu[m]:=1;
     end;
end;

function gcd(a,b:int64):int64;

begin
     while b>0 do
     begin
          r:=a mod b;
          a:=b;
          b:=r;
     end;

     exit(a);
end;

procedure inkq;
begin
     readln(n);
     sangNT(1000000);
     while n>0 do
     begin
          read(a,b);
          dec(n);

          u:=gcd(a,b);
          a:=a div u;
          b:=b div u;

          m:=0;
          pt(a);   na:=m;
          for i:=1 to m do begin da[i]:=d[i]; ma[i]:=mu[i]; end;

          m:=0;
          pt(b);   nb:=m;
          for i:=1 to m do begin db[i]:=d[i]; mb[i]:=mu[i]; end;

          for i:=1 to na do
          begin
               while ma[i]>=2 do
               begin
                    a:=a div da[i];
                    a:=a div da[i];
                    dec(Ma[i],2);
               end;
          end;

          for i:=1 to nb do
          begin
               while mb[i]>=2 do
               begin
                    b:=b div db[i];
                    b:=b div db[i];
                    dec(mb[i],2);
               end;
          end;

          for i:=1 to na do
          if (ma[i]>0) and (a div da[i] + b*da[i]<a+b) then
          begin
               a:=a div da[i];
               b:=b*da[i];
          end;

          for i:=1 to nb do
          if (mb[i]>0) and (b div db[i] + a*db[i]<a+b) then
          begin
               a:=a*db[i];
               b:=b div db[i];
          end;

          writeln(a,' ',b);
     end;
end;

BEGIN
     openf;
     inkq;
     closef;
END.
