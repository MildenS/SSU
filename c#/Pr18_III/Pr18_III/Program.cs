using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr18_III
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            StreamWriter FileWriter = new StreamWriter("output.txt");
            int n=int.Parse(FileReader.ReadLine());
            string authorSurname = FileReader.ReadLine();

            Publication[] catalog = new Publication[n];
            string line;
            string[] info;
            for (int i = 0; i < n; i++)
            {
                line = FileReader.ReadLine();
                if (line.Length == 0)
                {
                    --i;
                    continue;
                }
                info = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                switch (info[0])
                {
                    case "book":
                        catalog[i] = new Book(info[1], info[2], uint.Parse(info[3]), info[4]);
                        break;
                    case "article":
                        catalog[i] = new Article(info[1], info[2], info[3], ulong.Parse(info[4]), uint.Parse(info[5]));
                            break;
                    case "er":
                        catalog[i] = new ElectronicResource(info[1], info[2], info[3], info[4]);
                        break;
                    default:
                        i--;
                        break;
                }
            }

            FileWriter.WriteLine("Full catalog information: -----------------------");
            foreach (var item in catalog)
            {
                FileWriter.WriteLine(item);
            }

            FileWriter.WriteLine();
            FileWriter.WriteLine("Searched information: -----------------------");
            foreach (Publication item in catalog)
            {
                if (item.IsEqual(authorSurname))
                    FileWriter.WriteLine(item);
            }

            FileWriter.WriteLine();
            FileWriter.WriteLine("Sorted catalog information: -----------------------");
            Array.Sort(catalog);
            foreach (var item in catalog)
            {
                FileWriter.WriteLine(item);
            }


            FileWriter.Close();
            FileReader.Close();
            Console.WriteLine("Program has been ended succesfully");
        }
    }
}
