public class ContainerWithMostWater {
    public static void main(String[] args) {
        int[] height = {1,8,6,2,5,4,8,3,7};
        Solution sol = new Solution();
        System.out.println(sol.maxArea(height));
    }

    static class Solution {
        public int maxArea(int[] height) {
            int start = 0;
            int end = height.length-1;

            //너비를 최대로 두고 시작하기때문에, 높이가 무조건 높아져야 한다.
            int answer = 0;
            while(start < end){
                int newHeight = Math.min(height[start], height[end]); // 둘중에 더 작은것이 높이
                int newWidth = end-start;
                answer = Math.max(answer, newHeight*newWidth);

                if(height[start] < height[end]){ // 작은것을 더 높이려고 해보자. 그래야 높이가 높아지지..
                    start++;
                }
                else{
                    end--;
                }
            }

            return answer;

        }
    }
}

