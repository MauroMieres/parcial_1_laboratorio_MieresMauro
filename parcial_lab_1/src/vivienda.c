/*
 * vivienda.c
 *
 *  Created on: 21 may. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "censista.h"
#include "vivienda.h"

int inicializarViviendas(eVivienda* list, int len)
{
	int todoOk = 0;
	    if (list != NULL && len > 0)
	    {
	        todoOk = 1;
	        for (int i = 0; i < len; i++)
	        {
	        	(*(list+i)).isEmpty = 1;
	        }
	    }
	    return todoOk;
}

int encontrarViviendaLibre(eVivienda* list,int len)
{
	int indice = -1;
	for (int i = 0; i < len; i++)
	{
		if ((*(list+i)).isEmpty)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int validarTipoVivienda(int num)
{
	int ok;
	if(num!=1&&num!=2&&num!=3&&num!=4)
	{
		printf("Error, ingrese una opcion correcta.\n");
		ok=0;
	}
	else
	{
		ok=1;
	}
	return ok;
}

int agregarVivienda(eVivienda* list, int len, int*id,eCensista*lista,int lenC)
{
	int todoOk = 0;
	int indice;
	eVivienda auxVivienda;
	if (list != NULL && len > 0)
	{
		printf("  ***Agregar vivienda*** \n\n");
		indice = encontrarViviendaLibre(list,len);
		if (indice == -1)
		{
			printf("No hay lugar\n");
		}
		else
		{
			auxVivienda.idVivienda = *id;
			(*id)++;

		   getString(auxVivienda.calle, "Ingrese calle: ", "Error, maximo 25 caracteres por calle",25);
		   toupperString(auxVivienda.calle);

		   getInt(&auxVivienda.cantidadPersonas, "Ingrese cantidad de personas: ", "Error, ingrese una cantidad valida:\n");

		   getInt(&auxVivienda.cantidadHabitaciones, "Ingrese cantidad de habitaciones: ", "Error, ingrese una cantidad valida:\n");

		   do
		   {
			   getInt(&auxVivienda.tipoVivienda,"Ingrese el tipo de vivienda: 1(CASA)/2(DEPARTAMENTO)/3(CASILLA)/4(RANCHO)","Error, ingrese un tipo de casa valido\n");
		   }while(!validarTipoVivienda(auxVivienda.tipoVivienda));

		   mostrarCensistas(lista,lenC);

		   do
		   {
			   getInt(&auxVivienda.legajoCensista,"Ingrese el legajo del censista: ","Error, ingrese un legajo valido: ");
		   }while(encontrarCensistaLegajo(lista,lenC,auxVivienda.legajoCensista)==-1);

		   auxVivienda.isEmpty = 0;

		   (*(list+indice)) = auxVivienda;
		todoOk = 1;
		}
	}
	return todoOk;
}

void mostrarVivienda(eVivienda vivienda,eTipoVivienda*lista,int lenT)
{
	char descripcion[12];
	cargarTipoViviendaDescripcion(lista, lenT,vivienda.tipoVivienda,descripcion);

	printf(" %-5d  %-25s    %-2d                       %-2d                            %-12s          %d \n",
	vivienda.idVivienda,
	vivienda.calle,
	vivienda.cantidadPersonas,
	vivienda.cantidadHabitaciones,
	descripcion,
	vivienda.legajoCensista
	);
}

int mostrarViviendas(eVivienda* list,int len,eTipoVivienda*lista,int lenT)
{
	 	int todoOk = 0;
	    int flag = 1;
	    if (list != NULL && len > 0&&lista!=NULL&&lenT>0)
	    {
	        printf("                                              ***Lista de viviendas ***\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	        printf("   ID   Calle                        Cantidad de Personas     Cantidad de Habitaciones      Tipo de Vivienda      Legajo Censista\n");
	        printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	        for (int i = 0; i < len; i++)
	        {
	            if (!(*(list+i)).isEmpty)
	            {
	            	mostrarVivienda((*(list+i)), lista, lenT);
	                flag = 0;
	            }
	        }
	        if (flag)
	        {
	            printf("No hay viviendas para mostrar.\n");
	        }
	        todoOk = 1;
	    }
	    printf("\n");
	    return todoOk;
}

int cargarTipoViviendaDescripcion(eTipoVivienda*lista, int lenT,int idTipoVivienda, char*descripcion)
{
    int todoOk = 0;
    int flag = 1;
    if (lista != NULL && lenT > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < lenT; i++)
        {
            if ((*(lista+i)).idTipoVivienda == idTipoVivienda)
            {
                strcpy(descripcion,(*(lista+i)).descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}

int encontrarViviendaId(eVivienda* list, int len,int id)
{
	int indice = -1;
	for (int i = 0; i < len; i++)
	{
		if ((*(list+i)).idVivienda == id && (*(list+i)).isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	    return indice;
}

int modificarVivienda(eVivienda*list, int len,eTipoVivienda*lista,int lenT)
{
	int ok=0;
	int indice;
	int id;
	char respuesta;
	char confirmar;

	eVivienda auxVivienda;

	if(list!=NULL && len>0)
	{
		printf("   ***Modificar vivienda***    \n\n");
		mostrarViviendas(list, len, lista, lenT);
		printf("Ingrese ID vivienda: ");
		scanf("%d",&id);

		indice = encontrarViviendaId(list, len,id);

		if(indice == -1)
		{
			 printf("El id vivienda: %d no esta registrado en el sistema\n", id);
		}
		else
		{
			do
			{
				switch(modificarViviendaMenu(list[indice],lista,lenT))
				{
				case 1:

				getString(auxVivienda.calle, "Ingrese calle: ", "Error, maximo 25 caracteres por calle",25);
				getCaracter(&confirmar, "Confirma cambio de calle? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				if (confirmar == 'S')
				{
					 toupperString(auxVivienda.calle);
					strcpy((*(list+indice)).calle,auxVivienda.calle);
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;

				case 2:
				getInt(&auxVivienda.cantidadPersonas, "Ingrese cantidad de personas: ", "Error, ingrese una cantidad valida:\n");
				getCaracter(&confirmar, "Confirma modificacion? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					 (*(list+indice)).cantidadPersonas=auxVivienda.cantidadPersonas;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;
				case 3:
				getInt(&auxVivienda.cantidadHabitaciones, "Ingrese cantidad de habitaciones: ", "Error, ingrese una cantidad valida:\n");
				getCaracter(&confirmar, "Confirma modificacion? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					 (*(list+indice)).cantidadHabitaciones=auxVivienda.cantidadHabitaciones;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;

			    case 4:
			    do
			    {
				   getInt(&auxVivienda.tipoVivienda,"Ingrese el tipo de vivienda: 1(CASA)/2(DEPARTAMENTO)/3(CASILLA)/4(RANCHO)","Error, ingrese un tipo de casa valido\n");
			    }while(!validarTipoVivienda(auxVivienda.tipoVivienda));

				getCaracter(&confirmar, "Confirma modificacion? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					 (*(list+indice)).tipoVivienda=auxVivienda.tipoVivienda;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;

				case 5:
					printf("Volver al menu principal? S/N");
					fflush(stdin);
					scanf("%c",&respuesta);
					break;
				default:
					printf("Ingrese una opcion valida.\n");
					break;
				}
			}while(respuesta=='S');
		}
		ok=1;
	}

	return ok;
}

int modificarViviendaMenu(eVivienda vivienda,eTipoVivienda*lista,int lenT)
{
	int option;

	printf("                                           MENU MODIFICACION DE VIVIENDA\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("   ID   Calle                        Cantidad de Personas     Cantidad de Habitaciones      Tipo de Vivienda      Legajo Censista\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	mostrarVivienda(vivienda,lista, lenT);
	printf("1. Modificar Calle  \n");
	printf("2. Modificar Cantidad de Personas \n");
	printf("3. Modificar Cantidad de Habitaciones\n");
	printf("4. Modificar Tipo de Vivienda\n");
	printf("5. Salir\n");
	printf("Ingrese una opcion: ");
	scanf("%d",&option);

	return option;
}

int removerVivienda(eVivienda* list, int len,eTipoVivienda*lista,int lenT,int*contadorViviendas)
{
	int ok=0;
	int indice;
	int id;
	char confirmar;

	 if (list != NULL && len > 0 && lista!=NULL&&lenT>0)
	 {

		printf("Ingrese ID: ");
		scanf("%d",&id);

		indice = encontrarViviendaId(list, len, id);

		if(indice == -1)
		{
			 printf("El id: %d no esta registrado en el sistema\n", id);
		}
				else
				{
					printf("---------------------------------------------------------------------------------------------------------------------------------\n");
					printf("   ID   Calle                        Cantidad de Personas     Cantidad de Habitaciones      Tipo de Vivienda      Legajo Censista\n");
					printf("---------------------------------------------------------------------------------------------------------------------------------\n");
					mostrarVivienda(list[indice], lista, lenT);
					getCaracter(&confirmar, "Quiere darle de baja a esta vivienda? S/N \n","Ingrese una opcion valida (S/N):",'S','N');

					 if (confirmar == 'S')
					{
						 (*(list+indice)).isEmpty=1;
						printf("Baja exitosa.\n");
					}
					else
					{
						printf("Baja cancelada.\n");
					}
				}
				ok=1;
				(*contadorViviendas)--;
	 }
			return ok;
}

int ordenarViviendas(eVivienda* list, int len, int order,eTipoVivienda*lista,int lentT)
{
	int todoOk = 0;
	    eVivienda auxVivienda;
	    if (list != NULL && len > 0 && lista!=NULL&&lentT>0)
	    {
			for (int i = 0; i < len -1; i++)
			{
				for (int j = i+1; j < len; j++)
				{

					if(order==0)//decreciente calle Y cantidad de personas
					{
						if((strcmp((*(list+i)).calle,(*(list+j)).calle)<0)||
						((strcmp((*(list+i)).calle,(*(list+j)).calle)==0)&&((*(list+i)).cantidadPersonas<(*(list+j)).cantidadPersonas)))
						{
							auxVivienda = (*(list+i));
							(*(list+i)) = (*(list+j));
							(*(list+j)) = auxVivienda;
						}
					}
					else
					{
						if((strcmp((*(list+i)).calle,(*(list+j)).calle)>0)||
						((strcmp((*(list+i)).calle,(*(list+j)).calle)==0)&&((*(list+i)).cantidadPersonas>(*(list+j)).cantidadPersonas)))
						{
							auxVivienda = (*(list+i));
							(*(list+i)) = (*(list+j));
							(*(list+j)) = auxVivienda;
						}
					}
				}
			}
			todoOk=1;
	    }
	    return todoOk;
}

char calles[5][25]=
{
		"AV. LA PLATA 5055","YRIGOYEN 3000","OLAVARRIA 600","AV. LA PLATA 5055","FONDO DE BIKINI"
};

int cantidadPersonas[5]=
{
		3,7,5,4,8
};

int cantidadHabitaciones[5]=
{
		2,3,4,5,1
};

int tipoViviendas[5]=
{
		1,3,2,4,1
};

int legajos[5]=
{
		100,102,102,102,103
};

int hardcodearViviendas(eVivienda*list, int len, int cant, int*pId,int*contadorViviendas)
{
	int contador = -1;
	if (list != NULL && len > 0 && cant >= 0 && cant <= len && pId != NULL)
	{
		contador = 0;
		for (int i = 0; i < cant;  i++)
		{
			((*(list+i)).idVivienda)=*pId;
			(*pId)++;
			strcpy((*(list+i)).calle,(*(calles+i)));
			(*(list+i)).cantidadPersonas=(*(cantidadPersonas+i));
			(*(list+i)).cantidadHabitaciones=(*(cantidadHabitaciones+i));
			(*(list+i)).tipoVivienda=(*(tipoViviendas+i));
			(*(list+i)).legajoCensista=(*(legajos+i));
			(*(list+i)).isEmpty=0;
			(*contadorViviendas)++;
			contador++;
		}
	}
	return contador;
}
