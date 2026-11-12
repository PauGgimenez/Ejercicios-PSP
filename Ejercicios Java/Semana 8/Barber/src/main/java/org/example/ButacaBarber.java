package org.example;

public class ButacaBarber {
    boolean isOcupada = false;
    int turnoClientActual;


    public synchronized void ocuparButaca(Client c) {
        while (this.isOcupada) {
            System.out.println("Cliente " + c.turno + " ha intentat seure en BUTACA pero no pot.");

            try {
                wait();
            } catch (Exception e) {

            }
        }
        System.out.println("Cliente " + c.turno + " seu en la BUTACA");
        turnoClientActual = c.turno;
        this.isOcupada = true;
        notifyAll();

    }

    public synchronized void tallarCabell() {
        while (!this.isOcupada) {
            try {
                wait();

            } catch (Exception e) {
                throw new RuntimeException(e);
            }

        }
        try {
            Thread.sleep(2000);
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
        isOcupada = false;
        notifyAll();
        System.out.println("Barber ha TALLAT el cabell a " + turnoClientActual);
    }


}





