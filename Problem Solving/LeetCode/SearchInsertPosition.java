package problemSolving;

public class SearchInsertPosition {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//int nums[] = {1,3,5,6};
		//int target = 5;
		
		int nums[] = {2,3,5,6,9};
		int target = 7;
		
		System.out.println(searchInsert(nums, target));
	}
	
    public static int searchInsert(int[] nums, int target) {
    	
    	int answer = 0;
    	int start = 0;
    	int end = nums.length-1;
    	int mid= 0;
    	
    	while(start <= end) {
    		mid = (start+end)/2;
    		
    		if(target == nums[mid]) {
    			return mid;
    		}
    		// target이 작으면 왼쪽sub
    		else if(target < nums[mid]) {
    			end = mid-1;
    			if(start <= end) {
    				// 좌측 sub의 마지막칸이 target보다 작으면 여기 들어가야된다.
    				if(nums[end]<target) {
    					//System.out.println("??");
    					return mid;
    				}
    			}
    		}
    		else {
    			start = mid+1;
    			
    			if(start <= end) {
    				// 우측 sub의 첫번째칸이 target보다 크면 여기 들어가야된다.
    				if(nums[start]>target) {
    					//System.out.println("!!");
    					return mid+1;
    				}
    			}
    		}
    	}
    	
    	// 마지막에도 못찾은경우
    	if(mid == nums.length-1) {
    		if(nums[mid]>target){
    			return mid;
    		}
    		else {
    			return mid+1;
    		}
    	}
    	else {
    		return 0;
    	}
    	
    }
    
}

