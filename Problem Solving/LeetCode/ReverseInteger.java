package problemSolving;

public class ReverseInteger {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(reverse(123123));
	}
	
    public static int reverse(int x) {
    	String str = Long.toString(x);
        
        // StringBuffer �� �̿��� �������غ���
        // -> ���̳ʽ��϶� ���ֺҸ��ϴ�
        StringBuffer sb = new StringBuffer(str);
        sb.reverse();
        
        // ���������ڰ� ���̳ʽ��� �տ�������
        //System.out.println(sb.charAt(sb.length()-1));
        if( sb.charAt(sb.length()-1) == '-') {
        	sb.deleteCharAt(sb.length()-1);
        	sb.insert(0, "-");
        }
        
        //System.out.print(sb.toString());
        
        long longAnswer = (Long.parseLong(sb.toString()));
        
        if(longAnswer > Integer.MAX_VALUE || longAnswer < Integer.MIN_VALUE) return 0;
        
        int answer = (int)longAnswer;
        
    	return answer;
    }

}
