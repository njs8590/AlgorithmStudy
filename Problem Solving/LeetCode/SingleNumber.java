import java.util.HashMap;
import java.util.Map;

public class SingleNumber {

    public static void main(String[] args) {

    }

    class Solution {
        public int singleNumber(int[] nums) {

            // 한개의 숫자 빼고는 모두 두번씩 들어있음. -> 이 숫자를 찾아라

            Map<Integer, Integer> map = new HashMap<>();

            for(int num :nums){
                if(map.containsKey(num)){
                    map.put(num, 2);
                }
                else{
                    map.put(num,1);
                }
            }
            int answer = 0;
            for(int key : map.keySet()){
                if(map.get(key)==1){
                    answer = key;
                    break;
                }
            }

            return answer;
        }
    }
}


/*
 XOR 연산을 이용한 다른 풀이....

we use bitwise XOR to solve this problem :

        first , we have to know the bitwise XOR in java

        0 ^ N = N
        N ^ N = 0
        So..... if N is the single number

        N1 ^ N1 ^ N2 ^ N2 ^..............^ Nx ^ Nx ^ N

        = (N1^N1) ^ (N2^N2) ^..............^ (Nx^Nx) ^ N

        = 0 ^ 0 ^ ..........^ 0 ^ N

        = N

public int singleNumber(int[] nums) {
        int ans =0;

        int len = nums.length;
        for(int i=0;i!=len;i++)
        ans ^= nums[i];

        for (int num : nums) ans ^= num;

        return ans;

        }*/
