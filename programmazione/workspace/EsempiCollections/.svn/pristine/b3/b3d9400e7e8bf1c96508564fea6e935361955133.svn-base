
public class EsEccezioniNumeri {

	public static void main(String[] args) {
		
		String s = "la risposta";
		int i;
		try{
			i = Integer.parseInt(s);
			System.out.println("i= " + i);
		}catch(NumberFormatException nfe){
			System.out.println("Formato numerico non valido..");
			i = 0;
		}
		
		
		String[] numeri = {"1","3","5","sette","9"};
		for(String n : numeri){
			try{
				int x = Integer.parseInt(n);
				System.out.println(x);
			}catch(NumberFormatException nfe){
				System.out.println("formato non valido");
			}
		}

		
		int totale = 0;
		try{
			for(String n : numeri){
				int x = Integer.parseInt(n);
				totale += x;
			}
			System.out.println("Totale= " + totale);
		}catch(NumberFormatException nfe){
			System.out.println("Trovato un errore nei numeri");
		}

	}

}
