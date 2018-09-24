package university;

import static university.Student.*;

import java.util.Collection;
import java.util.Comparator;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.BiConsumer;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.stream.Stream;

import static java.util.stream.Collectors.*;
import static java.util.Comparator.*; 

public class Examples {

	public static void main(String[] args) {
		Collection<Student> students = new LinkedList<>();
		// Setup a sample of data structures
		students.add(new Student(100,"John","Smith",Gender.MALE));
		students.add(new Student(101,"Mary","Johnson",Gender.FEMALE));
		students.add(new Student(201,"Andrea","Rossi",Gender.MALE));
		students.add(new Student(202,"Giulia","Ferrari",Gender.FEMALE));
		students.add(new Student(301,"Wei","Wang",Gender.MALE));
		students.add(new Student(302,"Fang","Li",Gender.FEMALE));
		students.add(new Student(401,"Maria","Rossi",Gender.FEMALE));


		Course c1 = new Course("02JEY","Object-Oriented Programming");
		Course c2 = new Course("02LAS","Databases");
		Course c3 = new Course("02HGK","Computer Networks");
		Course c4 = new Course("01QZN","Visualization of Quantitative Information");


		students.stream().forEach(c1::enroll);  // iscrive tutti gli studenti a OOP
		students.stream().limit(3).forEach( c2::enroll); // 100, 101, 201
		students.stream().skip(2).limit(3).forEach( c3::enroll); // 201, 202, 301

		// retrieve all the female students
		
		Predicate<Student> isFemale = s -> s.isFemale();
		students.stream().filter( isFemale ).forEach(System.out::println);
		// OPPURE
		students.stream().filter( s -> s.isFemale() ).forEach(System.out::println);
		// OPPURE		
		students.stream().filter( Student::isFemale ).forEach(System.out::println);
		
		

		// retrieve all students whose first name is "John"
		
		students.stream()
				.filter( s -> s.getFirst().equals("John") )
				.forEach(System.out::println);

		students.stream()
				.filter( s -> s.matchFirst("John") )
					.forEach(System.out::println);
		
		
		
		
		// retrieve the collection of (unique) last names of students
		
		Collection<String> lastNames =
				students.stream()
				.map( Student::getLast )
//				.distinct()
//				.collect(toList());
				.collect(toCollection(TreeSet::new));
//				.collect(toCollection(HashSet::new));
//				.collect(toCollection(
//						() -> new TreeSet(comparing(String::length))));

		lastNames.forEach(System.out::println);
		
		
	
		// retrieve the student with the longest first names of students
		
		// Soluzione approssimativa
		students.stream()
			.map(Student::getLast)
			.max(comparing(String::length))
			.ifPresent(System.out::println);
		
		// Soluzione corretta
		int max = students.stream()
				.map(Student::getLast)
				.mapToInt(String::length)
				.max().orElse(-1);
	
		students.stream()
			.filter(s -> s.getLast().length()==max)
			.forEach(System.out::println);
		
		SortedMap<Integer,List<Student>> perLunghezza =
				students.stream()
				.collect(groupingBy(s->s.getLast().length(),
						 //TreeMap::new,
						 ()-> new TreeMap<Integer,List<Student>>(reverseOrder()),
						 toList()
						));	
		perLunghezza.get(perLunghezza.firstKey()).forEach(System.out::println);
		
		perLunghezza.get(perLunghezza.keySet().iterator().next()).forEach(System.out::println);
		
		perLunghezza.values().iterator().next().forEach(System.out::println);
		
		
		// retrieve the students that are enrolled to 2 or more courses
		
		students.stream()
		.filter( s -> s.enrolledIn().size()>=2 )
		.forEach(System.out::println);
		
		// find how many students  are enrolled to 2 or more courses
		
		long nGE2 = 
		students.stream()
		.filter( s -> s.enrolledIn().size()>=2 )
		.count()
		// OPPURE
		//.collect(counting())
		// OPPURE
//		.mapToInt( s-> 1)
//		.reduce(0, (a,i) -> a+i)
		;
		System.out.println("Studenti con 2 o + corsi: " +nGE2);
		
		
		
		// get all the courses having at least one enrolled student
		
		students.stream()
//		.map( Student::enrolledIn ) // -> Stream<Collection<Course>>
//		.flatMap(Collection::stream) // -> Stream<Course>
		// OPPURE
		.flatMap( s -> s.enrolledIn().stream() )
		.distinct()
		.forEach(System.out::println);
		
		
			
		
		// get the names of the courses having at least one enrolled student
		
		
		
		students.stream()
//		.map( Student::enrolledIn ) // -> Stream<Collection<Course>>
//		.flatMap(Collection::stream) // -> Stream<Course>
		// OPPURE
		.flatMap( s -> s.enrolledIn().stream() )
		.distinct()
		.map(Course::getTitle)
		.forEach(System.out::println);
		
	
		
		// get the maximum length of students last names
		
		// get a string with the list of sorted first names of all male students separated by ";" 
		
		// group students by gender
		
		Map<Student.Gender,List<Student>> byGender =
				students.stream()
				.collect(groupingBy(Student::getGender,toList()));
		System.out.println(byGender);
		
		// find number of students by gender
		Map<Student.Gender,Long> numByGender =
				students.stream()
				.collect(groupingBy(Student::getGender,counting()));
		System.out.println(numByGender);

		
		// group students by number of attending courses
		
		Map<Integer,List<Student>> byNumCourses =
				students.stream()
				.collect(groupingBy(s->s.enrolledIn().size()));
		System.out.println(byNumCourses);
		
		
		// ranking of students by num attended courses
		
		SortedMap<Integer,List<Student>> byNumCoursesSorted = 
		students.stream()
		.collect(groupingBy(s->s.enrolledIn().size(),
				() -> new TreeMap<Integer,List<Student>>(reverseOrder()),
				toList()
				));

		for(Integer k : byNumCoursesSorted.keySet()){
			List<Student> l = byNumCoursesSorted.get(k);
			for(Student s : l){
				System.out.println(k + " : " + s);
			}
		}
		
		students.stream()
		.collect(groupingBy(s->s.enrolledIn().size(),
				() -> new TreeMap<Integer,List<Student>>(reverseOrder()),
				toList()
				))
		.entrySet().stream()
		.flatMap(e -> e.getValue().stream()
							.map( s -> e.getKey() + " : " + s)
				)
		.forEach(System.out::println);
		
		/*
Stampare la classifica con le relative posizioni

pos 1:(201) Rossi, Andrea
pos 2:(100) Smith, John
pos 2:(101) Johnson, Mary
pos 2:(202) Ferrari, Giulia
pos 2:(301) Wang, Wei
pos 6:(302) Li, Fang
pos 6:(401) Rossi, Maria
		 */
		
		// printing
		int[] pos = {1};
		students.stream()
		.collect(groupingBy(s->s.enrolledIn().size(),
				() -> new TreeMap<Integer,List<Student>>(reverseOrder()),
				toList()
				))
		.entrySet().stream()
		.flatMap(e -> {
					int p = pos[0];
					pos[0]+=e.getValue().size();
					return e.getValue().stream()
					.map( s -> "pos " + p + ": " +
							   e.getKey() + " courses : "
								+ s);
				})
		.forEach(System.out::println);

		// collecting into map
		pos[0] = 1;
		SortedMap<Integer,List<Student>> ranking = 
		students.stream()
		// group by ranking parameter
		.collect(groupingBy(s->s.enrolledIn().size(),
				() -> new TreeMap<Integer,List<Student>>(reverseOrder()),
				toList()
				))
		.entrySet().stream()
		// map entries to ranking entries (key = position)
		.map(e -> {
			int p = pos[0];
			pos[0]+=e.getValue().size();
			Map.Entry<Integer,List<Student>> re = 
			new Map.Entry<Integer,List<Student>>() {
				public Integer getKey() { return p; }
				public List<Student> getValue() { return e.getValue(); }
				public List<Student> setValue(List<Student> value) { return null; }
			};
			return re;
		})
		// collect entries into map
		.collect(
				//TreeMap::new,
				() -> new TreeMap<Integer,List<Student>>(){
					public String toString(){
						return this.entrySet().stream()
						.flatMap(e -> e.getValue().stream()
								.map(s -> e.getKey() + ") " + s ))
						.collect(joining("\n"))
						;
					}
				},
				( m, re ) -> m.put(re.getKey(),re.getValue()),
				( m, n ) -> m.putAll(n)
				);
		
		System.out.println(ranking);
		
		System.out.println(ranking(students.stream(),(Student s)->s.enrolledIn().size(),reverseOrder()));
	}

	public static <T,K extends Comparable<? super K>> 
	SortedMap<Integer,List<T>> ranking(Stream<T> stream,
									  Function<? super T,K> propGet
									  ){
		return ranking(stream,propGet,naturalOrder());
	}

	public static <T,K> 
	SortedMap<Integer,List<T>> ranking(Stream<T> stream,
									  Function<? super T,K> propGet,
									  Comparator<K> comparator
									  ){
		int[] pos = {1}; 
		return stream
		// group by ranking parameter
		.collect(groupingBy(propGet,
				() -> new TreeMap<K,List<T>>(comparator),
				toList()
				))
		.entrySet().stream()
		// map entries grouped by property to ranking entries (key = position)
		.map(e -> {
			int p = pos[0];
			pos[0]+=e.getValue().size();
			Map.Entry<Integer,List<T>> re = 
			new Map.Entry<Integer,List<T>>() {
				public Integer getKey() { return p; }
				public List<T> getValue() { return e.getValue(); }
				public List<T> setValue(List<T> value) { return null; }
			};
			return re;
		})
		// collect entries into map
		.collect(
				() -> new TreeMap<Integer,List<T>>(){
					public String toString(){
						return this.entrySet().stream()
						.flatMap(e -> e.getValue().stream()
								.map(s -> e.getKey() + ") " + s ))
						.collect(joining("\n"))
						;
					}
				},
				( m, re ) -> m.put(re.getKey(),re.getValue()),
				( m, n ) -> m.putAll(n)
				);
	}
}
