/*
 * censista.h
 *
 *  Created on: 21 may. 2022
 *      Author: knofl
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct
{
	int legajoCensista;
	char nombre[20];
	int edad;
	char telefono[10];//xxxx-xxxx
	int isEmpty;
}eCensista;

#endif /* CENSISTA_H_ */

#include "vivienda.h"

/** \brief hardcodea la lista de censistas,recibe la cantidad requerida
 *
 * \param eCensista*list       array de censistas
 * \param len int   largo del array
 * \param cant int  cantidad requerida
 * \param int*pId   puntero al id del censista autoincremental
 * \return int retorno 1=ok, 0=error
 *
 */
int hardcodearCensista(eCensista*list, int len, int cant, int*pId);

/** \brief recibe un id y busca una coincidencia con el id de un censista existente en el sistema
 *
 * \param list eCensista*   array censistas
 * \param len int   largo del array
 * \param id int    id que se busca coincidencia
 * \return int retorna el indice del array de censistas si hubo coincidencia, -1 si no existe
 *
 */
int encontrarCensistaLegajo(eCensista* list, int len,int id);

/** \brief muetra el array de censistas
 *
 * \param eCensista*list    array de censistas
 * \param len int   largo del array
 * \return int retorno 1=ok, 0=error
 *
 */
int mostrarCensistas(eCensista*list,int len);

void mostrarCensistasCompleto(eVivienda *vivienda,int lenV, eTipoVivienda*lista,int lenT,eCensista*censistas,int lenC);
