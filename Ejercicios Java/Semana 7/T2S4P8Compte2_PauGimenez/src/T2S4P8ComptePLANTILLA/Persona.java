package T2S4P8ComptePLANTILLA;

import java.util.Random;

class Persona extends Thread {
    private Compte c; // declare objecte compte c
    private String nom;

    // constructor
    public Persona(String nom, Compte c) {
        super(nom);
        this.c = c;
    }

    // run
    public void run() {
        Random rnd = new Random();
        for (int x = 1; x <= 2; x++) {

            int dineroIngresar = (int) (rnd.nextDouble() * 201.0);
            c.ingresarDinero(dineroIngresar, getName());

            int dineroRetirar = (int) (rnd.nextDouble() * 201.0);
            c.retirarDinero(dineroRetirar, getName());


        }
    }
}