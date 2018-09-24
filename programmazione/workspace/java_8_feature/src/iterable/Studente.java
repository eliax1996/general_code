package iterable;

public class Studente implements Comparable<Studente> {
	
	private int voto;
	
	public Studente(int voto){
		this.setVoto(voto);
	}
	
	
	public int getVoto() {
		return voto;
	}
	
	public void setVoto(int voto) {
		this.voto = voto;
	}
	

	@Override
	public int compareTo(Studente o) {
		return voto - o.getVoto();
	}

}
