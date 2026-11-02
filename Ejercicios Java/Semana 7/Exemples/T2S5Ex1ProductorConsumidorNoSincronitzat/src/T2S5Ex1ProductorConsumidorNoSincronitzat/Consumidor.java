package T2S5Ex1ProductorConsumidorNoSincronitzat;

class Consumidor extends Thread {
	private Cua cua;
	private int n;

	public Consumidor(Cua c, int n) {
		cua = c;
		this.n = n;
	}

	public void run() {
		int valor = 0;
		for (int i = 0; i < 5; i++) {
			valor = cua.get();// recull el número
		}
	}
}