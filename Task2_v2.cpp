#include <iostream>
#include "stack.cpp"
#include <cstdlib>
using namespace std;
bool isValid = true;
bool checkParenthesis(const string expression)
{
    Stack<char> S;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            S.push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            if (S.isEmpty())
            {
                return false;
            }
            S.pop();
        }
    }
    if (S.isEmpty())
    {
        return true;
    }
    return false;
}
float performOperator(float a, float b, char op)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/' && b != 0)
        return a / b;
    isValid = false;
    return -1;
}
int checkPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
bool isOp(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}
bool isNum(char c)
{
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
        return true;
    return false;
}
string manipulateString(string expression)
{
    int i = 0;
    while (i < expression.length() - 1)
    {
        if (expression[i] == ' ')
        {
            expression.erase(i, 1);
        }
        else if (expression[0] == '-')
        {
            expression.insert(0, "(");
            expression.insert(expression.length(), ")");
        }
        else if (expression[i] == ')' && expression[i + 1] == '(')
        {
            expression.insert(i + 1, "*");
        }
        else if (isNum(expression[i]) && expression[i + 1] == '(')
        {
            expression.insert(i + 1, "*");
        }
        else if (isOp(expression[i]) && expression[i + 1] == '-')
        {
            if (isOp(expression[i + 2]))
            {
                isValid = false;
                return "-1";
            }
            expression.erase(i + 1, 1);
            expression.insert(i + 1, "(-1)*");
        }
        else if (isNum(expression[i + 1]) && expression[i] == ')')
        {
            expression.insert(i + 1, "*");
        }
        i++;
    }
    // cout << expression << endl;
    return expression;
}
float calculateExpression(string expression)
{
    Stack<char> main;
    Stack<float> operand;
    Stack<char> op;
    float remember1;
    float remember2;
    float remember3;
    int remember1L;
    int remember2L;
    int remember3L;
    expression = manipulateString(expression);
    if (!isValid)
        return -1;
    for (int i = expression.length() - 1; i >= 0; i--)
    {
        main.push(expression[i]);
    }
    while (main.length() != 0)
    {
        if (main.topvalue() != '(' &&
            main.topvalue() != ')' &&
            !isNum(main.topvalue()) &&
            !isOp(main.topvalue()))
        {
            isValid = false;
            return -1;
        }
        if (main.topvalue() == '(')
        {
            remember1 = operand.topvalue();
            remember1L = operand.length();
            // if ((remember1 == remember3 && remember1L == remember3L)||(remember5 == remember6 && remember5L == remember6L))
            //{
            //     op.push('*');
            // }
            op.push(main.pop());
        }
        else if (main.topvalue() == ')')
        {
            while (op.topvalue() != '(' && !op.isEmpty())
            {
                if (operand.length() < 2)
                {
                    isValid = false;
                    return -1;
                }
                float a = operand.pop();
                float b = operand.pop();
                char c = op.pop();
                // if (b == remember1 && (c == '-' && op.topvalue() == '('))
                //{
                //     operand.push(b);
                //     float temp = a * (-1.0);
                //     operand.push(temp);
                // }
                operand.push(performOperator(b, a, c));
                if (!isValid)
                    return -1;
            }
            remember3 = operand.topvalue();
            remember3L = operand.length();
            op.pop();
            main.pop();
        }
        else if (isNum(main.topvalue()))
        {
            char temp_num[100];
            int i = 0;
            while (!main.isEmpty() && isNum(main.topvalue()))
            {
                temp_num[i] = main.pop();
                i++;
            }
            temp_num[i] = '\0';
            operand.push(atoi(temp_num));
        }
        else if (isOp(main.topvalue()))
        {
            if (main.topvalue() == '-')
            {
                remember2 = operand.topvalue();
                remember2L = operand.length();
                if (remember1 == remember2 && remember1L == remember2L)
                {
                    operand.push(0);
                }
            }
            while (checkPrecedence(op.topvalue()) >= checkPrecedence(main.topvalue()) && !op.isEmpty())
            {
                if (operand.length() < 2)
                {
                    isValid = false;
                    return -1;
                }
                float a = operand.pop();
                float b = operand.pop();
                char c = op.pop();
                operand.push(performOperator(b, a, c));
                if (!isValid)
                    return -1;
            }
            op.push(main.pop());
        }
    }
    // if (!isValid)
    //     return -1;
    while (!op.isEmpty() && isValid)
    {
        if (operand.length() < 2)
        {
            isValid = false;
            return -1;
        }
        float a = operand.pop();
        float b = operand.pop();
        char c = op.pop();
        operand.push(performOperator(b, a, c));
    }
    if (op.isEmpty() && operand.length() > 1)
    {
        isValid = false;
        return -1;
    }
    return operand.topvalue();
}
int main()
{
    string exp;
    getline(cin, exp);
    isValid = checkParenthesis(exp);
    float answer = calculateExpression(exp);
    if (isValid)
    {

        cout << "Valid Expression" << endl;
        cout << "Computed value: " << answer << endl;
    }
    else
    {
        cout << "Not valid" << endl;
    }
    return 0;
}