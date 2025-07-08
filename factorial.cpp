#include "factorial.h"

void reverseString(std::string &str) {
    int n = str.length();
    for (int i = 0; i < n/2; i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

std::string multiplyString(const std::string &numStr, int multiplier) {
    std::string result;
    int carry = 0;
    
    for (int i = numStr.length() - 1; i >= 0; i--) {
        int digit = numStr[i] - '0';
        int product = digit * multiplier + carry;
        carry = product / 10;
        result.push_back((product % 10) + '0');
    }
    
    while (carry > 0) {
        result.push_back((carry % 10) + '0');
        carry /= 10;
    }
    
    reverseString(result);
    return result;
}

std::string factorialRecursive(int n, std::string current) {
    if (n == 0 || n == 1) {
        return current;
    }
    std::string next = multiplyString(current, n);
    return factorialRecursive(n - 1, next);
}

void runFactorialTask() {
    int number;
    std::cout << "Введите число (значительно больше 13): ";
    std::cin >> number;

    if (number < 26) {
        std::cout << "Число должно быть значительно больше 13 (минимум в 2 раза)!" << std::endl;
        return;
    }
    
    std::string result = factorialRecursive(number);
    std::cout << number << "! = " << result << std::endl;
}