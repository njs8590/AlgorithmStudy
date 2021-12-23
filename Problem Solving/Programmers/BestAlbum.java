package problemSolving;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

public class BestAlbum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		String[] genres = {"a","b","c","d","a","d","d","d","a","a","c","c"};
//		int[] plays = {100,300,400,150,100,300,200,600,700,110,900,9000};
		
		String[] genres = {"classic", "pop", "classic", "classic", "pop"};
		int[] plays = {500, 600, 150, 800, 2500};

		
		int[] answer = solution(genres, plays);
		for(int i:answer) {
			System.out.print(i+" ");
		}
		
		
	}
	
    public static int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        HashMap<String, Integer> playPerGenre = new HashMap<>();
        HashMap<String, ArrayList<Music>> listPerGenre = new HashMap<>();
        
        for(int i=0;i<genres.length;i++) {
        	
        	// 장르별 플레이 횟수 누적
        	String genre = genres[i];
        	// 처음이 아닐경우
        	if(playPerGenre.containsKey(genre)) {
        		int currentPlayCount = playPerGenre.get(genre);
        		playPerGenre.put(genre, currentPlayCount+plays[i]);
        		
        		// 장르별 리스트구성
        		Music music = new Music(i,plays[i]);
        		listPerGenre.get(genre).add(music);
        		
        	}
        	// 처음 찾은 장르일경우
        	else {
        		playPerGenre.put(genre, plays[i]);
        		
        		// 장르별 리스트구성
        		ArrayList<Music> tempArr = new ArrayList<>();
        		Music music = new Music(i,plays[i]);
        		tempArr.add(music);
        		listPerGenre.put(genre,tempArr);
        	}
        }
        
        //장르별 플레이횟수 정렬
        ArrayList<Music> playPerGenreArrayList = new ArrayList<>();
        
        Iterator<String> it = playPerGenre.keySet().iterator();
        while(it.hasNext()) {
        	String genre = it.next();
        	int play = playPerGenre.get(genre);
        	
        	Music music = new Music(play, genre);
        	playPerGenreArrayList.add(music);
        }
        Collections.sort(playPerGenreArrayList, new Music());
        
        
        // 플레이수 많은 장르부터 루프
        ArrayList<Integer> answerArrayList = new ArrayList<>();
        
        for(int i=0;i<playPerGenreArrayList.size();i++) {
        	String genre = playPerGenreArrayList.get(i).genre;
        	
        	// 해당 장르의 플레이리스트
        	ArrayList<Music> tempArr = listPerGenre.get(genre);
        	// play순서대로 정렬
        	Collections.sort(tempArr, new Music());
        	//answer 에 입력
        	for(int j=0;j<tempArr.size();j++) {
        		answerArrayList.add(tempArr.get(j).id);
        		if(j==1) break; // 최대 두개까지만
        	}
        }
        
//        for(int i=0;i<answerArrayList.size();i++) {
//        	System.out.print(answerArrayList.get(i)+" ");
//        }
        
        answer = new int[answerArrayList.size()];
        for(int i=0;i<answerArrayList.size();i++) {
        	answer[i] = answerArrayList.get(i);
        }
        
        
        
        return answer;
    }
    
    public static class Music implements Comparator<Music>{
    	String genre;
    	int id;
    	int play;
    	
    	Music(int play, String genre){
    		this.play =play;
    		this.genre = genre;
    	}
    	
    	Music(int id, int play){
    		this.id = id;
    		this.play =play;
    	}

		public Music() {
			// TODO Auto-generated constructor stub
		}

		@Override
		public int compare(Music o1, Music o2) {
			
			// play수가 많다면 앞으로가
			if(o1.play > o2.play) {
				return -1;
			}
			// play수가 같으면 id가 작은게 앞으로와
			if(o1.id < o2.id) {
				return -1;
			}
			
			return 0;
		}
    }

}
