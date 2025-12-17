#include <iostream>
#include <string>
#include "CustomArray.h"

int main() {
    try {
        std::cout << "--- Integer Array Demo ---" << std::endl;
        int n;
        std::cout << "Enter size for int array: ";
        std::cin >> n;

        CustomArray<int> intArray(n);
        std::cout << "Enter " << n << " integers:" << std::endl;
        std::cin >> intArray;

        std::cout << "Your array: " << intArray << std::endl;
        std::cout << "Element at index 0 is: " << intArray[0] << std::endl;

        std::cout << "\n--- String Array Demo ---" << std::endl;
        CustomArray<std::string> strArray(2);
        strArray[0] = "Hello";
        strArray[1] = "C++";

        CustomArray<std::string> copyArray;
        copyArray = strArray; // Testing assignment operator

        std::cout << "Original: " << strArray << std::endl;
        std::cout << "Assigned Copy: " << copyArray << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\nPress Enter to exit...";
    std::cin.ignore(1000, '\n');
    std::cin.get();

    return 0;
}