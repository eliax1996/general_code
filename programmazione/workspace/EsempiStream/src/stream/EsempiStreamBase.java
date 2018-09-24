package stream;

import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import static java.util.Comparator.*;

public class EsempiStreamBase {

	public static void main(String[] args){
		
		String[] parole = Quotations.RING_VERSE.split("[ \n.,-]+");
		
		for(String w : parole){
			System.out.println(w);
		}

		for(String w : parole){ System.out.println(w); }

		Arrays.asList(parole).forEach(System.out::println);
		
		Arrays.stream(parole).forEach(System.out::println);
		
		// FILTRAGGIO
		
		System.out.println("\n------\nfilter():\n");
		
		Arrays.stream(parole).
				filter( w -> w.length() == 5 ).
				forEach(System.out::println);

		
		System.out.println("\n------\nlimit():\n");
		
		Arrays.stream(parole).
				limit( 3 ).
				forEach(System.out::println);

		System.out.println("\n------\nfilter() + limit():\n");
		
		Arrays.stream(parole).
				filter( w -> w.length() > 3 ).
				limit( 3 ).
				forEach(System.out::println);

		// ATTENZIONE: l'ordine è importante!
		Arrays.stream(parole).
				limit( 3 ).
				filter( w -> w.length() > 3 ).
				forEach(System.out::println);
		
		int n = 0;
		for(String w:parole){
			if(w.length() > 3){
//				++n;
//				if(n<=3){
//					System.out.println(w);
//				}
				
				System.out.println(w);
				if(++n == 3) break;
			}
		}
		
		System.out.println("\n------\nskip():\n");
		
		Arrays.stream(parole).				// Source
				skip( 20 ) .					// Intermediate operation
				limit( 3 ).					// Intermediate operation
				forEach(System.out::println);// Terminal operation

		System.out.println("\n------\nsorted():\n");
		
		Arrays.stream(parole).
				sorted().
				forEach(System.out::println);
		
		System.out.println("\n------\nsorted() + distinct():\n");
		
		Arrays.stream(parole).
				sorted().
				distinct().
				forEach(System.out::println);


		System.out.println("\n------\nsorted() w/comparator:\n");
		
		Arrays.stream(parole).
				sorted( (w,y) -> w.length() - y.length() ).
				distinct().
				forEach(System.out::println);
		
		System.out.println("\n------\nversione convenzionale\n");
		// sorted()
		String[] paroleCopy = parole.clone();
		Arrays.sort(paroleCopy, (w,y) -> w.length() - y.length() );
		// distinct()
		Set<String> paroleOrdinate = new LinkedHashSet<>();
		for(String w : paroleCopy){
			paroleOrdinate.add(w);
		}
		// sorted() + distinct()  NON FUNZIONA!!!!
//		//Set<String> paroleOrdinate = new TreeSet<>((w,y) -> w.length() - y.length() );
//		Set<String> paroleOrdinate = new TreeSet<>( );
//		for(String w : parole){
//			paroleOrdinate.add(w);
//		}
		//forEach()
		paroleOrdinate.forEach(System.out::println);

		System.out.println("\n------\nsorted() + map():\n");

		Arrays.stream(parole).
			map( w -> w.toLowerCase()).
			sorted(  ).
			distinct().
			forEach(System.out::println);

		System.out.println("\n------\nsorted() w/comparator:\n");
		
		Arrays.stream(parole).
//				sorted( (w,y) -> w.length() - y.length() ).
//				sorted( Comparator.comparing( w -> w.length()) ).
//				sorted( Comparator.comparing( String::length ) ).
//				sorted( Comparator.comparingInt( String::length ) ).
				sorted( comparingInt( String::length ) ).
				distinct().
				forEach(System.out::println);

		System.out.println("\n------\nsorted() w/comparator - primi 3:\n");
		
		Comparator<String> natural = naturalOrder();
		Arrays.stream(parole).
				distinct().
				sorted( comparingInt( String::length ).
									reversed().
									//thenComparing( (s1,s2) -> s1.compareTo(s2))
									//thenComparing(naturalOrder().reversed())
									//thenComparing(natural.reversed())
									thenComparing(reverseOrder())
									
						).
				limit(3).
				forEach(System.out::println);

		System.out.println("\n------\nmap() tipi diversi:\n");
		
		System.out.println(Arrays.stream(parole).
				mapToInt( w -> w.length()).
				average().getAsDouble());

		
		System.out.println("\n------\nflatMap() :\n");
		
		Arrays.stream(parole).   // Stream<String>
		map( w -> {
			LinkedList<Character> res = new LinkedList<>();
			for(int i=0; i<w.length(); ++i){
				res.add(w.charAt(i));
			}
			return res;
		}). // Stream<LinkedList<Character>>
		//flatMap( l -> l.stream() ).
		flatMap( List::stream ).
		distinct().
		sorted().
		forEach(System.out :: println);

		System.out.println("\n------\nflatMap() String::chars :\n");
		
		Arrays.stream(parole).   // Stream<String>
		flatMapToInt( String:: chars ).
		distinct().
		sorted(). 
		mapToObj( i -> new Character((char)i) ).
		forEach(System.out :: println);


		
		Arrays.stream(parole).   // Stream<String>
		parallel().
		flatMapToInt( String:: chars ).
		distinct().
		sorted(). 
		mapToObj( i -> new Character((char)i) ).
		forEach(System.out :: println);
		
		System.out.println("\n------\nmax()  :\n");

		Arrays.stream(parole).   // Stream<String>
		    filter( w -> w.length() > 99).
			max( naturalOrder() ).
			ifPresent(System.out :: println);

		String piuLunga = 
		Arrays.stream(parole).   // Stream<String>
			filter( w -> w.length() > 99).
			max( comparing(String::length) ).
			orElse("-- nessuna parola trovata --");
		System.out.println(piuLunga);
			
			
		System.out.println("\n------\nterminale()  :\n");

//			int counter=0;
//			Arrays.stream(parole).   // Stream<String>
//				forEach( w -> {
//					counter++;
//				});
			
		long numero = Arrays.stream(parole).count();
		System.out.println(numero);
}
}
