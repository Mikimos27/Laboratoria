with Ada.Text_IO;
with Ada.Integer_Text_IO;
use Ada.Text_IO;
use Ada.Integer_Text_IO;
with Ada.Unchecked_Deallocation;
with Ada.Numerics.Elementary_Functions;
with Ada.Command_Line ; use Ada.Command_Line;
use Ada.Numerics.Elementary_Functions;

procedure zadanie2 is
   a : Integer;
   n : Integer;
   k : Integer;
   x : Integer;

   function halfcos(X : Long_Float) return Long_Float is 
      x2 : Long_Float := x;
   begin
      x2 := x2 / 2.0;
      return Long_Float(Cos(Float(x2)));
   end halfcos;

   type functype is access function (X : Long_Float) return Long_Float;

   function FindZero(f : functype; a, b, eps : Long_Float) return Long_Float is
      c : Long_Float;
      a2 : Long_Float := a;
      b2 : Long_Float := b;
   begin
      while (b2 - a2 > eps) loop
         c := (a2 + b2) / 2.0;
         if ((f(a2) * f(c)) < 0.0) then 
            b2 := c;
         else
            a2 := c;
         end if;
      end loop;

      return a2;
   end FindZero;

begin

Put_Line ("Result: " & FindZero(halfcos'Access, 2.0, 4.0, 0.000001)'Image);

   New_Line;
end zadanie2;
