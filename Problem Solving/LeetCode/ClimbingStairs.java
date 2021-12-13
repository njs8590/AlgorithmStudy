package problemSolving;

public class ClimbingStairs {

	static int dp[] = new int[46];
	
	public static void main(String[] args) {
		System.out.println(climbStairs(45));
	}
    
    public static int climbStairs(int n) {
    	// 1칸짜리 계단을 오르는 방법은 1개
    	if(n==1) {
    		return 1;
    	}
    	// 2칸짜리 계단을 오르는 방법은 2개 (1step or 2step)
    	else if(n==2){
    		return 2;
    	}
    	
    	// 메모이제이션 사용
    	if(dp[n]!=0) {
    		return dp[n];
    	}else {
    		// n번짜리 계단을 오르는 방법은 n-2에서 2step or n-1에서 1step
    		dp[n] = climbStairs(n-2) + climbStairs(n-1);
    		return dp[n];
    	}
    }

}
