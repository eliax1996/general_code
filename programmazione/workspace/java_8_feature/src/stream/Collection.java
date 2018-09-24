package stream;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;

public class Collection {
	
	public static void main(String[] args) {
		java.util.Collection<String> collection = new ArrayList<>();
		
		collection.add("ciao");
		collection.add("aaa");
		collection.add("bbb");
		collection.add("elia");
		collection.add("zzz");
		collection.add("elia");
		
		Collections.sort((List<String>) collection,(a,b) -> ((String)a).compareTo((String)b));
		collection.stream().forEach(System.out::println);
		System.out.println("il massimo e' " + Collections.max(collection,(a,b) -> ((String)a).compareTo((String)b)));
		
		
		
		HashSet<String> set = new HashSet<>();
		
		set.add("ciao");
		set.add("mondo");
		set.add("mondo"); // un set non ha elementi ripetuti
		set.add("alessandro");
		
		set.stream().forEach(a -> System.out.println(a));
		
		// ordinato
		
		System.out.println("\nora stampo ordinato:");
		set.stream().sorted().forEach(a -> System.out.println(a));
		
		LinkedHashSet<Integer> hashIterabile = new LinkedHashSet<Integer>();
		hashIterabile.add(new Integer(2));
		hashIterabile.add(new Integer(8));
		hashIterabile.add(new Integer(3));
		hashIterabile.add(new Integer(7));
		
		Iterator<Integer> iteratore = hashIterabile.iterator();
		Integer i = null;
		for (;iteratore.hasNext();){
			i = iteratore.next();
			if (i == 7) // rimuovo il 7
				iteratore.remove();
			System.out.println(i);
		}
		
		System.out.println("numero di elementi ora: " + hashIterabile.size());
	}
}
