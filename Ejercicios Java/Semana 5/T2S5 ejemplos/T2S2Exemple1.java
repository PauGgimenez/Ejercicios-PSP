public class T2S2Exemple1 extends Thread {
	
	//Atributs classe
	private int x; 

	//Constructor classe
	public T2S2Exemple1 (int x)
	{
		this.x=x;
	}//fi constructor
	
	//Mètode d'execució (run). Accions que fa el fil
	public void run(){
		for (int i=0;i<x;i++)
			System.out.println ("Dins del fil..");
		}//fi run
		
	//Mètode main
	public static void main(String[] args){
		T2S2Exemple1 p=new T2S2Exemple1(10); //cree el fil
		p.start();
	} //fi main

} //fi classe
