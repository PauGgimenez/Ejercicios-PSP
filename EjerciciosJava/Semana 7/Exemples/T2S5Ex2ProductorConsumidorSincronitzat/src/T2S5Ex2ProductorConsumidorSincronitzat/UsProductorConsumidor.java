package T2S5Ex2ProductorConsumidorSincronitzat;

public class UsProductorConsumidor {
	public static void main(String[] args) {
		Cua cua = new Cua();
		Productor p = new Productor(cua, 1);
		Consumidor c = new Consumidor(cua, 1);
		p.start();
		c.start();
	}
}
