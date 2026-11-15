//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void main() {

    Parking p = new Parking(4);
    for (int i = 1; i <= 10 ; i++) {
        Coche c = new Coche(p, i);
        c.start();

    }



}
