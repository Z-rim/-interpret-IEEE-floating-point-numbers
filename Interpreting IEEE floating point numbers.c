
#include <stdio.h>
#include <stdint.h>

// Function to convert decimal to binary representation
void decimalToBinary(float decimal) {
    union {
        float f;
        uint32_t i;
    } converter;

    converter.f = decimal;

    printf("Binary representation: ");
    for (int i = 31; i >= 0; i--) {
        printf("%d", (converter.i >> i) & 1);
        if (i == 31 || i == 23)
            printf(" ");
    }
    printf("\n");
}

// Function to convert binary to decimal representation
void binaryToDecimal(uint32_t binary) {
    union {
        float f;
        uint32_t i;
    } converter;

    converter.i = binary;

    printf("Decimal representation: %f\n", converter.f);
}

int main() {
    int choice;
    printf("Choose conversion:\n");
    printf("1. Decimal to Binary\n");
    printf("2. Binary to Decimal\n");
    scanf("%d", &choice);

    if (choice == 1) {
        float decimal;
        printf("Enter decimal number: ");
        scanf("%f", &decimal);
        decimalToBinary(decimal);
    } else if (choice == 2) {
        uint32_t binary;
        printf("Enter binary representation (as an unsigned 32-bit integer): ");
        scanf("%u", &binary);
        binaryToDecimal(binary);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
