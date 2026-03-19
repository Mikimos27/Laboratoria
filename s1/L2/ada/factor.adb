with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure factor is
    n, it, len, count, org : Integer;
    function p(n: Integer) return Integer is
        i: Integer := 3;
    begin
        if n <= 1 then
            return 0;
        end if;
        if n = 2 then
            return 1;
        end if;
        if n mod 2 = 0 then
            return 0;
        end if;
        
        while i * i <= n loop
            if n mod i = 0 then return 0;
            end if;
            i := i + 2;
        end loop;
    return 1;
    end p;
begin
    count := 0;

    Get(n);
    org := n;
    len := n / 2 + 1;
    if n = 1 then
        Put(1);
    end if;
    if p(n) = 1 then
        Put(n);
        return;
    end if;

    while n mod 2 = 0 loop
        count := count + 1;
        n := n / 2;
    end loop;
    if count = 1 then
        Put("2, ");
    else 
        if count > 1 then
            Put("2^" & count'Image);
        end if;
    end if;


    it := 3;
    while it <= len loop
        count := 0;
        while n mod it = 0 loop
            count := count + 1;
            n := n / it;
        end loop;
        if count = 1 then
            Put(it);
        else 
            if count > 1 then
                Put(it'Image & "^" & count'Image);
            end if;
        end if;
        it := it + 2;
    end loop;

    if n > 1 then
        Put(org);
    end if;

    Put_Line("");
end factor;
