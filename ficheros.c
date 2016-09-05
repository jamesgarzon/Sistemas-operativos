#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 500

struct product{
	char name[50];
	int size;
	float price;
};

void token(char *str, struct product *products, int position);
void printData(struct product *products, int counter);
int main(int argc, char *argv[]){
	char bff[MAX];
	struct product products[10];
	int counter = 0;
	char *fileName;
	FILE *file;

	fileName = argv[1];
	file = fopen(fileName, "r");

	while(feof(file) == 0){
		fgets(bff, MAX, file);
		puts(bff); //Para verificar si está bien
		token(bff, products, counter);
		counter++;
	}
	printf("===============\n");
	printData(products, counter);
	fclose(file);

	return 0;
}

void token(char *str, struct product *products, int position){
	char name[50];
	int size;
	float price;
	char *pch;
	pch = strtok(str, ";,");
	strcpy(name, pch);

	pch = strtok(NULL, ";,");
	size = atoi(pch);

	pch = strtok(NULL, ";,");
	price = atof(pch);

	strcpy(products[position].name, name);
	products[position].size = size;
	products[position].price = price;
	// printf("%s\n", name);
	// printf("%d\n", size);
	// printf("%f\n", price);

}

void printData(struct product *products, int counter){
	int i;
	float sum = 0;
	printf("Nombre      Cant       Precio\n");
	for (i = 0; i < counter; ++i){
		printf("%s ", products[i].name);
		printf("%d ", products[i].size);
		printf("%f \n", products[i].price);
		sum = sum + (products[i].size * products[i].price);
	}
	printf("Total: %f\n", sum);
}

// void getData(struct product *products, int position){

// }

//void printData
