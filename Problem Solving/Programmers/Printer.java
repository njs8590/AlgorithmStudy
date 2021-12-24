package problemSolving;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Printer {

	public static void main(String[] args) {
		//int[] priorities = {2,1,3,2};
		//int location = 2;
		
		int[] priorities = {1,1,9,1,1,1};
		int location = 0;
		
		System.out.println(solution(priorities, location));
		
	}
	
    public static int solution(int[] priorities, int location) {
        int answer = 1;
        
        // index�� location�� �ִ� ������ �μ�Ǵ°�?
        Queue<Doc> queue = new LinkedList<Doc>();
        
        // �߿䵵 ������ ���
        ArrayList<Integer> arr = new ArrayList<Integer>();
        // ť�� �ױ�
        for(int i=0;i<priorities.length;i++) {
        	
        	arr.add(priorities[i]);
        	
        	Doc doc = new Doc(i, priorities[i]);
        	queue.add(doc);
        }
        
        Collections.sort(arr, Collections.reverseOrder());
        
        
        // ��������
        int arr_i = 0;
        while(!queue.isEmpty()) {
        	
        	Doc curdoc = queue.peek();
        	//System.out.println(curdoc.priority+":"+arr.get(arr_i));
        	
        	// �������� �߿��ϴ�
        	if(curdoc.priority == arr.get(arr_i)) {
        		// ã�����ϴ� �༮�̴�
        		if(curdoc.index == location) {
        			//��
        			break;
        		}
        		else{
        			// ���!!!
        			queue.poll();
        			arr_i++;
        			answer++;
        		}
        	}
        	else { // �������� �߿����� �ʴ�.
        		// �ǵڷκ�����
        		queue.poll();
        		queue.add(curdoc);
        	}
        }
        
        //System.out.println(answer);
        
        return answer;
    }
    
    public static class Doc{
    	int index;
    	int priority;
    	
    	Doc(){};
    	Doc(int i, int p){
    		index =i;
    		priority = p;
    	}
    }

}
