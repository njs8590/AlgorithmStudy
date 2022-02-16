import java.util.ArrayList;
import java.util.List;

public class letterCombinations {
    public static void main(String[] args) {

//        Input: digits = "23"
//        Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

        String digits = "23";
        Solution sol = new Solution();

        sol.letterCombinations(digits);
    }

    static class Solution {
        String[] letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ArrayList<String> answer;

        public List<String> letterCombinations(String digits) { //23
            /* 2~ 9 까지 숫자
             * 핸드폰 키패드로 입력가능한 조합을 리턴
             */
            answer = new ArrayList<>();

            StringBuilder sb = new StringBuilder();

            dfs(sb, digits.length(), 0, digits);

            return answer;

        }

        void dfs(StringBuilder curLetters, int length, int index, String digits){
            // break
            if(curLetters.length() == length){
                answer.add(curLetters.toString());
                return;
            }
            // 이번 번호키에 대해서 순서대로 넣어보자
            char curDigit = digits.charAt(index);
            StringBuilder sb = new StringBuilder(letters[curDigit-'0']);

            for(int i=0;i<sb.length();i++){
                char letter = sb.charAt(i);
                curLetters.append(letter);
                dfs(curLetters, length, index+1, digits);
                //backup
                curLetters.deleteCharAt(curLetters.length()-1);
            }
        }
    }
}
