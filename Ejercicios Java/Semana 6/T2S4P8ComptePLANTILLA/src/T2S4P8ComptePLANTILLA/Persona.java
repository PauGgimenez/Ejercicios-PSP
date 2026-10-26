package T2S4P8ComptePLANTILLA;

class Persona extends Thread {
	private Compte c; // declare objecte compte c
	String nom;
	// constructor
	public Persona(String n, Compte c) {
		super(n);
		this.c = c;
	}
	// run
	public void run() {
		for (int x = 1; x <= 4; x++) {
			c.RetirarDiners(10, getName());
		}
	}
}