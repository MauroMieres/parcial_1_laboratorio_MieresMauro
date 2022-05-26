/*
 * censista.c
 *
 *  Created on: 21 may. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "censista.h"
#include <string.h>

//Censista ({100, Ana, 34, 1203-2345}, {101, Juan, 24, 4301-54678}, {102, Sol, 47, 5902-37487}

/*int legajoCensista;
	char nombre[20];
	int edad;
	char telefono;//xxxx-xxxx*/

char nombres[5][20]=
{
		"Ana","Juan","Sol","Diego","Valeria"
};

int edades[5]=
{
	34,24,47,55,18
};

char telefonos [5][10]=
{
		"1203-2345","4301-5468","5902-3748","4355-5677","4345-7889"
};

int hardcodearCensista(eCensista*list, int len, int cant, int*pId)
{
	int contador = -1;
	if (list != NULL && len > 0 && cant >= 0 && cant <= len && pId != NULL)
	{
		contador = 0;
		for (int i = 0; i < cant;  i++)
		{
			((*(list+i)).legajoCensista)=*pId;
			(*pId)++;
			strcpy((*(list+i)).nombre,(*(nombres+i)));
			(*(list+i)).edad=(*(edades+i));
			strcpy((*(list+i)).telefono,(*(telefonos+i)));
			contador++;
		}
	}
	return contador;
}

int encontrarCensistaLegajo(eCensista* list, int len,int id)
{
	int indice = -1;
	for (int i = 0; i < len; i++)
	{
		if ((*(list+i)).legajoCensista == id)
		{
			indice = i;
			break;
		}
	}
	    return indice;
}

int mostrarCensistas(eCensista*list,int len)
{
	int ok=0;
	if(list!=NULL&&len>0)
	{
		printf("            ***Lista de censistas***\n");
		printf("Legajo Nombre                       Edad Telefono\n");
		for(int i=0;i<len;i++)
		{
			printf("%d    %-25s     %-2d  %9s\n",(*(list+i)).legajoCensista,(*(list+i)).nombre,(*(list+i)).edad,(*(list+i)).telefono);
		}
		ok=1;
	}
	return ok;
}

void mostrarCensistasCompleto(eVivienda *vivienda,int lenV, eTipoVivienda*lista,int lenT,eCensista*censistas,int lenC)
{
	if(vivienda!=NULL&&lenV>0&&lista!=NULL&&lenT>0&&censistas!=NULL&&lenC>0)
	{
			for(int i=0;i<lenT;i++)
			{
				printf("\n");
				printf("Legajo Nombre                       Edad Telefono\n");
				printf("%d    %-25s     %-2d  %9s\n",(*(censistas+i)).legajoCensista,(*(censistas+i)).nombre,(*(censistas+i)).edad,(*(censistas+i)).telefono);
				 printf("   ID   Calle                        Cantidad de Personas     Cantidad de Habitaciones      Tipo de Vivienda      Legajo Censista\n");
				for(int j=0;j<lenT;j++)
				{

					if(!(*(vivienda+j)).isEmpty && (*(vivienda+j)).legajoCensista == (*(censistas+i)).legajoCensista)
					{



						mostrarVivienda((*(vivienda+j)), lista, lenT);
					}
				}
			}
		}
}

void censistaMasCensos(eCensista*lista,int lenC,eVivienda*list,int lenV)
{
	int legajoMasCensos;
	int masCensos=0;
	int contador=0;
	int flag=0;
	if(lista!=NULL&&lenC>0)
	{
		for(int i=0;i<lenC;i++)
		{
			for(int j=0;j>lenC;j++)
			{
				if(!(*(list+j)).isEmpty && (*(list+j)).legajoCensista == (*(lista+i)).legajoCensista)
				{
					contador++;
				}
				if(flag==0&&contador>masCensos)
				{
				 legajoMasCensos = (*(lista+i)).legajoCensista;
				}
			}
			contador=0;
		}
	}

	printf("%d legao mas censos: ",legajoMasCensos);
}

