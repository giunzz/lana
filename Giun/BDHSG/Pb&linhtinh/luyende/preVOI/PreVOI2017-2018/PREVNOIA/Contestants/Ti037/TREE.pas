VAR
  n : longint ;
  cha,b,a : array[1..5000] of longint ;
  free : array[1..5000] of boolean ;
PROCEDURE nhap;
  var i,x,y : longint ;
  begin
    read(n) ;
    for i := 1 to n do
      begin
        read(a[i]) ;
        free[i] := true ;
      end;
    for i := 1 to n-1 do
      begin
        read(x,y) ;
        cha[y] := x ;
        free[x] := false ;
      end;
  end;
PROCEDURE visit(u : longint) ;
  begin
    if u=1 then exit ;
    b[cha[u]] := b[cha[u]] + b[u] ;
    visit(cha[u]) ;
  end;
PROCEDURE khoitao;
  var i : longint ;
  begin
    for i := 1 to n do
      if free[i] then
        begin
          if a[i]>1 then b[i] := 1
            else b[i] := a[i] ;
          visit(i) ;
        end;
  end;
PROCEDURE main;
  var res,i,u,cnt : longint ;
  begin
    res := 0 ;
    for i := 1 to n do
      res := res + abs(a[i]-b[i]) ;
    for i := 1 to n do
      if free[i] then
        begin
          if b[i]=0 then
            begin
              u := i ;
              if b[i]<a[i] then cnt := -1
                else cnt := 1 ;
              while u<>1 do
                begin
                  u := cha[u] ;
                  if b[u]<a[u] then dec(cnt)
                    else inc(cnt) ;
                end;
              if cnt<0 then
                begin
                  res := res + cnt ;
                  u := i ;
                  b[u] := 1 ;
                  while u<>1 do
                    begin
                      u := cha[u] ;
                      inc(b[u]) ;
                    end;
                end;
            end
          else
            begin
              u := i ;
              if b[i]>a[i] then cnt := -1
                else cnt := 1 ;
              while u<>1 do
                begin
                  u := cha[u] ;
                  if b[u]>a[u] then dec(cnt)
                    else inc(cnt) ;
                end;
              if cnt<0 then
                begin
                  res := res + cnt ;
                  u := i ;
                  b[u] := 0 ;
                  while u<>1 do
                    begin
                      u := cha[u] ;
                      dec(b[u]) ;
                    end;
                end;
            end;
        end;
    write(res) ;
  end;
BEGIN
  assign(input,'TREE.inp') ; reset(input) ;
  assign(output,'TREE.out') ; rewrite(output) ;
  nhap;
  khoitao;
  main;
  close(input) ; close(output) ;
END.

















