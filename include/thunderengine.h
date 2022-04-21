//
// Created by kosmas on 12/10/21.
//

#ifndef XCALC_REWRITE_THUNDERENGINE_H
#define XCALC_REWRITE_THUNDERENGINE_H

#include <string>
#include <vector>

enum ElementType {
    ELEMENTTYPE_NUMBER,
    ELEMENTTYPE_VARIABLE,
    ELEMENTTYPE_OPERATOR
};

enum InterpretedOperator {
    INTERPRETEDOPERATOR_ADDITION,
    INTERPRETEDOPERATOR_SUBTRACTION,
    INTERPRETEDOPERATOR_MULTIPLICATION,
    INTERPRETEDOPERATOR_DIVISION,
    INTERPRETEDOPERATOR_PARENTHESESOPEN,
    INTERPRETEDOPERATOR_PARENTHESESCLOSE,
    INTERPRETEDOPERATOR_INVALID
};

struct OperationElement {
    union {
        double number;
        char character;
    }value;
    ElementType type;
};

class ThunderEngine {
private:
    std::vector<struct OperationElement> convertMathExpressionStringToElements();
    double evaluateOperation(std::vector <struct OperationElement> operationToEvaluate);
    bool exit;
    bool errored;
    std::string infoMessage;

public:
    std::string mathExpression;

    ThunderEngine();
    double evaluateMathExpression();
    std::string getInfoMessage();
    bool hasErrored();
    bool shouldExit();
    void concatenateDigitToNumberElement(OperationElement *dest, OperationElement *src);
    double getNextNumber(std::vector<struct OperationElement> *operationToEvaluate);
    InterpretedOperator getNextOperator(std::vector<struct OperationElement> *operationToEvaluate);
};


#endif //XCALC_REWRITE_THUNDERENGINE_H
