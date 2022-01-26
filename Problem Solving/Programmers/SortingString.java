import java.util.*;

//Comparator 연습

public class SortingString {
    public static void main(String[] args) {

        String[] string = {"sun", "bed", "car"};
        int n = 1;

        String[] answer = solution(string, n);

        for(String answertemp:answer){
            System.out.println(answertemp);
        }
    }

    public static String[] solution(String[] strings, int n) {
        String[] answer = {};

        ArrayList<Mystring> str = new ArrayList();
        for(String strtemp:strings){
            Mystring mystring = new Mystring(strtemp, strtemp.charAt(n));
            str.add(mystring);
        }

        //3. 클래스 객체와 함께 소팅함수 호출
        Collections.sort(str, new Mystring());

        answer = new String[str.size()];
        for(int i=0;i<str.size();i++){
            answer[i] = str.get(i).str;
        }

        return answer;
    }
}

// 1. Comparator 인터페이스를 포함한 클래스 생성
class Mystring implements Comparator<Mystring>{
    String str;
    char cha;

    Mystring(){}

    Mystring(String s ,char c){
        str = s;
        cha = c;
    }

    // 2.compare 함수 구현
    @Override
    public int compare(Mystring s1, Mystring s2){
        // cha 비교해서 더 작으면 앞으로가
        if(s1.cha < s2.cha){
            return -1;
        }

        // cha 가 같으면
        // 문자열 작으면 앞으로가
        else{
            // s1이 s2보다 작으면(사전순으로 앞서면) 앞으로가
            if(s1.str.compareTo(s2.str) <0){
                return -1;
            }
            else if(s1.str.compareTo(s2.str) > 0){
                return 1;
            }
            else{
                return 0;
            }
        }
    }

}
