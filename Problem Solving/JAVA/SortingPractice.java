import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

public class SortingPractice {

	public static void main(String[] args) {
		
		ArrayList<Person> persons = new ArrayList<>();
		persons.add(new Person("에이", 10, 150));
		persons.add(new Person("비비", 20, 140));
		persons.add(new Person("씨씨", 10, 160));
		persons.add(new Person("디디", 10, 190));
		persons.add(new Person("이이", 20, 140));
		
		Iterator<Person> iterator = persons.iterator();
		while(iterator.hasNext()) {
			Person temp = iterator.next();
			System.out.println(temp.name+":"+temp.age+":"+temp.height);
		}
		
		Collections.sort(persons, new Person());
		
		System.out.println("==========sorting=========");
		
		Iterator<Person> iterator2 = persons.iterator();
		while(iterator2.hasNext()) {
			Person temp = iterator2.next();
			System.out.println(temp.name+":"+temp.age+":"+temp.height);
		}
	}

}

class Person implements Comparator<Person>{
	String name;
	int age;
	int height;
	
	Person(){}
	
	Person(String n, int a, int h){
		this.name = n;
		this.age = a;
		this.height = h;
	}

	@Override
	public int compare(Person o1, Person o2) {
		
		if(o1.age > o2.age) { // 내가 나이가 더 많으면 => 나이 오름차순
			return 1; // 뒤로가
		}
		else if(o1.age < o2.age){ // 내가 나이가 더 적으면 
			return -1; // 앞으로가
		}
		else { // 나이가 같으면
			if(o1.height > o2.height) { // 내가 키가더 크면
				return 1; // 뒤로가
			}
			else if(o1.height < o2.height) {
				return -1;
			}
			else {
				return o1.name.compareTo(o2.name); // 내가더크면 1, 내가더작으면 -1, 같으면 0
			}
		}
	}
}