import java.util.LinkedList;
import java.util.Queue;

public class NumberofIslands {

    public static void main(String[] args) {
//        char[][] grid = {
//                {'1', '1', '1', '1', '0'},
//                {'1', '1', '0', '1', '0'},
//                {'1', '1', '0', '0', '0'},
//                {'0', '0', '0', '0', '0'}
//        };
        
          char[][] grid = {{'1','1','0','0','0'},
                            {'1','1','0','0','0'},
                            {'0','0','1','0','0'},
                            {'0','0','0','1','1'}};
        
        Solution sol = new Solution();

        System.out.println(sol.numIslands(grid));
    }

    static class Solution {
        public int numIslands(char[][] grid) {
            int dx[] = {0,0,-1,+1};
            int dy[] = {-1,+1,0,0};

            Queue<Pos> q = new LinkedList<>();

            // m*n graph
            int n = grid[0].length;
            int m = grid.length;
            int[][] visited = new int[m][n]; // m*n

            int answer = 0;

            // grid 전체탐색 loop
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){

                    // continue 조건
                    if(visited[i][j] == 1)continue; // 이미 방문한경우
                    if(grid[i][j] == '0' )continue; // 물일경우

                    // 섬을 찾았다. 여기부터 BFS로 뻗어나가보자
                    if(grid[i][j] == '1'){
                        answer++; // 섬 찾았다.
                        visited[i][j] = 1; // 방문체크
                        Pos pos = new Pos(i,j);
                        q.add(pos);

                        // BFS QUEUE
                        while(!q.isEmpty()){
                            Pos curpos = q.poll();

                            for(int d=0;d<4;d++){
                                Pos nextpos = new Pos(curpos.y+dy[d], curpos.x+dx[d]);
                                //continue 조건
                                if(nextpos.y >= m || nextpos.y < 0 || nextpos.x >= n || nextpos.x < 0) continue; //grid 를 벗어난경우
                                if(visited[nextpos.y][nextpos.x] == 1)continue; // 이미방문한경우
                                if(grid[nextpos.y][nextpos.x] == '0')continue;//물일경우

                                // 섬일경우 다음진행
                                if(grid[nextpos.y][nextpos.x] == '1'){
                                    q.add(nextpos);
                                    visited[nextpos.y][nextpos.x] = 1;
                                }
                            }
                        } // end while for q
                    }

                } // end loop for j
            } // end loop for i

            return answer;
        }

        class Pos{
            int y;
            int x;
            Pos() {}
            Pos(int y, int x){
                this.x = x;
                this.y = y;
            }
        }
    }
}
