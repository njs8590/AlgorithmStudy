public class CoinChange {
    public static void main(String[] args) {

        int[] coins =
                //{1,2,5};
                //{2};
                {1};

        int amount =
                //11;
                //3;
                0;

        Solution sol = new Solution();

        System.out.println(sol.coinChange(coins, amount));
    }

    static class Solution {
        public int coinChange(int[] coins, int amount) {

//            coins는 동전의 종류
//            amount는 만들어야하는 금액
//            Input: coins = [1,2,5], amount = 11
//            Output: 3
//            Explanation: 11 = 5 + 5 + 1

            int[] dp = new int[amount+1];
            for(int i=0;i<=amount;i++) dp[i]=Integer.MAX_VALUE;
            dp[0] = 0;

            for(int i=1;i<=amount;i++){
                for(int coin : coins){
                    //coin 하나로되면 그게최선
                    if(i==coin){
                        dp[i] = 1;
                        break;
                    }
                    else{
                        // 범위체크
                        if(i-coin<=0)continue;
                        if(dp[i-coin]==Integer.MAX_VALUE)continue;
                        // 코인하나를 더하면 되는 값이랑 비교
                        System.out.println(dp[i]+","+dp[i-coin]+1);
                        dp[i] = Math.min(dp[i], dp[i-coin]+1);
                    }
                }
            }

            if(dp[amount]==Integer.MAX_VALUE)return -1;
            return dp[amount];
        }
    }
}
