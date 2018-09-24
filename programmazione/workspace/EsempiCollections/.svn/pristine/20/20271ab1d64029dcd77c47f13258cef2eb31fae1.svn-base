import java.util.ArrayList;
import java.util.List;
import java.util.function.Consumer;

public class EsIterazione {

	public static void main(String[] args) {
		
		List<Double> numeri = new ArrayList<>();
		
		numeri.add(10.0);
		numeri.add(20.1);
		numeri.add(9.7);
		numeri.add(50.0);
		
		double acc=0.0;
		for(double d : numeri){
			acc+=d;
		}
		System.out.println("Media: " + acc/numeri.size());

		// numeri.forEach( d -> acc+=d);  // acc must be final
		// EQUIVALE A
		// numeri.forEach( new MyConsumer(acc) );

		Accumulator a = new Accumulator();
		numeri.forEach( d -> a.acc+=d);
		// EQUIVALE A
		// numeri.forEach( new MyConsumer2(a) );
		System.out.println("Media: " + a.acc/numeri.size());
	}
	
	private static class Accumulator {
		double acc=0;
	}

	private static class MyConsumer implements Consumer<Double>{
		private final double acc;
		MyConsumer(double acc) { this.acc=acc; }
		@Override
		public void accept(Double d) {
			//acc+=d; // acc is final..
		}		
	}
	
	private static class MyConsumer2 implements Consumer<Double>{
		private final  Accumulator a;
		MyConsumer2(Accumulator a) { this.a=a; }
		@Override
		public void accept(Double d) {
			a.acc+=d;
		}
		
	}

}
