/*
 * menus.c
 *
 *  Created on: 21 may. 2022
 *      Author: knofl
 */
#include "menus.h"
#include <ctype.h>

char menuOpciones()
{
	char option;

	printf("MENU ABM CENSO\n\n");
	printf("A. ALTA VIVENDA\n");
	printf("B. MODIFICAR VIVIENDA\n");
	printf("C. BAJA VIVIENDA\n");
	printf("D. LISTAR VIVENDAS\n");
	printf("E. LISTAR CENSISTAS\n");
	printf("F. Salir\n ");
	printf("G. Listado de todos los datos de cada Censista con todos los datos de las viviendas censadas\n");
	fflush(stdin);
	scanf("%c",&option);
	option = toupper(option);

	return option;
}
