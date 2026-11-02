package T2S5Ex1ProductorConsumidorNoSincronitzat;

public class Cua {
	// atributs
	private int numero;
	private boolean disponible = false; // inicialment buida

	// mètodes
	// traure
	public int get() {
		if (disponible) { // si no està buida
			disponible = false; // pose que està buida
			System.out.println("Consumeix: " + numero);
			return numero; // torne numero
		}
		else {
			System.out.println("Intenta consumir pero no consumeix");
			return -1; // no hi ha numero
		}
	}

	public void put(int valor) {
		numero = valor; // col·locar valor a la cua
		disponible = true; // disponible per a consumir, cua plena
		System.out.println("Produeix: " + valor);
	}

}