/*
 * electro.c
 *
 *  Created on: 14 oct. 2020
 *
 */
#define TAMR 4
#define TAMM 5
#define TAM 3
#define TAMS 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "electro.h"
#include "utn.h"


int initElectro(Electrodomestico* electro, int len)
{
	int retorno =-1;
	//retorna 0 if ok
	int i=0;
	if(electro!=NULL && TAM > 0)
	{
		for(i=0;i<TAM;i++){
			electro[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}

int searchForSpace(Electrodomestico* electro, int len, int* position)
{
	int retorno=-1;
	int i =0;
	if(electro!=NULL && TAM >=0 && position!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(electro[i].isEmpty==1)
			{
				retorno=0;
				*position=i;
			}
		}
	}
	return retorno;
}
int descripcionMarca(char description[], int id, Marca* marcas, int tamM)
{
    int todoOk = 0;

    for(int i=0; i<TAMM; i++)
    {
        if(marcas[i].idMarca == id)
        {
            strcpy(description, marcas[i].descripcionMarca);
            todoOk = 1;
        }
    }
    return todoOk;
}

void printElectro(Electrodomestico electro, Marca* marcas, int lenM)
{


	char descripMarca[20];
	descripcionMarca(descripMarca, electro.idMarca, marcas, TAMM);
	printf("  %d  %d   %d   %20s\n", electro.id, electro.serie, electro.fFabricacion.year, descripMarca);


}


int printElectros(Electrodomestico* electro, int len, Marca* marcas, int lenM)
{
	int retorno =-1;
	int i;
	printf("***** Lista de electrodomesticos *****\n");
	printf("   Id      Serie    ID de Marca     Fecha de fabricacion  Sector\n\n");
	if(electro!=NULL && TAM >=0)
	    {
		for(i=0; i<TAM; i++)
		    {
		        if(electro[i].isEmpty == 0)
		        {
		            printElectro(electro[i], marcas, TAMM);

		        }
		    }
		retorno=0;
	}


	return retorno;
}
int findElectroById(Electrodomestico* electro, int len, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(electro!= NULL && TAM >=0)
	    {
	        for(i=0;i<TAM;i++)
	        {
	            if(electro[i].isEmpty==1)
	                continue;
	            else if(electro[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
void printMarca(Marca marcas, int tamM)
{
    printf("  %d %20s  \n", marcas.idMarca, marcas.descripcionMarca);
}
void printMarcas(Marca* marcas, int tamM)
{
    printf("\n***** electroa de marcas *****\n");
    printf("   Id      Marcas\n\n");

    for(int i=0; i<TAMM; i++)
    {
        printMarca(marcas[i],TAMM);
    }
}
int addElectro(Electrodomestico* electro, int len)
{
	int retorno=-1;
	// o ok -1 error
	int position;

	if(electro!= NULL && TAM > 0)
	{
		if(searchForSpace(electro,TAM,&position)==-1)
		{
			printf("No hay lugares disponibles\n");

		}
		else
		{
			getUnsignedInt("Ingrese numero de id\n","Error, vuelva a ingresar el numero",0,TAM,0,TAM,1,&electro[position].id);
			getUnsignedInt("Ingrese numero de serie\n","Error, vuelva a ingresar el numero",0,TAM,0,TAM,1,&electro[position].serie);
			getUnsignedInt("Ingrese numero de marca correspondiente: \n1-Whirpool\n 2-Sony\n 3-Liliana\n 4-Gafa\n 5-Philips\n\n","Error, vuelva a ingresar el numero",1,5,1,5,1,&electro[position].idMarca);
		    getUnsignedInt("Ingrese año de fabricacion\n","Error, vuelva a ingresar el numero",2000,2020,2000,2020,1,&electro[position].fFabricacion.year);
		    electro[position].isEmpty=0;
			retorno=0;
		}
	}
	return retorno;
}
int removeElectro(Electrodomestico* electro, int len,Marca* marcas)
{
	int retorno =-1;
	//-1 if error 0 if ok

	int position;
	int auxId;
    if(electro!=NULL && TAM>0)
	    {
	       printElectro(*electro, marcas,TAMM);
	    	getSignedInt("ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",1,TAM,1,TAM,1, &auxId);
	        if(findElectroById(electro, TAM,auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	            electro[position].isEmpty=1;
	            retorno=0;
	        }
	    }
	return retorno;
}
int modifyElectro(Electrodomestico* electro, int len)
{
	int retorno=-1;
	    int position;
	    int auxId;
	    int optionModify;
	    char continuar='s';

	    if(electro!=NULL && TAM>0)
	    {

	    	getSignedInt("ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",0,TAM,0,TAM,1, &auxId);
	    		        if(findElectroById(electro, TAM, auxId, &position)==-1)
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {

	            do
	            {
	            	 printf("ID: %d\n Id Marca: %5d\n Serie: %d\n Fecha de fabricacion: %4d\n ",electro[position].id, electro[position].idMarca,electro[position].serie,electro[position].fFabricacion.year);
	                getSignedInt("Modificar: 1 2 3(Salir)\n","Error.Ingrese opcion entre 1 y 3\n",1, 3, 1, 3, 1,&optionModify);
	                switch(optionModify)
	                {
	                    case 1:
	                    	getSignedInt("Ingrese nuevo numero de serie entre 1 y 3000\n","Error\n",1, 3000, 1, 3000, 1,&electro[position].serie);
	                        break;
	                    case 2:
	                    	getSignedInt("Ingrese nuevo año de modelo entre 2000 y 2020\n","Error\n",2000,2020,2000,2020, 1,&electro[position].fFabricacion.year);
	                        break;
	                    case 3:
	                    	printf("Usted ha seleccionado salir del menu");
	                    	break;
	                    default:
	                        printf("Opcion no valida\n");
	                }
	            }while(continuar!='s');
	            retorno=0;
	        }

	    }
	    return retorno;
}
void sortElectro(Electrodomestico* electro, int len)
{


	//return -1 error 0 ok

	int i;
	int j;


	Electrodomestico auxElectro;

				if(TAM > 0 && electro != NULL)

					{
					for( i=0; i<TAM - 1; i++)
					{
				for( j=i+1; j<len; j++)
					{
				if(electro[j].fFabricacion.year < electro[i].fFabricacion.year)
					{
					auxElectro = electro[i];
					electro[i] = electro[j];
					electro[j] = auxElectro;
					}
					else if(electro[j].fFabricacion.year == electro[i].fFabricacion.year && electro[j].serie == electro[i].serie)
					{
					auxElectro = electro[i];
					electro[i] = electro[j];
					electro[j] = auxElectro;
					}
						 }
					 }

					}




}
