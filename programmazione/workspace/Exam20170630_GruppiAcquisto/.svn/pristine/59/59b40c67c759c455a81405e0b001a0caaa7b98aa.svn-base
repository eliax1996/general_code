package groups;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.function.BiConsumer;
import java.util.Set;
import java.util.SortedMap;
import java.util.TreeMap;
import java.util.stream.Stream;


public class GroupHandling {
	
	private HashMap<String,Prodotto> prodotti = new HashMap<>();
	private HashMap<String,Fornitore> fornitori = new HashMap<>();
	private HashMap<String,GruppoAcquisto> gruppi = new HashMap<>();
	
//R1	
	public void addProduct (String productTypeName, String... supplierNames) 
			throws GroupHandlingException {
		if (prodotti.containsKey(productTypeName))
			throw new GroupHandlingException();
		
		prodotti.put(productTypeName, new Prodotto(productTypeName)); //TODO METTERE I PARAMETRI AL PRODOTTO
		
		Fornitore forn = null;
		
		for(String fornitore: supplierNames){
			if (!fornitori.containsKey(fornitore)){
				forn = new Fornitore(fornitore);
				fornitori.put(fornitore, new Fornitore(fornitore));
			}
			
			forn = fornitori.get(fornitore);
			
			fornitori.get(fornitore).addProdotto(prodotti.get(productTypeName));
			prodotti.get(productTypeName).addFornitore(forn);
		}
	}
	
	public List<String> getProductTypes (String supplierName) {
		return fornitori.get(supplierName).prodottiFornitoreString();
	}
	
//R2	
	public void addGroup (String name, String productName, String... customerNames) 
			throws GroupHandlingException {
		if (!prodotti.containsKey(productName) || gruppi.containsKey(name))
			throw new GroupHandlingException();
		
		GruppoAcquisto ac = new GruppoAcquisto(name,prodotti.get(productName));
		
		for (String cliente : customerNames){
			ac.addClienti(cliente);
		}
		
		gruppi.put(name, ac);
	}
	
	public List<String> getGroups (String customerName) {
		List<String> clienti = new LinkedList<>();
		
		Set<String> keys = gruppi.keySet();
		List<String> nomeGruppi = new LinkedList<>();
		
		for (String key : keys){
			if (gruppi.get(key).contieneCliente(customerName)){
				nomeGruppi.add(key);
			}
		}
		
		nomeGruppi.sort((a,b) -> ((String)a).compareTo(((String)b)));
		
		return nomeGruppi;
		
	}

//R3
	public void setSuppliers (String groupName, String... supplierNames)
			throws GroupHandlingException {
		
		for (String fornitore: supplierNames){			
			if (!fornitori.containsKey(fornitore) ||
					!fornitori.get(fornitore).trattaProdotto(gruppi.get(groupName).getProdotto().getName()))
				throw new GroupHandlingException();
			
			gruppi.get(groupName).addFornitore(fornitori.get(fornitore));
			
		}
		
	}
	
	public void addBid (String groupName, String supplierName, int price)
			throws GroupHandlingException {
		
		gruppi.get(groupName).aggiungiOfferta(supplierName,price);
		
		
	}
	
	public String getBids (String groupName) {
		return gruppi.get(groupName).offerteString();
	}
	
	
//R4	
	public void vote (String groupName, String customerName, String supplierName)
			throws GroupHandlingException {
		gruppi.get(groupName).vota(customerName,supplierName);
	}
	
	public String  getVotes (String groupName) {
        return gruppi.get(groupName).getVoti();
	}
	
	public String getWinningBid (String groupName) {
        return gruppi.get(groupName).getVincitore();
	}
	
//R5
	public SortedMap<String, Integer> maxPricePerProductType() { //serve toMap
        Set<String> nomi_gruppi = gruppi.keySet();
        
        SortedMap<String,Integer> mappa = new TreeMap<>();
        
        for (String g : nomi_gruppi){
        	try {
        		if (gruppi.get(g).massimaOfferta() == null){
        			continue;
        		}
        	} catch(Exception e) {
        		continue;
        	}
        	TreeMap<String, Integer> val = gruppi.get(g).massimaOfferta();
        	mappa.put(val.firstKey(),val.get(val.firstKey()));
        }
        
		return mappa;
	}
	
	public SortedMap<Integer, List<String>> suppliersPerNumberOfBids() {
		List<String> forn = fornitori.keySet().stream().sorted().collect(java.util.stream.Collectors.toList());
        
        Iterator<String> it = forn.iterator();
        
        SortedMap<Integer,List<String>> fornitori = new TreeMap<>(Collections.reverseOrder());
        
        for (;it.hasNext();){
        	
        	String fornitore = it.next();
        	
        	long numero = gruppi.entrySet().stream()
        			.filter(map -> map.getValue().fornitoriConOfferte()
        			.contains(fornitore)).count();
        	
        	if (numero > 0){
        	
	        	long somma = gruppi.entrySet().stream()
	        			.filter(map -> map.getValue().getFornitori().contains(fornitore))
	        			.count();
	        	
	        	if (((int)(somma)) > 0) {
		        	if (fornitori.containsKey(((int)somma))){
		        		fornitori.get(((int)somma)).add(fornitore);
		        	} else {
		        		List<String> lista = new LinkedList<>();
		        		lista.add(fornitore);
		        		fornitori.put(((int)somma),lista);
		        	}
	        	}
	        	
        	} else {
        		
        		it.remove();
        		
        	}
        	
        }
        
		return fornitori;
	}
	
	public SortedMap<String, Long> numberOfCustomersPerProductType() {
        List<String> prod = prodotti.keySet().stream().sorted().collect(java.util.stream.Collectors.toList());
        
        Iterator<String> it = prod.iterator();
        
        SortedMap<String,Long> prodotti = new TreeMap<>();
        
        for (;it.hasNext();){
        	
        	String prodotto = it.next();
        	
        	int somma = gruppi.entrySet().stream()
        			.filter(map -> map.getValue().getProdotto()
        					.getName().equals(prodotto))
        			.mapToInt(map -> map.getValue().getNumeroClienti())
        			.sum();
        	
        	prodotti.put(prodotto, Long.valueOf(somma));
        	
        }
        
		return prodotti;
	}
	
}
