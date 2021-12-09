
public class RemoveDuplicatesFromSortedArray {

	public static void main(String[] args) {
		// 감소하지않는 순서의 array
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
        	// 이전꺼랑 이번꺼랑 같으면 skip
        	if(before == nums[i]) {
        		i++;
        	}
        	// 이전거랑 이번거랑 다르면 update
        	else {
        		nums[index++] = nums[i];
        		before = nums[i];
        	}
        }
        
        
    	return index;
    }

}
