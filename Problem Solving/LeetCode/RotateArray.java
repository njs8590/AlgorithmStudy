package problemSolving;

public class RotateArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//int nums[] = {1,2,3,4,5,6,7};
		// int k = 3;
		//int nums[] = {-1, -100, 3, 99};
		//int k = 2;
		
		int nums[] = {-1};
		int k = 2;
		rotate(nums, k);

	}
	
    public static void rotate(int[] nums, int k) {
        int extra_nums[] = new int[k];
        
        // length번 회전하면 처음배열임을 이용하여 종료조건설정
        k = k%nums.length;
        if(k==0)return;
        
        // 끝에 k개만큼 숫자 뺴놓음
        int index = 0;
        for(int i=nums.length-k;i<nums.length;i++) {
        	extra_nums[index++] = nums[i];
        }
        
        // 끝에서부터 i -> k+i 번으로이동
        for(int i=nums.length-1-k;i>=0;i--) {
        	nums[k+i] = nums[i];
        }

        // 빼놨던 숫자를 앞에붙임
        index=0;
        for(int i=0;i<k;i++) {
        	nums[index++] = extra_nums[i];
        }
        
//        for(int i=0;i<nums.length;i++) {
//        	System.out.print(nums[i]+" ");
//        }
//        System.out.println();
    }

}
