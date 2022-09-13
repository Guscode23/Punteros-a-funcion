#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include <string.h>
#define TAM 4

typedef struct
{
    char cod[5];
    int stock;
} Producto;

typedef int(*Cmp)(const void*, const void*);
typedef void(*Mostrar)(const void*);

void ordenarSel(void* vec, int ce, size_t tamElem, Cmp cmp);
void* buscarMenor(void* ini, void* fin, size_t tamElem, Cmp cmp);
void intercambiar(void* a, void* b, size_t tamElem);

int cmpProdCod(const void* p1, const void* p2);
int cmpProdStockCod(const void* p1, const void* p2);
void MostrarProd(const void* p1);

void cargarProds(Producto* vProd, int* ce, int tam);
void mostrarVec(void* vec, int ce, size_t tamElem, Mostrar mostrar);

#endif // PRODUCTOS_H_INCLUDED
