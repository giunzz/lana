var     f,g:text;
        m,n,k,i,t:longint;
        a1,b1,kq:array[1..3000] of longint;
        stt:ansistring;
function ss(st1,st2:ansistring):boolean;
begin
        while length(st1)<length(st2) do st1:='0'+st1;
        while length(st2)<length(st1) do st2:='0'+st2;
        if st1<st2 then exit(true) else exit(false);
end;
procedure xl(sa,sb:longint);
var     i,la,lb,vta,vtb,lkq,ktt,dd:longint;
        kt,aa,a,b,bb,kqn:array[1..3000] of longint;
        st1,st2,st,tmp:ansistring;
begin
 for i:=1 to m+1 do a[i]:=a1[i];
 for i:=1 to n+1 do b[i]:=b1[i];
 fillchar(kt,sizeof(kt),0); dd:=1;
 repeat
        if sa=0 then break; ktt:=0;
        for i:=1 to m do if (kt[i]=0) and (a[i]>a[i+1]) then
        begin
                kt[i]:=1; dec(sa); ktt:=1; break;
        end;
        if ktt=0 then begin dec(sa); while kt[dd]=1 do inc(dd); kt[dd]:=1; end;
 until sa=0; la:=0;
 for i:=1 to m do if kt[i]=0 then
 begin
        inc(la); aa[la]:=a[i];
 end;
 fillchar(kt,sizeof(kt),0); dd:=1;
 repeat
        if sb=0 then break; ktt:=0;
        for i:=1 to n do if (kt[i]=0) and (b[i]>b[i+1]) then
        begin
                kt[i]:=1; dec(sb); ktt:=1; break;
        end;
        if ktt=0 then begin dec(sb); while kt[dd]=1 do inc(dd); kt[dd]:=1; end;
 until sb=0; lb:=0;
 for i:=1 to n do if kt[i]=0 then
 begin
        inc(lb); bb[lb]:=b[i];
 end;
 repeat
        vta:=1; vtb:=1; st:=''; lkq:=0;
        st1:=''; st2:='';
        for i:=vta to la do begin str(aa[i],tmp); st1:=st1+tmp; end;
        for i:=vtb to lb do begin str(bb[i],tmp); st2:=st2+tmp; end;
        if st1+st2<st2+st1 then begin str(aa[vta],tmp); st:=st+tmp; inc(vta); inc(lkq); kqn[lkq]:=aa[vta]; end
        else begin str(bb[vtb],tmp); st:=st+tmp; inc(vtb); inc(lkq); kqn[lkq]:=bb[vtb]; end;
 until (vta=la) and (vtb=lb);
 if ss(st,stt) then
 begin
        stt:=st; for i:=1 to lkq do kq[i]:=kqn[i];
 end;
end;
begin
        assign(f,'SEQUENCE.INP'); reset(f);
        assign(g,'SEQUENCE.OUT'); rewrite(g);
        readln(f,m,n,k);
        for i:=1 to m do read(f,a1[i]); readln(f); a1[m+1]:=high(longint);
        for i:=1 to n do read(f,b1[i]); b1[n+1]:=high(longint);
        t:=m+n-k;
        for i:=0 to t do
         begin
          xl(i,t-i);
         end;
        for i:=1 to k do write(g,kq[i],' ');
        close(f);
        close(g);
end.
