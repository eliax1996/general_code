import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.TreeSet;

public class EsCollezioni {

	public static void main(String[] args) {
		
		Collection<String> c;
		
		//c = new LinkedList<>();
		c = new TreeSet<>();
		
		c.add("Primo");
		c.add("Secondo");
		c.add("Il Terzo");
		
		for(String s : c){
			System.out.println(s);
		}
		
		List<String> l = new LinkedList<>();
		
		l.add("Primo");
		l.add("Secondo");
		l.add("Il Terzo");
		
		l.add(1,"Primo e mezzo");

		for(String s : l){
			System.out.println(s);
		}
		
		l.add(4,"Ventunesimo");
		
		System.out.println("Secondo elemento:" + l.get(1));

		// ------ MAP
		
		Map<String,String> dizionario = new HashMap<>();
		
		dizionario.put("rosso", "red");
		dizionario.put("verde", "green");
		dizionario.put("blu", "blu");
		dizionario.put("bianco", "white");
		
		System.out.println("Inglese per verde " 
							+ dizionario.get("verde"));

		System.out.println("Italiano per green " 
				+ dizionario.get("green"));  // NON FUNZIONA
		
		String k = "black";
		
		if( dizionario.get(k)==null ){
			System.out.println(k + " non presente");
		}
		
		if( dizionario.containsKey(k) ){
			System.out.println(k + " non presente");
		}

	}

}
