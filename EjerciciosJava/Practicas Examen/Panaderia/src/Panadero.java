public class Panadero extends Thread {

    private Bandeja b;

    public Panadero(Bandeja b) {
        this.b = b;
    }

    public void run() {
        for (int i = 0; i <= 9; i++) {
            b.hornear();
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

        }

    }
}
