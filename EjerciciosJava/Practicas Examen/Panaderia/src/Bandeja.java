public class Bandeja {
    private int panes;
    private int maxPanes;

    public Bandeja(int maxPanes) {
        this.panes = 0;
        this.maxPanes = maxPanes;
    }

    public synchronized  void hornear() {
        System.out.println("El panadero pone a hornear un pan");
        while (panes >= maxPanes) {
            System.out.println("No caben mas panes en la bandeja");
            try {
                wait();
            } catch (Exception e) {

            }

        }
        System.out.println("El panadero pone un pan en la bandeja");
        this.panes++;
        notifyAll();

    }


    public synchronized  void comprar(String nombreCliente) {
        System.out.println("El cliente " + nombreCliente + " intenta coger un pan.");
        while (panes == 0) {
            System.out.println("Aun no hay panes en la bandeja");
            try {
                wait();
            } catch (Exception e) {

            }
        }
        System.out.println("El cliente " + nombreCliente + " coge un pan en la bandeja");
        this.panes--;
        notifyAll();

    }
}
