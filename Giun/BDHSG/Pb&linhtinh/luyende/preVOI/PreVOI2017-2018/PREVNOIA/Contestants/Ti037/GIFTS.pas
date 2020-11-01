USES math ;
VAR
  n,k : longint ;
  a : array[1..1000000] of longint ;
  sum,l,r : array[0..1000000] of int64 ;
PROCEDURE nhap;
  var i : longint ;
  begin
    read(n,k) ;
    for i := 1 to n do read(a[i]) ;
  end;
PROCEDURE main;
  var i : longint ;
      res : int64 ;
  begin
  	for i := 1 to n do
  	  sum[i] := sum[i-1] + a[i] ;
  	for i := 1 to n do
  	  if i<k then l[i] := 0
  	    else l[i] := max(l[i-1],sum[i]-sum[i-k]) ;
  	for i := n downto 1 do
  	  if i>n-k+1 then r[i] := 0
  	    else r[i] := max(r[i+1],sum[i+k-1]-sum[i-1]) ;
  	res := 10**15 ;
    for i := 1 to n-k+1 do
      res := min(res,max(l[i-1],r[i+k])) ;
    write(res) ;
  end;
BEGIN
  assign(input,'GIFTS.inp') ; reset(input) ;
  assign(output,'GIFTS.out') ; rewrite(output) ;
  nhap;
  main;
  close(input) ; close(output) ;
END.
