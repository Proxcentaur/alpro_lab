/**
 * Create by Septia Dini Rahayu 
 * NIM: 2802663931
 */

#include <stdio.h>
#include <stdbool.h>
#define MAX_INPUT_SIZE 5 // Define the maximum number of inputs

int main() {
    int scores[MAX_INPUT_SIZE]; // Array to store user input numbers
    int *ptr = scores;  // Pointer to the first element of the array

    printf("Hello! You need to enter 5 students scores \n");

    /**
     * Loop to get user input for 5 scores
     * The loop will continue until all 5 scores are entered correctly
     * It checks for valid input and ensures that the second and third numbers are not zero
     */
    for (int inputIndex = 0; inputIndex < MAX_INPUT_SIZE; inputIndex++) {
        printf("Enter value for score %d: ", inputIndex + 1);
        
        int result = scanf("%d", ptr + inputIndex); // Using pointer arithmetic to access the array elements
        bool isInputNotNumber = result != 1; // Check if the input is not a valid number

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
    
    }

    printf("\nYou entered the following scores:\n");

    /**
     * Print the inputted scores using pointer dereferencing
     */
    for (int inputIdx = 0; inputIdx < MAX_INPUT_SIZE; inputIdx++) {
        int scoreValue;
        scoreValue = *(ptr + inputIdx); // Dereferencing the pointer to get the value
        
        printf("%d", scoreValue); // Print each score
        
        if (inputIdx < MAX_INPUT_SIZE - 1) {
            printf(", "); // Print comma between scores except after the last one
        }
        
        if (inputIdx == MAX_INPUT_SIZE - 1) {
            printf("\n"); // Print newline after the last score
        }
    }

    /**
     * Calculate the highest score, lowest score, and the sum of scores
     */
    int maxScore = ptr[0]; // Start with the first score as the maximum
    int minScore = ptr[0]; // Start with the first score as the minimum
    int sumScores = 0; // Variable to hold the sum of scores

    for (int idx = 0; idx < MAX_INPUT_SIZE; idx++) {
        if (ptr[idx] > maxScore) {
            maxScore = ptr[idx]; // Update maxScore if a higher score is found
        }  

        if (ptr[idx] < minScore) {
            minScore = ptr[idx]; // Update minScore if a lower score is found
        }  

        sumScores += ptr[idx]; // Add the current score to the sum
    }

    /**
     * Print the results
     * Display the highest score, lowest score, sum of scores, and average score
     */
    printf("The highest score is: %d\n", maxScore);
    printf("The lowest score is: %d\n", minScore);
    printf("The sum of scores is: %d\n", sumScores);
    printf("The average score is: %.2f\n", (float) sumScores / MAX_INPUT_SIZE);

    return 0; 
}