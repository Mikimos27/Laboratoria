with Ada.Text_IO;        use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Generic_Elementary_Functions;
with Ada.Command_Line; use Ada.Command_Line;


procedure zadanie1ada is

   Max_N : constant := 20;  -- maksymalna liczba hetmanow
   type Board_Array is array (1 .. Max_N) of Integer;
   N : Integer;
   Arr : Board_Array;


 
   function Check_Safe(Arr : Board_Array; Len : Integer) return Boolean is
begin
   for i in 1 .. Len loop
      for j in i + 1 .. Len loop
         if (i - Arr(i) = j - Arr(j)) or (i + Arr(i) = j + Arr(j)) then
            return False;
         end if;
      end loop;
   end loop;
   return True;
end Check_Safe;

   function Permute(A : in out Board_Array; Len : Integer) return Boolean is
      k, l, tmp, i, j : Integer;
   begin
      k := Len - 1;
      while k >= 1 and then Arr(k) >= Arr(k + 1) loop
         k := k - 1;
      end loop;

      if k = 0 then
         return False;
      end if;

      l := Len;
      while Arr(l) <= Arr(k) loop
         l := l - 1;
      end loop;

      tmp := Arr(k); Arr(k) := Arr(l); Arr(l) := tmp;

      
      i := k + 1;
      j := Len;
      begin
         while i < j loop
            tmp := Arr(i); Arr(i) := Arr(j); Arr(j) := tmp;
            i := i + 1;
            j := j - 1;
         end loop;
      end;

      return True;
   end Permute;

   SolsCount : Integer := 0;

begin
   N := Natural'Value(Argument(1));
   
   for i in 1 .. N loop
      Arr(I) := I;
   end loop;

   loop
      if Check_Safe(Arr, N) then
         SolsCount := SolsCount + 1;
         for i in 1 .. N loop
            Put(Integer'Image(Arr(I)) & " ");
         end loop;
         New_Line;
      end if;

      exit when not Permute(Arr, N);
   end loop;

   Put("Num of solutions");
   Put(Integer'Image(SolsCount));
   New_Line;

end zadanie1ada;
