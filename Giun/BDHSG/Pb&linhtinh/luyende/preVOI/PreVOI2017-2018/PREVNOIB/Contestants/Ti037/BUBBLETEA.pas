USES math ;
VAR
  n,k,l,time : longint ;
  res : int64 ;
  ke,next,ts : array[-50000..50000] of longint ;
  d : array[1..50000] of int64 ;
  pos,x : array[1..10] of longint ;
  head,q,tin,tout : array[1..50000] of longint ;
  f : array[1..50000,0..20] of longint ;
  free : array[1..10] of boolean ;
PROCEDURE add(i,u,v,c : longint) ;
  begin
    ke[i] := v ; next[i] := head[u] ; head[u] := i ; ts[i] := c ;
  end;
PROCEDURE nhap;
  var i,u,v,c : longint ;
  begin
    read(n,k) ;
    for i := 1 to k do read(q[i]) ;
    for i := 1 to n-1 do
      begin
        read(u,v,c) ;
        add(i,u,v,c) ;
        add(-i,v,u,c) ;
      end;
  end;
PROCEDURE DFS(u : longint) ;
  var j,v : longint ;
  begin
    inc(time) ; tin[u] := time ;
    for j := 1 to l do
      f[u,j] := f[f[u,j-1],j-1] ;
    j := head[u] ;
    while j<>0 do
      begin
        v := ke[j] ;
        if v<>f[u,0] then
          begin
            f[v,0] := u ;
            d[v] := d[u] + ts[j] ;
            DFS(v) ;
          end;
        j := next[j] ;
      end;
    inc(time) ; tout[u] := time ;
  end;
FUNCTION check(u,v : longint) : boolean ;
  begin
    if (tin[u]<=tin[v]) and (tout[u]>=tout[v]) then exit(true) ;
    exit(false) ;
  end;
FUNCTION LCA(u,v : longint) : longint ;
  var j : longint ;
  begin
    if check(u,v) then exit(u) ;
    if check(v,u) then exit(v) ;
    for j := l downto 0 do
      if not check(f[u,j],v) then u := f[u,j] ;
    exit(f[u,j]) ;
  end;
PROCEDURE inkq;
  var i : longint ;
      cnt : int64 ;
  begin
    for i := 1 to k do
      pos[x[i]] := q[i] ;
    cnt := 0 ;
    i := 1 ;
    while i<=k do
      begin
        cnt := max(cnt,d[pos[i]]+d[pos[i+1]]-2*d[LCA(pos[i],pos[i+1])]) ;
        i := i+2 ;
      end;
    res := min(res,cnt) ;
  end;
PROCEDURE duyet(i : longint) ;
  var j : longint ;
  begin
    if i=k+1 then inkq
      else for j := 1 to k do
             if free[j] then
               begin
                 free[j] := false ;
                 x[i] := j ;
                 duyet(i+1) ;
                 free[j] := true ;
               end;
  end;
PROCEDURE sub1;
  var i,j : longint ;
  begin
    l := trunc(sqrt(n)) ; time := 0 ;
    f[1,0] := 1 ;
    DFS(1) ;
    for i := 1 to k do free[i] := true ;
    res := 10**15 ;
    duyet(1) ;
    write(res) ;
    halt;
  end;
PROCEDURE main;
  begin
    if k<=10 then sub1;
  end;
BEGIN
  assign(input,'BUBBLETEA.inp') ; reset(input) ;
  assign(output,'BUBBLETEA.out') ; rewrite(output) ;
  nhap;
  main;
  close(input) ; close(output) ;
END.