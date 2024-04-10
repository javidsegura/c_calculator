
/* TO BE RUN IN TERMINAL */

#include <stdio.h>
#include "mode_selection.h"

int main(){



      while (1)
      {
            
      

      system("clear");


      int n;

      printf("\n ------------------------------------------------\n\t\t HOMEPAGE\n ");
      printf("------------------------------------------------\n");
      printf("\n => Select your mode: ");
      printf("\n\t\t 1. Arithmetic");
      printf("\n\t\t 2. Geometric");
      printf("\n\t\t 3. Statistics");
      printf("\n\t\t 4. Finance\n");

      printf("\n=> Your option here (index): ");
      scanf("%d",&n);

      user_option(n);

      }


}

