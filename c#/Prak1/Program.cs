using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 3) запрашивает с клавиатуры три целых числа, и выводит на экран сумму данных чисел:
a= 24
b= 5
c= 36
24+5+36=65;
 */

namespace Pr1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a, b, c;
            Console.Write("a= ");
            a=Convert.ToInt32(Console.ReadLine());
            Console.Write("b= ");
            b = Convert.ToInt32(Console.ReadLine());
            Console.Write("c= ");
            c = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine($"{a}+{b}+{c}={a+b+c}");
            /*
             int d=a+b+c;
            Console.WriteLine("{0}+{1}+{2}={3}",a,b,c,d);
             */
        }
    }
}
