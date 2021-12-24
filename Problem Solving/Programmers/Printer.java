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
        
        // index가 location인 애는 몇번재로 인쇄되는가?
        Queue<Doc> queue = new LinkedList<Doc>();
        
        // 중요도 순서를 기록
        ArrayList<Integer> arr = new ArrayList<Integer>();
        // 큐에 쌓기
        for(int i=0;i<priorities.length;i++) {
        	
        	arr.add(priorities[i]);
        	
        	Doc doc = new Doc(i, priorities[i]);
        	queue.add(doc);
        }
        
        Collections.sort(arr, Collections.reverseOrder());
        
        
        // 루프돌기
        int arr_i = 0;
        while(!queue.isEmpty()) {
        	
        	Doc curdoc = queue.peek();
        	//System.out.println(curdoc.priority+":"+arr.get(arr_i));
        	
        	// 내가가장 중요하다
        	if(curdoc.priority == arr.get(arr_i)) {
        		// 찾고자하는 녀석이다
        		if(curdoc.index == location) {
        			//끗
        			break;
        		}
        		else{
        			// 출력!!!
        			queue.poll();
        			arr_i++;
        			answer++;
        		}
        	}
        	else { // 내가가장 중요하진 않다.
        		// 맨뒤로보낸다
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
