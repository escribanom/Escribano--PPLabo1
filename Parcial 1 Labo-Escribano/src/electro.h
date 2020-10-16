/*
 * electro.h
 *
 *  Created on: 14 oct. 2020
 *
 */

#ifndef ELECTRO_H_
#define ELECTRO_H_


typedef struct{
	int day;
	int month;
	int year;
}Fecha;
typedef struct{
	int idMarca;//arranca en 1k
	char descripcionMarca[20];
}Marca;


typedef struct{
	int id;
	int serie;
	int idMarca;
	int isEmpty;
	Fecha fFabricacion;
}Electrodomestico;
#endif /* ELECTRO_H_ */
int initElectro(Electrodomestico* electro, int len);
int searchForSpace(Electrodomestico* electro, int len, int* position);
int descripcionMarca(char description[], int id, Marca* marcas, int tamM);
void printElectro(Electrodomestico electro, Marca* marcas, int lenM);
int printElectros(Electrodomestico* electro, int len, Marca* marcas, int lenM);
int findElectroById(Electrodomestico* electro, int len, int valor, int* position);
void printMarca(Marca marcas, int tamM);
void printMarcas(Marca* marcas, int tamM);
int addElectro(Electrodomestico* electro, int len);
int removeElectro(Electrodomestico* electro, int len,Marca* marcas);
int modifyElectro(Electrodomestico* electro, int len);
void sortElectro(Electrodomestico* electro, int len);
