var     f,g:text;
        a,b,s,k,u,v,t:int64;
        i,n,l,r,kt:longint;
        q,color:array[0..10000000] of int64;
begin
        assign(f,'MODULO.INP'); reset(f);
        assign(g,'MODULO.OUT'); rewrite(g);
        readln(f,a,b); readln(f,n,k);
        if a>b then begin t:=a; a:=b; b:=t; end;
        s:=1; for i:=1 to n do s:=s*2;
        l:=2; r:=2; q[1]:=0; q[2]:=0; color[1]:=1; color[2]:=2;
        while l<=r do
        begin
                u:=q[l]; inc(l);
                v:=u*10+a; t:=v mod s;
                if t=k then begin kt:=1; break; end;
                if color[t]=0 then
                begin
                        inc(r); q[r]:=v;
                        color[t]:=1;
                end;
                v:=u*10+b; t:=v mod s;
                if t=k then begin kt:=1; break; end;
                if color[t]=0 then
                begin
                        inc(r); q[r]:=v;
                        color[t]:=1;
                end;
        end;
        if kt=1 then writeln(g,v) else writeln(g,'-1');
        close(f);
        close(g);
end.









