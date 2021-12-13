package problemSolving;

public class MaximumSubarray {

	public static void main(String[] args) {
		//int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		int[] nums = {5,4,-1,7,8};
		System.out.println(maxSubArray(nums));

	}
	
    public static int maxSubArray(int[] nums) {
        // 인접한 원소로 구성된 subarray.
    	// subarray의 합의 최대값을 리턴
    	
    	// DP[N] = N번째 원소까지 SUBARRAY의 최대합. N번째원소까지 SUBARRAY가 있거나, N번원소부터 새로시작하거나.
    	int dp[] = new int[nums.length+1];
    	for(int i=0;i<nums.length;i++) {
    		dp[i] = Integer.MIN_VALUE;
    	}
    	
    	int answer = Integer.MIN_VALUE;
    	
    	for(int i=0;i<nums.length;i++) {
    		if(i==0) {
    			dp[i] = nums[i];
    		}
    		else {
    			// 이전최대합 + 이번거까지 < 이번에서 새로시작
    			if(dp[i-1]+nums[i] < nums[i]) {
    				dp[i] = nums[i];
    			}
    			else {
    				dp[i] = dp[i-1]+nums[i];
    			}
    		}
    		if(answer < dp[i])answer = dp[i];
    	}
    	
    	return answer;
    }

}
