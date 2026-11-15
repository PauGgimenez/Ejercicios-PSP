//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public static void main(String[] args) {
    Bandeja b = new Bandeja(3);
    Panadero p = new Panadero(b);
    Cliente c1 = new Cliente(b, "Juan");
    Cliente c2 = new Cliente(b, "Marta");

    p.start();
    c1.start();
    c2.start();


}
