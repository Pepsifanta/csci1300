// largeIntegers.h

#ifndef LARGE_INTEGERS_H
#define LARGE_INTEGERS_H

class largeIntegers {
private:
    int* digits;  // Pointer to store the digits of the integer
    int numDigits;  // Number of digits in the integer
    char sign;  // Sign of the integer

public:
    // Constructor
    largeIntegers(int* numList, int length, char s);

    // Destructor
    ~largeIntegers();

    // Member functions
    largeIntegers add(const largeIntegers& num) const;
    largeIntegers subtract(const largeIntegers& num) const;
    bool equal(const largeIntegers& num) const;
    void setDigits(int* numList, int length);
    void setSign(char s);
    void print() const;
};

#endif
