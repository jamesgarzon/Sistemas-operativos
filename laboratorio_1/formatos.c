#include <stdio.h>

float sum(float,float);

int main(){
 int age=0;
 char name[20];
 printf("Escriba su numbre: ");
 scanf("%s", &name[0]);
 printf("Escriba el año de nacimiento ");
 scanf("%d", &age);
 //printf("Hola %s, tienes %d años \n", &name[0], 2016-age);
 printf("|%10.5s|%10.5s| \n", "Name", "Age");
 printf("|%10.5s|%10.5d| \n", name, age);

 return 0;
}