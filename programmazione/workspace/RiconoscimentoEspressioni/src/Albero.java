
public class Albero {
	
	private Albero sinistro;
	private Albero destro;
	private String value;
	
	
	public String getValue() {
		return value;
	}
	
	public void setValue(String value) {
		this.value = value;
	}
	
	public void setSinistro(Albero sinistro){
		this.sinistro = sinistro;
	}
	
	public void setDestro(Albero destro){
		this.destro = destro;
	}

}
