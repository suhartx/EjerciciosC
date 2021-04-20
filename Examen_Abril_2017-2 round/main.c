#include "persona.h"
#include "censo.h"
#include <stdio.h>
#include <stdlib.h>

void crearInforme(GrupoPersonas gp, char* fichero);

int main(void)
{
	Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	fflush(stdin);
	imprimirPersona(personas[0]);
	fflush(stdout);
	fflush(stdin);
	printf("\n %i", cuantasPersonas(personas, 5, 50));
	fflush(stdout);
	fflush(stdin);
	GrupoPersonas jovenes = recuperarJovenes(personas, 5, 50);
	printf("\n %.2f", jovenes.mediaEdad);
	fflush(stdout);
	fflush(stdin);
	printf("\n Yogurin:\n");
	fflush(stdout);
	fflush(stdin);
	imprimirPersona(*recuperarYogurin(personas, 5));
	fflush(stdout);
	crearInforme(recuperarJovenes(personas, 5, 50), "reporte.txt");
	fflush(stdin);
	printf("\ncantidad de personas con inicial A: %i\n", cuantosNombres(personas, 5, 'A'));
	fflush(stdout);
	char** pertsonak = listadoNombres(personas, 5, 'A');
	fflush(stdin);
	printf("\nListado de personas con la inicial a A:\n");
	fflush(stdout);
	for (int i = 0; i < cuantosNombres(personas, 5, 'A'); ++i) {
		fflush(stdin);
		printf("%s\n", pertsonak[i]);//ES UN PUNTERO A PUNTERO ASI QUE INDICAMOS LA DIRECION DE LA PRIMERA POSICION DEL ARRAY DE CHARS
		fflush(stdout);	}

	free(pertsonak);//LIBERAMOS LOS DATOS DE LA MEMORIA DINAMICA
	pertsonak = NULL;
	free(jovenes.personas);
	jovenes.personas=NULL;
	return 0;

}


void crearInforme(GrupoPersonas gp, char* fichero){

	FILE* f;//VARIABLE CON PUNTERO DONDE SE INICIALIZA EL FICHERO
	f = fopen(fichero, "w");//W = SOBREESCRIBIR

	fprintf(f,"%p\n",&f);//DIRECCION DEL PUNTERO DONDE SE INDICA EL FICHERO

	fprintf(f, "CENSO DE JOVENES");//ESCRITURA EN EL FICHERO
	fprintf(f, "\n----------------\n");

	int i = 0;
	while(i<gp.tamanyo){
		fprintf(f, "[Nobre:%s, Edad: %i]\n", gp.personas[i].nombre,gp.personas[i].edad);
		i++;
	}
	fclose(f);


}
