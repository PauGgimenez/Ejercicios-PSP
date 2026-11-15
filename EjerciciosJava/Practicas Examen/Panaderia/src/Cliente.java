public class Cliente extends Thread {

    private Bandeja b;
    private String nombre;

    public Cliente(Bandeja b, String nombre) {
        this.b = b;
        this.nombre = nombre;
    }


    public void run() {
        for (int i = 0; i < 5; i++) {
            b.comprar(nombre);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

        }

    }
}
