import java.util.Scanner;

public class NthTribonacciNumber {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int n;
        Scanner sc = new Scanner(System.in);

        n = sc.nextInt();
        System.out.println(sol.tribonacci(n));
    }

    static class Solution {
        int[] dp =new int[38]; // constraints 0<=n<=37

        Solution(){
            for(int i=0;i<38;i++){
                dp[i] = 0;
            }
        }

        public int tribonacci(int n) {
        /* 점화식
        f(0) = 0
        f(1) = 1
        f(2) = 1
        f(n+3) = f(n) + f(n+1) + f(n+2) for n >=0
        -> f(n) = f(n-1) + f(n-2) + f(n-3) for n>= 3
         */

            if(n==0)return 0;
            if(n==1)return 1;
            if(n==2)return 1;

            if(dp[n]!=0) return dp[n];
            else dp[n] = tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3);

            return dp[n];
        }
    }
}


