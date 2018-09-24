

public class Venditore implements Comparable<Venditore>{
	
	private int eta;
	private String nome;
	
	public Venditore(String nome, int eta) {
		this.nome=nome;
		this.eta=eta;
	}
	
	public int getEta() {
		return eta;
	}
	
	public String getNome() {
		return nome;
	}

	@Override
	public int compareTo(Venditore o) {
		return this.getNome().compareTo(this.getNome());
	}

}
