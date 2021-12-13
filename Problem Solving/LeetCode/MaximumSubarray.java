package problemSolving;

public class MaximumSubarray {

	public static void main(String[] args) {
		//int[] nums = {-2,1,-3,4,-1,2,1,-5,4};
		int[] nums = {5,4,-1,7,8};
		System.out.println(maxSubArray(nums));

	}
	
    public static int maxSubArray(int[] nums) {
        // ������ ���ҷ� ������ subarray.
    	// subarray�� ���� �ִ밪�� ����
    	
    	// DP[N] = N��° ���ұ��� SUBARRAY�� �ִ���. N��°���ұ��� SUBARRAY�� �ְų�, N�����Һ��� ���ν����ϰų�.
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
    			// �����ִ��� + �̹��ű��� < �̹����� ���ν���
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
