using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr17_III
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            int a, b, x;
            string Params = FileReader.ReadLine();
            a = Convert.ToInt32(Params.Split(' ')[0]); 
            b = Convert.ToInt32(Params.Split(' ')[1]); 
            x = Convert.ToInt32(Params.Split(' ')[2]); 

            //1 and 2
            Rectangle rectangle = new Rectangle(a, b);

            //3
            Console.WriteLine("Rectangle: "+ rectangle);
            Console.WriteLine("Perimetr = "+ rectangle.Perimetr());
            Console.WriteLine("Area = "+ rectangle.Area());

            //4
            rectangle.A = 6;
            rectangle.B = 6;
            Console.WriteLine("New rectangle: " + rectangle);
            Console.WriteLine("Is square: " + rectangle.IsSquare);

            //5
            Console.WriteLine("rectangle sides: a = " + rectangle[0] + ", b = " + rectangle[1]);
            rectangle[3] = 1;

            //6
            rectangle++;
            Console.WriteLine("incremented rectangle: " + rectangle);
            rectangle--;
            Console.WriteLine("decremented rectangle: " + rectangle);
            if (rectangle)
                Console.WriteLine("rectangle is square");
            else
                Console.WriteLine("rectangle isn't square");
            rectangle *= x;
            Console.WriteLine("rectangle after multiplication: " + rectangle);
        }
    }
}
