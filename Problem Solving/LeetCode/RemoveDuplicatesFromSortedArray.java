
public class RemoveDuplicatesFromSortedArray {

	public static void main(String[] args) {
		// ���������ʴ� ������ array
		int nums[] = {1,1,2,3,4,5,5};
		int k = removeDuplicates(nums);
		System.out.print(k);
		
	}
	
    public static int removeDuplicates(int[] nums) {
        if(nums.length ==0 )return 0;
    	
    	int before = nums[0];
        int i=1;
        int index = 1;
        while(i<nums.length) {
        	int cur = nums[i];
        	// �������� �̹����� ������ skip
        	if(before == nums[i]) {
        		i++;
        	}
        	// �����Ŷ� �̹��Ŷ� �ٸ��� update
        	else {
        		nums[index++] = nums[i];
        		before = nums[i];
        	}
        }
        
        
    	return index;
    }

}
