#include <stdio.h>
#include <string.h>

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(char pattern[], int M, int lps[]) {
    // Length of the previous longest prefix & suffix
    int len = 0;
    
    // lps[0] is always 0
    lps[0] = 0;
    
    // Calculate lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                // Try matching with the previous longest prefix
                len = lps[len - 1];
            } else {
                // No match found, set lps[i] to 0
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search algorithm
void KMPSearch(char text[], char pattern[]) {
    int N = strlen(text);
    int M = strlen(pattern);
    
    // Create an array to hold the longest prefix suffix values
    int lps[M];
    
    // Preprocess the pattern
    computeLPSArray(pattern, M, lps);
    
    int i = 0;  // Index for text
    int j = 0;  // Index for pattern
    int found = 0; // Flag to check if pattern is found
    
    while (i < N) {
        // Current characters match, move both pointers
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        // If we've matched the entire pattern
        if (j == M) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            // Look for the next match
            j = lps[j - 1];
        } 
        // Mismatch after some matches
        else if (i < N && pattern[j] != text[i]) {
            if (j != 0) {
                // Use the LPS values to skip characters
                j = lps[j - 1];
            } else {
                // No match found, move to next character in text
                i++;
            }
        }
    }
    
    if (!found) {
        printf("Pattern not found in the text\n");
    }
}

// Main function with example usage
int main() {
    char text[100];
    char pattern[100];
    
    printf("Enter the text: ");
    scanf("%s", text);
    
    printf("Enter the pattern to search: ");
    scanf("%s", pattern);
    
    printf("\nSearching for pattern: %s\n", pattern);
    printf("In text: %s\n\n", text);
    
    KMPSearch(text, pattern);
    
    return 0;
}