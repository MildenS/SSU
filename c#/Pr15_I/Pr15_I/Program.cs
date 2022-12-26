using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr15_I
{
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            StreamWriter FileWriter = new StreamWriter("output.txt");

            int A = int.Parse(FileReader.ReadLine());

            string s=FileReader.ReadToEnd();
            string[] arr = s.Split(new char[] { ' ', ',', '\n', '\t', '\r' }, StringSplitOptions.RemoveEmptyEntries);

            List<int> nums = new List<int>();
            for(int i=0; i < arr.Length; i++)
            {
                nums.Add(int.Parse(arr[i]));
            }
            var ans = from n in nums where n < A orderby n select (n>=0 ? 3 * n : n/3);

            foreach (int i in ans)
            {
                FileWriter.WriteLine(i);
            }

            Console.WriteLine("Program has been ended");
            FileReader.Close();
            FileWriter.Close();
        }
    }
}
