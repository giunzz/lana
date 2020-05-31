var s,tmp:ansistring;
    ans,i,n:integer;
    c1,c2,c3:char;
    ok:boolean;
begin
    readln(n);
    readln(s);
    ans:=0;
    for c1:='a' to 'z' do
        for c2:=chr(ord(c1)+1) to 'z' do
            begin
                tmp:=s;
                for c3:='a' to 'z' do
                    if (c3<>c1) and (c3<>c2) then
                        while pos(c3,tmp)>0 do delete(tmp,pos(c3,tmp),1);
                ok:=true;
                if length(tmp)<2 then ok:=false
                else for i:=1 to length(tmp)-1 do
                    if tmp[i]=tmp[i+1] then ok:=false;
                if (ok=true) and (length(tmp)>ans) then ans:=length(tmp);
            end;
    writeln(ans);
end.    
