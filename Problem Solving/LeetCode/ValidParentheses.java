package problemSolving;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class ValidParentheses {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		// String s = "()[]{}";
		String s = "{[]}";
		System.out.println(isValid(s));
		
	}
	
    public static boolean isValid(String s) {
        
    	// () {} []
    	Stack<Character> stk = new Stack<>();
    	
    	for(int i=0;i<s.length();i++) {
    		char temp = s.charAt(i);
    		
    		
    		if(temp == '(') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����.
    				if(stk.peek() == '(' || stk.peek() == '{' ||stk.peek() == '[') {
    					stk.add(temp);
    				}
    				// ���������� ������..
    				else if(stk.peek() == ')' || stk.peek() == '}' || stk.peek() == ']') {
    					return false;
    				}
    			}
    		}
    		else if(temp == ')') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����
    				if(stk.peek() == '(') {
    					stk.pop();
    				}
    				// ���������� ������..
    				else if(stk.peek() == ')') {
    					return false;
    				}
    				// �ٸ��� �����־ ������..
    				else if(stk.peek() == '{' || stk.peek() == '[') {
    					return false;
    				}
    			}
    		}
    		
    		else if(temp == '{') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����.
    				if(stk.peek() == '(' || stk.peek() == '{' ||stk.peek() == '[') {
    					stk.add(temp);
    				}
    				// ���������� ������..
    				else if(stk.peek() == ')' || stk.peek() == '}' || stk.peek() == ']') {
    					return false;
    				}
    			}
    		}
    		else if(temp == '}') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����
    				if(stk.peek() == '{') {
    					stk.pop();
    				}
    				// ���������� ������..
    				else if(stk.peek() == '}') {
    					return false;
    				}
    				// �ٸ��� �����־ ������..
    				else if(stk.peek() == '(' || stk.peek() == '[') {
    					return false;
    				}
    			}
    		}
    		
    		else if(temp == '[') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����.
    				if(stk.peek() == '(' || stk.peek() == '{' ||stk.peek() == '[') {
    					stk.add(temp);
    				}
    				// ���������� ������..
    				else if(stk.peek() == ')' || stk.peek() == '}' || stk.peek() == ']') {
    					return false;
    				}
    			}
    		}
    		else if(temp == ']') {
    			// ��������� ����.
    			if(stk.isEmpty())stk.add(temp);
    			else {
    				// ���������� ����
    				if(stk.peek() == '[') {
    					stk.pop();
    				}
    				// ���������� ������..
    				else if(stk.peek() == ']') {
    					return false;
    				}
    				// �ٸ��� �����־ ������..
    				else if(stk.peek() == '{' || stk.peek() == '(') {
    					return false;
    				}
    			}
    		}
    	}
    	
    	if(stk.empty()) {
    		return true;
    	}
    	else return false;
    	
    	
    }

}
