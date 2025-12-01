#include <stdio.h>
#include <string.h>

// Function to perform currency exchange
void curr_change(float amCur1, float amMax, float excRate, float *amCur2, float *leftOver) {
    // Check if the amount exceeds the maximum allowed
    if (amCur1 > amMax) {
        *leftOver = amCur1 - amMax;  // Calculate leftover amount
        *amCur2 = amMax * excRate;   // Convert only the max allowed amount
    } else {
        *leftOver = 0;               // No leftover
        *amCur2 = amCur1 * excRate;  // Convert the entire amount
    }
}

int main() {
    struct {
        char curr[10];  // Currency name as C-string
        float bRate;      // Rate for buying (local -> foreign)
        float sRate;     // Rate for selling (foreign -> local)
    } currencies[3] = {
        {"USD", 0.27, 3.67},    // 1 AED = 0.27 USD (buy), 1 USD = 3.67 AED (sell)
        {"EUR", 0.23, 4.28},    // 1 AED = 0.24 EUR (buy), 1 EUR = 4.23 AED (sell)
        {"OMR", 0.10, 9.58}     // 1 AED = 0.10 OMR (buy), 1 OMR = 9.58 AED (sell)
    };
    
    char localCurrency[] = "AED";  // Local currency
    float amMax = 5000.0;   // Maximum exchangeable amount in local currency
    
    // Variables for user input
    float amount;
    char fromCurrency[10];
    char toCurrency[10];
    
    // Prompt user for input
    printf("Available currencies: AED (local), USD, EUR, OMR\n\n");
    printf("Enter amount: ");
    scanf("%f", &amount);
    printf("Enter currency you have: ");
    scanf("%s", fromCurrency);
    printf("Enter target currency: ");
    scanf("%s", toCurrency);
    
    // Input validation
    if (amount <= 0) {
        printf("\nError: Amount must be positive!\n");
        return 1;
    }
    
    // Check if currencies are valid
    int validFrom = 0, validTo = 0;
    if (strcasecmp(fromCurrency, localCurrency) == 0)
        validFrom = 1;
    if (strcasecmp(toCurrency, localCurrency) == 0)
        validTo = 1;
    
    for (int i = 0; i < 3; i++) {
        if (strcasecmp(fromCurrency, currencies[i].curr) == 0) validFrom = 1;
        if (strcasecmp(toCurrency, currencies[i].curr) == 0) validTo = 1;
    }
    
    if (!validFrom || !validTo) {
        printf("\nError: Invalid currency entered!\n");
        return 1;
    }
    
    // Check if one currency is local (as per requirement)
    if (strcasecmp(fromCurrency, localCurrency) != 0 && strcasecmp(toCurrency, localCurrency) != 0) {
        printf("\nError: One currency must be the local currency (AED)!\n");
        return 1;
    }
    
    if (strcasecmp(fromCurrency, toCurrency) == 0) {
        printf("\nError: Cannot exchange same currencies!\n");
        return 1;
    }
    
    // Variables for currency exchange
    float amCur2 = 0;
    float leftOver = 0;
    float excRate = 0;
    float amCur1 = amount;  // Amount in local currency for cap check
    
    // Determine exchange rate and perform conversion
    if (strcasecmp(fromCurrency, localCurrency) == 0) {
        // Buying foreign currency with local currency
        for (int i = 0; i < 3; i++) {
            if (strcasecmp(toCurrency, currencies[i].curr) == 0) {
                excRate = currencies[i].bRate;
                break;
            }
        }
    } else {
        // Selling foreign currency for local currency
        for (int i = 0; i < 3; i++) {
            if (strcasecmp(fromCurrency, currencies[i].curr) == 0) {
                excRate = currencies[i].sRate;
                amCur1 = amount * excRate;  // Convert to local for cap check
                break;
            }
        }
    }
    
    // Call the currency exchange function
    curr_change(amCur1, amMax, excRate, &amCur2, &leftOver);
    
    // Display results
    printf("\n=== Transaction Details ===\n");
    printf("Exchange Rate: %.4f\n", excRate);
    printf("Converted Amount: %.2f %s\n", amCur2, toCurrency);
    
    if (leftOver > 0) {
        printf("Leftover Amount: %.2f %s (exceeds bank cap)\n", leftOver, fromCurrency);
    } else {
        printf("Leftover Amount: 0.00 %s\n", fromCurrency);
    }
    
    printf("Bank Transaction Cap: %.2f %s\n", amMax, localCurrency);
    
    return 0;
}
