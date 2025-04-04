#include <iostream>

void print_result(double firstNum, double secondNum, char operation, double result) {
    std::cout << firstNum << " " << operation << " " << secondNum << " = " << result << std::endl;
}

int main() {
    double firstNum, secondNum, result = 0;
    std::cout << "Enter two numbers for calculation: ";
    std::cin >> firstNum >> secondNum;
	if (std::cin.fail()) { // Check if input is valid
        std::cout << "Invalid input: please enter numbers only.\n";
        return 1;
    }

    char operation;
    std::cout << "Enter operation (+, -, *, /, %): ";
    std::cin >> operation;

    switch (operation) {
    case '+':
        result = firstNum + secondNum;
        print_result(firstNum, secondNum, operation, result);
        break;
    case '-':
        result = firstNum - secondNum;
        print_result(firstNum, secondNum, operation, result);
        break;
    case '*':
        result = firstNum * secondNum;
        print_result(firstNum, secondNum, operation, result);
        break;
    case '/':
        if (secondNum != 0) {
            result = firstNum / secondNum;
            print_result(firstNum, secondNum, operation, result);
        } else {
            std::cout << "Error: Division by zero\n";
        }
        break;
    case '%':
        if (secondNum != 0) {
			result = static_cast<int>(firstNum) % static_cast<int>(secondNum); // Ensure both numbers are treated as integers for modulus
            print_result(static_cast<int>(firstNum), static_cast<int>(secondNum), operation, result);
        } else {
            std::cout << "Error: Division by zero\n";
        }
        break;
    default:
        std::cout << "Error: Invalid operation '" << operation << "'\n";
        break;
    }

    return 0;
}