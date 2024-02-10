

using System.Runtime.InteropServices.Marshalling;

namespace lc14
{
  public class Solution
  {
    public string LongestCommonPrefix(string[] strs)
    {

      string ans = "";

      int i = 0;

      while (true)
      {

        char ob;

        if (strs[0].Length == i)
        {
          return ans;
        }
        else
        {

          ob = strs[0][i];

        }

        // Console.WriteLine($"Char is {ob}");

        foreach (string s in strs)
        {

          if (s.Length == i)
          {
            return ans;
          }
          if (s[i] != ob)
          {
            return ans;
          }
        }
        ans += ob;
        i++;

      }

    }

    public void Test()
    {
      // string[] strs = ["flower", "flow", "flight"];
      string[] strs = ["dog", "racecar", "car"];

      string ans = LongestCommonPrefix(strs);

      Console.WriteLine($"ans is: {ans}");
    }
  }
}
