#include <stdio.h>
float sum(float,float);

int main(){
 float varA, varB, res;
 puts("Ingrese los valores");
 scanf("%f%f", &varA, &varB);
 res = sum(varA, varB);
 printf("Resultado : %f \n", res);
 return 0;
}

float sum(float a, float b){
 float res;
 res = a+b;
 return res;
}