#include <stdio.h>
#include <stdbool.h>
#define MAX_INPUT_SIZE 7 // Define the maximum number of inputs

void temperatureAnalyzer() {
    /**
     * Implementation of basic temperature analyzer
     * This function is not used in the main program, but can be implemented if needed
     */
    int maxDays;
    int temperatures[MAX_INPUT_SIZE]; // Array to store user input temperatures
    int *ptr = temperatures;  // Pointer to the first element of the array

    while(1) {
        printf("How many days of temperatures do you want to input (1-7)? ");
        scanf("%d", &maxDays); // Read user input for the number of days

        /**
         * Validate the input to ensure it is within the range of 1 to MAX_INPUT_SIZE
         */
        
        if(maxDays >= 1 && maxDays <= MAX_INPUT_SIZE) {
            break; // Exit the loop if the input is valid
        } else {
            printf("Invalid input! Please enter a number between 1 and %d: \n", MAX_INPUT_SIZE);
        }
    }

    float average = 0; // Variable to store the average temperature
    int sum = 0; // Variable to store the sum of temperatures
    for(int idx = 0; idx < maxDays; idx++){
        printf("Enter temperature for day %d: ", idx + 1);
        int result = scanf("%d", ptr + idx); // Using pointer arithmetic to access the array elements
        sum += *(ptr + idx); // Add the input temperature to the sum
    }

    average = (float) sum / maxDays; // Calculate the average temperature

    if (average >= 30) {
        printf("The average temperature is: %.2f, It's a hot day!\n", average);
    } else if (average >= 20 && average < 30) {
        printf("The average temperature is: %.2f, It's a warm day!\n", average);
    } else if (average < 20) {
        printf("The average temperature is: %.2f, It's a cool day!\n", average);
    }
    
}

void temperatureAnalzyer2() {
    /**
     * Implementation of a more advanced temperature analyzer
     * We will use dynamic memory allocation to store the maximum number of days
     */
    
}

int main() {
    temperatureAnalyzer();
    return 0;
}