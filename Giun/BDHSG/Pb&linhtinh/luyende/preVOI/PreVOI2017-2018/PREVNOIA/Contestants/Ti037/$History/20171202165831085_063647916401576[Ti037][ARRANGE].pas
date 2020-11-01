USES math;
VAR
  n : longint ;
  sum : int64 ;
  a : array[1..100000] of int64 ;
  d : array[0..100000] of int64 ;
  b : array[1..10000,0..10000] of longint ;
  f : array[0..10000,0..10000] of int64 ;
PROCEDURE sub1;
  var i,k : longint ;
      res : int64 ;
  begin
    k := sum div n ;
    res := 0 ;
    for i := 1 to n do
      begin
        if a[i]<k then
          begin
            res := res + k - a[i] ;
            a[i+1] := a[i+1] - k + a[i] ;
            a[i] := k ;
          end;
        if a[i]>k then
          begin
            res := res + a[i] - k ;
            a[i+1] := a[i+1] + a[i] - k ;
            a[i] := k ;
          end;
      end;
    write(res) ;
  end;
PROCEDURE sub2;
  var i,j,k,q : longint ;
  begin
    k := sum div n ; q := sum mod n ;
    for i := 1 to n do
      d[i] := d[i-1] + a[i] ;
    for i := 1 to n do
      for j := 0 to i-1 do
        b[i,j] := a[i] + d[i-1] - (j*k+(i-1-j)*(k+1)) ;
    for i := 1 to n do
      for j := 0 to i do
        f[i,j] := 10**15 ;
    f[0,0] := 0 ;
    for i := 1 to n do
      for j := 0 to i do
        begin
          f[i,j] := min(f[i,j],f[i-1,j]+abs(b[i,j]-k-1)) ;
          if j>0 then
            f[i,j] := min(f[i,j],f[i-1,j-1]+abs(b[i,j-1]-k)) ;
        end;
    write(f[n,n-q]) ;
  end;
PROCEDURE nhap;
  var i : longint ;
  begin
    read(n) ;
    sum := 0 ;
    for i := 1 to n do
      begin
        read(a[i]) ;
        sum := sum + a[i] ;
      end;
    if sum mod a[i] = 0 then sub1
      else sub2;
  end;
BEGIN
  assign(input,'ARRANGE.inp') ; reset(input) ;
  assign(output,'ARRANGE.out') ; rewrite(output) ;
  nhap;
  close(input) ; close(output) ;
END.
