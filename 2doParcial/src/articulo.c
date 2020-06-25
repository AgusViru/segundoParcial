/*
 * articulo.c
 *
 *  Created on: 24 jun. 2020
 *      Author: Ezequiel
 */
#include "articulo.h"

eArticulo* Articulo_nuevoArticulo()
{
    eArticulo* unArticulo=(eArticulo*)malloc(sizeof(eArticulo));
    return unArticulo;
}
int Articulo_borrarArticulo(eArticulo* articulo)
{
    int seLibero=0;
    if(articulo!=NULL)
    {
        free(articulo);
        seLibero=1;
    }
    return seLibero;
}
int Articulo_setIdArticulo(eArticulo* articulo,int idArticulo)
{
    int retorno=0;
    if((articulo!=NULL) && (idArticulo > 0))
    {
        articulo->idArticulo=idArticulo;
        retorno=1;
    }
    return retorno;
}
int Articulo_setPrecio(eArticulo* articulo,int precio)
{
    int retorno=0;
    if((articulo!=NULL) && (precio > 0))
    {
        articulo->precio=precio;
        retorno=1;
    }
    return retorno;
}
int Articulo_setIdRubro(eArticulo* articulo,int idRubro)
{
    int retorno=0;
    if((articulo!=NULL) && (idRubro > 0))
    {
        articulo->rubroId=idRubro;
        retorno=1;
    }
    return retorno;
}
int Articulo_setArticulo(eArticulo* articulo,char* Aarticulo)
{
    int retorno=0;
    if((articulo!=NULL) && (strlen(Aarticulo) > 0))
    {
        strcpy(articulo->articulo,Aarticulo);
        retorno=1;
    }
    return retorno;
}
int Articulo_setMedida(eArticulo* articulo,char* medida)
{
    int retorno=0;
    if((articulo!=NULL) && (strlen(medida) > 0))
    {
        strcpy(articulo->medida,medida);
        retorno=1;
    }
    return retorno;
}

int Articulo_getIdArticulo(eArticulo* articulo,int* idArticulo)
{
    int retorno=0;
    if(articulo!=NULL && idArticulo!=NULL)
    {
        *idArticulo=articulo->idArticulo;
        retorno=1;
    }
    return retorno;
}
int Articulo_getPrecio(eArticulo* articulo,int* precio)
{
    int retorno=0;
    if(articulo!=NULL && precio!=NULL)
    {
        *precio=articulo->precio;
        retorno=1;
    }
    return retorno;
}
int Articulo_getIdRubro(eArticulo* articulo,int* idRubro)
{
    int retorno=0;
    if(articulo!=NULL && idRubro!=NULL)
    {
        *idRubro=articulo->rubroId;
        retorno=1;
    }
    return retorno;
}
int Articulo_getArticulo(eArticulo* articulo,char* Aarticulo)
{
    int retorno=0;
    if(articulo!=NULL && Aarticulo!=NULL)
    {
        strcpy(Aarticulo,articulo->articulo);
        retorno=1;
    }
    return retorno;
}
int Articulo_getMedida(eArticulo* articulo,char* medida)
{
    int retorno=0;
    if(articulo!=NULL && medida!=NULL)
    {
        strcpy(medida,articulo->medida);
        retorno=1;
    }
    return retorno;
}
eArticulo* Articulo_nuevoArticuloParametros(char* idArticulo,char* articulo,char* medida,char* precio,char* idRubro)
{
    eArticulo* unArticulo=NULL;
    if((idArticulo!=NULL) && (articulo!=NULL) && (precio!=NULL) && (medida!=NULL) && (idRubro!=NULL))
    {
        unArticulo=Articulo_nuevoArticulo();
        if(unArticulo!=NULL)
        {
            if(!Articulo_setIdArticulo(unArticulo,atoi(idArticulo))
            	|| !Articulo_setArticulo(unArticulo,articulo)
            	|| !Articulo_setMedida(unArticulo,medida)
				|| !Articulo_setPrecio(unArticulo,atoi(precio))
				|| !Articulo_setIdRubro(unArticulo,atoi(idRubro)))
            {
                Articulo_borrarArticulo(unArticulo);
                unArticulo=NULL;
            }
        }
    }
    return unArticulo;
}
int Articulo_cargarDatosModoTexto(FILE* archivo,LinkedList* listaArticulos)
{
    char nombreArchivo[256];
    char auxIdArticulo[256];
    char auxArticulo[256];
    char auxPrecio[256];
    char auxMedida[256];
    char auxIdRubro[256];
    eArticulo* auxDatos;
    int sePudo=-1;
    if(!utn_getLetrasYNumeros(nombreArchivo,256,"\nIngrese el nombre del archivo a cargar: "))
    {
        archivo=fopen(nombreArchivo,"r");
        if(archivo!=NULL)
        {
            ll_clear(listaArticulos);
            fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdArticulo,auxArticulo,auxMedida,auxPrecio,auxIdRubro);
            while(!feof(archivo))
            {
                fscanf(archivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",auxIdArticulo,auxArticulo,auxMedida,auxPrecio,auxIdRubro);
                auxDatos=Articulo_nuevoArticuloParametros(auxIdArticulo,auxArticulo,auxMedida,auxPrecio,auxIdRubro);
                ll_add(listaArticulos,auxDatos);
                if(feof(archivo))
                {
                    break;
                }
            }
            fclose(archivo);
            printf("\nSe han cargado los datos\n");
            sePudo=1;
        }
    }
    return sePudo;
}
int Articulo_funcionCriterio(void* itemUno, void* itemDos)
{
	 char bufferArticuloA[100];
	 char bufferArticuloB[100];
	 int result;
	 Articulo_getArticulo(itemUno,bufferArticuloA);
	 Articulo_getArticulo(itemDos,bufferArticuloB);
	    if(strcmp(bufferArticuloA,bufferArticuloB)<0)
	    {
	        result=-1;
	    }
	    	else if(strcmp(bufferArticuloA,bufferArticuloB)>0)
	    	{
	    		result=1;
	    	}
	    		else
	    		{
	    			result=0;
	    		}
	    return result;
}
void Articulo_mostrarListaArticulos(LinkedList* listaArticulos)
{
    eArticulo* auxArticulo;
    int i;
    int len=ll_len(listaArticulos);
    if(listaArticulos!=NULL)
    {
        if(listaArticulos!=NULL && ll_isEmpty(listaArticulos)==1)
        {
            printf("\nNo hay ningun elemento en la lista\n");
        }
        else
        {
            printf("\nIdArticulo--Articulo--Medida--Precio--RubroId--\n");
            for(i=0;i<len;i++)
            {
                auxArticulo=(eArticulo*)ll_get(listaArticulos,i);
                Articulo_mostrarUnArticulo(auxArticulo);
            }
        }
    }
}
int Articulo_mostrarUnArticulo(eArticulo* unArticulo)
{
    int idArticulo;
    char articulo[256];
    int precio;
    char medida[256];
    int rubroId;

    Articulo_getIdArticulo(unArticulo,&idArticulo);
    Articulo_getArticulo(unArticulo,articulo);
    Articulo_getMedida(unArticulo,medida);
    Articulo_getPrecio(unArticulo,&precio);
    Articulo_getIdRubro(unArticulo,&rubroId);
    int seMostro=0;
    if(unArticulo!=NULL)
    {
        printf("\n%d",idArticulo);
        printf("%2s\t",articulo);
        printf("%2s\t",medida);
        printf("%2d",precio);
        printf("%5d\n",rubroId);
        seMostro=1;
    }
    return seMostro;
}
int Articulo_calcularPrecioPorCuidadoRopa(eArticulo* unArticulo)
{
	int retorno=-1;
    int precio;
    int idRubro;
    if(unArticulo!=NULL)
    {
        precio=unArticulo->precio; //precio-(precio*0.2);
        idRubro= unArticulo->rubroId;
        if(precio>=120 && idRubro==1)
        {
            unArticulo->precio=precio-(precio*0.2);
            retorno=0;
        }
    }
    return retorno;
}

int Articulo_calcularPrecioPorCuidadoRopaDos(void* unArticulo)
{
	int mapeo=0;
    int precio;
    int idRubro;
 	int precioDescto;
    eArticulo* articulo=(eArticulo*)unArticulo;
    Articulo_getPrecio(articulo,&precio);
    Articulo_getIdRubro(articulo,&idRubro);
    precioDescto=precio-(precio*0.2);
    if(precioDescto>=120 && idRubro==1)
    {
        mapeo=1;
    }
    return mapeo;
}
int Articulo_calcularPrecioPorLimpiezaDos(void* unArticulo)
{
	int mapeo=0;
    int precio;
    int idRubro;
 	int precioDescto;
    eArticulo* articulo=(eArticulo*)unArticulo;
    Articulo_getPrecio(articulo,&precio);
    Articulo_getIdRubro(articulo,&idRubro);
    precioDescto=precio-(precio*0.1);
    if(precioDescto<=200 && idRubro==2)
    {
        mapeo=1;
    }
    return mapeo;
}
int Articulo_calcularPrecioPorLimpieza(eArticulo* unArticulo)
{
	int retorno=-1;
    int precio;
    int idRubro;
    if(unArticulo!=NULL)
    {
        precio=unArticulo->precio; //precio-(precio*0.2);
        idRubro=unArticulo->rubroId;
        	if(precio<=200 && idRubro==2)
        	{
        		unArticulo->precio=precio-(precio*0.1);
        		retorno=0;
        	}
    }
    return retorno;
}
int Articulo_guardarDatosMapeo(FILE* archivo,LinkedList* listaArticulos)
{
    char nombreArchivo[256];
    char auxIdArticulosStr[256];
    char auxArticuloStr[256];
    char auxMedidaStr[256];
    char auxprecioStr[256];
    char auxRubroIdStr[256];
    int auxIdArticulos;
    int auxPrecio;
    int auxRubroId;
    int sePudo=-1;
    LinkedList* nuevaLista;
    eArticulo* auxDatos;
    int i;
    int len;
    if(listaArticulos!=NULL && ll_isEmpty(listaArticulos)==1)
    {
        printf("\nNo hay ningun elemento en la lista\n");
    }
    else
    {
        if(getStrLetras("\nIngrese el nombre del nuevo archivo a crear: ",nombreArchivo,"\nSolo se permiten letras\n","\nRango valido entre 1 y 16\n",1,16,3))
        {
            archivo=fopen(nombreArchivo,"w");
            if(archivo!=NULL)
            {
            	nuevaLista=mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorCuidadoRopa);
            	nuevaLista=mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorLimpieza);
            	/*nuevaLista=mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorCuidadoRopaDos);
            	nuevaLista=mapeo(listaArticulos,(void*)Articulo_calcularPrecioPorLimpiezaDos);*/
            	if(nuevaLista!=NULL)
            	{
                    len=ll_len(nuevaLista);
                    fprintf(archivo,"\nIdArticulo--Articulo--Medida--Precio--RubroId--\n");
                    for(i=0;i<len;i++)
                    {
                        auxDatos=(eArticulo*)ll_get(nuevaLista,i);
                        Articulo_getIdArticulo(auxDatos,&auxIdArticulos);
                        itoa(auxIdArticulos,auxIdArticulosStr,10);
                        Articulo_getArticulo(auxDatos,auxArticuloStr);
                        Articulo_getMedida(auxDatos,auxMedidaStr);
                        Articulo_getPrecio(auxDatos,&auxPrecio);
                        itoa(auxPrecio,auxprecioStr,10);
                        Articulo_getIdRubro(auxDatos,&auxRubroId);
                        itoa(auxRubroId,auxRubroIdStr,10);
                        fprintf(archivo,"%s,%s,%s,%s,%s\n",auxIdArticulosStr,auxArticuloStr,auxMedidaStr,auxprecioStr,auxRubroIdStr);
                    }
            	}
                fclose(archivo);
                printf("\nSe han guardado los datos\n");
                sePudo=1;
            }
        }
    }
    return sePudo;
}
int Articulo_MontoMayora100(void* pElement)
{
    int retorno;
    int aux;
    if(pElement!=NULL){
        Articulo_getPrecio(pElement,&aux);
        if(aux>100){
            retorno=1;
            Articulo_mostrarUnArticulo((eArticulo*)pElement);
        }else
            retorno=0;
    }
    return retorno;
}
int Articulo_CantidadRubroUno(void* pElement)
{
	int retorno;
	int auxRubro;
	if(pElement!=NULL)
	{
	    Articulo_getIdRubro(pElement,&auxRubro);
	    if(auxRubro==1)
	    {
	    	retorno=1;
	        Articulo_mostrarUnArticulo((eArticulo*)pElement);
	    }
	    else
	    {
	       retorno=0;
	    }
	}
	    return retorno;

}

