package problemSolving;

public class PalindromeLinkedList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode list1 = new ListNode(1, null);
		list1.next = new ListNode(2, null);
		list1.next.next = new ListNode(2, null);
		list1.next.next.next = new ListNode(1, null);
		
		System.out.println(isPalindrome(list1));
		
	}
	
    public static boolean isPalindrome(ListNode head) {
    	boolean answer = true;
    	// array에 넣고 비교해볼까..
    	int arr[] = new int[100001];
    	int index=0;
    	
    	while(head!=null) {
    		int temp = head.val;
    		arr[index++] = temp;
    		head = head.next;
    	}
    	
    	for(int i=0;i<index/2;i++) {
    		if(arr[i] != arr[index-1-i]) {
    			answer = false;
    			break;
    		}
    	}
    	
    	return answer;
    }

}
