public class Coche extends Thread {

    Parking p;
    int mat;

    public Coche(Parking p, int mat) {
        this.p = p;
        this.mat = mat;
    }

    public void run() {
        p.entrar(mat);
        try {
            Thread.sleep(2000);

        } catch (Exception e) {

        }
        p.salir(mat);

    }
}
