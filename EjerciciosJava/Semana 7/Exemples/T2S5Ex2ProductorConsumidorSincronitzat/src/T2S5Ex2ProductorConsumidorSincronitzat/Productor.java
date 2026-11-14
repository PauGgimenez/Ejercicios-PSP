package T2S5Ex2ProductorConsumidorSincronitzat;

class Productor extends Thread {
	private Cua cua;
	private int n;

	public Productor(Cua c, int n) {
		cua = c;
		this.n = n;
	}

	public void run() {
		for (int i = 0; i < 5; i++) {
			cua.put(i); // posa el número
			try {
				sleep(1000);
			} catch (InterruptedException e) {
			}
		}
	}
}
