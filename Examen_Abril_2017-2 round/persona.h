#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct
{
	char* nombre;//ARRAY DE CARACTERES = PUNTERO
	int edad;
} Persona;

void imprimirPersona(Persona p);

#endif /* PERSONA_H_ */
