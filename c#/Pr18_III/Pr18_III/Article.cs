using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr18_III
{
    internal class Article: Publication
    {
        protected string journalName;
        protected ulong journalNumber;
        protected uint publicationYear;

        public Article(string name, string authorSurname, string journalName, ulong journalNumber, uint publicationYear):
            base(name, authorSurname)
        {
            this.journalName = journalName; 
            this.journalNumber = journalNumber;
            this.publicationYear = publicationYear;
        }

        public override string ToString()
        {
            return "Article: " + name + ", " + authorSurname + ", " + journalName + ", " + journalNumber + ", " + publicationYear;
        }
    }
}
