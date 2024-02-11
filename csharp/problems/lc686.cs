// https://leetcode.com/problems/repeated-string-match/description/

using System.Text.RegularExpressions;

namespace lc686
{

    public class Solution
    {
        public int RepeatedStringMatch(string a, string b)
        {

            Console.WriteLine(RabinKarp("abcdabcdabcd", "cdabcdab"));
            // int ans = 1;
            // string newa = a;
            // while (newa.Length < b.Length)
            // {
            //     newa += a;
            //     ans += 1;
            // }

            // if (RabinKarp(newa, b) != -1)
            // {
            //     return ans;
            // }
            // if (RabinKarp(newa + a, b) != -1)
            // {
            //     return ans + 1;
            // }

            return -1;

        }


        private int RabinKarp(string text, string pattern)
        {

            Console.WriteLine($"a is {text}, b is {pattern}");

            int M = 2147483647;
            // int M = 1;

            int m = pattern.Length;
            int n = text.Length;

            if (n < m)
            {
                return -1;
            }

            double hash = 0;

            for (int i = 0; i < m; i++)
            {
                hash += (1L * (pattern[i] * (Math.Pow(26L, m - i - 1) % M))) % M;
            }
            // Console.WriteLine($"hash is {hash}");


            double currentHash = 0;

            for (int i = 0; i < m; i++)
            {
                currentHash += (1L * (text[i] * Math.Pow(26L, m - i - 1) % M)) % M;
            }

            if (currentHash == hash)
            {
                bool match = true;

                for (int i = 0; i < m; i++)
                {
                    if (text[i] != pattern[i])
                    {
                        match = false;
                        break;
                    }
                }

                if (match)
                {
                    return m - 1;
                }

            }

            for (int i = m; i < n; i++)
            {
                // Console.WriteLine($"i is {i}, m is {m}, h is {currentHash}");
                var coeff = Math.Pow(26L, m - 1);
                var firstComp = (text[i - m] * coeff);
                var beforeLatest = currentHash - firstComp;
                var final = ((beforeLatest * 10)) + text[i];
                Console.WriteLine($" coeed is {coeff}, fc is {firstComp}, bl is {beforeLatest}, final is {final}, m is {m}");
                currentHash = final;

                // currentHash = (((currentHash - (pv)) * 26) % M) + text[i];
                // Console.WriteLine($"ch {currentHash}, hash is {hash}, i is {i}, p is {p}, pv is {pv}");

                if (currentHash == hash)
                {
                    bool match = true;

                    for (int j = 0; j < m; j++)

                    {
                        // Console.WriteLine($"i is {i}, here t is {i - m + 1 + j}, p is {j}");
                        if (text[i - m + 1 + j] != pattern[j])
                        {

                            match = false;
                            break;
                        }
                    }

                    if (match)
                    {
                        return i;
                    }

                }
            }


            return -1;
        }

        public void Test()
        {
            string a = "abcd";
            string b = "cdabcdab";

            int ans = RepeatedStringMatch(a, b);
            Console.WriteLine($"ans is {ans}");
        }
    }

}
