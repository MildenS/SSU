using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr18_III
{
    internal class Book: Publication 
    {
        //new protected readonly string className = "book";
        protected uint publicationYear;
        protected string publisher;
        //protected string name;
        //protected string authorSurname;

        public Book (string name, string authorSurname, uint publicationYear, string publisher):base(name, authorSurname)
        {
            this.publicationYear = publicationYear;
            this.publisher = publisher;
        }

        public override string ToString()
        {
            return "Book: " + name +", "+ authorSurname +", "+ publicationYear + ", " + publisher;
        }
    }
}
