using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Pr18_III
{
    internal class ElectronicResource:Publication
    {
        protected string URL;
        protected string annotation;

        public ElectronicResource(string name, string authorSurname, string URL, string annotation):
            base(name, authorSurname)
        {
            this.URL = URL;
            this.annotation = annotation;
        }

        public override string ToString()
        {
            return "Electronic resource: " + name + ", " + authorSurname + ", " + URL + ", " + annotation;
        }

    }
}
