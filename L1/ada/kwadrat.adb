with Ada.Text_IO; use Ada.Text_IO;
with Ada.Float_Text_IO; use Ada.Float_Text_IO;
with Ada.Numerics.Elementary_Functions; use  Ada.Numerics.Elementary_Functions;


procedure kwadrat is
    a, b, c, d, x1, x2 : Float;
begin
    Get(a);
    Get(b);
    Get(c);

    if a /= 0.0 then
        d := b * b - 4.0 * a * c;
        if d < 0.0 then
            Put_Line("x nie istnieje dla liczb rzeczywistych");
        elsif d = 0.0 then
            x1 := -b / 2.0 / a;
            Put_Line("x = " & x1'Image);
        else
            x1 := (-b - Sqrt(d)) / 2.0 / a;
            x2 := (-b + Sqrt(d)) / 2.0 / a;
            Put_Line("x1 = " & x1'Image);
            Put_Line("x2 = " & x2'Image);
        end if;
    elsif b /= 0.0 then
        x1 := -c / b;
        Put_Line("x = " & x1'Image);
    elsif c = 0.0 then
        Put_Line("x należy do liczb rzeczywistych\n");
    else Put_Line("x nie istnieje");
    end if;
        
    
end kwadrat;
