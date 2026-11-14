package T2S4P8ComptePLANTILLA;

class Compte {
    private int saldo;
    private int maxSaldo;

    // constructor
    Compte(int s, int maxSaldo) {
        this.saldo = s;
        this.maxSaldo = maxSaldo;
    }

    // torna el saldo
    int getSaldo() {
        return this.saldo;
    }

    // resta la quantitat al saldo
    void restar(int cantidad) {
        this.saldo -= cantidad;
    }

    void sumar(int cantidad) {
        this.saldo += cantidad;
    }

    public synchronized void retirarDinero(int cant, String nom) {
        System.out.println(nom + " intenta retirar => : " + cant + ". Saldo Actual: " + getSaldo());

        // El hilo espera si no hay saldo suficiente
        while (cant > getSaldo()) {
            System.out.println(nom + " se queda esperando. No hay saldo suficiente.");
            try {
                wait();
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }

        restar(cant);
        System.out.println(nom + " retira => : " + cant + ". Saldo Actual: " + getSaldo());
        notifyAll(); // avisa al otro hilo de que el saldo ha cambiado
    }


    public synchronized void ingresarDinero(int cant, String nom) {
        System.out.println(nom + " intenta ingresar => : " + cant + ". Saldo Actual: " + getSaldo());

        while ((cant + getSaldo()) > maxSaldo) {
            System.out.println(nom + " se queda esperando. Se pasa del maximo (" + maxSaldo + ").");
            try {
                wait();
            } catch (InterruptedException ex) {
                ex.printStackTrace();
            }
        }

        sumar(cant);
        System.out.println(nom + " ingresa => : " + cant + ". Saldo Actual: " + getSaldo());
        notifyAll(); //
    }
}


