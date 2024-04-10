#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculations_funcs.h"




void arithmetic();
void geometric();
void statistics();
void finance();


void user_option(int a){ // This will emulate a main function (in the sense it will behave as a central subroutine that will call others)

      system("clear");

      sleep(.85);


      switch (a)
      {
      case 1:
            arithmetic();
            break;
      case 2:
            geometric();
            break;
      case 3:
            statistics();
            break;
      case 4:
             finance();
             break;
      default:
            printf("No option has been received, please try again.");
            break;
      }


}

// ARITHMETIC PANEL

void arithmetic(){
      int operation_decision;
      int type_decision;
      
      int first_operand;
      int second_operand;
      float f_first_operand;
      float f_second_operand;

      printf("\n ------------------------------------------------\n\t\t MODE: ARITHMETIC\n ");
      printf("------------------------------------------------\n");
      printf("\n => Select your mode: ");
      printf("\n\t\t 1. Addition");
      printf("\n\t\t 2. Substraction");
      printf("\n\t\t 3. Multiplication");
      printf("\n\t\t 4. Division\n");

      printf("\n=> Your option here (index): ");
      scanf("%d",&operation_decision);

      printf("\nBefore you provide the numbers, select data types: ints (0), floats(1)\n");
      printf("Your decision: ");
      scanf("%d",&type_decision);

      printf("Select two operands: \n ");
      
      printf("\nFirst: ");

      if (type_decision == 0){
           scanf("%d", &first_operand);
      }
      else{
            scanf("%f", &f_first_operand);
      }

      printf("Second: ");

      if (type_decision == 0){
           scanf("%d", &second_operand);
      }
      else{
            scanf("%f", &f_second_operand);
      }

      switch(operation_decision)
      {
      case 1:
            if (type_decision == 0){
                  addition(first_operand, second_operand);
            }
            else{
                  f_addition(f_first_operand, f_second_operand);
            }
            break;
      case 2:
            if (type_decision == 0){
                  substraction(first_operand, second_operand);
            }
            else{
                  f_substraction(f_first_operand, f_second_operand);
            }
            break;
      case 3:
            if (type_decision == 0){
                  multiplication(first_operand, second_operand);
            }
            else{
                  f_multiplication(f_first_operand, f_second_operand);
            }
            break;
      case 4:
            if (type_decision == 0){
                  division(first_operand, second_operand);
            }
            else{
                  f_division(f_first_operand, f_second_operand);
            }
            break;
      default:
            printf("Your option has not been registered sucesfully, please try again...");
            break;
      }

}

// GEOMETRIC PANEL

void geometric(){
      int operation_decision;
      
      float value_to_transform;

      printf("\n ------------------------------------------------\n\t\t MODE: GEOMETRIC\n ");
      printf("------------------------------------------------\n");
      printf("\n => Select your mode: ");
      printf("\n\t\t 1. From degress to radians");
      printf("\n\t\t 2. From radians to degrees\n");
    

      printf("\n=> Your option here (index): ");
      scanf("%d",&operation_decision);

      printf("\n\nProvide your number: ");
      scanf("%f", &value_to_transform);

      switch(operation_decision)
      {
      case 1:
            degrees_transform(value_to_transform);
            break;
      case 2:
            radians_transform(value_to_transform);
            break;
      default:
            printf("Your option has not been registered sucesfully, please try again...");
            break;
      }


}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void statistics() {
    int operation_decision;
    char input[256];  // Buffer to hold the user input
    int numbers[256]; // Array to store the numbers
    int count = 0;    // Counter to keep track of the number of numbers

    printf("\n ------------------------------------------------\n\t\t MODE: STATISTICS\n ");
    printf("------------------------------------------------\n");
    printf("\n => Select your mode: ");
    printf("\n\t\t 1. Compute mean");
    printf("\n\t\t 2. Compute variance");
    printf("\n\t\t 3. Compute standard deviation\n");

    printf("\n=> Your option here (index): ");
    scanf("%d", &operation_decision);

    // Clear the input buffer after scanf
    clear_input_buffer();

    printf("\n\nEnter numbers separated by commas (e.g., 1,2,3): ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error reading input.\n");
        exit(1);
    }

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Tokenize the input string using comma as a delimiter
    char *token = strtok(input, ",");
    while (token != NULL && count < 256) {
        numbers[count++] = atoi(token); // Convert token to integer and store in numbers array
        token = strtok(NULL, ","); // Go to the next token
    }

    // At this point, you have your numbers array filled with user input
    // You can now proceed to calculate mean, variance, or standard deviation based on operation_decision

      switch (operation_decision)
      {
      case 1:
            mean(numbers, count);
            break;
      case 2:
            variance(numbers, count);
            break;
      case 3:
            std(numbers,count);
            break;
      default:
            printf("Your option has not been registered, please try again");
            break;
      }
}


// Finance 

void finance() {
    int operation_decision;

    int principal = 0;
    int interest_rate = 0;
    int frequency = 0; // Only for compound interest
    int time = 0;
   

    printf("\n ------------------------------------------------\n\t\t MODE: STATISTICS\n ");
    printf("------------------------------------------------\n");
    printf("\n => Select your mode: ");
    printf("\n\t\t 1. Compute compound interest");
    printf("\n\t\t 2. Compute simple interest\n");
   

    printf("\n=> Your option here (index): ");
    scanf("%d", &operation_decision);

    switch (operation_decision)
    {
    case 1:




      printf("\nPrincipal: ");
      scanf("%d", &principal);

      printf("Interest rate (e.g: 5): ");
      scanf("%d", &interest_rate);

      printf("Number of times interest applied per time period: ");
      scanf("%d", &frequency);

      printf("Number of time periods: ");
      scanf("%d", &time);
      
      compound_interest(principal, interest_rate,time, frequency);

      break;

      case 2:
      printf("\nPrincipal: ");
      scanf("%d", &principal);

      printf("Interest rate (e.g: 5): ");
      scanf("%d", &interest_rate);

      printf("Number of time periods: ");
      scanf("%d", &time);

      simple_interest(principal, interest_rate,time);
      break;

    
    default:
      printf("Your option could not be saved sucesfully, please try again.");
      break;
    }



}





