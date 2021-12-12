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
        
        // length�� ȸ���ϸ� ó���迭���� �̿��Ͽ� �������Ǽ���
        k = k%nums.length;
        if(k==0)return;
        
        // ���� k����ŭ ���� ������
        int index = 0;
        for(int i=nums.length-k;i<nums.length;i++) {
        	extra_nums[index++] = nums[i];
        }
        
        // ���������� i -> k+i �������̵�
        for(int i=nums.length-1-k;i>=0;i--) {
        	nums[k+i] = nums[i];
        }

        // ������ ���ڸ� �տ�����
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
