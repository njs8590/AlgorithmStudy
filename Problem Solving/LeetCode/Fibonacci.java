import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n;
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        System.out.println(sol.fib(n));
    }

}

class Solution {
    public int fib(int n) {

        /* 점화식
         f(0) = 0
         f(1) = 1
         f(n) = f(n-1) + f(n-2), for n > 1
         */

        if(n==0) return 0;
        if(n==1) return 1;

        return fib(n-1) + fib(n-2);
    }
}