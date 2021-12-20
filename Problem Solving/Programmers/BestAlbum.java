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
		String[] genres = {"a","b","c","d","a","d","d","d","a","a","c","c"};
		int[] plays = {100,300,400,150,100,300,200,600,700,110,900,9000};

		
		int[] answer = solution(genres, plays);
		for(int i=0;i<4;i++) {
			System.out.print(answer[i]+" ");
		}
		
		
	}
	
    public static int[] solution(String[] genres, int[] plays) {
        int[] answer = {};
        
        HashMap<String, Integer> playPerGenre = new HashMap<>();
        HashMap<String, ArrayList<Music>> listPerGenre = new HashMap<>();
        
        for(int i=0;i<genres.length;i++) {
        	
        	// �帣�� �÷��� Ƚ�� ����
        	String genre = genres[i];
        	// ó���� �ƴҰ��
        	if(playPerGenre.containsKey(genre)) {
        		int currentPlayCount = playPerGenre.get(genre);
        		playPerGenre.put(genre, currentPlayCount+plays[i]);
        		
        		// �帣�� ����Ʈ����
        		Music music = new Music(i,plays[i]);
        		listPerGenre.get(genre).add(music);
        		
        	}
        	// ó�� ã�� �帣�ϰ��
        	else {
        		playPerGenre.put(genre, plays[i]);
        		
        		// �帣�� ����Ʈ����
        		ArrayList<Music> tempArr = new ArrayList<>();
        		Music music = new Music(i,plays[i]);
        		tempArr.add(music);
        		listPerGenre.put(genre,tempArr);
        		
        	}
        }
        
        // ���� ���� ����� �帣Ž��
        Iterator<String> it = playPerGenre.keySet().iterator();
        String top1 = "";
        String top2 = "";
        int top1_cnt = 0;
        int top2_cnt = 0;
        while(it.hasNext()) {
        	String key = it.next();
        	int value = playPerGenre.get(key);
        	
        	if(top1_cnt < value) {
        		top1_cnt = value;
        		top1 = key;
        	}
        	else if(top2_cnt < value) {
        		top2_cnt = value;
        		top2 = key;
        	}
        }
        
        // top �帣�� ����Ʈ ����
        ArrayList<Integer> temparr = new ArrayList<>();
        
        if(listPerGenre.containsKey(top1)) {
        	Collections.sort(listPerGenre.get(top1), new Music());

        	for(int i=0;i<listPerGenre.get(top1).size();i++) {
        		if(i==2) break;
        		temparr.add(listPerGenre.get(top1).get(i).id);
        	}
        }
        	
        if(listPerGenre.containsKey(top2)) {
        	Collections.sort(listPerGenre.get(top2), new Music());
        	
        	for(int i=0;i<listPerGenre.get(top2).size();i++) {
        		if(i==2) break;
        		temparr.add(listPerGenre.get(top2).get(i).id);
        	}
        }
        	
        answer = new int[temparr.size()];
        for(int i=0;i<temparr.size();i++) {
        	answer[i] = temparr.get(i);
        }
        
        
        return answer;
    }
    
    public static class Music implements Comparator<Music>{
    	int id;
    	int play;
    	
    	Music(int id, int play){
    		this.id = id;
    		this.play =play;
    	}

		public Music() {
			// TODO Auto-generated constructor stub
		}

		@Override
		public int compare(Music o1, Music o2) {
			
			// play���� ���ٸ� �����ΰ�
			if(o1.play > o2.play) {
				return -1;
			}
			// play���� ������ id�� ������ �����ο�
			if(o1.id < o2.id) {
				return -1;
			}
			
			return 0;
		}
    }

}
