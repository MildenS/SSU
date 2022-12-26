using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

struct SPoint
{
    public double x;
    public double y;
    public SPoint(double x, double y)
    {
        this.x = x;
        this.y = y;
    }
    public double Distance (SPoint other)
    {
        return Math.Sqrt(Math.Pow((this.x-other.x),2) + Math.Pow((this.y-other.y), 2));
    }

    public override string ToString()
    {
        string s = x + " " + y;
        return s;
    }
}

namespace Pr14_I
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            StreamWriter FileWriter = new StreamWriter("output.txt");

            int N=Convert.ToInt32(FileReader.ReadLine());
            SPoint[] arr = new SPoint[N];

            string s;
            string[] Coordinates;
            double x;
            double y;
            for (int i = 0; i < N; i++)
            {
                s= FileReader.ReadLine();
                if (s != string.Empty)
                {
                    Coordinates = s.Split(new char[] { ' ', '\n' }, StringSplitOptions.RemoveEmptyEntries);
                    x = Convert.ToDouble(Coordinates[0]);
                    y = Convert.ToDouble(Coordinates[1]);
                    arr[i] = new SPoint(x, y);
                }
                else
                    i--;
            }

            int Index=0;
            double MaxDist = 0;
            double SumOfDist = 0;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    SumOfDist += arr[i].Distance(arr[j]);
                }
                if (SumOfDist>MaxDist)
                {
                    MaxDist = SumOfDist;
                    Index = i;
                }
                SumOfDist = 0;
            }

            FileWriter.WriteLine(arr[Index]);
            Console.WriteLine("Program has been ended.");
            FileReader.Close();
            FileWriter.Close();
        }
    }
}
