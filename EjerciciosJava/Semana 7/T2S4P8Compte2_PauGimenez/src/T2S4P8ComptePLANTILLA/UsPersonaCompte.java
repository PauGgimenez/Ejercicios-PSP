package T2S4P8ComptePLANTILLA;

public class UsPersonaCompte {
	public static void main(String[] args) {
		Compte c = new Compte(40, 500);
		Persona h1 = new Persona("Elena Nito", c);
		Persona h2 = new Persona("Ana Boueles", c);

		h1.start();
		h2.start();
	}

}