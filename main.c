#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"

int main()
{
    int ceProd;
    Producto vProd[TAM];

    cargarProds(vProd, &ceProd, TAM);
    ordenarSel(vProd, ceProd, sizeof(Producto), cmpProdStockCod);
    mostrarVec(vProd, ceProd, sizeof(Producto), MostrarProd);

    return 0;
}
