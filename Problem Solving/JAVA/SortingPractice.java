import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

public class SortingPractice {

	public static void main(String[] args) {
		
		ArrayList<Person> persons = new ArrayList<>();
		persons.add(new Person("����", 10, 150));
		persons.add(new Person("���", 20, 140));
		persons.add(new Person("����", 10, 160));
		persons.add(new Person("���", 10, 190));
		persons.add(new Person("����", 20, 140));
		
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
		
		if(o1.age > o2.age) { // ���� ���̰� �� ������ => ���� ��������
			return 1; // �ڷΰ�
		}
		else if(o1.age < o2.age){ // ���� ���̰� �� ������ 
			return -1; // �����ΰ�
		}
		else { // ���̰� ������
			if(o1.height > o2.height) { // ���� Ű���� ũ��
				return 1; // �ڷΰ�
			}
			else if(o1.height < o2.height) {
				return -1;
			}
			else {
				return o1.name.compareTo(o2.name); // ������ũ�� 1, ������������ -1, ������ 0
			}
		}
	}
}