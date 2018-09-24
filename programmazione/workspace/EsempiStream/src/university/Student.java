package university;

import java.util.Collection;
import java.util.LinkedList;

public class Student {
	private int id;
	private String name;
	private String surname;
	
	public static enum Gender { FEMALE, MALE };
	private Gender gender;
	
	private Collection<Course> courses;
	
	Student(int id, String n, String s) {
		  this.id = id;
		  this.name = n;
		  this.surname = s;
		  gender = Gender.MALE;
		  courses = new LinkedList<Course>();
	  }

		Student(int id, String n, String s, Gender g) {
		  this.id = id;
		  this.name = n;
		  this.surname = s;
		  gender = g;
		  courses = new LinkedList<Course>();
	  }
	

	  String getFirst() { return name; }
	  String getLast() { return surname; }
	  
	  boolean isFemale() { return gender==Gender.FEMALE; }
	  boolean isMale() { return gender==Gender.MALE; }
	  
	  Gender getGender() { return gender; }
	  

	  public boolean matchFirst(String first){
		  return name.equals(first);
	  }
	  
	  Collection<Course> enrolledIn() { 
		  return courses;
	  }

	  void enrollIn(Course c){
		  courses.add(c);
	  }
	  
	  public String toString(){
		  return "(" + id + ") " + surname + ", " + name;
	  }

}
