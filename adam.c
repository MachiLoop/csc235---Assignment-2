#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char *filename = "adam.in";
    FILE *file = fopen(filename, "r");

    if(file == NULL){
        printf("Error opening file");
        return 1;
    }

    //create a variable to store the strings (maximum of 256bytes)
    const unsigned MAX_LENGTH = 256;
    char stringText[MAX_LENGTH];

    //Read number of test cases from file
    char noCases[250];
    fgets(noCases, 250, file);
    noCases[strlen(noCases) - 1]= '\0';
    

    // convert number of test cases to integer
    int numCase = atoi(noCases);

    if(numCase < 1){
        printf("Error! Number of inputs cannot be less than 1");
        return 1;
    }

    //while file exists
    while(fgets(stringText, MAX_LENGTH , file)){
      
    //convert string to uppercase
    strupr(stringText);

     //get rid of newline character, if any and replace with a null character    
    if(stringText[strlen(stringText) - 1]= '\n'){
          stringText[strlen(stringText) - 1]= '\0';
      };

      
      //loop through the strings
      for (int i = 0; i < strlen(stringText); i++){

          //check if character is 'D'
          if(stringText[i] == 'D'){
                printf("%d \n", i);
                break;
            } 
            //check if character is 'U'
            else if(stringText[i] == 'U'){
                if(i == strlen(stringText) - 1){
                printf("%d \n", strlen(stringText));
                }
            }

            //check if input is not 'U' or 'D'
            else{
                printf("ERROR: string can only contain 'U' or 'D' \n \n");
                return 1;
            }
      }
    }

    fclose(file);
    return 0;
}

