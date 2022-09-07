using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

/*
 какая из цифр трехзначного числа больше: первая или вторая; 
*/

namespace Pr2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int a;
            a=Convert.ToInt32(Console.ReadLine());
            string answer = (a > 999 || a < 100) ? "Incorrect input" :
                (a / 100 > a / 10 % 10) ? "First digit is bigger then second" : (a / 100 == a / 10 % 10) ? "First and second digits is equal" :
                "Second digit is bigger then first";
            Console.WriteLine(answer);
        }
    }
}
