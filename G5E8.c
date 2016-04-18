/*Defino las bibliotecas que usaremos*/
#include <stdio.h>

/*Defino mis codigos de error*/
#define ERROR -1
#define OK     0
#define OPCION 1
#define VALOR 2
#define PARAMETRO 3

int check (char *key, char *value );
int imprimir (int argc, char *argv[]);
int parse ( int argc, char *argv[], int (*callbk_check)(char* , char*) );

int main (int argc, char *argv[])
{
	/*Defino mis variables*/
	int status;
	if ((status=parse (argc, argv, check)) == ERROR) return ERROR;
	status=imprimir(argc,argv);
	return status;
}

int parse ( int argc, char *argv[], int (*callbk_check)(char* , char*) )
{
	/*Defino las variables que utilizaremos*/
	unsigned int n;

	/*Si no recibimos parametros*/
	if (argc == 1) return OK;
	
	/*Compruebo que cada opcion tenga su respectivo valor*/
	for ( n=1 ; n<argc ; n++ )
	{
		/*Si no es una opcion avanzo al siguiente*/
		if ( (argv[n][0]) != '-' )
			continue;
		
		/*Si el siguiente es una opcion debo devolver error*/
		if ( ( n==(argc-1)) || (argv[n+1][0] == '-') )
		{
			printf("\nFalta un valor para el argumento %d\n", n);
			return ERROR;
		}
	    n++;
	}
	
	/*Compruebo la validez de las opciones ingresadas*/
	for ( n=1 ; n<argc ; n++ )
	{
		/*Si es una opcion, paso la opcion y su valor a la funcion check*/
		if ( argv[n][0] == '-' )
		{
			/*Si check devuelve error lo anuncio*/
			if ( callbk_check( argv[n] , argv[n+1] ) )
			{
				printf("\nOpcion no valida en argumento %d\n", n);
				return ERROR;
			}
			n++;
		}
	}
	
/*Devuelvo el estado del programa*/
return OK;
}
	
int check (char *key, char *value )
{
	return 0;
}	

int imprimir(int argc, char* argv[])
{
		/*Defino las variables a usar*/
		unsigned int n=1;
		
		/*Busco e imprimo las opciones*/		
		printf("\nEstas son las opciones:\n");
		while(n<argc)
		{
			/*Si es una opcion*/
			if(argv[n][0]=='-')
			{
				/*La imprimo y su valor*/
				printf("%s\t%s\n",argv[n],argv[n+1]);
				
				/*Subo el siguiente es su parametro*/
				n+=2;
			}
			/*Si no es una opcion avanzo al siguiente*/
			else
				n++;
		}
		/*Reseteo el contador*/
		n=1;	
		
		/*Busco e imprimo los parametros*/
		printf("\nEstos son los parametros:\n");
		while(n<argc)
		{
			/*Si es una opcion la salteo y a su parametro*/
			if(argv[n][0]=='-')
				n+=2;
				
			/*Si es un parametro lo imprimo y voy al siguiente*/
			else
			{
				printf("%s\n",argv[n]);
				n++;
			}
		}
	/*Devuelvo el estado de la impresion*/
	return OK;
}




