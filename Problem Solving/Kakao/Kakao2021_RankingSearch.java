import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;

public class Kakao2021_RankingSearch {
	public static void main(String[] args) {
		String[] info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
		//String[] info = {"java backend junior pizza 150"};
		
		String[] query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150", "java and - and - and - 300"};
		//String[] query = {"java and backend and junior and pizza 100"};
		//String[] query = {"- and - and - and - 150"};
		
		int[] arr = solution(info, query);
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
	}	
	
	public static int[] solution(String[] info, String[] query) {
        int[] answer = {};
        
        // ���	����	���	�ҿ� Ǫ��	����
        
        HashMap<String, ArrayList<Integer>> map = new HashMap<>();
        
        for(String curinfo : info) {
        	String[] strtemp = curinfo.split(" ");
            String language = strtemp[0];
            String job = strtemp[1];
            String year = strtemp[2];
            String food = strtemp[3];
            int score = Integer.parseInt(strtemp[4]);
            
            String temp = "";
            /* ����Ǽ� 2^4 = 16 */
            
            temp = "----"; // 0000
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ "---"; //1000
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "-"     + job + "--" ; //0100
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "--"          + year +"-"; //0010
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "---"                +food; //0001
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ job + "--" ; //1100
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ "-" + year +"-"; //1010
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ "--"       +food;//1001
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "-"     + job + year +"-";//0110
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "-"     + job + "-"  +food;//0101
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "--"          + year +food; //0011
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ job + year +"-";//1110
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ job + "-"  +food;//1101
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ "-" + year +food;//1011
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = "-"     + job + year +food;//0111
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
            temp = language+ job + year +food; //1111
            if(map.containsKey(temp)) {map.get(temp).add(score);}
            else {ArrayList<Integer> newarr = new ArrayList<Integer>();newarr.add(score);map.put(temp, newarr);}
        }
        
        
		// ����
		for(String it : map.keySet()) {
			Collections.sort(map.get(it));
			  
//			System.out.print(it+":");
//			for(int i : map.get(it)) {
//				System.out.print(i+",");
//			}
//			System.out.println();
		}
		  
	
		ArrayList<Integer> answerList = new ArrayList<>();
		
		for(String temp:query) { 
			//String[] query = {"java and backend and junior and pizza 100"};
			String[] strarr = temp.split(" ");
			String curQuery = strarr[0]+strarr[2]+strarr[4]+strarr[6];
//			System.out.println(curQuery);
			int curScore = Integer.parseInt(strarr[7]);
			
			ArrayList<Integer> curArr = map.get(curQuery);
			
//			System.out.print("find["+curScore+"] arr:");
//			for(int tempcurArr:curArr) {
//				System.out.print(tempcurArr+",");
//			}
//			System.out.println();
			
			// ����Ž��
//			int head = 0;
//			int tail = curArr.size()-1;
//			int AnswerStartFrom = 0;
//			int AnswerEnd = tail;
//			boolean noAnswer = false;
//			
//			while(head < tail) {
//				
//				int mid = (head+tail)/2;
////				System.out.println("mid@:"+mid);
//				
//				int cur = curArr.get(mid);
//				
//				
//				// ������ ������ �������� ������ ū �ָ� ã�ƾ���.
//				if(cur < curScore){
//					// ���Ⱑ �������̸� ����.
//					if(mid == AnswerEnd) {
//						noAnswer = true;
//						break;
//					}
//					else {
//						// �������� ������ũ��
//						if(curArr.get(mid+1) > curScore) {
//							AnswerStartFrom = mid+1;
//							break;
//						}
//						else {
//							// ������ �� Ž��
//							head = mid+1;
//						}
//					}
//				}
//				else if(cur == curScore) {
//					// ã�Ҵµ� ������ ������ �۴ٸ� ���Ⱑ �����̴�
//					if(mid>0) {
//						if(curArr.get(mid-1)<curScore) {
//							AnswerStartFrom = mid;
//							break;
//						}
//					}
//				}
//				
//				// ����Ž��
//				tail = mid-1;
//				
//			}
//			
//			if(noAnswer)answerList.add(0);
//			else answerList.add(curArr.size() - AnswerStartFrom);
//			//System.out.println("answer:"+curArr.size()+"-"+AnswerStartFrom+"="+(curArr.size() - AnswerStartFrom));
			
			// �����ϰ� Ž��
			int i=0;
			for(i=0;i<curArr.size();i++) {
				if(curArr.get(i) >= curScore) {
					break;
				}
			}
			answerList.add(curArr.size()-i);
		}
    	
		answer= new int[answerList.size()];
		for(int i=0;i<answerList.size();i++) {
			answer[i] = answerList.get(i);
		}
        
        
        return answer;
    }	
   
}
