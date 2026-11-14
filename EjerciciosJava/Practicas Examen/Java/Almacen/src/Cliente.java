import java.util.Random;

public class Cliente extends Thread {
    Almacen c;


    public Cliente(Almacen c, String nom) {
        super(nom);
        this.c = c;

    }

    public void run() {
        Random rm = new Random();
        for (int i = 1; i <= 3; i++) {
           int cantidad = rm.nextInt((50 - 10) + 1) + 10;
           c.hacerPedido(cantidad, getName());

        }
    }
}
