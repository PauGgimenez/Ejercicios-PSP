public class T2S2Exemple4Alive extends Thread {
	
	//Atributs --------------------------------
	private int c; //comptador fil
	private int fil;

	//Constructor --------------------------------
	public T2S2Exemple4Alive (int fil){
		this.fil=fil;
		System.out.println("Creant Fil: " + fil);
	}//fi constructor
	
	//Mètode Run -----------------------------------
	public void run(){
		c=0;
		while (c<=5){
			System.out.println ("Fil:"+ fil + " C= " + c);
			c++;
		}
	}//fi run
} //fi classe
