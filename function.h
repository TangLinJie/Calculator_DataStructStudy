#ifndef FUNCTION_H
#define FUNCTION_H
#include"stack.h"
class Function
{
public:
    static Line getBackE(QString string);
    static bool judge(QChar ch1,QChar ch2);
    static double getResultByLine(Line line);
};

#endif // FUNCTION_H
