package problemSolving;

public class FirstUniqueCharacterinaString {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(firstUniqChar("aabb"));
	}
	
	public static int firstUniqChar(String s) {
	    
		// ����ũ�� ���� ù���� ĳ������ �ε����� ��ȯ����.
		// ���⵵������ ������ ������ ������ ��������
		int answer = -1;
		
		for(int i=0;i<s.length();i++) {
			char candi = s.charAt(i);
			Boolean find = true;
			
			for(int j=0;j<s.length();j++) {
				if(i==j)continue;
				if(s.charAt(j) == candi) {
					// stringBuilder ��� �ߺ��߰� ���Ŀ� ��˻���ϰ� �ٲ����.
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

