package university;

import java.util.Collection;
import java.util.LinkedList;

public class Course {
	
	private String title;
	private Collection<Student> students;
	private String code;

	public Course(String code, String t){
		this.title = t;
		this.code = code;
		students = new LinkedList<>();
	}
	
	public String getTitle() { return title; }
	
	public void enroll(Student s){
		students.add(s);
		s.enrollIn(this);
	}

	public String toString(){
		return code + " : " + title;
	}

}
