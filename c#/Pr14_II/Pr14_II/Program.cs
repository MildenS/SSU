using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr14_II
{
    struct CloakRoom:IComparable<CloakRoom>
    {
        public string Surname;
        public string Name;
        public string SecondName;

        public int NumberOfItems;
        public double TotalWeight;

        public double AverageWeight;
        public CloakRoom(string Surname, string Name, string SecondName, int NumberOfItems, double TotalWeight)
        {
            this.Surname = Surname;
            this.Name = Name;
            this.SecondName = SecondName;
            this.NumberOfItems = NumberOfItems;
            this.TotalWeight = TotalWeight;
            this.AverageWeight=TotalWeight/NumberOfItems;
        }
        public int CompareTo (CloakRoom other)
        {
            if (this.NumberOfItems < other.NumberOfItems)
                return -1;
            else if (this.NumberOfItems > other.NumberOfItems)
                return 1;
            else
                return 0;
        }
        public override string ToString()
        {
            string s=Surname+" "+Name+" "+SecondName+" "+NumberOfItems+" "+TotalWeight;
            return s;
        }
    }
    internal class Program
    {
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            StreamWriter FileWriter = new StreamWriter("output.txt");

            int N = Convert.ToInt32(FileReader.ReadLine());
            double AverageWeight= Convert.ToDouble(FileReader.ReadLine());

            CloakRoom[] arr = new CloakRoom[N];
            string s;
            string[] CloakRooms;
            for (int i = 0; i < N; i++)
            {
                s = FileReader.ReadLine();
                if (s != string.Empty)
                {
                    CloakRooms = s.Split(new char[] { ' ', '\n' }, StringSplitOptions.RemoveEmptyEntries);
                    arr[i] = new CloakRoom(CloakRooms[0], CloakRooms[1], CloakRooms[2], Convert.ToInt32(CloakRooms[3]), Convert.ToDouble(CloakRooms[4]));
                }
                else
                    i--;
            }

            Array.Sort(arr);

            for (int i =0; i<arr.Length; i++)
            {
                if (arr[i].AverageWeight > AverageWeight)
                    FileWriter.WriteLine(arr[i]);
            }

            Console.WriteLine("Program has been ended.");
            FileReader.Close();
            FileWriter.Close();
        }
    }
}
