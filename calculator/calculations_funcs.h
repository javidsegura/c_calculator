#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

// ARITHMETIC FUNCTIONS 

void addition(int a, int b){
      printf("\n => Result: %d", a+b);
}

void f_addition(float a, float b){
      printf("\n => Result: %f", a+b);
}

void substraction(int a, int b){
      printf("\n => Result: %d", a-b);
}

void f_substraction(float a, float b){
      printf("\n => Result: %f", a-b);
}

void multiplication(int a, int b){
      printf("\n => Result: %d", a*b);
}

void f_multiplication(float a, float b){
      printf("\n => Result: %f", a*b);
}

void division(int a, int b){
      printf("\n => Result: %d", a/b);
}

void f_division(float a, float b){
      printf("\n => Result: %f", a/b);
}

// GEOMETRIC FUNCTIONS 

void degrees_transform(int a){
      int transformed_result;

      transformed_result = (a * PI) / 180;

      printf("\n => Result: %lf", (float)transformed_result);

}

void radians_transform(int a){
      int transformed_result;

      transformed_result = (a * 180) / PI;

       printf("\n => Result: %lf", (float) transformed_result);

}

// Statistics

void mean(int array[], int size){


      int sum = 0;

      for (int i= 0; i < size;i++ ){
           sum += (*(array +i));
      }

      printf("\n => Mean is: %lf", (float) sum / size);


}

void variance(int array[], int size){


      int sum = 0;

      for (int i= 0; i < size;i++ ){
           sum += (*(array +i));
      }

      int mean = (float) sum / size;

      int numerator = 0;

      for (int i = 0; i <size; i++){
            numerator += pow((*(array+i)) - mean,2);
      }

      printf("\n => Variance is: %f", (float)numerator/size-1);


}

void std(int *array, int size){ // I am copying the code all over again, because of not using a return type.

      int sum = 0;

      for (int i= 0; i < size;i++ ){
           sum += (*(array +i));
      }

      int mean = (float) sum / size;

      int numerator = 0;

      for (int i = 0; i <size; i++){
            numerator += pow((*(array+i)) - mean,2);
      }

      int variance = (float)numerator/(size-1);

      int std = sqrt(variance);

      printf("\n => Std is %f",(float)std);
}

// FINANCE

void simple_interest(int principal, int interest_rate, int time) {
    float final_amount = 0;
    final_amount = principal * (1 + (interest_rate / 100.0) * time);
    printf("\n => Final amount is %f", final_amount);
}

void compound_interest(int principal, int interest_rate, int time, int frequency) {
    float final_amount = 0;
    final_amount = principal * pow((1 + (interest_rate / 100.0) / frequency), time * frequency);
    printf("\n => Final amount is %f", final_amount);
}
