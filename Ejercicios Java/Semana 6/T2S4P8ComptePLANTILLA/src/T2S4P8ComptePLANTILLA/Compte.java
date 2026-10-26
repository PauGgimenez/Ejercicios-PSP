package T2S4P8ComptePLANTILLA;

class Compte {
	private int saldo;

	// constructor
	Compte(int s) {
		saldo = s; // inicialitza el saldo actual
	}// --------------------------------------

	// torna el saldo
	int getSaldo() {

	}// --------------------------------

	// resta la quantitat al saldo
	void restar(int cantidad) {

	}// -----------------------------------

	// comprova que es puga retirar diners i els retira
	void RetirarDiners(int cant, String nom) {
		if (getSaldo() >= cant) {
			System.out.println(nom + " va a retirar saldo (actual és: " + getSaldo() + ")");
			try {
				Thread.sleep(1000);
			} catch (InterruptedException ex) {
			}
			restar(cant);
			System.out.println(nom + " retira => : " + cant + ". Saldo Actual: " + getSaldo() + "");
		} else {
			System.out.println(nom + " No pot retirar diners no hi ha saldo. Saldo Actual: " + getSaldo() + "");
		}

	}// fi retiras diners------------------------------

}// Compte
