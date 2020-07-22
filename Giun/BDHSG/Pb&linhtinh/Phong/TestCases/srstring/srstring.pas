var s: string;
    i:integer;
    ok:boolean;
begin
    readln(s);
    ok:=true;
    while ok do
        begin
            i:=1;
            ok:=false;
            while i<length(s) do
                if s[i]=s[i+1] then 
                    begin
                        delete(s,i,2);
                        ok:=true;
                    end
                else i:=i+1;
        end;
    if s='' then writeln('Empty String')
        else writeln(s);
end.
