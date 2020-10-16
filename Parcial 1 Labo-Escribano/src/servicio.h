/*
 * servicio.h
 *
 *  Created on: 15 oct. 2020
 *
*/
#include "electro.h"
#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct{
	int id;//autoincremental
	int serie;
	int idServicio;
	Fecha fRepar;
	int isEmpty;
}Reparacion;
typedef struct{
	int idServicio;//arranca 20k
	char descripcionServ[25];
	int precio;
	int isEmpty;
}Servicio;

#endif /* SERVICIO_H_ */
int initRepa(Reparacion* fix, int len);
int searchForSpaceRep(Reparacion* fix, int len, int* position);
int addRep(Reparacion* fix,int* nextIdRep,Electrodomestico* electro, int tam,Marca* marcas, int lenM, Servicio* lista, int lenS);
int descripcionServicio(char description[], int id, Servicio* lista, int tamS);
void printServ(Servicio lista, int tamS);
void printServs(Servicio* lista, int tamS);
int findRepById(Reparacion* fix, int len, int valor, int* position);
int removeRep(Reparacion* fix, int len,Servicio* lista);
int modifyRep(Reparacion* fix, int len);
void printRep(Reparacion fix, Servicio* lista, int tamS);
void printReps(Reparacion* fix, int len, Servicio* lista);
