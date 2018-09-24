package eredita;

public class Esempio {

	public static void main(String[] args) {
		
		Fish fish = new Fish();
		Animal animal = new Animal();
		Plant plant = new Plant();
		
		fish.ruggisci();
		animal.ruggisci();
		
		// downcast
		
		Animal pesce = (Animal) fish;
		
		pesce.ruggisci(); // anche se è ritornato ad essere di tipo animale
		// i metodi con override rimangono gli stessi
		
		if (fish instanceof Animal)
			System.out.println("il pesce e' una specificazione di animale");
			
		
		// error upcast
		
		//Animal pianta = (Animal) plant;
		
		// vettore di 10 elementi pesci
		Animal[] pesci = new Animal[2];
		
		// un puntatore di elementi generici può puntare a elementi specifici
		pesci[0] = new Animal();
		pesci[1] = new Fish();
		
		Fish[] animali = new Fish[2];
		
		// non è vero il contrario
		//animali[0] = new Animal(); errore
		animali[1] = new Fish();
		
		/*
		insiemisticamente parlando un pesce ha tutte le proprietà di un
		animale ma un animale non tutte quelle di un pesce quindi un puntatore
		di animale soddisfa i requisiti per un animale ma anche un puntatore di pesce
		
		
		mentre un puntatore di pesce non può essere soddisfatto da un puntatore di 
		animale generico; mancano delle proprietà (es non nuota)
		 */
		
		// soluzione brutta ma funzionale:
		
		System.out.println("\n\n\n esempio object \n\n\n");
		
		Object[] oggetti = new Object[3];
		
		oggetti[0] = fish;
		oggetti[1] = animal;
		oggetti[2] = plant;
		
		for (int x = 0; x < 3; x++){
			System.out.print("l'elemento numero " + x + " è ");
			
			if (oggetti[x] instanceof Fish){
				System.out.println("un pesce");
			} else if (oggetti[x] instanceof Animal){
				System.out.println("un animale generico");
			} else {
				System.out.println("una pianta");
			}
		}
		
		
	}

}
