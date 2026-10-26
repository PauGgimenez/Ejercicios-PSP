public class T2S2Exemple2 extends Thread {
	//Atributs --------------------------------
	private int c; //comptador fil
	private int fil;

	//Constructor --------------------------------
	public T2S2Exemple2 (int fil){
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
	
	//Mètode main
	public static void main(String[] args){
	T2S2Exemple2 h=null;
	for (int i=0;i<3;i++){
		h=new T2S2Exemple2(i+1); //cree fil
		h.start(); //inicialitzar fil
		}		
	System.out.println("3 Fils creats...");
	} //fi main

} //fi classe
