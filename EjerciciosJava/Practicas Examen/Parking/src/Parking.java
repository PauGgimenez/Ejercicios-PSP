public class Parking {

    private int plazasOcupadas;
    private int plazasMaximas;

    public Parking(int plazasMaximas) {
        this.plazasMaximas = plazasMaximas;
        this.plazasOcupadas = 0;
    }

    public synchronized void entrar(int mat) {
        System.out.println("El coche-" + mat + " intenta entrar.");
        while (plazasOcupadas >= plazasMaximas) {
            System.out.println("El coche-" + mat + " NO ha podido entrar (Parking lleno). Esperando...");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.plazasOcupadas++;
        System.out.println("El coche-" + mat + " ENTRA. Plazas ocupadas " + this.plazasOcupadas + " plazas");

    }

    public synchronized void salir(int mat) {
        System.out.println("El coche-" + mat + " SALE.");
        this.plazasOcupadas--;
        notifyAll();


    }
}
