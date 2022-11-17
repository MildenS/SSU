using System;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Text.RegularExpressions;

namespace Task
{
    class Program
    {
        static string niceSentencePat = @"(^[A-Z])|(^[A-Z])(\w)+";
        static string niceWordPat = @"(^[a-zA-Z]$)|(^[a-zA-Z])([a-z]+$)|(^[a-zA-Z])([a-z]+)-([a-z]+$)|(^[A-Z]+$)|(^[a-zA-Z])([a-z]+)\'([a-z]*$)";

        static Regex niceWordReg = new Regex(niceWordPat);
        static Regex niceSentenceReg = new Regex(niceSentencePat);

        static string[] separSymbols = { " ", ", ", "; ", "- ", ", - " };
        static string[] endSymbols = { ". ", "... ", "! ", "? " };

        static bool isNiceSentence(string text)
        {
            if (!(niceSentenceReg.IsMatch(text)))
                return false;

            return true;
        }
        static bool isNiceWord(string word)
        {
            return (niceWordReg.IsMatch(word));
        }

        static bool isNiceText(string text)
        {
            string[] sentence = text.Split(endSymbols, StringSplitOptions.RemoveEmptyEntries);

            foreach (var item in sentence)
            {
                if (!isNiceSentence(item))
                    return false;

                string[] words = item.Split(separSymbols, StringSplitOptions.RemoveEmptyEntries);

                foreach (var word in words)
                {
                    if (!isNiceWord(word))
                        return false;
                }
            }

            return true;
        }
        static void Main(string[] args)
        {
            StreamReader FileReader = new StreamReader("input.txt");
            string text = FileReader.ReadToEnd();
            Console.WriteLine(isNiceText(text));
        }
    }
}