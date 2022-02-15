import java.math.BigInteger;
import java.util.Stack;

public class AddTwoNumbers {

      public static class ListNode {
        int val;
        ListNode next;
        ListNode() {}
        ListNode(int val) { this.val = val; }
        ListNode(int val, ListNode next) { this.val = val; this.next = next; }
      }

    public static void main(String[] args) {

        Solution sol = new Solution();


    }
    static class Solution{
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

            /* 두개의 비어있지 않은 양수 링크드리스트 가 주어짐.
             * 각 원소들은  한자리수임
             * 두 리스트의 합을 구하면됨.
             * l1 = [2,4,3], l2 = [5,6,4]
             * 2->4->3     ,       5->6->4
             * 합 = 8 -> 0 -> 7
             *
             * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
             * Output: [8,9,9,9,0,0,0,1]
             *
             * sol)
             * (x) 거꾸로 10진수 만들고.. 더한뒤에 결과값 거꾸로 읽기.. => 이렇게하면 범위초과 에러발생함.. 문제를 너무 대충읽은듯하다..
             * 더하고 upper digit 을 뒤로 보내는 방법으로 풀어보자
             */

            ListNode l1tail, l2tail;
            l1tail = l1;
            l2tail = l2;

            int l1digit, l2digit, upperDigit;

            upperDigit = 0;

            ListNode answer = new ListNode();
            ListNode tail;
            tail = answer;

            while(true){
                l1digit = 0;
                l2digit = 0;

                if(l1!=null){
                    l1digit = l1.val;
                    l1 = l1.next;
                }

                if(l2!=null){
                    l2digit = l2.val;
                    l2 = l2.next;
                }

                int newSum = l1digit+l2digit+upperDigit;
                upperDigit = newSum/10;
                newSum = newSum%10;

                tail.val = newSum;
                if(upperDigit == 0 && l1==null && l2==null)break;
                tail.next = new ListNode();
                tail = tail.next;
            }

            return answer;

        }
    }
}
