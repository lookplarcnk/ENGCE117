using System;
namespace program_test
{
  class Program
  {
    public static void Main(string[] args)
    {
      string str_1 = "50";
      int x_1 = int.Parse(str_1);
      Console.WriteLine(x_1);

      string str_2 = "50";
      int res;
      bool b_1 = int.TryParse(str_2, out res);
      Console.WriteLine(res);

      Console.ReadLine();
    }
  }
}