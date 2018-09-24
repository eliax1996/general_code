package groups;

import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

public class Fornitore {
	
	private HashMap<String,Prodotto> prodottiFornitore = new HashMap<>();
	private String name;

	public Fornitore(String fornitore) {
		this.name = fornitore;
	}
	
	public String getName() {
		return name;
	}

	public void addProdotto(Prodotto prodotto) {
		prodottiFornitore.put(prodotto.getName(), prodotto);
	}
	
	public boolean trattaProdotto(String name){
		return prodottiFornitore.containsKey(name);
	}
	
	public List<Prodotto> prodottiFornitore(){
		return prodottiFornitore.values().stream()
				.sorted((a,b) -> {
					return ((Prodotto)a).getName().compareTo(((Prodotto)b).getName());
				}).collect(Collectors.toList());
	}
	
	public List<String> prodottiFornitoreString(){
		return prodottiFornitore.values().stream()
				.sorted((a,b) -> {
					return ((Prodotto)a).getName().compareTo(((Prodotto)b).getName());
				}).map(p -> p.getName()).collect(Collectors.toList());
	}

}
