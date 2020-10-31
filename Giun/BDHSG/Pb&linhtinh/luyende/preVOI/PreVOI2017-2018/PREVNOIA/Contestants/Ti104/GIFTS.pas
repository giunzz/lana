Uses math;

Const fi = 'GIFTS.inp';
      fo = 'GIFTS.out';
      maxn = 1000000 + 10;
Var sum, s, a: array[0..maxn] of int64;
    n, k: longint;

Procedure enter;
Var i: longint;

BEGIN
        Assign(input, fi); reset(input);
        Assign(output, fo); rewrite(output);
        Read(n, k);
        For i := 1 to n do
                BEGIN
                 Read(a[i]);
                 Sum[i] := sum[i - 1] + a[i];
                END;
END;

Procedure solve;
Var vt, maxv, i: longint;
    max_kq: int64;

BEGIN
        Enter;
        maxv := sum[k];
        vt := 1;
        For i := 2 to n - k + 1 do
         If maxv < sum[i + k - 1] - sum[i - 1] then
                BEGIN
                 maxv := sum[i + k - 1] - sum[i - 1];
                 vt := i;
                END;
        max_kq := 0;
        For i := 1 to vt - k do
                 max_kq := max(max_kq, sum[i + k - 1] - sum[i - 1]);
        For i := vt + k to n - k + 1 do
                 max_kq := max(max_kq, sum[i + k - 1] - sum[i - 1]);
        Write(max_kq);
END;

BEGIN
        Solve;
END.