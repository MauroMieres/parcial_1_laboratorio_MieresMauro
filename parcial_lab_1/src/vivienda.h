/*
 * vivienda.h
 *
 *  Created on: 21 may. 2022
 *      Author: knofl
 */

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

typedef struct
{
	int idVivienda;//arranca en 20000
	char calle [25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
	char tipoViviendaDescripcion[20];
	int legajoCensista;
	int isEmpty;
}eVivienda;

typedef struct
{
	int idTipoVivienda;
	char descripcion[20];
}eTipoVivienda;

#endif /* VIVIENDA_H_ */

/** \brief carga el campo isEmpty de las viviendas con un 1
 *
 * \param list eVivienda* array de viviendas
 * \param len int  largo del array
 * \return int retorno 1=ok, 0=error
 *
 */
int inicializarViviendas(eVivienda* list, int len);

/** \brief agrega una vivienda al array
 *
 * \param list eVivienda*   array de viviendas
 * \param len int   largo del array vivienda
 * \param int*id    puntero del id de la vivienda
 * \param eCensista*lista   array censistas
 * \param lenC int  largo array censistas
 * \return int  retorno 1=ok, 0=error
 *
 */
int agregarVivienda(eVivienda* list, int len, int*id,eCensista*lista,int lenC);

/** \brief recibe un array de viviendas y luego llama a otra funcion para mostrarlas de a una
 *
 * \param list eVivienda*   array de viviendas
 * \param len int   largo array de viviendas
 * \param eTipoVivienda*lista   array tipo de vivienda
 * \param lenT int  largo array tipo de vivienda
 * \return int retorno 1=ok, 0=error
 *
 */
int mostrarViviendas(eVivienda* list,int len,eTipoVivienda*lista,int lenT);

/** \brief muetra una vivienda
 *
 * \param vivienda eVivienda    vivienda en una posicion del array
 * \param eTipoVivienda*lista   array tipo vivienda
 * \param lenT int  largo array tipo vivienda
 * \return void
 *
 */
void mostrarVivienda(eVivienda vivienda,eTipoVivienda*lista,int lenT);

/** \brief carga el char*descripcion con el tipovivienda descripcion, cuando encuentra una coincidencia entre el id y la estructura eTipoVivienda
 *
 * \param eTipoVivienda*lista   array tipos de vivienda
 * \param lenT int  largo array tipos de vivienda
 * \param idTipoVivienda int   el id que se busca coincidencia
 * \param char*descripcion
 * \return int retorno 1=ok, 0=error
 *
 */
int cargarTipoViviendaDescripcion(eTipoVivienda*lista, int lenT,int idTipoVivienda, char*descripcion);

/** \brief permite modificar los datos de una vivienda cargada
 *
 * \param eVivienda*list    array de viviendas
 * \param len int   largo array de viviendas
 * \param eTipoVivienda*lista   array de tipo de vivienda
 * \param lenT int  largo del array de tipo de vivienda
 * \return int  retorno 1=ok, 0=error
 *
 */
int modificarVivienda(eVivienda*list, int len,eTipoVivienda*lista,int lenT);

/** \brief recibe el array de viviendas, largo y un id, busca una coincidencia del id recibido con algun id de una vivienda existente
 *
 * \param list eVivienda*   array de viviendas
 * \param len int   largo array
 * \param id int    id recibido
 * \return int  retorna el indice del array de donde encuentra la coincidencia, devuelve -1 si no existe
 *
 */
int encontrarViviendaId(eVivienda* list, int len,int id);

/** \brief menu de modificar vivienda, recibe la posicion de una vivienda del array, la printea y nos muestra opciones de modificacion
 *
 * \param vivienda eVivienda   posicion de una vivienda del array
 * \param eTipoVivienda*lista   array de tipo de vivienda
 * \param lenT int  largo del array de tipo vivienda
 * \return int  el retorno es una opcion del menu
 *
 */
int modificarViviendaMenu(eVivienda vivienda,eTipoVivienda*lista,int lenT);

/** \brief baja logica de una vivienda cargada en el sistema
 *
 * \param list eVivienda*   array de viviendas
 * \param len int   largo array de viviendas
 * \param eTipoVivienda*lista   array de tipo vivienda
 * \param lenT int  largo array de tipo vivienda
 * \param int*contadorViviendas  puntero al contador de viviendas
 * \return int retorno 1=ok, 0=error
 *
 */
int removerVivienda(eVivienda* list, int len,eTipoVivienda*lista,int lenT,int*contadorViviendas);

/** \brief hardcodea las viviendas
 *
 * \param eVivienda*list    array de viviendas
 * \param len int   largo del array
 * \param cant int  cantidad   de viviendas que se quieren hardcodear
 * \param int*pId   puntero del idVivienda autoincremental
 * \param int*contadorViviendas puntero del contador de viviendas cargadas
 * \return int  retorno 1=ok, 0=error
 *
 */
int hardcodearViviendas(eVivienda*list, int len, int cant, int*pId,int*contadorViviendas);

/** \brief ordena las viviendas segun el criterio recibido
 *
 * \param list eVivienda*   array de   viviendas
 * \param len int largo del array de viviendas
 * \param order int criterio de ordenamiento
 * \param eTipoVivienda*lista   array de tipo de viviendas
 * \param lentT int largo del array de tipo de viviendas
 * \return int retorno 1=ok, 0=error
 *
 */
int ordenarViviendas(eVivienda* list, int len, int order,eTipoVivienda*lista,int lentT);
