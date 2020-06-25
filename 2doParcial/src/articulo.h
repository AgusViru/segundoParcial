/*
 * articulo.h
 *
 *  Created on: 24 jun. 2020
 *      Author: Ezequiel
 */

#ifndef ARTICULO_H_
#define ARTICULO_H_
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Validaciones.h"
#include "utn.h"
#include "rubro.h"
typedef struct
{
	int idArticulo;
	char articulo[50];
	int precio;
	char medida[50];
	int rubroId;
}eArticulo;

eArticulo* Articulo_nuevoArticulo();
int Articulo_borrarArticulo(eArticulo* articulo);
int Articulo_setIdArticulo(eArticulo* articulo,int idArticulo);
int Articulo_setPrecio(eArticulo* articulo,int precio);
int Articulo_setIdRubro(eArticulo* articulo,int idRubro);
int Articulo_setArticulo(eArticulo* articulo,char* Aarticulo);
int Articulo_setMedida(eArticulo* articulo,char* medida);
int Articulo_getIdArticulo(eArticulo* articulo,int* idArticulo);
int Articulo_getPrecio(eArticulo* articulo,int* precio);
int Articulo_getIdRubro(eArticulo* articulo,int* idRubro);
int Articulo_getArticulo(eArticulo* articulo,char* Aarticulo);
int Articulo_getMedida(eArticulo* articulo,char* medida);
eArticulo* Articulo_nuevoArticuloParametros(char* idArticulo,char* articulo,char* medida,char* precio,char* idRubro);
int Articulo_cargarDatosModoTexto(FILE* archivo,LinkedList* listaArticulos);
int Articulo_funcionCriterio(void* itemUno, void* itemDos);
void Articulo_mostrarListaArticulos(LinkedList* listaArticulos);
int Articulo_mostrarUnArticulo(eArticulo* unArticulo);
int Articulo_calcularPrecioPorCuidadoRopa(eArticulo* unArticulo);
int Articulo_calcularPrecioPorCuidadoRopaDos(void* unArticulo);
int Articulo_calcularPrecioPorLimpiezaDos(void* unArticulo);
int Articulo_calcularPrecioPorLimpieza(eArticulo* unArticulo);
int Articulo_guardarDatosMapeo(FILE* archivo,LinkedList* listaArticulos);
int Articulo_MontoMayora100(void* pElement);
int Articulo_CantidadRubroUno(void* pElement);

#endif /* ARTICULO_H_ */
