package problemSolving;

public class FirstUniqueCharacterinaString {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(firstUniqChar("aabb"));
	}
	
	public static int firstUniqChar(String s) {
	    
		// 유니크한 가장 첫번재 캐릭더의 인덱스를 반환하자.
		// 복잡도조건이 없으니 포문을 열심히 돌려보자
		int answer = -1;
		
		for(int i=0;i<s.length();i++) {
			char candi = s.charAt(i);
			Boolean find = true;
			
			for(int j=0;j<s.length();j++) {
				if(i==j)continue;
				if(s.charAt(j) == candi) {
					// stringBuilder 라면 중복발견 이후에 재검사안하게 바꿔놓자.
					find = false;
					break;
				}
			}
			if(find) {
				answer = i;
				break;
			}
		}
		
		return answer;
	}
}

