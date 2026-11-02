public class T2S2P4TicTacGimenez extends Thread {

        String palabra;

        public T2S2P4TicTacGimenez(String palabra) {
                this.palabra = palabra;
        }

        public void run() {
                boolean seguir = true;
                while (seguir) {
                        System.out.println(palabra);
                        try {
                                // Pausa 1 segundo
                                sleep(1000);
                        } catch (InterruptedException e) {
                        }
                }
        }

        public static void main(String[] args) {
                T2S2P4TicTacGimenez tic = new T2S2P4TicTacGimenez("TIC"); 
                T2S2P4TicTacGimenez tac = new T2S2P4TicTacGimenez("TAC"); 

                tic.start();
                tac.start();
        }
}
