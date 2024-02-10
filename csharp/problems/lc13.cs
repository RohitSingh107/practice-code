using System;
using System.Collections.Generic;

namespace lc13
{



    public class Solution
    {
        public int RomanToInt(string s)
        {
            Dictionary<char, int> m = new Dictionary<char, int>();
            m.Add('I', 1);
            m.Add('V', 5);
            m.Add('X', 10);
            m.Add('L', 50);
            m.Add('C', 100);
            m.Add('D', 500);
            m.Add('M', 1000);



            int ans = 0;

            int n = s.Length;
            int i = 0;

            while (i < n - 1)
            {

                int sign = 1;

                if (m[s[i]] < m[s[i + 1]])
                {
                    sign = -1;
                }

                ans += (sign * m[s[i]]);
                i++;

            }

            ans += m[s[i]];



            return ans;

        }

        public void Test()
        {
            // lc151.Solution s = new lc151.Solution();
            string s = "MCMXCIV";
            int ans = RomanToInt(s);
            Console.WriteLine($"ans is {ans}");
        }


    }

}