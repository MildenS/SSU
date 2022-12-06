using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr18_III
{
    internal class Publication:IComparable<Publication>
    {
        //public readonly string className = "publication";
        protected string name;
        protected string authorSurname;

        protected Publication(string name, string authorSurname)
        {
            this.name = name;
            this.authorSurname = authorSurname;
        }

        public int CompareTo(Publication other)
        {
            return authorSurname.CompareTo(other.authorSurname);
            //return string.Compare(authorSurname, other.authorSurname)
        }

        //abstract public bool IsEqual(string authorSurname);
        public bool IsEqual(string authorSurname)
        {
            return authorSurname == this.authorSurname;
        }
    }
}
