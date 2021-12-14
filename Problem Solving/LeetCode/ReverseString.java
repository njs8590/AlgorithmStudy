package problemSolving;

public class ReverseString {

	public static void main(String[] args) {
		
		char[] s = {'h','e','l','l','o'};
		reverseString(s);
		
	}
	
    public static void reverseString(char[] s) {
        int stringSize = s.length;
    	
    	for(int i=0;i<stringSize/2;i++) {
        	char temp = s[i];
        	s[i] = s[stringSize-1 - i];
        	s[stringSize-1 -i] = temp;
        }
    }

}
