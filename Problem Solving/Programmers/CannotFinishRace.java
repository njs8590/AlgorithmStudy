import java.util.HashMap;

public class CannotFinishRace {

	public static void main(String[] args) {
		String[] participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
		String[] completion = {"josipa", "filipa", "marina", "nikola"};
		
		System.out.println(solution(participant, completion));
	}
	
    public static String solution(String[] participant, String[] completion) {
        String answer = "";
        
        // 한명만 완주를 못함
        // 동명이인이 있을수있음
        
        // 완주자 map 생성
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String comp : completion) {
        	if(map.containsKey(comp)) {
        		map.put(comp, map.get(comp)+1);
        	}
        	else {
        		map.put(comp, 1);
        	}
        }
        
        // 참가자 루프
        for(String parti : participant) {
        	// 완주했으면 --
        	if(map.containsKey(parti)) {
        		// 동명이인이 아니면 return
        		if(map.get(parti)==0) {
        			answer = parti;
        			break;
        		}
        		else {
        			map.put(parti, map.get(parti)-1);
        		}
        	}
        	// 완주자명단에 없으면
        	else {
        		answer = parti;
        		break;
        	}
        }
        
        return answer;
    }

}
