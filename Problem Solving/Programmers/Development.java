package problemSolving;

import java.util.ArrayList;
import java.util.Stack;

public class Development {

	public static void main(String[] args) {
		
		int[] progresses = {93, 30, 55};
		int[] speeds = {1,30,5};
		
		solution(progresses, speeds);
		
	}
	
    public static int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        
        // progresses: 작업의 진도율
        // speeds 하루에 진행가능한 정도
        
        Stack<Process> stack = new Stack<Process>();
        
        // 스택에 거꾸로 넣어보자
        for(int i=progresses.length-1;i>=0;i--) {
        	Process process = new Process(progresses[i], speeds[i]);
        	
        	stack.add(process);
        }
        
        int day = 0;
        int deploy = 0;
        
        ArrayList<Integer> arr = new ArrayList<Integer>();
        
        while(!stack.empty()) {
        	Process process = stack.peek();
        	//System.out.println(process.progress+":"+day);
        	// 지금일수로 배포가 가능하다
        	if(process.progress + process.speed*day >= 100) {
        		stack.pop();
        		deploy++;
        	}
        	// 다음날을 기약하자
        	else {
        		// 배포된게 있나?
        		if(deploy > 0 ) arr.add(deploy);
        		deploy = 0;
        		day++;
        	}
        }
        //마지막 처리
        if(deploy > 0 ) arr.add(deploy);
        
        answer = new int[arr.size()];
        for(int i=0;i<arr.size();i++) {
        	answer[i] = arr.get(i);
        	//System.out.print(answer[i]+" ");
        }
        
        
        return answer;
    }
    
    public static class Process{
    	
    	int progress;
    	int speed;
    	
    	Process(){};
    	Process(int p, int s){
    		progress = p;
    		speed = s;
    	}
    }

}
