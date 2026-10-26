public class T2S2Exemple3Usa {
  public static void main(String[] args){
		T2S2Exemple3 h=null;
		for (int i=0;i<3;i++){
			h=new T2S2Exemple3(i+1); //cree fil
			h.start(); //iniciar fil
			//comprovem si este fil està viu
			System.out.println("status = " + h.isAlive());
		}
		System.out.println("3 Fils creats...");
	} //fi main
} //fi classe
