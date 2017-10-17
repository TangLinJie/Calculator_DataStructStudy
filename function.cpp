#include"function.h"
bool Function::judge(QChar ch1,QChar ch2)
{

   if(ch1=='*'||ch1=='/')          //ch1为待判断运算符
   {
       if(ch2=='*'||ch2=='/')
           return false;
       return true;
   }
   if(ch1=='+'||ch1=='-')
   {
       if(ch2=='('||ch2=='#')
           return true;
       return false;
   }
   return true;
}
Line Function::getBackE(QString string)
{
   Line line;
   Stack stack;
   QString temString;         //暂存字符串

   stack.push("#");

   string=string.trimmed();   //除去无关字符
   string.append('#');
   if(string.at(0)=='-')      //修改字符串，使其合法
       string.prepend('0');
   for(;string.contains("(-");)    //处理单目
       string.insert(string.indexOf("(-")+1,'0');
       string.remove(' ');   //使当前字符串合法
       string.remove('\n');



   for(int i=0;i<string.size();i++)
   {
       if(string.at(i).isNumber()||string.at(i)=='.')
           temString.append(string.at(i));
       else
       {

           if(temString!=NULL)
           {

                  //压上面的数字符串进队列
           line.push(temString);
           temString.clear();
           }
           if(string.at(i)!=')'&&string.at(i)!='#')
           {

              if(judge(string.at(i),stack.getTop()->value.at(0)))  //当前运算符优先级大于栈顶运算符
              {
                  temString.append(string.at(i));
                      stack.push(temString);
                  temString.clear();
              }
              else
                 {
                    while(stack.getTop()->value.at(0)!='#'&&!judge(string.at(i),stack.getTop()->value.at(0)))// 依次判断前面的符号优先级
                    {
                        stack.pop(temString);
                      line.push(temString);
                      temString.clear();
                    }
                    stack.push(string.at(i));


                 }

           }
                 if(string.at(i)==')')
                 {
                     StackNode* currentStackNode=stack.getTop();
                     for(;currentStackNode->value!="("&&currentStackNode!=NULL;)
                     {
                         currentStackNode=currentStackNode->next;
                     stack.pop(temString);

                   line.push(temString);
                   temString.clear();
                     }
                     if(currentStackNode==NULL)
                         exit(1);
                     stack.pop(temString);
                     temString.clear();
                 }
               if(string.at(i)=='#')
               {

                   for(StackNode* current=stack.getTop();current->value!="#";)
                   {
                       current=current->next;
                       stack.pop(temString);
                        line.push(temString);
                       temString.clear();

                   }
               }

       }


   }
          return line;
}


double Function::getResultByLine(Line line)
{
   QString current;
   QString num1;
   QString num2;
   Stack stack;
   line.pop(current);            //弹出两个数
   stack.push(current);
   line.pop(current);
   stack.push(current);

   for(;!line.isEmply();)
   {
        line.pop(current);
          if(current!='+'&&current!='-'&&current!='*'&&current!='/')
          {
              stack.push(current);
          }
          else
          {
              stack.pop(num1);
              stack.pop(num2);
              double n1=num1.toDouble();
              double n2=num2.toDouble();
              if (current=="+")
                  n1=n2+n1;
              if(current=="-")
                  n1=n2-n1;
              if(current=="*")
                  n1=n2*n1;
              if(current=="/")
                  n1=n2/n1;


             stack.push(QString::number(n1));

          }
   }
   stack.pop(current);
 double result=current.toDouble();
 return result;
}
