package groups;

import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;
import java.util.function.BiConsumer;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class GruppoAcquisto {
	
	private String name;
	private Prodotto prodotto;	
	private List<String> clienti = new LinkedList<>();
	private HashMap<String,Fornitore> fornitoriProdottoOfferta = new HashMap<>();
	private TreeMap<String,Integer> offerte = new TreeMap<>();
	private Map<String,String> voti = new HashMap<>();
	
	public List<String> fornitoriConOfferte(){
		return offerte.keySet().stream().collect(java.util.stream.Collectors.toList());
	}

	public GruppoAcquisto(String name, Prodotto prodotto) {
		this.name = name;
		this.prodotto = prodotto;
	}
	
	public List<String> getFornitori(){
		return fornitoriProdottoOfferta.keySet().stream().collect(java.util.stream.Collectors.toList());
	}
	
	public int getNumeroClienti(){
		return clienti.size();
	}
	
	public String getName() {
		return name;
	}

	public Prodotto getProdotto() {
		return prodotto;
	}
	
	public void addClienti(String cliente) {
		clienti.add(cliente);
	}
	
	public boolean contieneCliente(String name){
		return clienti.contains(name);
	}

	public void addFornitore(Fornitore fornitore) {
		fornitoriProdottoOfferta.put(fornitore.getName(), fornitore);
	}

	public void aggiungiOfferta(String supplierName, int price) throws GroupHandlingException {
		if (!fornitoriProdottoOfferta.containsKey(supplierName))
			throw new GroupHandlingException();
		
		offerte.put(supplierName, price);
		
	}
	
	public String offerteString(){
		Stream<Integer> ris = offerte.values().stream().sorted((a,b) -> {
			if (((Integer)a) > ((Integer)b))
				return 1;
			if (((Integer)b) > ((Integer)a))
				return -1;
			
			return 0;
		});
		
		Iterator<Integer> valoriOfferte = ris.iterator();
		
		StringBuffer risultato = new StringBuffer();
		
		Integer val;
		
		for (;valoriOfferte.hasNext();){
			
			Integer prossimo = valoriOfferte.next();
			
			// per ogniuno aggiungi nome:valore alla stringa
			offerte.forEach(new BiConsumer<String, Integer>() {

				@Override
				public void accept(String arg0, Integer arg1) {
					if (arg1 == prossimo){
						risultato.append(arg0).append(":").append(String.valueOf(arg1)).append(",");					}
				}
			});
		}
		
		
		return risultato.toString().substring(0,(risultato.toString().length() - 1));
		
		
	}

	public void vota(String customerName, String supplierName) throws GroupHandlingException {
		if (!clienti.contains(customerName) || !offerte.containsKey(supplierName))
			throw new GroupHandlingException();
		
		voti.put(customerName, supplierName); // fornitore -- cliente
	}

	public String getVoti() {
		Collection<String> fornitori = voti.values().stream().distinct().sorted().collect(java.util.stream.Collectors.toList());
		String ris = "";
		
		Iterator it = fornitori.iterator();
		
		for (;it.hasNext();){
			
			Object prossimo = it.next();
			long risultato_voti = voti.entrySet().stream()
					.filter(map -> map.getValue().equals(prossimo)).count();
			
			ris += prossimo + ":" + Integer.valueOf(String.valueOf(risultato_voti)) + ",";
		}
		
		return ris.substring(0,ris.length() - 1);
	}
	
	public TreeMap<String, Integer> massimaOfferta(){
		Integer val;
		
		Optional<Integer> intV = offerte.values().stream()
				.max((a,b) -> {
					return a.intValue()-b.intValue();
				});
		
		if (intV.isPresent()){
			TreeMap<String,Integer> m = new TreeMap<>();
			m.put(prodotto.getName(), intV.get());
			return m;
		}
		
		return null;
	}

	public String getVincitore() {
		
		if (offerte.size() == 0)
			return null;
		
		Collection<String> fornitori = voti.values().stream().sorted().distinct().collect(java.util.stream.Collectors.toList());
		String ris = "";
		
		Iterator it = fornitori.iterator();
		long max = 0l;
		List<String> vincitori_parziali = new LinkedList<>();
		
		for (;it.hasNext();){
			
			String prossimo = (String) it.next();
			
			long risultato_voti = voti.entrySet().stream()
					.filter(map -> map.getValue().equals(prossimo)).count();
			
			if (risultato_voti == max){
				vincitori_parziali.add(prossimo);
			}
			
			if (risultato_voti > max){
				max = risultato_voti;
				vincitori_parziali = new LinkedList<>();
				vincitori_parziali.add(prossimo);
			}
		}
		
		String vincitore = null;
		int prezzo_min = 1000000;
		
		for (String vinc : vincitori_parziali){
			if (prezzo_min >= offerte.get(vinc).intValue()){
				prezzo_min = offerte.get(vinc);
				vincitore = vinc;
			}
		}
		
		return vincitore + ":" + Integer.valueOf(String.valueOf(max));
	}
	
	public Map<String, Integer> numero_offerte_fornitori(){
		return offerte;
		//fornitoriProdottoOfferta.values().stream();
	}

}
