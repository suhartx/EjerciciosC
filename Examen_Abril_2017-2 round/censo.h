/*
 * censo.h
 *
 *  Created on: 14 abr. 2021
 *      Author: Suhar
 */

#ifndef CENSO_H_
#define CENSO_H_
#include "persona.h"

typedef struct {

	Persona* personas;//AL HACER UN ARRAY INDICARLO SIEMPRE COMO PUNTERO

	int tamanyo;

	float mediaEdad;

}GrupoPersonas;

int cuantasPersonas(Persona* ap, int tamanyo, int edad);//CUANTAS PERSONAS MENORES DE LA EDAD INDICADA EXISTEN

GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo, int edad);//DEVUELVE MENORES DE 30 AÑOS

Persona* recuperarYogurin(Persona* ap, int tamanyo);//DEVUELVE LA PERSONA DE MENOR EDAD

int cuantosNombres(Persona* ap, int tamanyo, char letra);

char** listadoNombres(Persona* ap, int tamanyo, char letra);//DEVUELVE LISTADO DE CADENA DE CARACTERES

#endif /* CENSO_H_ */
