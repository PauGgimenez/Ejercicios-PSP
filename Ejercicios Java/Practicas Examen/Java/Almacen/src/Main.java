/* Simulacro 2 — Java (nivel exacto de Compte 2)
Simula un almacén compartido (Almacen) con un stock inicial de 20 cajas y una capacidad máxima de 100.
Crea dos tipos de hilos:
Proveedor (hace 3 entregas de entre 10 y 50 cajas; si supera el máximo, espera con wait()) y Cliente (hace 3 pedidos de entre 10 y 50 cajas;
si no hay stock suficiente, espera con wait()).
Lanza 2 proveedores y 2 clientes en el main mostrando cada intento, espera y stock actualizado. */


public static void main(String[] args) {
    Almacen a = new Almacen(20, 100);
    Proveedor p1 = new Proveedor(a, "PROVEEDOR 1");
    Proveedor p2 = new Proveedor(a, "PROVEEDOR 2");

    Cliente c1 = new Cliente(a, "CLIENTE 1");
    Cliente c2 = new Cliente(a, "CLIENTE 2");

    p1.start();
    p2.start();

    c1.start();
    c2.start();


}






