package T2S5Ex2ProductorConsumidorSincronitzat;

public class Cua {
	// atributs
	private int numero;
	private boolean disponible = false; // inicialment buida

	// mètodes
	// traure
	public synchronized int get() {
		while (disponible == false) { // si està buida
			try {
				wait();
			} catch (InterruptedException e) {e.printStackTrace();};
		}
		disponible = false;
		notifyAll();
		System.out.println("Consumeix: " + numero);
		return numero; // no hi ha numero
	}

	public synchronized void put(int valor) {
		while (disponible == true) { // si no està buida
			try {
				wait();
			} catch (InterruptedException e) {e.printStackTrace();};
		}
		numero = valor;
		disponible = true;
		System.out.println("Produeix: " + valor);
		notifyAll();
	}
}
