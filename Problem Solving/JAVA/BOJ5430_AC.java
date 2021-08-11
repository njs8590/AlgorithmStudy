import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.Iterator;
import java.util.StringTokenizer;

// 2021-08-09

/* ����� 
 * 
1. StringTokenizer(string, "�����ھƹ��ų�����")
2. System.out.Print() �Ź���º��� StringBuilder �� ��������� ����ϴ°� �� ������.
3. Iterator.hasNext() ���޸� ���������Ѵ�.
4. Deque<Integer> dq = new ArrayDeque<Integer>();
 *
 */

public class BOJ5430_AC {
	
	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		int T = Integer.parseInt(br.readLine());
		
		for(int test_case = 0; test_case<T; test_case++) {
			
			StringBuilder sb = new StringBuilder();
			String p = br.readLine(); // ������ �Լ�
			int n = Integer.parseInt(br.readLine()); // �迭 ũ��
			
			Deque<Integer> deque = new ArrayDeque<Integer>();
			
			String arrtemp = new String(br.readLine());
			StringTokenizer st = new StringTokenizer(arrtemp, "[],");
			
			for(int i=0;i<n;i++) {
				deque.add(Integer.parseInt(st.nextToken()));
			}
			
			int reverse_yn = 0;
			int err_yn = 0;
			
			// command
			for(int i=0;i<p.length();i++) {
				char curCommand = p.charAt(i);
				
				if(curCommand == 'D') {
					// �迭�� ��������� ����
					if(deque.isEmpty()) {
						// error
						err_yn = 1;
						break;
					}
					else {
						if(reverse_yn==0) deque.removeFirst();
						else deque.removeLast();
					}
				}
				else if(curCommand == 'R') {
					reverse_yn = 1 - reverse_yn;
				}
				
			}
			
			// answer
			if(err_yn == 1) {
				System.out.println("error");
			}
			else
			{
				sb.append('['); // System.out.print("[");
				if(reverse_yn == 0) {
//					Iterator<Integer> iterator = deque.iterator();
//					while(iterator.hasNext()) {
//						sb.append(iterator.hasNext()); // System.out.print(iterator.next());
//						if(iterator.hasNext()) sb.append(','); //System.out.print(",");
//					}
					if(!deque.isEmpty())sb.append(deque.pollFirst());
					while(!deque.isEmpty()) {
						sb.append(',');
						sb.append(deque.pollFirst());
					}
				}
				else {
//					Iterator<Integer> iterator = deque.descendingIterator();
//					while(iterator.hasNext()) {
//						sb.append(iterator.hasNext()); // System.out.print(iterator.next());
//						if(iterator.hasNext()) sb.append(','); //System.out.print(",");
//					}
					if(!deque.isEmpty())sb.append(deque.pollLast());
					while(!deque.isEmpty()) {
						sb.append(',');
						sb.append(deque.pollLast());
					}
				}
				sb.append(']'); // System.out.println("]");
				
				System.out.println(sb);
			}

		}

	}

}
