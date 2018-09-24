package raggruppamenti_java;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class MainClass {

	public static void main(String[] args) {

		List<Person> persons =
		    Arrays.asList(
		        new Person("Max", 18),
		        new Person("Peter", 23),
		        new Person("Pamela", 23),
		        new Person("David", 12));

		
		Map<Integer, List<Person>> personsByAge = persons
			    .stream()
			    .collect(Collectors.groupingBy(p -> p.age));

			personsByAge
			    .forEach((age, p) -> System.out.format("age %s: %s\n", age, p));
			
		System.out.println("la media dell'età è: " + 
					persons.stream()
						.mapToInt(s -> s.age)
						.average().getAsDouble());
		
		System.out.println("la somma dell'età è: " + 
				persons.stream()
					.mapToInt(s -> s.age)
					.reduce(0, (a,b) -> a+b));
	}

}
