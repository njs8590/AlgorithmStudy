package problemSolving;


class MergeTwoSortedLists {
	
	public static void main(String[] args) {
		
		ListNode list1 = new ListNode(1, null);
		list1.next = new ListNode(2, null);
		list1.next.next = new ListNode(4, null);
		
		ListNode list2 = new ListNode(1, null);
		list2.next = new ListNode(3, null);
		list2.next.next = new ListNode(4, null);
		
		
//		while(list1!=null) {
//			System.out.print(list1.val+" ");
//			list1 = list1.next;
//		}
			
		
		ListNode answer = mergeTwoLists(list1, list2);
		
		while(answer!=null) {
			System.out.print(answer.val+" ");
			answer = answer.next;
		}
	}
	
    public static ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
    	ListNode answer = new ListNode();
    	ListNode answerHead = answer;
    	
    	ListNode curList1 = list1;
    	ListNode curList2 = list2;
    	
    	// 둘중하나가 끝날때까지 루프
    	while(curList1!=null || curList2!=null) {
    		if(curList1==null && curList2!=null) {
    			answer.next = curList2;
    			answer = answer.next;
    			break;
    		}
    		else if(curList1!=null && curList2==null) {
    			answer.next = curList1;
    			answer = answer.next;
    			break;
    		}
    		
    		
    		if(curList1.val <= curList2.val) {
    			answer.next = curList1;
    			answer = answer.next;
    			curList1 = curList1.next;
    		}
    		else {
    			answer.next = curList2;
    			answer = answer.next;
    			curList2 = curList2.next;
    		}
    	}
    	
    	answer = answerHead.next;
    	
    	return answer;
    	
    }
}