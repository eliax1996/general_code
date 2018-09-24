package observable;

import java.util.Observable;
import java.util.Observer;

public class Osservato extends Observable {
	
	private int valore_intero;
	
	public Osservato(Observer osservatore){
		this.addObserver(osservatore);
	}
	
	public void modificaValori(int val){
		this.valore_intero = val;
		setChanged();
		notifyObservers("buonasssera mentana");
		
	}

}
