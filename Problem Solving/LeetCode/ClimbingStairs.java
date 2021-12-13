package problemSolving;

public class ClimbingStairs {

	static int dp[] = new int[46];
	
	public static void main(String[] args) {
		System.out.println(climbStairs(45));
	}
    
    public static int climbStairs(int n) {
    	// 1ĭ¥�� ����� ������ ����� 1��
    	if(n==1) {
    		return 1;
    	}
    	// 2ĭ¥�� ����� ������ ����� 2�� (1step or 2step)
    	else if(n==2){
    		return 2;
    	}
    	
    	// �޸������̼� ���
    	if(dp[n]!=0) {
    		return dp[n];
    	}else {
    		// n��¥�� ����� ������ ����� n-2���� 2step or n-1���� 1step
    		dp[n] = climbStairs(n-2) + climbStairs(n-1);
    		return dp[n];
    	}
    }

}
