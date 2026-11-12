package org.example;

public class CadiresEspera {
    int cadiresNum;
    int cadiresLliures;

    Client c;

    public CadiresEspera(int cadiresNum) {
        this.cadiresNum = cadiresNum;
        this.cadiresLliures = cadiresNum;
    }


    public synchronized boolean ocuparCadira(Client c) {

        if (cadiresLliures != 0) {
            System.out.println("Cliente " + c.turno + " seu en una CADIRA d'espera.");
            cadiresLliures--;
            return true;


        } else {
            System.out.println("Cliente " + c.turno + " SE VA DE LA BARBERIA.");
            return false;

        }
    }

    public synchronized void desocuparCadira() {

        cadiresLliures++;
    }
}
