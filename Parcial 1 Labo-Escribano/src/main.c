/*
 ============================================================================
 Name        : main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
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
#include "servicio.h"
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);


	Electrodomestico electro[TAM];
	initElectro(electro,TAM);
	Reparacion fix[TAMR];
	initRepa(fix,TAMR);

	Marca marcas[TAMM] =
			{
			        {1000, "Whirpool"},
			        {1001, "Sony"},
			        {1002, "Liliana"},
			        {1003, "Gafa"},
			        {1004, "Philips"}
			};
	Servicio lista[]=
				{
						{20001, "Garantia",250,1},
						{20002, "Mantenimiento",500,1},
						{20003, "Repuestos",400,1},
						{20004, "Refaccion",600,1},
				};
	char continuar = 's';
		int opcion;
		int flagNum1 = 0;
		int posAux;


		int nextIdRep=0;
		    do
		    {

		        printf("*****************************************\n");
		        printf("**** Bienvenido al menu de empleados ****\n");
		        printf("*********** Menu de opciones ************\n");
		        printf("*****************************************\n");
		        printf("1- Alta de Electrodomestico\n");
		        printf("2- Modificar Electrodomestico\n");
		        printf("3- Baja de Electrodomestico\n");
		        printf("4- Listar Electrodomesticos\n");
		        printf("5- Listar Marcas\n");
		        printf("6- Listar Servicios\n");
		        printf("7- Alta de Reparacion\n");
		        printf("8- Listar Reparaciones\n");
		        printf("9- Salir\n\n");
		        printf("Indique opcion: ");
		        scanf("%d", &opcion);
		        switch(opcion)
		        {
		        case 1:
		        	//id calcu auto el resto usuario
		        	if(searchForSpace(electro, TAM, &posAux)==1)
		        	{
		        		printf("No hay lugar disponible");
		        	}
		        	else
		        	{

		        		addElectro(electro, TAM);
		        	   flagNum1 = 1;
		        	}

		            break;
		        case 2://moidf electro
		        	if(flagNum1 ==1)
		        	{

		        		modifyElectro(electro,TAM);
		        		printElectros(electro,TAM,marcas,TAMM);
		        	}
		        	else
		        	{
		        		printf("Para modificar un electrodomestico primero debe INGRESARLO\n");
		        	}
		            break;
		        case 3://remov eelectro
		        	if((flagNum1 ==1) && (searchForSpace(electro, TAM, &posAux)==0))
		        	{

		        		removeElectro(electro,TAM,marcas);
		        		printElectros(electro,TAM,marcas,TAMM);
		        	}
		            else
		        	{
		            printf("Para eliminar un electrodomestico primero debe INGRESARLO");
		        	}

		            break;
		        case 4://listar electros
		        	if(flagNum1)
		        	{
		        		printElectros(electro,TAM,marcas,TAMM);//ordenar x modelo y serie
		        		sortElectro(electro, TAM);
		        		printElectros(electro,TAM,marcas,TAMM);
		        	}
		        	else
		        	{
		        	    printf("Para listar un electrodomestico primero debe INGRESARLO");
		        	}

		        	//needs case 1
		            break;
		        case 5://lkistar marcas

                    printMarcas(marcas, TAMM);

		        	break;
		        		        	//needs case 1
		        case 6://listar servicios c

		        	printServs(lista, TAMS);
		            break;
		        case 7://alta reparacion
		        	addRep(fix, &nextIdRep, electro, TAM,marcas, TAMM,lista,TAMS);
		        	printf("Ingrese n para salir");
		            break;
		        case 8://listar repa

		            printReps(fix,TAMR,lista);
		            break;
		        case 9://salir

		       		printf("Ingrese n para salir");
		       		break;

		        default:
		            printf("No es una opcion valida\n");
		        }
		        printf("Desea volver al menu? s/n : \n");
		        fflush(stdin);
		        scanf("%c", &continuar);
		       	    }
		    while(continuar =='s');
		    return opcion;


	return EXIT_SUCCESS;
}
void harcodearMarca(Marca* marcas)
{

	int i;
	  Marca listaMarcas[TAMM] =
		{
		        {1000, "Whirpool"},
		        {1001, "Sony"},
		        {1002, "Liliana"},
		        {1003, "Gafa"},
		        {1004, "Philips"}
		};
	  for(i=0;i<TAMS;i++)
		{
			marcas[i]= listaMarcas[i];
		}

}
void harcodearServicio(Servicio* lista)
{
	int i;
		  Servicio registro[]=
			{
					{20001, "Garantia",250,1},
					{20002, "Mantenimiento",500,1},
					{20003, "Repuestos",400,1},
					{20004, "Refaccion",600,1},
			};
		  for(i=0;i<TAMM;i++)
		  		{
		  		    lista[i]=registro[i];
		  		}
}
