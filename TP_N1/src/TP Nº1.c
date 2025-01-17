/*
 ============================================================================
 Name        : TP_N�1
 Author      : Qui�onez Pablo
 Description : Agencia de Viajes
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int x=0; //Kilometros.
	int y=0; //Aerol�neas.
	int z=0; //Latam.
	int difPrecio;
	int validacion=0;


	do
	{
		printf("1-Ingrese Kilometros.\n2-Ingresar Precio de Vuelos. \n3-Calcular todos los costos \n4-Informar Resultados \n5-Carga frozada de Datos\n6-Salir\n\n-Seleccionar Opcion:");
		scanf("%d",&opcion);

		switch(opcion)
		{
			case 1:
				printf("Ingrese Kilometros:");
				x = numerosPositivo(x);
			break;

			case 2:
			printf("Precio vuelo Aerol�neas: ");
			y = numerosPositivo(y);
			printf("Precio vuelo Latam: ");
			z = numerosPositivo(z);
			break;

			case 3:
				if(y==0 && z==0)
				{
				printf("Error, no se ingresaron precios.\n\n");
				}
				else
				{
				printf("Calculando...\n\n");
				validacion=1;
				}
			break;

			case 4:
				if(validacion == 0)
				{
				printf("Error, no calculo.\n\n");
				}

				while(validacion > 0)
				{
					if(x!=0)
					{
						printf("KMs ingresados: %dKm \n\n", x);
						if (y!=0)
							{ 	//Vuelos Aerolineas.
								printf("Precio Aerolineas: $%d \n", y);
								ingresarDatos(y,x);
							}
						else
							{
								printf("No ingreso precio de vuelo para Aerolineas.\n\n");
							}

						if (z!=0)
							{	//Vuelos Latam.
								printf("Precio Latam: $%d \n", z);
								ingresarDatos(z,x);
							}
						else
							{
								printf("No ingreso precio de vuelo para Latam.\n\n");
							}

						if(x!=0 && z!=0)//Diferencia entre los precios.
						{
								difPrecio = diferencia(z,y);
								printf("La diferencia de precio es: $%d \n\n", difPrecio);
						}
						else
						{
								printf("No hay diferencia de precio, tiene que ingresar mas vuelos...\n\n");
						}
					}
					else
					{
						printf("Error, no ingreso ningun Kilometros.\n");
					}
					validacion=0;
					break;
				}
			break;

			case 5:
				x=7090;
				y=162965;
				z=159339;
			//Kilometros.
			printf("KMs ingresados: %dKm \n\n", x);
			//Vuelos Aerolineas.
			printf("Precio Aerolineas: $%d \n", y);
			ingresarDatos(y,x);

			//Vuelos Latam.
			printf("Precio Latam: $%d \n", z);
			ingresarDatos(z,x);

			difPrecio = diferencia(z,y);
			printf("La diferencia de precio es: $%d \n\n", difPrecio);
			break;

			case 6:
			printf("Que tenga buen viaje...\n");
			break;

			default:
			printf("Error no ingreso una opcion correcta\n");
			break;
		}

	}while(opcion != 6);

	return 0;
}
