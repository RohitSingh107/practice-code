using System.Diagnostics;

namespace lc8
{
    public class Solution
    {

        private int toInt(char c)
        {
            switch (c)
            {

                case '1':
                    return 1;
                case '2':
                    return 2;
                case '3':
                    return 3;
                case '4':
                    return 4;
                case '5':
                    return 5;
                case '6':
                    return 6;
                case '7':
                    return 7;
                case '8':
                    return 8;
                case '9':
                    return 9;
                case '0':
                    return 0;

                default:
                    return -1;
            }
        }
        public int MyAtoi(string s)
        {

            long ans = 0;

            long sign = 1;

            bool digitReading = false;

            string digit = "";

            foreach (char c in s)
            {
                if (c == '-' && !digitReading)
                {
                    sign = -1;
                    digitReading = true;
                    continue;
                }
                if (c == '+' && !digitReading)
                {
                    sign = 1;
                    digitReading = true;
                    continue;
                }
                if (c == ' ' && digitReading)
                {
                    break;
                }

                if (c == ' ')
                {
                    continue;
                }

                if (toInt(c) != -1)
                {
                    digitReading = true;

                    if (c == '0' && digit == "")
                    {
                        continue;
                    }
                    digit += c;

                }
                else
                {
                    break;
                }
            }

            int n = digit.Length;
            // Console.WriteLine($"digit is:{digit}, n is {n}");

            if (n > 10)
            {
                if (sign == 1)
                {
                    return 2147483647;
                }
                return -2147483648;
            }

            for (int i = 0; i < n; i++)
            {
                // ans += (long)(toInt(digit[i]) * Math.Pow(10, n - 1 - i));
                ans += (long)(toInt(digit[i]) * Math.Pow(10, n - 1 - i));

                if (sign * ans >= 2147483647)
                {
                    // Console.WriteLine($"sign is {sign}, ans is {ans}");
                    return 2147483647;
                }

                if (sign * ans <= -2147483648)
                {
                    return -2147483648;
                }
            }



            return (int)(sign * ans);

        }

        public void Test()
        {
            // string s = "4193 with words";
            // string s = "words and 987";
            // string s = "   -42";
            // string s = "42";
            // string s = "-91283472332";
            // string s = "+-12";
            // string s = "00000-42a1234";
            // string s = "20000000000000000000";
            string s = "  0000000000012345678";

            int ans = MyAtoi(s);
            Console.WriteLine($"ans is {ans}");
        }
    }
}