#include <stdio.h>
#include <stdbool.h>
#define MAX_INPUT_SIZE 3 // Define the maximum number of inputs

int main() {
    int numbers[MAX_INPUT_SIZE]; //Array to store user input number
    int *ptr = numbers;  // Pointer to the first element of the array

    printf("Hello! You need to enter 3 round numbers \n");

    /**
     * Loop to get user input for 3 numbers
     * The loop will continue until all 3 numbers are entered correctly
     * It checks for valid input and ensures that the second and third numbers are not zero
     */
    for (int inputIndex = 0; inputIndex < MAX_INPUT_SIZE; inputIndex++) {
        printf("Enter value for number %d: ", inputIndex + 1);
        
        int result = scanf("%d", ptr + inputIndex); // Using pointer arithmetic to access the array elements
        bool isInputNotNumber = result != 1; //Check if the input is not a valid number

        /**
         * Check if the input is not a number
         */
        if (isInputNotNumber) {
            printf("Invalid input! Please enter a number :) \n");
            
            // Clear the input buffer
            int inputValue;
            while ((inputValue = getchar()) != '\n' && inputValue != EOF) {
                printf("Clearing invalid input: %c\n", inputValue); // Print the invalid input
            }

            inputIndex--; // Decrement index to repeat the input for the same position
            continue; // Skip to the next iteration to re-prompt for input
        }
        
        /**
         * Check if the second or third input is zero
         */
        if((inputIndex == 1  || inputIndex == 2) && ptr[inputIndex] == 0) {
            printf("Zero is not a valid input! Please enter a non zero number :) \n");
            inputIndex--; // Decrement index to repeat the input for the same position
            continue; // Skip to the next iteration to re-prompt for input
        }
    
    }

    printf("\nYou entered the following numbers:\n");

    /**
     * Print the inputted number using pointer dereferencing
     */
    for (int inputIdx=0; inputIdx < MAX_INPUT_SIZE; inputIdx++) {
        int inputtedNumbers;
        inputtedNumbers = *(ptr + inputIdx); // Dereferencing the pointer to get the value
        
        printf("%d", inputtedNumbers); // Print each number
        
        if (inputIdx < MAX_INPUT_SIZE - 1)
        {
            printf(","); // Print comma after each number except the last one
        }

        if(inputIdx == MAX_INPUT_SIZE - 1) printf("\n"); //Print new line after the last number
    }
    
    int firstInput = ptr[0]; // Accessing first input numbers using pointer arithmetic
    int secondInput = ptr[1]; // Accessing second input numbers using pointer arithmetic
    int thirdInput = ptr[2];//Accessing third input numbers using pointer arithmetic
    
    /**
     * Performing arithmetic operations on the input numbers
     */
    int sum = firstInput + secondInput + thirdInput;
    int subtraction = firstInput - secondInput - thirdInput;
    int multiplication = firstInput * secondInput * thirdInput;
    float division = (float) firstInput / (float) secondInput / (float) thirdInput;
    float average = (float)sum / MAX_INPUT_SIZE;

    /**
     * Display the results of the arithmetic operations
     */
    printf("The sum of the numbers is: %d\n", sum);
    printf("The subtraction of the numbers is: %d\n", subtraction);
    printf("The multiplication of the numbers is: %d\n", multiplication);
    printf("The division of the numbers is: %.2f\n", division);
    printf("The average of the numbers is: %.2f\n", average);
    printf("Thank you for using this program! :) \n");

    return 0;
}