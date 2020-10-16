/*
 * utn.h
 *
 *  Created on:
 *      Author:
 */

#ifndef UTN_H_
#define UTN_H_

int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado);

int getName(char* msg,char* msgError,int min,int max,int reintentos,char* resultado);
int isValidName(char* stringRecibido);

int getUnsignedInt(  char* msg,char* msgError,int minSize,int maxSize,int min,int max,int reintentos,int* input);
int isValidNumber(char* stringRecibido);

int getSignedInt(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, int* input);
int isValidSignedNumber(char* stringRecibido);

int getFloat(char* msg, char* msgError, int minSize, int maxSize, int min, int max, int reintentos, float* input);
int isValidFloatNumber(char* stringRecibido);


#endif /* UTN_H_ */
