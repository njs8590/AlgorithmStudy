import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

public class VaccineSolution {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//String[] vac = {"PIZER 3 20 99", "ASTRA 1 9 55", "YANSEN 10000 22 49"};
		//String[] peo = {"susan 50 ASTRA YANSEN PIZER","kevin 55 ASTRA","luka 60 PIZER ASTRA","erica 20 YANSEN PIZER ASTRA","roy 20 PIZER"};
		
		String[] vac = {"Y 1 30 40","X 9999 1 99","Z 9 50 65", "T 10000 1 99"};
		String[] peo = {"aaa 50 Z Y","bbb 40 Y T X", "cc 30 Y T", "dd 65 Y Z","gg 1 T"};
		
		Sol sol = new Sol();
		
		String[] answer = sol.solution(vac, peo);
		
		for(int i=0;i<answer.length;i++) {
			System.out.println(answer[i]);
		}
	}

}

class Sol{
	String[] solution(String[] vac, String[] peo) {
		String[] answer;
		
		HashMap<String, Vaccine> map = new HashMap<>();
		ArrayList<Vaccine> vaccines = new ArrayList<>();
		ArrayList<Person> persons = new ArrayList<>();
		
		//백신정보
		for(String v:vac) {
			String curvac[]= v.split(" ");
			Vaccine vaccine = new Vaccine(curvac[0], Integer.parseInt(curvac[1]), Integer.parseInt(curvac[2]), Integer.parseInt(curvac[3]));
			//vaccine.mytoString();
			// vaccines.add(vaccine);
			map.put(vaccine.name, vaccine);
		}
		
		// 희망조사
		int rank = 1;
		for(String p:peo) {
			String curpeo[] = p.split(" ");
			ArrayList<String> arrtemp = new ArrayList<>();
			
			//System.out.println("curpeo.length:"+curpeo.length);
			for(int i=2;i<curpeo.length;i++) {
				arrtemp.add(curpeo[i]);
			}
			
			Person person = new Person(rank++, curpeo[0], Integer.parseInt(curpeo[1]), arrtemp);
			persons.add(person);
		}
		
		Collections.sort(persons, new Person());
		
		//접종해보자..
		for(int i=0;i<persons.size();i++) {
			Person curPerson = persons.get(i);
			
			for(String candiVaccine:curPerson.vaccine) {
				// 백신재고확인
				Vaccine curVaccine = map.get(candiVaccine);
				if(curVaccine.stock <= 0) {
					continue;
				}
				
				// 나이확인
				if(curPerson.age > curVaccine.max_age || curPerson.age < curVaccine.min_age) {
					continue;
				}
				
				// 맞자
				map.get(candiVaccine).stock--;
				map.get(candiVaccine).people.add(curPerson.name);
				break;
			}
		}
		
		// map to list
		for(String key : map.keySet()){
			vaccines.add(map.get(key));
		}
		
		Collections.sort(vaccines, new Vaccine());
		
		
		ArrayList<String> answerList = new ArrayList<>();
		
		for(int i=0;i<vaccines.size();i++) {
			// 접종자가 없는 백신은 스킵
			if(map.get(vaccines.get(i).name).people.size()<=0)continue;
			
			StringBuilder sb = new StringBuilder();
			sb.append(vaccines.get(i).name);
			sb.append(" ");
			sb.append(map.get(vaccines.get(i).name).returnValue());
			answerList.add(sb.toString());
		}
		
		answer = new String[answerList.size()];
		for(int i=0;i<answerList.size();i++) {
			answer[i]=  answerList.get(i);
		}
		
		return answer;
	}
}

class Vaccine implements Comparator<Vaccine>{
	String name;
	int stock;
	int min_age;
	int max_age;
	ArrayList<String> people;
	
	Vaccine(){}
	
	Vaccine(String n, int s, int mi, int ma){
		name = n;
		stock = s;
		min_age = mi;
		max_age = ma;
		people = new ArrayList<>();
	}
	
	void mytoString() {
		System.out.println(name+"/"+stock+"/"+min_age+"/"+max_age);
	}
	
	void addPerson(String personName) {
		people.add(personName);
	}
	
	String returnValue() {
		Collections.sort(people);
		
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<people.size();i++) {
			sb.append(people.get(i));
			if(i<people.size()-1) {
				sb.append(" ");
			}
		}
		
		return sb.toString();
	}
	
	@Override
	public int compare(Vaccine v1, Vaccine v2) {
		// 백신이름 오름차순
		if(v1.name.compareTo(v2.name)<0) {
			return -1;
		}
		else if(v1.name.compareTo(v2.name)>0){
			return 1;
		}
		else {
			return 0;
		}
	}
}

class Person implements Comparator<Person>{
	int rank;
	String name;
	int age;
	ArrayList<String> vaccine;
	
	Person(){}
	
	Person(int r, String n, int a, ArrayList<String> v){
		rank = r;
		name = n;
		age = a;
		vaccine = v;
	}
	
	@Override
	public int compare(Person p1, Person p2) {
		// 나이가 많으면 앞으로가
		if(p1.age > p2.age) {
			return -1;
		}
		else if(p1.age < p2.age) {
			return 1;
		}
		else {
			// rank 가 작으면 앞으로가
			if(p1.rank < p2.rank) {
				return -1;
			}
			else return 1;
		}
	}
	
	void mytoString() {
		System.out.print(rank+"/"+name+"/"+age+"/");
		for(String temp:vaccine) {
			System.out.print(temp+",");
		}
		System.out.println();
	}
}