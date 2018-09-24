package iterable;

import java.util.Arrays;
import java.util.Comparator;

public class Esempio {

	public static void main(String[] args) {
		Studente[] studenti = new Studente[5];
		
		for (int x = 0; x < 5; x++)
			studenti[x] = new Studente(6-x);
		
		System.out.println("stampa array non ordintato");
		
		for (int x = 0; x < 5; x++)
			System.out.println(studenti[x].getVoto());
		
		// posso ordinarlo con Array.sort perchè studente implementa comparable 
		Arrays.sort(studenti);
		// oppure se non è comparable
		Arrays.sort(studenti, (a,b)->{return ((Studente)a).getVoto() - ((Studente)b).getVoto();});
		// se ha una sola riga di codice:
		// Arrays.sort(studenti, (a,b) -> ((Studente)a).getVoto() - ((Studente)b).getVoto() );
		
		Arrays.sort(studenti, Comparator.comparing(Studente::getVoto));
		
		
		System.out.println("\n\nstampa array ordinato");
		
		for (Studente stud : studenti)
			System.out.println(stud.getVoto());
		
		}
	
}
