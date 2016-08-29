#include <stdio.h>
#include <stdlib.h> 

/* Definicion de macros y constantes. */
#define MAX_CHARS_NAME 50

/* Declaration of functions (prototypes). */
void getOption(char *_option);
void registerEmployees(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras);
void showEmployees(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras);
void mostrarNomina(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras);
float getSalaryEmploye(float salarioBase, float horasExtras);
float getSalaryTotal(float *_salaries);
int existEmployees();

/* Variables globales. */
int max_employees = 0;
int num_employees = 0;
int extra_hour;

int main(int argc, char *argv[]){
	
	/* Variables locales*/
	char option = 'x';
	char (*names)[MAX_CHARS_NAME];
	float *salaries;
	float total = 0;
	float *horasExtras;
	// Validacion: Numero de argumentos por consola.
	if (argc !=3) {
		printf("Error: Numero de parametros invalido. \nDebe iniciar así: :/evaluacion.out <numero maximo de trabajadores> <Valor hora extra>\n");
		exit(0);
	}
	
	//Traer argumentos de la consola y convertirlo a numero
	max_employees = atoi(argv[1]);
	extra_hour = atoi(argv[2]);

	//Validacion: Argumento tiene que ser un entero positivo.
	if (max_employees <= 0 | extra_hour <= 0) {
		printf("Error: Parametro invalido. \nDebe iniciar así: :/evaluacion.out <numero maximo de trabajadores> <Valor hora extra>\n");
		exit(0);
	}

	printf("El numero maximo de trabajadores sera %d \n", max_employees);
	printf("El valor de cada hora extra sera %d \n", extra_hour);

	/*Conseguir espacio libre en memoria*/
	names = (char (*)[MAX_CHARS_NAME]) malloc(sizeof(char[MAX_CHARS_NAME]) * max_employees);
	salaries = (float *) malloc(sizeof(float) * max_employees);
	horasExtras = (float *) malloc(sizeof(float)* max_employees);
	
	do {
		getOption(&option);
		switch (option) {
			case 'a':
				registerEmployees(names, salaries, horasExtras);
				break;
			case 'b':
				showEmployees(names, salaries, horasExtras);
				break;
			case 'c':
				mostrarNomina(names, salaries, horasExtras);
				break;
			case 'q':
				printf("Saliendo del programa...\n");
				break;
			default:
				printf("La opcion '%c' no es valida. Regresando al menu.\n", option);
				break;
			
		}
	} while(option != 'q');
	
	//Liberando memoria
	free(names);
	free(salaries);
	free(horasExtras);

	return 0;
}

/* Implementacion de funciones. */
      

void getOption(char *_option) {
	printf("\nMENU DE OPCIONES\n");
	printf("\ta) Registrar trabajadores.\n");
	printf("\tb) Ver lista de trabajadores.\n");
	printf("\tc) Calcular nomina.\n");
	printf("\tq) Salir del programa.\n");
	printf("Seleccione una opcion: ");
	setbuf(stdin, NULL);
	scanf("\n%c", _option);
}

void registerEmployees(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras) {
	//Variables locales
	int i = 0;
	int num_new_employees = 0;
	printf("Ingrese el numero de trabajadores a registrar: ");
	setbuf(stdin, NULL);
	scanf("%d", &num_new_employees);
	if (num_employees + num_new_employees > max_employees) {
		printf("No es posible registrar %d trabajadores.\n", num_new_employees);
		printf("La capacidad maxima es %d y actualmente estan registrados %d.\n", max_employees, num_employees);
		return;
	}
	for (i = num_employees; i < num_employees + num_new_employees; i++) {
		/* Obtener información del nuevo empleado. */
		printf("\nNombre del empleado #%d: ", i + 1);
		setbuf(stdin, NULL);
		scanf("%s", (char *)(_names+i));
		printf("Salario: ");
		setbuf(stdin, NULL);
		scanf("%f", _salaries+i);
		printf("Horas extras realizadas: ");
		setbuf(stdin, NULL);
		scanf("%f", _horasExtras+i);
	}
	num_employees += num_new_employees;
	printf("\nSe han registrado %d trabajadores en la lista.\n", num_new_employees);
}

void showEmployees(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras) {

    /* Local variables. */
    int i = 0;

    if (!existEmployees()) {
        printf("No hay trabajadores para mostrar.\n");
        return;
    }

    printf("|%-18s|%-15s|%-12s\n", "Nombre", "Salario base", "Horas Extras");
    for (i = 0; i < num_employees; i++) {
        printf("|%-18s|%-15.2f|%-12.2f\n", *(_names+i), *(_salaries+i), *(_horasExtras+i));
	
    }
    //printf("|%18s|%-15.2f|\n", "Total ", getSalaryTotal(_salaries));

}

float getSalaryTotal(float *_salaries) {
	/* Local variables. */
	int i = 0;
	float total = 0;
	if (!existEmployees()) {
		printf("No se puede calcular el total porque no se han registrado trabajadores.\n");
	return 0;
	}
	for (i = 0; i < num_employees; i++) {
		total += *(_salaries+i);
	}
	//printf("\nEl pago total es de: %.2f$\n", total);
	return total;
}

float getSalaryEmployee(float salarioBase, float numHorasExtras){
        float total;
        total = (float) salarioBase + (numHorasExtras*extra_hour);
        return total;
}

void mostrarNomina(char (*_names)[MAX_CHARS_NAME], float *_salaries, float *_horasExtras){
        int i;
        float salarioEmpleado [num_employees];
        float totalSalarios;
	

        printf("\t\t\t%s\n", "Lista de trabajadores");
        printf("|%-s %47s|\n","Nombre de la empresa","NIT.#############");
        printf("|%-20s|%-15s|%-15s|%-15s|\n","Nombres","Salario base","Salario extra","Total");
        for(i=0;i<num_employees;i++){
		
                salarioEmpleado[i] = getSalaryEmployee(*(_salaries+i), *(_horasExtras+i));
		float salario_extra=*(_horasExtras+i)*extra_hour;
                printf("|%-20s|%-15.2f|%-15.2f|%-15.2f|\n",*(_names+i),*(_salaries+i),salario_extra, salario_extra + *(_salaries+i));

        }
        totalSalarios = getSalaryTotal(salarioEmpleado);
        printf("\nEl pago total es de: %.2f$\n", totalSalarios);
}






int existEmployees() {
    if (num_employees) {
        return 1;
    }
    return 0;
}

