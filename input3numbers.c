#include <stdio.h>
#include <stdbool.h>

int main() {
    const int SIZE = 3;
    int numbers[SIZE];
    int *ptr = numbers;  // Pointer to the element of the array

    printf("Hello! You need to enter 3 round numbers \n");

    for (int inputIndex = 0; inputIndex < SIZE; inputIndex++) {
        printf("Enter value for number %d: ", inputIndex + 1);
        
        int result = scanf("%d", ptr + inputIndex); // Using pointer arithmetic to access the array elements
        bool isInputNotNumber = result != 1;

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
    for (int inputIdx=0; inputIdx < SIZE; inputIdx++) {
        int inputtedNumbers;
        inputtedNumbers = *(ptr + inputIdx); // Dereferencing the pointer to get the value
        
        printf("%d", inputtedNumbers); // Print each number using pointer dereferencing
        
        if (inputIdx < SIZE - 1)
        {
            printf(",");
        }

        if(inputIdx == SIZE - 1) printf("\n");
    }
    
    int firstInput = ptr[0];
    int secondInput = ptr[1];
    int thirdInput = ptr[2];
    
    int sum = firstInput + secondInput + thirdInput;
    int subtraction = firstInput - secondInput - thirdInput;
    int multiplication = firstInput * secondInput * thirdInput;
    float division = (float) firstInput / (float) secondInput / (float) thirdInput;
    float average = (float)sum / SIZE;

    printf("The sum of the numbers is: %d\n", sum);
    printf("The subtraction of the numbers is: %d\n", subtraction);
    printf("The multiplication of the numbers is: %d\n", multiplication);
    printf("The division of the numbers is: %.2f\n", division);
    printf("The average of the numbers is: %.2f\n", average);
    printf("Thank you for using this program! :) \n");

    return 0;
}