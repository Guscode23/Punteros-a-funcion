#include <stdio.h>
#include <stdlib.h>
#include "Productos.h"

void ordenarSel(void* vec, int ce, size_t tamElem, Cmp cmp)
{
    void *ult = vec + (ce-1) * tamElem, *m;

    for(void *i = vec;i < ult;i += tamElem)
    {
        m = buscarMenor(i, ult, tamElem, cmp);
        if(m != i)
            intercambiar(m, i, tamElem);
    }
}

void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp)
{
    void *m = ini;

    for(void *j = ini + tamElem; j <= fin; j += tamElem)

        if(cmp(j,m) < 0)
            m = j;

    return m;
}

void intercambiar(void* a, void* b, size_t tamElem)
{
    char aux[tamElem];

    memcpy(aux, a, tamElem); //intercambio tamElem cant de bytes
    memcpy(a, b, tamElem);
    memcpy(b, aux, tamElem);
}

int cmpProdCod(const void *p1,const void *p2)
{
    const Producto *prod1 = (Producto*) p1;
    const Producto *prod2 = (Producto*) p2;

    return strcmp(prod1->cod, prod2->cod);
}

int cmpProdStockCod(const void *p1,const void *p2)
{
    const Producto *prod1 = (Producto*) p1;
    const Producto *prod2 = (Producto*) p2;

    int comp = prod1->stock - prod2->stock;

    if(comp != 0)
        return comp;

    return strcmp(prod1->cod, prod2->cod);
}

void cargarProds(Producto* vProd, int* ce, int tam)
{
    for(Producto* i = vProd; i <= vProd + tam - 1; i++)
    {
        fflush(stdin);
        fgets(i->cod, 5, stdin); //la quinta posicion la reserva para el \0 para no pasarse del limite
        fflush(stdin);
        scanf("%d", &i->stock);
    }

    *ce = tam;
}

void mostrarVec(void* vec, int ce, size_t tamElem, Mostrar mostrar)
{
     void* ult = vec + (ce) * tamElem;

     for(void* i = vec; i < ult ; i += tamElem)
     {
         mostrar(i);
     }
}

void MostrarProd(const void* p1)
{
    const Producto *prod1 = (Producto*) p1;

    printf("Producto %s // stock %d\n", prod1->cod, prod1->stock);
}
