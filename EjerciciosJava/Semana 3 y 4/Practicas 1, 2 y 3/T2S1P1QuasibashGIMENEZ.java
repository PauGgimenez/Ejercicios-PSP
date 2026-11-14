import java.util.Scanner;


public class T2S1P1Quasibash {
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	Runtime r=Runtime.getRuntime();
	System.out.println("Comando a ejecutar: ");
	String n = sc.nextLine();
	String comando= n; 
	Process p;

	try{
		p=r.exec(comando);
		} catch(Exception e) {
			System.out.println ("Error en "+comando);
			e.printStackTrace();
			}
	}

}//T2S1Quasibash
