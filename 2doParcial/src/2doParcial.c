/*
 ============================================================================
 Name        : 2doParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Validaciones.h"
#include "articulo.h"

int main(void) {
	setbuf(stdout,NULL);
	FILE* archivoTexto=NULL;
	LinkedList* listaArticulos=ll_newLinkedList();
	int opcionMenu;
	int max=0;
	int i;
	char continuarMenu='s';
	    do
	    {
	        printf("1-Leer un archivo(modo texto)\n");
	        printf("2-Ordenar Ascendente\n");
	        printf("3-Imprimir Por pantalla\n");
	        printf("4-Funcion map con descto (solo cuidado ropa)\n");
	        printf("5-Generar archivo con los 2 descuentos de map-\n");
	        printf("6-Informe\n");
	        printf("7-Informe rubros\n");
	        printf("8-Salir\n");
	        opcionMenu=getInt("\nIngrese una opcion: ");
	                switch(opcionMenu)
	                {
	                    case 1:
	                        Articulo_cargarDatosModoTexto(archivoTexto,listaArticulos);
	                        break;
	                    case 2:
	                        ll_sort(listaArticulos,Articulo_funcionCriterio,1);
	                        break;
	                    case 3:
	                    	Articulo_mostrarListaArticulos(listaArticulos);
	                        break;
	                    case 4:
	                        mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorCuidadoRopa);
	                    	mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorLimpieza);
	                        break;
	                    case 5:
	                    	Articulo_guardarDatosMapeo(archivoTexto,listaArticulos);
	                        break;
	                    case 6:
	                        ll_count(listaArticulos,(void*)Articulo_MontoMayora100,&max);
	                        break;
	                    case 7:
	                    	ll_count(listaArticulos,(void*)Articulo_CantidadRubroUno,&i);
	                    	break;
	                    case 8:
	                    	 continuarMenu='n';
	                    	 break;
	                    default:
	                        printf("\nOpcion ingresada no valida\n");
	                }
	                system("pause");
	                system("cls");
	    }while(continuarMenu=='s');
	    ll_deleteLinkedList(listaArticulos);
	return EXIT_SUCCESS;
}
