package org.example;

public class Client extends Thread {
    ButacaBarber butaca;
    CadiresEspera cadira;
    int turno;

    public Client(ButacaBarber butaca, CadiresEspera cadira, int turno) {
        this.butaca = butaca;
        this.cadira = cadira;
        this.turno = turno;
    }

    public void run() {
        if (cadira.ocuparCadira(this)) {
            butaca.ocuparButaca(this);
            cadira.desocuparCadira();
        }


    }
}
