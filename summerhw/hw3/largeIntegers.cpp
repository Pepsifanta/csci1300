// largeIntegers.cpp

#include "largeIntegers.h"
#include <iostream>

// Constructor
largeIntegers::largeIntegers(int* numList, int length, char s) {
    numDigits = length;
    digits = new int[numDigits];
    setDigits(numList, length);
    setSign(s);
}

// Destructor
largeIntegers::~largeIntegers() {
    delete[] digits;
}

// Addition
// Addition
largeIntegers largeIntegers::add(const largeIntegers& num) const {
    int maxLength = std::max(numDigits, num.numDigits);  // Determine the maximum length of the two large integers
    int* resultDigits = new int[maxLength];
    int carry = 0;

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < numDigits) ? digits[i] : 0;  // Get the digit from the first large integer
        int digit2 = (i < num.numDigits) ? num.digits[i] : 0;  // Get the digit from the second large integer

        int sum = digit1 + digit2 + carry;
        resultDigits[i] = sum % 10;  // Store the current digit in the result
        carry = sum / 10;  // Calculate the carry for the next digit
    }

    if (carry > 0) {
        int* newDigits = new int[maxLength + 1];
        std::copy(resultDigits, resultDigits + maxLength, newDigits);
        newDigits[maxLength] = carry;
        delete[] resultDigits;
        resultDigits = newDigits;
        maxLength++;
    }

    largeIntegers result(resultDigits, maxLength, sign);  // Create a new object to store the result
    delete[] resultDigits;
    return result;
}


// Subtraction
// Subtraction
largeIntegers largeIntegers::subtract(const largeIntegers& num) const {
    int maxLength = std::max(numDigits, num.numDigits);  // Determine the maximum length of the two large integers
    int* resultDigits = new int[maxLength];
    int borrow = 0;

    for (int i = 0; i < maxLength; i++) {
        int digit1 = (i < numDigits) ? digits[i] : 0;  // Get the digit from the first large integer
        int digit2 = (i < num.numDigits) ? num.digits[i] : 0;  // Get the digit from the second large integer

        int difference = digit1 - digit2 - borrow;
        if (difference < 0) {
            difference += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        resultDigits[i] = difference;  // Store the current digit in the result
    }

    // Remove leading zeros
    int leadingZeros = 0;
    for (int i = maxLength - 1; i >= 0; i--) {
        if (resultDigits[i] == 0) {
            leadingZeros++;
        } else {
            break;
        }
    }

    int resultLength = maxLength - leadingZeros;

    largeIntegers result(resultDigits, resultLength, sign);  // Create a new object to store the result
    delete[] resultDigits;
    return result;
}

// Equality check
// Equality check
bool largeIntegers::equal(const largeIntegers& num) const {
    if (numDigits != num.numDigits) {
        return false;
    }

    for (int i = 0; i < numDigits; i++) {
        if (digits[i] != num.digits[i]) {
            return false;
        }
    }

    return true;
}


// Set the digits of the integer
void largeIntegers::setDigits(int* numList, int length) {
    for (int i = 0; i < length; i++) {
        digits[i] = numList[i];
    }
}

// Set the sign of the integer
void largeIntegers::setSign(char s) {
    sign = s;
}

// Print the integer
void largeIntegers::print() const {
    // Print logic here
    // ...
}
