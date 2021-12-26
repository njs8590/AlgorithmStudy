import java.util.HashMap;

public class PhoneBook {

	public static void main(String[] args) {
		String[] phone_book = {"123", "456", "789"};
		
		System.out.println(solution(phone_book));
		
	}
	
    public static boolean solution(String[] phone_book) {
        boolean answer = true;
        
        // 해시맵 구성
        HashMap<String, Integer> map = new HashMap<>();
        
        for(String phone : phone_book) {
        	map.put(phone, 1);
        }
        
        for(String phone:phone_book) {
        	// 한글자씩 루프
        	String temp = "";
        	for(int i=0;i<phone.length()-1;i++) {
        		temp+=phone.charAt(i);
        		System.out.println(temp);
        		if(map.containsKey(temp)) {
        			System.out.println("!!");
        			answer = false;
        			break;
        		}
        	}
        }
        
        return answer;
    }

}
