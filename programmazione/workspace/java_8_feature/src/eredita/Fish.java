package eredita;

public class Fish extends Animal {
	
	public Fish(){
		super("sono un pesce!");
	}
	
	@Override
	public void ruggisci(){
		System.out.println("splash");
	}

}
