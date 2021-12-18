package problemSolving;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

//https://programmers.co.kr/learn/courses/30/lessons/72412

public class Kakao2021_RankingSearch {

	public static void main(String[] args) {
		
		//String[] info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
		//String[] query = {"- and - and - and - 0","java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
		
		String[] info = {"cpp backend senior pizza 260"};
		String[] query = {"- and - and - and - 0","java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
		
		int[] arr = solution(info, query);
		for(int i=0;i<arr.length;i++) {
			System.out.print(arr[i]+" ");
		}
	}
	
    public static int[] solution(String[] info, String[] query) {
        int[] answer = {};
        
        // 개발언어 선택 : cpp, java, python
        // 지원직군 선택 : back, front
        // 경력구분 선택 : junior, senior
        // 소울푸드 선택 : chicken, pizza
        
        // 자료구조: 언어 - 직군 - 경력 - 푸드 -점수
        
        // init
        // food
        HashMap<String, ArrayList<Integer>> map_food = new HashMap<>();
        map_food.put("chicken", new ArrayList<Integer>());
        map_food.put("pizza", new ArrayList<Integer>());
        map_food.put("-", new ArrayList<Integer>());
        
        // career
        HashMap<String, HashMap<String, ArrayList<Integer>>> map_career = new HashMap<>();
        map_career.put("junior", map_food);
        map_career.put("senior", map_food);
        map_career.put("-", map_food);
        
        // job
        HashMap<String, HashMap<String, HashMap<String, ArrayList<Integer>>>> map_job = new HashMap<>();
        map_job.put("backend", map_career);
        map_job.put("frontend", map_career);
        map_job.put("-", map_career);
        
        // language
        Map<String, //언어
    	HashMap<String, //직군
    		HashMap<String, // 경력
    			HashMap<String, ArrayList<Integer>>>>> // 점수 list
        map = new HashMap<>();
        map.put("cpp", map_job);
        map.put("java", map_job);
        map.put("python", map_job);
        map.put("-", map_job);
        
        
        
        for(int i=0;i<info.length;i++) {
        	
        	String[] strArray = info[i].split(" ");
        	
        	String language = strArray[0];
        	String job = strArray[1];
        	String career = strArray[2];
        	String food = strArray[3];
        	int score = Integer.parseInt(strArray[4]);
        	
        	// insert
/*
        	0000
        	1000
        	1001
        	1010
        	1011
        	1100
        	1101
        	1110
        	1111
        	0100
        	0101
        	0110
        	0111
        	0010
        	0011
        	0001
*/      	
        	
        	ArrayList<Integer> arr;
        	map.get(language).get(job).get(career).get(food).add(score);
        	map.get("-").get(job).get(career).get(food).add(score);
        	map.get("-").get(job).get(career).get("-").add(score);
        	map.get("-").get(job).get("-").get(food).add(score);
        	map.get("-").get(job).get("-").get("-").add(score);
        	map.get("-").get("-").get(career).get(food).add(score);
        	map.get("-").get("-").get(career).get("-").add(score);
        	map.get("-").get("-").get("-").get(food).add(score);
        	map.get("-").get("-").get("-").get("-").add(score);
        	map.get(language).get("-").get(career).get(food).add(score);
        	map.get(language).get("-").get(career).get("-").add(score);
        	map.get(language).get("-").get("-").get(food).add(score);
        	map.get(language).get("-").get("-").get("-").add(score);
        	map.get(language).get(job).get("-").get(food).add(score);
        	map.get(language).get(job).get("-").get("-").add(score);
        	map.get(language).get(job).get(career).get("-").add(score);
        	
        	arr = map.get(language).get(job).get(career).get(food);
        	for(int ii=0;ii<arr.size();ii++) {
        		System.out.print(arr.get(ii)+" ");
        	}
        	System.out.println();
        	
        }
        
        // Sorting
        
        answer = new int[query.length];
        
        for(int i=0;i<query.length;i++) {
        	
        	String[] strArray = query[i].split(" and ");
        	String language = strArray[0];
        	String job = strArray[1];
        	String career = strArray[2];
        	
        	String[] lastStr = strArray[3].split(" ");
        	String food = lastStr[0];
        	int score = Integer.parseInt(lastStr[1]);
        	
        	ArrayList<Integer> arrList = map.get(language).get(job).get(career).get(food);
        	
//        	for(int ii=0;ii<arrList.size();ii++) {
//        		System.out.print(arrList.get(ii)+" ");
//        	}
//        	System.out.println();
        	
        	int count = 0;
        	for(int j=0;j<arrList.size();j++) {
        		if(arrList.get(j)>=score) {
        			count++;
        		}
        	}
        	answer[i]=count;
        }
        
        
        
        return answer;
    }
    
    

}
