#include <stdio.h>
#define ERROR -1

#define OPCION 1
#define VALOR 2
#define PARAMETRO 3

int check (char *key, char *value );
int imprimir (char *key, char *value, char type);

int main (int argc, char *argv[])
{
	if (parse (argc, argv, check) == ERROR) return ERROR;



}

int parse ( int argc, char *argv[], int * callbk_check() )
{
	int n;
	int arg_type [20]={0};	// arreglo que guarda que tipo es cada parametro que se le paso
	
	for ( n=1 ; n<argc ; n++ )
	{
		if ( *(argv[n][0]) != '-' )
		{
			arg_type [n] = PARAMETRO;
			continue;
		}
		
		if ( (*argv[n+1][0] == '-') || ( n==(argc-1) ) )
		{
			printf("Falta un valor para el argumento %d", n);
			return ERROR;
		}
		arg_type [n] = OPCION;
	    arg_type [n+1] = VALOR;
	    n++;
	}
	
	for ( n=1 ; n<argc ; n++ )
	{
		if ( *argv[n][0] == '-' )
		{
			if ( callbk_check( argv[n] , argv[n+1] ) )
			{
				printf("Opcion no valida en argumento %d", n);
				return ERROR;
			}
			n++;
		}
	}
	
int check (char *key, char *value )
{
	return 0;
}	
		
