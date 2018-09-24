package it.polito.po;

public class Quiz {
	final static public String[] questions = {
	"Cosa contiene la sezione centrale di una classe UML?",
	"Qual'e' la differenza tra verifica e convalida?",
	"Che metodo usa SVN per risolvere conflitti?"
	};
	final static public String[][] options = {
	{
		"Nome del package",
		"Metodi",
		"Attributi statici",
		"Nome della classe",
		"Attributi"	},
	{
		"Una e' efficace, l'altra no",
		"Sono sinonimi, non c'e' differenza",
		"Una riguarda il test, l'altra le ispezioni",
		"Una determina la qualita' l'altra l'utilita' del sistema",
		"Una riguarda il test, l'altra no"	},
	{
		"Copy-Modify-Merge",
		"Check-in/Check-out",
		"Check-out/Commit",
		"Lock-Unlock-Modify",
		"Check-out/Check-in"	}
	};
	
	/**
	 * Return the index of the right answer(s) for the given question 
	 */
	public static int[] answer(int question){
		

		
		int q1[] = {1,3,4};
		int q2[] = {2};
		int q3[] = {0};
		
		switch(question){
		
		
			case 0: return q1; // replace with your answers
			case 1: return q2; // replace with your answers
			case 2: return q3; // replace with your answers
		}
		
		
		return null; // means: "No answer"
	}

	/**
	 * When executed will show the answers you selected
	 */
	public static void main(String[] args){
		for(int q=0; q<questions.length; ++q){
			System.out.println("Question: " + questions[q]);
			int[] a = answer(q);
			if(a==null || a.length==0){
				System.out.println("<undefined>");
				continue;
			}
			System.out.println("Answer" + (a.length>1?"s":"") + ":" );
			for(int i=0; i<a.length; ++i){
				System.out.println(a[i] + " - " + options[q][a[i]]);
			}
		}
	}
}

