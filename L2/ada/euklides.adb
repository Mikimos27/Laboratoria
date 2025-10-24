with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;


procedure euklides is
    a, b, c : Integer;
    function NWD(x: Integer; y: Integer) return Integer is
        a, b, c: Integer;
    begin
        a := x;
        b := y;
        while b /= 0 loop
            a := a mod b;
            c := a;
            a := b;
            b := c;
        end loop;
        return a;
    end NWD;
begin
    Put("Podaj pierwszą liczbę: ");
    Get(a);
    Put("Podaj drugą liczbę: ");
    Get(b);

    if a < 0 or b < 0 then
        Put_Line("Liczby nie moga byc mniejsze od 0");
        return;
    end if;
    if a = 0 or b = 0 then
        c := a + b;
        Put_Line("NWD =" & c'Image);
        return;
    end if;


    a := NWD(a, b);

    Put_Line("NWD =" & a'Image);
end euklides;
