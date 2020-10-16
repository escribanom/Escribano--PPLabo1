/*
 * servicio.c
 *
 *  Created on: 15 oct. 2020
 *
 */
#define TAMR 4
#define TAMM 5
#define TAM 6
#define TAMS 4
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "servicio.h"
#include "electro.h"
#include "utn.h"
void printRep(Reparacion fix, Servicio* lista, int tamS)
{
    char descripServicio[20];

    descripcionServicio(descripServicio, fix.idServicio, lista, TAMS);

    printf("  %d  %d   %d   %2d/%2d/%4d %20s\n", fix.id,fix.idServicio, fix.serie, fix.fRepar.day,fix.fRepar.month,fix.fRepar.year, descripServicio);
}

void printReps(Reparacion* fix, int len, Servicio* lista)
{
    int flag = 0;
    printf("***** Lista de reparaciones *****\n");
    printf("   Id      Serie    ID de Servicio     Fecha de reparacion    Descripcion  \n\n");

    for(int i=0; i<TAMR; i++)
    {
        if(fix[i].isEmpty == 0)
        {
            printRep(fix[i], lista, TAMR);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("*** No hay reparaciones que listar ***\n");
    }
}
int initRepa(Reparacion* fix, int len)
{
	int retorno =-1;
	//retorna 0 if ok
	int i=0;
	if(fix!=NULL && TAM > 0)
	{
		for(i=0;i<TAM;i++){
			fix[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int searchForSpaceRep(Reparacion* fix, int len, int* position)
{
	int retorno=-1;
	int i =0;
	if(fix!=NULL && TAMR >=0 && position!=NULL)
	{
		for(i=0;i<TAM;i++)
		{
			if(fix[i].isEmpty==1)
			{
				retorno=0;
				*position=i;
			}
		}
	}
	return retorno;
}
int addRep(Reparacion* fix,int* nextIdRep,Electrodomestico* electro, int tam,Marca* marcas, int lenM, Servicio* lista, int lenS)
{
	int retorno=-1;
	// o ok -1 error
	int position;
	int auxId;

	if(fix!= NULL && TAM > 0 && nextIdRep!= NULL)
	{
		if(searchForSpaceRep(fix,TAM,&position)==-1)
		{
			printf("No hay lugares disponibles\n");

		}
		else
		{
			(*nextIdRep)++;
			fix->id = *nextIdRep;
			printElectros(electro,TAM, marcas, TAMM);

			getSignedInt("Ingrese ID de electrodomestico a reparar: \n","Error. Vuelva a ingresar ID\n",1,TAM,1,TAM,1, &auxId);
				        if(findElectroById(electro, TAM,auxId, &position)==-1)
				        {
				       	            printf("ID inexistente\n");
				       	        }
				       	        else
				       	        {
				       	           auxId=fix->serie;
				       	        }
			printServs(lista, TAMS);
			getUnsignedInt("Ingrese numero de servicio correspondiente: \n20001-Garantia\n 20002-Mantenimiento\n 20003-Repuestos\n 20004-Refaccion\n\n","Error",20001,20004,20001,20004,1,&fix[position].idServicio);




		    getUnsignedInt("Ingrese dia de fabricacion\n","Error",1,31,1,31,1,&fix[position].fRepar.day);
		    getUnsignedInt("Ingrese mes de fabricacion\n","Error",1,12,1,12,1,&fix[position].fRepar.month);
		    getUnsignedInt("Ingrese año de fabricacion\n","Error",2000,2020,2000,2020,1,&fix[position].fRepar.year);
		    fix[position].isEmpty=0;
			retorno=0;
		}
	}
	return retorno;
}
int descripcionServicio(char description[], int id, Servicio* lista, int tamS)
{
    int todoOk = 0;

    for(int i=0; i<TAMS; i++)
    {
        if(lista[i].idServicio == id)
        {
            strcpy(description, lista[i].descripcionServ);
            todoOk = 1;
        }
    }
    return todoOk;
}
void printServ(Servicio lista, int tamS)
{
    printf("  %d %20s  \n", lista.idServicio, lista.descripcionServ);
}
void printServs(Servicio* lista, int tamS)
{
    printf("\n***** Lista de Servicios *****\n");
    printf("   Id      Servicios\n\n");

    for(int i=0; i<TAMS; i++)
    {
        printServ(lista[i],TAMS);
    }
}
int findRepById(Reparacion* fix, int len, int valor, int* position)
{
	int retorno = -1;
	int i;
	if(fix!= NULL && TAM >=0)
	    {
	        for(i=0;i<TAM;i++)
	        {
	            if(fix[i].isEmpty==1)
	                continue;
	            else if(fix[i].id==valor)
	            {
	                retorno=0;
	                *position=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}
int removeRep(Reparacion* fix, int len,Servicio* lista)
{
	int retorno =-1;
	//-1 if error 0 if ok

	int position;
	int auxId;
    if(fix!=NULL && TAMR>0)
	    {
	       printReps(fix,TAMR,lista);
	    	getSignedInt("ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",1,TAMR,1,TAMR,1, &auxId);
	        if(findRepById(fix, TAMR,auxId, &position)==-1)
	        {
	            printf("ID inexistente\n");
	        }
	        else
	        {
	            fix[position].isEmpty=1;
	            retorno=0;
	        }
	    }
	return retorno;
}
int modifyRep(Reparacion* fix, int len)
{
	int retorno=-1;
	    int position;
	    int auxId;
	    int optionModify;
	    char continuar='s';

	    if(fix!=NULL && TAMR>0)
	    {

	    	getSignedInt("ID a dar de baja: \n","Error. Vuelva a ingresar ID\n",1,TAMR,1,TAMR,1, &auxId);
	    		        if(findRepById(fix, TAMR, auxId, &position)==-1)
	    		        {
	    		            printf("ID inexistente\n");
	    		        }
	    		        else
	    		        {

	            do
	            {
	            	 printf("ID: %d\n Id Servicio: %5d\n Serie: %d\n Fecha de fabricacion %2d/%2d/%4d\n ",fix[position].id, fix[position].idServicio,fix[position].serie, fix[position].fRepar.day, fix[position].fRepar.month, fix[position].fRepar.year);
	                getSignedInt("Modificar: 1 2 3 4 5(Salir)\n","Error.Ingrese opcion entre 1 y 5\n",1, 1, 1, 5, 1,&optionModify);
	                switch(optionModify)
	                {
	                    case 1:
	                    	//getName("Ingrese nuevo nombre: \n","Error. Ingrese nuevo nombre\n",1,TEXT_SIZE,1,list[position].name);
	                        break;
	                    case 2:
	                    	//getName("Ingrese nuevo apellido: \n","Error. Ingrese nuevo apellido\n", 1, TEXT_SIZE, 1, list[position].lastName);
	                        break;
	                    case 3:
	                    	//getFloat("Ingrese nuevo salario: \n","Error. Ingrese nuevo salario\n", 1, 6, 1,999999, 1, &list[position].salary);
	                        break;
	                    case 4:
	                    	//getSignedInt("ingrese nuevo sector\n","Error, ingrese sector entre 1 y 3\n",1, 1,1, 3, 1, &list[position].sector);
	                        break;
	                    case 5:

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

