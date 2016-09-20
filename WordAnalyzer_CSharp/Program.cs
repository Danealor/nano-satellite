using System;
using System.IO;
using System.Linq;

namespace WordAnalyzer_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write(new string(File.ReadAllText(args[0]).Where(c => char.IsLetter(c) || c == ' ').ToArray()).ToLower().Split(' ').GroupBy(s => s).OrderBy(g => g.Key).SelectMany(g => g.Key + ": " + g.Count() + "\n").ToArray());
        }
    }
}
