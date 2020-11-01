const fi='minsum.inp';
      fo='minsum.out';
      maxn=1000;
var a,b,np,nn,ss,s,ans1,ans2,minn,kt:int64;
    e,p,m,c:array[0..maxn] of longint;
    aa,bb:array[0..2,0..maxn] of int64;
    nho,f:array[0..500,0..100000]  of boolean;
//----------------
procedure sangnt;
var i,j:longint;
begin
      for i:=1 to maxn do e[i]:=i;
      for i:=2 to maxn do
      begin
            if e[i]=i then
            begin
                  inc(nP); P[nP]:=i;
                  j:=1;
                  while j<=maxn/i do
                  begin
                        e[i*j]:=i;
                        inc(j);
                  end;
            end;
      end;
end;
//----------------
procedure phantich(x,y:int64);
var i:longint;
begin
      m[y]:=0;
      for i:=1 to np do
      begin
            if x=1 then break;
	    if p[i] > x/p[i] then
	    begin
                  inc(m[y]); aa[y,m[y]]:=x; bb[y,m[y]]:=1;
                  break;
            end;
	    if x mod p[i]=0 then
	    begin
 	          inc(m[y]); aa[y,m[y]]:=p[i]; bb[y,m[y]]:=0;
		  while x mod p[i]=0 do
		  begin
			inc(bb[y,m[y]]);
			x:=x div p[i];
		  end;
	    end;
      end;
End;
//----------------
function gcd(x,y:longint):longint;
var r:longint;
begin
      while y>0 do
      begin
            r:=x mod y;
            x:=y;
            y:=r;
      end;
      exit(x);
end;
//----------------
procedure try(x:longint);
var tg:int64;
    i:longint;
begin
      for i:=0 to 1 do
      begin
            if i=1 then ss:=ss*c[x];
            if (x=nn)and(ss<>0) then
            begin
                  tg:=s div ss;
                  if ss+tg<minn then
                  begin
                        minn:=ss+tg;
                        ans1:=ss;
                        ans2:=tg;
                  end;
            end
            else try(x+1);
            if i=1 then ss:=ss div c[x];
      end;
end;
//----------------
function calc(x,y:longint):boolean;
var i:longint;
begin
      if y>100000 then
      begin
            exit(false);
      end;
      if x>nn then
      begin
            if y=kt then exit(true)
            else exit(false);
      end;
      if nho[x,y] then exit(f[x,y]);
      nho[x,y]:=true;
      for i:=0 to 1 do
      begin
            if (i=0)and(calc(x+1,y)) then
            begin
                  f[x,y]:=true;
                  exit(true);
            end
            else
                  if calc(x+1,y*c[x]) then
                  begin
                        f[x,y]:=true;
                        exit(true);
                  end;
      end;
      exit(f[x,y]);
end;
//----------------
procedure xuli;
var i,j:longint;
begin
      i:=gcd(a,b);
      a:=a div i;
      b:=b div i;
      s:=a*b;
      phantich(a,1);
      phantich(b,2);

      nn:=0;
      for i:=1 to m[1] do
            bb[1,i]:=bb[1,i] mod 2;
      for i:=1 to m[2] do
            bb[2,i]:=bb[2,i] mod 2;

      a:=1;
      for i:=1 to m[1] do
      begin
            for j:=1 to bb[1,i] do
            begin
                  inc(nn);
                  c[nn]:=aa[1,i];
                  a:=a*c[nn];
            end;
      end;
      if a=1 then
      begin
            inc(nn);
            c[nn]:=1;
      end;
      b:=1;
      for i:=1 to m[2] do
      begin
            for j:=1 to bb[2,i] do
            begin
                  inc(nn);
                  c[nn]:=aa[2,i];
                  b:=b*c[nn];
            end;
      end;
      if b=1 then
      begin
            inc(nn);
            c[nn]:=1;
      end;
      s:=a*b;
      ss:=1;
      minn:=high(int64);
      if nn<=20 then
      begin
            try(1);
            writeln(ans1,' ',ans2);
      end
      else
      begin
            if trunc(sqrt(s))<=100000 then
            for i:=trunc(sqrt(s)) downto 1 do
            begin
                  fillchar(nho,sizeof(nho),false);
                  fillchar(f,sizeof(f),false);
                  kt:=i;
                  if calc(1,1) then
                  begin
                        writeln(i,' ',s div i);
                        exit;
                  end;
            end;
      end;
end;
//----------------
procedure doc;
var t:longint;
begin
      read(t);
      while t>0 do
      begin
            dec(t);
            read(a,b);
            xuli;
      end;
end;
//----------------
begin
      assign(input,fi); reset(input);
      assign(output,fo); rewrite(output);
      sangnt;
      doc;
end.
