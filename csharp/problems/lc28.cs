// https://leetcode.com/problems/repeated-string-match/description/

using System.Text.RegularExpressions;

namespace lc28
{

    public class Solution
    {



        public int StrStr(string text, string pattern)
        {

            // Console.WriteLine($"a is {text}, b is {pattern}");

            // int M = 2147483647;
            int M = 1000000;

            int m = pattern.Length;
            int n = text.Length;

            if (n < m)
            {
                return -1;
            }

            if (m == 0 || n == 0)
            {
                return -1;
            }
            int p = 1;

            for (int i = 0; i < m; i++)
            {
                p = (p * 26) % M;
            }

            int hash = 0;
            for (int i = 0; i < m; i++)
            {
                hash = (hash * 26 + pattern[i]) % M;
                // if (hash < 0)
                // {
                //     hash += M;
                // }
            }
            // Console.WriteLine($"hash is {hash}");


            int currentHash = 0;
            // Console.WriteLine($"p is {p}");
            for (int i = 0; i < n; i++)
            {
                currentHash = ((currentHash * 26) + text[i]) % M;
                if (currentHash < 0)
                {
                    currentHash += M;
                }

                if (i < m - 1)
                {
                    continue;
                }

                if (i >= m)
                {
                    currentHash -= ((text[i - m] * p) % M);
                    if (currentHash < 0)
                    {
                        currentHash += M;
                    }
                }
                // Console.WriteLine($"CH1 is {currentHash}, target is {hash}, i is {i}");


                if (currentHash == hash)
                {
                    if (text.Substring(i - m + 1, m) == pattern)
                    {
                        return i - m + 1;
                    }
                }
            }


            return -1;
        }

        public void Test()
        {
            string a = "abcd";
            string b = "cdabcdab";

            int ans = StrStr(a, b);
            Console.WriteLine($"ans is {ans}");
        }
    }

}
