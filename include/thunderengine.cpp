//
// Created by kosmas on 12/10/21.
//

#include <vector>
#include "thunderengine.h"

std::vector<struct OperationElement> ThunderEngine::convertMathExpressionStringToElements() {
    this->mathExpression.erase(std::remove(this->mathExpression.begin(), this->mathExpression.end(), ' '), this->mathExpression.end());
    unsigned long length = this->mathExpression.length();
    std::vector<struct OperationElement> fullOperation(length);
    OperationElement currentElement {};

    for (unsigned long i = 0; i < length; ++i) {
        char currentChar = this->mathExpression[i];
        if (isdigit(currentChar)) {
            currentElement.type = ELEMENTTYPE_NUMBER;
            currentElement.value.number = atoi(&currentChar);
        }
        else {
            switch (currentChar) {
                case '+':
                case '-':
                case '/':
                case '*':
                    break;
                default:
                    this->errored = true;
                    this->infoMessage = "Invalid character";
                    break;
            }
            currentElement.type = ELEMENTTYPE_OPERATOR;
            currentElement.value.character = currentChar;
        }
        fullOperation[i] = currentElement;
    }
    
    return fullOperation;
}

ThunderEngine::ThunderEngine() {
    this->mathExpression = "";
    this->infoMessage = "";
    this->exit = false;
    this->errored = false;
}

void ThunderEngine::concatenateDigitToNumberElement(OperationElement *dest, OperationElement *src) {
    dest->value.number *= 10;
    dest->value.number += src->value.number;
}

double ThunderEngine::getNextNumber(std::vector <struct OperationElement> *operationToEvaluate) {
    int numbersInElement = 0;
    int j = 0;

    std::vector <struct OperationElement> &operation = *operationToEvaluate;

    // When this function enters, the number will always be the first thing in the current operation
    if (operation[0].type == ELEMENTTYPE_NUMBER) {
        while (operation[j].type == ELEMENTTYPE_NUMBER && j < operation.size()) {
            ++numbersInElement;
            if (numbersInElement > 1) {
                this->concatenateDigitToNumberElement(&(operation[0]), &(operation[j]));
                operation.erase(operation.begin() + j);
                j = 0;
            }
            j++;
        }
    }
    double number = operation[0].value.number;
    return number;
}

enum InterpretedOperator ThunderEngine::getNextOperator(std::vector<struct OperationElement> *operationToEvaluate) {

    std::vector <struct OperationElement> &operation = *operationToEvaluate;

    if (operation[0].type == ELEMENTTYPE_OPERATOR) {
        switch (operation[0].value.character) {
            case '+':
                return INTERPRETEDOPERATOR_ADDITION;
            case '-':
                return INTERPRETEDOPERATOR_SUBTRACTION;
            case '*':
                return INTERPRETEDOPERATOR_MULTIPLICATION;
            case '/':
                return INTERPRETEDOPERATOR_DIVISION;
            case '(':
                return INTERPRETEDOPERATOR_PARENTHESESOPEN;
            case ')':
                return INTERPRETEDOPERATOR_PARENTHESESCLOSE;
            default:
                return INTERPRETEDOPERATOR_INVALID;
        }
    }
    return INTERPRETEDOPERATOR_INVALID;
}

double ThunderEngine::evaluateOperation(std::vector <struct OperationElement> operationToEvaluate) {
    while (operationToEvaluate.size() > 1) {
        double firstNumber = this->getNextNumber(&operationToEvaluate);
        operationToEvaluate.erase(operationToEvaluate.begin());
        InterpretedOperator interpretedOperator = this->getNextOperator(&operationToEvaluate);
        operationToEvaluate.erase(operationToEvaluate.begin());
        double secondNumber = this->getNextNumber(&operationToEvaluate);
        operationToEvaluate.erase(operationToEvaluate.begin());

        struct OperationElement elementToInsert{};
        elementToInsert.type = ELEMENTTYPE_NUMBER;

        switch (interpretedOperator) {
            case INTERPRETEDOPERATOR_ADDITION:
                elementToInsert.value.number = firstNumber + secondNumber;
                break;
            case INTERPRETEDOPERATOR_SUBTRACTION:
                elementToInsert.value.number = firstNumber - secondNumber;
                break;
            case INTERPRETEDOPERATOR_MULTIPLICATION:
                elementToInsert.value.number = firstNumber * secondNumber;
                break;
            case INTERPRETEDOPERATOR_DIVISION:
                elementToInsert.value.number = firstNumber / secondNumber;
                break;
            case INTERPRETEDOPERATOR_PARENTHESESOPEN:
            case INTERPRETEDOPERATOR_PARENTHESESCLOSE:
                break;
            case INTERPRETEDOPERATOR_INVALID:
                this->errored = true;
                this->infoMessage = "Invalid or unsupported operator provided";
        }
        operationToEvaluate.insert(operationToEvaluate.begin(), elementToInsert);
    }

    return operationToEvaluate[0].value.number;
}

double ThunderEngine::evaluateMathExpression() {
    // Perform some basic sanity checks
    if (this->mathExpression.length() < 3) {
        this->errored = true;
        this->infoMessage = "Invalid mathematical expression provided (Too short)";
        return 0;
    }

    std::vector<struct OperationElement> operationToEvaluate = this->convertMathExpressionStringToElements();
    return this->evaluateOperation(operationToEvaluate);
}

bool ThunderEngine::shouldExit() {
    return this->exit;
}

std::string ThunderEngine::getInfoMessage() {
    return this->infoMessage;
}

bool ThunderEngine::hasErrored() {
    return this->errored;
}
