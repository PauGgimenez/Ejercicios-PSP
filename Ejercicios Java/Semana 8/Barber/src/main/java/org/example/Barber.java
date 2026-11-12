package org.example;

public class Barber extends Thread {
    ButacaBarber butaca;


    public Barber(ButacaBarber butaca) {
        this.butaca = butaca;
    }

    public void run() {
        while (true) {
            butaca.tallarCabell();
        }


    }



}
