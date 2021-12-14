package problemSolving;

public class ReverseInteger {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(reverse(123123));
	}
	
    public static int reverse(int x) {
    	String str = Long.toString(x);
        
        // StringBuffer 를 이용해 리버스해보자
        // -> 마이너스일때 아주불리하다
        StringBuffer sb = new StringBuffer(str);
        sb.reverse();
        
        // 마지막글자가 마이너스면 앞에붙이자
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
