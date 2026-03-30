import java.util.*;

public class Test{
    public static void main(String[] args){
        if(args.length < 2){
            System.out.println("Za mało argumentów");
            return;
        }

        int n = 0;
        try{ n = Integer.parseInt(args[0]); }
        catch(NumberFormatException ex){
            System.out.println(args[0] + " - Nieprawidłowa dana");
            return;
        }
        if(n < 0){
            System.out.println(args[0] + " - Nieprawidłowy zakres");
            return;
        }

        PascalTriangleRow p = new PascalTriangleRow(n);

        for(int i = 1; i < args.length; i++){
            n = 0;
            try{ n = Integer.parseInt(args[i]); 

                int k = p.Elem(n);
                if(k == -1){
                    System.out.println(args[i] + " - liczba spoza zakresu");
                    continue;
                }
                System.out.print(args[i] + " - ");
                System.out.println(k);
            }
            catch(NumberFormatException ex){
                System.out.println(args[i] + " - nieprawidłowa dana");
            }
        }


    }
}
