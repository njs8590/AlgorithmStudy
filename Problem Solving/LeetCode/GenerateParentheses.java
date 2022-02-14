import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {
    public static void main(String[] args) {
//        Input: n = 3
//        Output: ["((()))","(()())","(())()","()(())","()()()"]

        Solution sol = new Solution();
        sol.generateParenthesis(3);

    }

    static class Solution {

        List<String> answer;
        public List<String> generateParenthesis(int n) {
            answer = new ArrayList<>();

            int left = n;
            int right = n;
            int open = 0;

            StringBuilder sb = new StringBuilder();
            dfs(left, right, open, sb, n);

//            for(String str:answer){
//                System.out.println(str);
//            }
            return answer;
        }

        void dfs(int left, int right, int open, StringBuilder sb, int n){
            //break
            if(left ==0 && right == 0){
                answer.add(sb.toString());
                return;
            }

            if(left > 0){
                sb.append("(");
                dfs(left-1, right, open+1, sb, n);
                sb.deleteCharAt(sb.length()-1);
            }
            if(open > 0){
                sb.append(")");
                dfs(left, right-1, open-1, sb, n);
                sb.deleteCharAt(sb.length()-1);
            }
        }
    }
}
