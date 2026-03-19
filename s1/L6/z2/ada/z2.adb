with Ada.Text_IO;        use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.Numerics.Generic_Elementary_Functions;
with Ada.Command_Line; use Ada.Command_Line;

procedure zadanie2ada is
   N : Integer;
begin
   N := Natural'Value(Argument(1));
   declare
      Solutions : Integer := 0;

      type Bool_Array is array (Integer range <>) of Boolean;
      type Integer_Array is array (Integer range <>) of Integer;

      Bije_Wiersz : Bool_Array (0 .. N - 1)     := (others => False);
      Bije_Przek1 : Bool_Array (0 .. 2 * N - 2) := (others => False);
      Bije_Przek2 : Bool_Array (0 .. 2 * N - 2) := (others => False);
      Pozycje : Integer_Array (0 .. N) := (others => 0);

      procedure Backtrack (R : Integer) is
      begin
         if R = N then
            Solutions := Solutions + 1;
            for C in 0 .. N - 1 loop
               Put(Integer'Image(Pozycje(C)));
            end loop;
            New_Line;
            return;
         end if;

         for C in 0 .. N - 1 loop
            if Bije_Wiersz(C)
              or Bije_Przek1(R + C)
              or Bije_Przek2(R - C + (N - 1))
            then
               null;
            else
               Bije_Wiersz(C) := True;
               Bije_Przek1(R + C) := True;
               Bije_Przek2(R - C + (N - 1)) := True;
               Pozycje (R) := C + 1;
               Backtrack(R + 1);

               Bije_Wiersz(C) := False;
               Bije_Przek1(R + C) := False;
               Bije_Przek2(R - C + (N - 1)) := False;
               Pozycje(R) := 0;
            end if;
         end loop;
      end Backtrack;

   begin
      Backtrack(0);

      Put_Line("Liczba rozwiazan dla N="
               & Integer'Image(N)
               & ":"
               & Integer'Image(Solutions));
   end;
end zadanie2ada;