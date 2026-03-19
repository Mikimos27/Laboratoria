import java.util.*;

public class Test{

    public static void main(String[] args){

        if(args.length < 2){
            System.out.println("Za mało argumentów");
            return;
        }

        int l = 0;
        try{ l = Integer.parseInt(args[0]); }
        catch(NumberFormatException ex){
            System.out.println(args[0] + " - Nieprawidłowa dana");
            return;
        }
        if(l <= 1){
            System.out.println(args[0] + " - Nieprawidłowy zakres");
            return;
        }

        PrimeNumbers lp = new PrimeNumbers(l);
        for(int i = 1; i < args.length; i++){
            int n = 0;
            boolean fail = false;
            try{ n = Integer.parseInt(args[i]); }
            catch(NumberFormatException ex){
                System.out.println(args[i] + " - nieprawidłowa dana");
                fail = true;
            }
            if(fail) continue;


            int k = lp.getNumber(n);
            if(k == -1){
                System.out.println(args[i] + " - liczba spoza zakresu");
                continue;
            }
            System.out.print(args[i] + " - ");
            System.out.println(k);
        }
    }
}
