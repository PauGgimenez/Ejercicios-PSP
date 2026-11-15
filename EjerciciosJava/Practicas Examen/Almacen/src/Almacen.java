public class Almacen {
    private int stock;
    private int stockMaximo;

    public Almacen(int stock, int stockMaximo) {
        this.stock = stock;
        this.stockMaximo = stockMaximo;

    }

    public synchronized void hacerPedido(int cantidad, String nom) {
        System.out.println(nom + " intenta PEDIR " + cantidad + ". Stock actual: " + stock);

        while (cantidad > this.stock) {
            System.out.println(nom + " espera (stock insuficiente: " + stock + ").");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        this.stock -= cantidad;
        System.out.println(nom + " realiza PEDIDO de " + cantidad + ". Stock actual: " + stock);
        notifyAll();


    }

    public synchronized void hacerEntrega(int cantidad, String nom) {
        System.out.println(nom + " intenta ENTREGAR " + cantidad + ". Stock actual: " + stock);
        while ((cantidad + this.stock) > this.stockMaximo) {
            System.out.println(nom + " espera (supera el máximo de " + stockMaximo + ").");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        this.stock += cantidad;
        System.out.println(nom + " realiza ENTREGA de " + cantidad + ". Stock actual: " + stock);
        notifyAll();
    }
}
