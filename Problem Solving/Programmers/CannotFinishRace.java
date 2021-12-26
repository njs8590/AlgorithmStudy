import java.util.HashMap;

public class CannotFinishRace {

	public static void main(String[] args) {
		String[] participant = {"marina", "josipa", "nikola", "vinko", "filipa"};
		String[] completion = {"josipa", "filipa", "marina", "nikola"};
		
		System.out.println(solution(participant, completion));
	}
	
    public static String solution(String[] participant, String[] completion) {
        String answer = "";
        
        // �Ѹ� ���ָ� ����
        // ���������� ����������
        
        // ������ map ����
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String comp : completion) {
        	if(map.containsKey(comp)) {
        		map.put(comp, map.get(comp)+1);
        	}
        	else {
        		map.put(comp, 1);
        	}
        }
        
        // ������ ����
        for(String parti : participant) {
        	// ���������� --
        	if(map.containsKey(parti)) {
        		// ���������� �ƴϸ� return
        		if(map.get(parti)==0) {
        			answer = parti;
        			break;
        		}
        		else {
        			map.put(parti, map.get(parti)-1);
        		}
        	}
        	// �����ڸ�ܿ� ������
        	else {
        		answer = parti;
        		break;
        	}
        }
        
        return answer;
    }

}
