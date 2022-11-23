using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr17_III
{
    internal class Rectangle
    {
        //1
        int a, b;

        //2
        public Rectangle(int a, int b)
        {
            if (a < 0 || b < 0)
            {
                //throw new ArgumentException("invalid parameters of rectangle construction");
                Console.WriteLine("invalid value in rectangle's constructor");
                this.a = 0;
                this.b = 0;
                return;
            }
            this.a = a;
            this.b = b;
        }

        //для оператора умножения на скаляр
        Rectangle(Rectangle other)
        {
            this.a = other.a;
            this.b = other.b;
        }

        //3
        public override string ToString()
        {
            return a.ToString() + " " + b.ToString();
        }
        public int Perimetr()
        {
            return (a + b) * 2;
        }
        public int Area()
        {
            return a * b;
        }

        //4
        public int A
        {
            get { return a; }
            set
            {
                if (value < 0)
                {
                    //throw new ArgumentException("invalid value a");
                    Console.WriteLine("invalid value a");
                    a = 0;
                    return;
                }
                a = value;
            }
        }
        public int B
        {
            get { return b; }
            set
            {
                if (value < 0)
                {
                    //throw new ArgumentException("invalid value a");
                    Console.WriteLine("invalid value b");
                    b = 0;
                    return;
                }
                b = value;
            }
        }
        public bool IsSquare
        {
            get
            {
                return a == b;
            }
        }

        //5
        public int this[int i]
        {
            get
            {
                if (i == 0)
                    return a;
                else if (i == 1)
                    return b;
                else
                {
                    Console.WriteLine("invalid rectangle index");
                    return -1;
                }
            }
            set
            {
                if (i == 0 && value >= 0)
                    a = value;
                else if (i == 0)
                    Console.WriteLine("invalid value in indexing");
                else if (i == 1 && value >= 0)
                    b = value;
                else if (i == 1)
                    Console.WriteLine("invalid value in indexing");
                else
                {
                    Console.WriteLine("invalid rectangle index");
                }
            }
        }

        //6
        public static Rectangle operator ++(Rectangle obj)
        {
            return new Rectangle(++obj.a, ++obj.b);
        }
        public static Rectangle operator --(Rectangle obj)
        {
            if (obj.a ==0 || obj.b ==0)
            {
                Console.WriteLine("can't to decremented (zero value in coordinates)");
                return obj;
            }
            return new Rectangle(--obj.a, --obj.b);
        }
        public static bool operator true(Rectangle obj)
        {
            return obj.IsSquare;
        }
        public static bool operator false(Rectangle obj)
        {
            return !obj.IsSquare;
        }
        public static Rectangle operator *(Rectangle obj, int x)
        {
            if (x<0)
            {
                Console.WriteLine("invalid rectangle multiplier");
                return obj;
            }
            Rectangle temp = new Rectangle(obj);
            temp.a *= x;
            temp.b *= x;
            return temp;
        }
    }
}
