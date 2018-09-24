package observable;

public class Esempio {

	public static void main(String[] args) {
		Osservatore osservatore = new Osservatore();
		Osservato osservato = new Osservato(osservatore);
		
		osservato.modificaValori(2);
	}

}
