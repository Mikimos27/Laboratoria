import java.util.*;

public class PrimeNumbers{

    private void printArr(int[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.println(Integer.toString(i) + " : " + Integer.toString(arr[i]));
        }
        System.out.println("-------------------------");
    }
    private void printArr(boolean[] arr){
        for(int i = 0; i < arr.length; i++){
            System.out.println(Integer.toString(i) + " : " + Boolean.toString(arr[i]));
        }
        System.out.println("-------------------------");
    }

    PrimeNumbers(int n){
        boolean[] sieve = new boolean[n + 1];
        for(int i = 2; i <= n; i++){
            sieve[i] = true;
        }
        for(int i = 2; i <= Math.sqrt(n); i++){
            if(sieve[i]){
                for(int j = i * i; j <= n; j += i){
                    sieve[j] = false;
                }
            }
        }
        //printArr(sieve);
        int[] raw = new int[n + 1];
        int count = 0;
        //System.out.println(sieve.length);
        for(int i = 2; i <= n; i++){
            if(sieve[i]){
                raw[count] = i;
                count++;
            }
        }
        //printArr(raw);
        data = new int[count];
        for(int i = 0; i < count; i++){
            data[i] = raw[i];
        }
        //printArr(data);
    }

    public int getNumber(int m){
        if(m < 0 || m >= data.length) return -1;
        return data[m];
    }
    public int length(){
        return data.length;
    }

    private int data[];
}
