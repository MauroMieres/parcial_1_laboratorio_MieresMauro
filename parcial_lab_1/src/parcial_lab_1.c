/*
 ============================================================================
 Name        : parcial_lab_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "censista.h"
#include "vivienda.h"
#define TAM_CENSISTAS 5
#define TAM_VIVIENDAS 100
#define TAM_TIPOVIVIENDAS 4

int main(void) {
	setbuf(stdout, NULL);
	char salir;
	int contadorViviendas=0;
	eCensista listaCensistas[TAM_CENSISTAS];
	eVivienda listaViviendas[TAM_VIVIENDAS];
	eTipoVivienda listaTipoVivienda[TAM_TIPOVIVIENDAS]=
	{
			{ 1, "CASA"},
			{ 2, "DEPARTAMENTO"},
			{ 3, "CASILLA"},
			{ 4, "RANCHO"}
	};
	int legajoCensista=100;
	int idVivienda=20000;
	inicializarViviendas(listaViviendas, TAM_VIVIENDAS);
	hardcodearCensista(listaCensistas,TAM_CENSISTAS,5,&legajoCensista);
	hardcodearViviendas(listaViviendas,TAM_VIVIENDAS,5,&idVivienda,&contadorViviendas);

	do
	{

		switch(menuOpciones())
		{
		case 'A':
			if(!agregarVivienda(listaViviendas, TAM_VIVIENDAS, &idVivienda, listaCensistas, TAM_CENSISTAS))
			{
				printf("Error en la funcion agregarVivienda\n");
			}
			contadorViviendas++;
			break;

		case 'B':
			if(contadorViviendas==0)
			{
				printf("No se pueden modificar viviendas porque no hay ninguna cargada\n");
			}
			else
			{
				if(!modificarVivienda(listaViviendas, TAM_VIVIENDAS, listaTipoVivienda, TAM_TIPOVIVIENDAS))
				{
					printf("Error en la funcion modificarVivienda\n");
				}
			}
			break;

		case 'C':
			if(contadorViviendas==0)
			{
				printf("No se pueden dar de baja viviendas porque no hay ninguna cargada\n");
			}
			else
			{
				if(!removerVivienda(listaViviendas, TAM_VIVIENDAS, listaTipoVivienda, TAM_TIPOVIVIENDAS,&contadorViviendas))
				{
					printf("Error en la funcion removerVivienda\n");
				}
			}
			break;

		case 'D':
			if(contadorViviendas==0)
			{
				printf("No se pueden mostrar viviendas porque no hay ninguna cargada\n");
			}
			else
			{
				if(!ordenarViviendas(listaViviendas, TAM_VIVIENDAS, 1, listaTipoVivienda, TAM_TIPOVIVIENDAS))
				{
					printf("Error en la funcion ordenarViviendas\n");
				}
				else
				{
					if(!mostrarViviendas(listaViviendas, TAM_VIVIENDAS, listaTipoVivienda, TAM_TIPOVIVIENDAS))
					{
						printf("Error en la funcion mostrarViviendas\n");
					}
				}
			}
			break;

		case 'E':
			if(!mostrarCensistas(listaCensistas, TAM_CENSISTAS))
			{
				printf("Error en la funcion mostrarCensistas\n");
			}
			break;

		case 'F':
			salir='F';
			break;

		case 'G':
			mostrarCensistasCompleto(listaViviendas, TAM_VIVIENDAS, listaTipoVivienda, TAM_TIPOVIVIENDAS, listaCensistas, TAM_CENSISTAS);
			break;

		case 'H':
			break;
		default:
			printf("Opcion ingresada invalida\n");
		}
	}while(salir!='F');

	return EXIT_SUCCESS;
}
