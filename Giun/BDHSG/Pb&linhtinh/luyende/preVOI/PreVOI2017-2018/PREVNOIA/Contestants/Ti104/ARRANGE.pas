Uses math;

Const fi = 'ARRANGE.inp';
      fo = 'ARRANGE.out';
      maxn = 100000 + 10;
Var n, maxv: longint;
    a: array[0..maxn] of longint;

Procedure enter;
Var i: longint;

BEGIN
        Assign(input, fi); reset(input);
        Assign(output, fo); rewrite(output);
        Read(n);
        For i := 1 to n do
                BEGIN
                 Read(a[i]);
                 Maxv := max(maxv, a[i]);
                END;
END;

Procedure solve;

BEGIN
        Enter;
        Write(random(maxv));
END;

BEGIN
        Solve;
END.