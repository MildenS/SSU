using System;
using System.IO;
using System.Globalization;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr16_II
{
    struct Toy
    {
        public string name;
        public float price;
        public int MinAge, MaxAge;
        public Toy(string name, float price, int MinAge, int MaxAge)
        {
            this.name = name;
            this.price = price;
            this.MinAge = MinAge;
            this.MaxAge = MaxAge;
        }
        public override string ToString()
        {
            return name + " " + price + " " + MinAge + " " + MaxAge;
        }
    }


    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            StreamWriter FileWriter = new StreamWriter("output.txt");

            int N, A, B;
            string[] a = FileReader.ReadLine().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
            N = int.Parse(a[0]);
            A = int.Parse(a[1]);
            B = int.Parse(a[2]);

            Toy[] arr = new Toy[N];
            string s;
            string[] Toys;
            for (int i = 0; i < N; i++)
            {
                s = FileReader.ReadLine();
                if (s != string.Empty)
                {
                    Toys = s.Split(new char[] { ' ', '\n' }, StringSplitOptions.RemoveEmptyEntries);
                    arr[i] = new Toy(Toys[0], float.Parse(Toys[1], CultureInfo.InvariantCulture.NumberFormat), Convert.ToInt32(Toys[2]), Convert.ToInt32(Toys[3]));
                }
                else
                    i--;
            }

            var ans =arr.Where(x=>x.MinAge>=A && x.MaxAge<=B).GroupBy(x=>x.name);
            foreach (var items in ans)
            {
                FileWriter.WriteLine(items.Key+':');
                foreach(var item in items)
                {
                    FileWriter.WriteLine("{0} ", item);
                }
                FileWriter.WriteLine();

            }


            FileReader.Close();
            FileWriter.Close();
        }
    }
}
