/*
 * censo.c
 *
 *  Created on: 14 abr. 2021
 *      Author: Suhar
 */
#include "persona.h"
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cuantasPersonas(Persona* ap, int tamanyo, int edad){
	//CUANTAS PERSONAS MENORES DE LA EDAD INDICADA EXISTEN
	int contador=0;

	for (int i = 0; i < tamanyo; ++i) {
		if (ap[i].edad<edad) {
		contador++;
		}
	}
	return contador;
}

GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo, int edad){
	//DEVUELVE MENORES DE 30 AÑOS EN FORMATO GRUPOPERSONAS
	int contador = 0;
	float edadMedia = 0;
	GrupoPersonas gp;
	gp.tamanyo= cuantasPersonas(ap, tamanyo, edad);//DETERMINAMOS EL TAMAÑO DEL ARRAY DENTRO DE LA ESTRUCTURA CON LA FUNCIÓN YA CREADA

	gp.personas = (Persona*)malloc(sizeof(Persona)*gp.tamanyo);//CON ESE TAMAÑO INDICAMOS EL ESPACIO QUE VA A OCUPAR EN MEMORIA DICHO ARRAY DENTRO DE LA ESTRUCTURA

	for (int i = 0; i < tamanyo; ++i) {
		if (ap[i].edad<edad) {
			gp.personas[contador]=ap[i];
			contador++;
			edadMedia += ap[i].edad;
		}
	}

	gp.mediaEdad = (float)edadMedia/contador;
	gp.tamanyo=contador;
	return gp;
}

Persona* recuperarYogurin(Persona* ap, int tamanyo){
	//DEVUELVE LA PERSONA DE MENOR EDAD
	int edadMinima=ap[0].edad;
	int posYogurin=0;

	for (int i = 0; i < tamanyo; ++i) {
		if (ap[i].edad<edadMinima) {
		posYogurin= i;
		}
	}
	return &ap[posYogurin];//COMO PARAMETRO INTRODUCTORIO HAY UN PUNTERO A PERSONA DEVOLVEREMOS LA DIRECCION

}

int cuantosNombres(Persona* ap, int tamanyo, char letra){//METODO QUE DEVUELVE EL NUMERO DE PERSONAS QUE HAY CON LA LETRA INDICADA

	int cantidadPersonas=0;

	for (int i = 0; i < tamanyo; ++i) {
		if (ap[i].nombre[0]==letra) {
			cantidadPersonas++;
		}
	}
	return cantidadPersonas;
}

char** listadoNombres(Persona* ap, int tamanyo, char letra){

	int cantidadPersonas=cuantosNombres(ap, tamanyo, letra);
	char** listado = (char**)malloc(sizeof(char*)*cantidadPersonas);
	int contador =0;


	for (int i = 0; i < tamanyo; ++i) {

		if (ap[i].nombre[0]==letra) {
			listado[contador]=(char*)malloc(sizeof(char)*strlen(ap[i].nombre)+1);
			listado[contador]=ap[i].nombre;//CONTIENE LA DIRECCION DEL NOMBRE ORIGINAL
			contador++;
		}
	}
	return listado;
}

