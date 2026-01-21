with Ada.Text_IO;         use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure zadanie3ada is

   NUMBERS   : constant Integer := 6;
   CODE_LEN  : constant Integer := 4;
   MAX_CODES : constant Integer := 1296; -- 6^4

   type Code_Array is array (1 .. CODE_LEN) of Integer;

   type Code is record
      V : Code_Array;
   end record;

   type Code_List is array (1 .. MAX_CODES) of Code;

   Possible       : Code_List;
   Possible_Count : Integer := 0;

   procedure Generate_Codes is
   begin
      for A in 1 .. NUMBERS loop
         for B in 1 .. NUMBERS loop
            for C in 1 .. NUMBERS loop
               for D in 1 .. NUMBERS loop
                  Possible_Count := Possible_Count + 1;
                  Possible(Possible_Count).V := (A, B, C, D);
               end loop;
            end loop;
         end loop;
      end loop;
   end Generate_Codes;

   procedure Score (Code_Val : Code; Guess : Code; Na_swoim : out Integer; Nie_na : out Integer) is
      Code_Count  : array (1 .. NUMBERS) of Integer := (others => 0);
      Guess_Count : array (1 .. NUMBERS) of Integer := (others => 0);

   begin
      Na_swoim := 0;
      Nie_na := 0;

      for I in 1 .. CODE_LEN loop
         if Code_Val.V(I) = Guess.V(I) then
            Na_swoim := Na_swoim + 1;
         end if;

         Code_Count(Code_Val.V(I))  := Code_Count(Code_Val.V(I)) + 1;

         Guess_Count(Guess.V(I)) := Guess_Count(Guess.V(I)) + 1;
      end loop;

      for I in 1 .. NUMBERS loop
         Nie_na := Nie_na + Integer'Min(Code_Count(I), Guess_Count(I));
      end loop;

      Nie_na := Nie_na - Na_swoim;
   end Score;



   Move : Integer := 1;
begin
   Generate_Codes;

   loop
      if Possible_Count = 0 then
         Put_Line("Oszukujesz!");
         return;
      end if;

      declare
         Guess : Code := Possible(1);
         Na_swoim : Integer;
         Nie_na : Integer;
      begin
         Put_Line("");
         Put("Ruch ");
         Put(Move);
         Put(": ");

         for I in 1 .. CODE_LEN loop
            Put(Guess.V(I));
            Put(" ");
         end loop;
         New_Line;

         Put("Na swoim miejscu: ");
         Get(Na_swoim);
         Put("Nie na swoim miejscu: ");
         Get(Nie_na);

         if Na_swoim = 4 then
            Put_Line("Kod odgadniety!");
            exit;
         end if;

         declare
            New_Possible : Code_List;
            New_Count    : Integer := 0;
            B, W         : Integer;
         begin
            for I in 1 .. Possible_Count loop
               Score(Possible(I), Guess, B, W);

               if B = Na_swoim and W = Nie_na then
                  New_Count := New_Count + 1;
                  New_Possible(New_Count) := Possible(I);
               end if;
            end loop;

            for I in 1 .. New_Count loop
               Possible(I) := New_Possible(I);
            end loop;

            Possible_Count := New_Count;
         end;

         Move := Move + 1;
      end;
   end loop;

end zadanie3ada;