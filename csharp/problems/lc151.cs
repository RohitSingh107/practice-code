
public class Solution
{

    static private List<string> Split(string s)
    {

        List<string> ans = [];

        int n = s.Length;

        string tmp = "";

        foreach (char c in s)
        {
            if (c == ' ' && tmp != "")
            {
                // Console.WriteLine($"here c is {c}");

                ans.Add(tmp);
                tmp = "";

            }
            else
            {
                // Console.WriteLine($"c is {c}");
                if (c != ' ')
                {
                    // Console.WriteLine($"here2 c is {c}");
                    tmp += c;
                    // Console.WriteLine($"tmp0 is {tmp}");
                }

            }
            // Console.WriteLine($"tmp is {tmp}");
        }
        if (tmp != "")
        {
            ans.Add(tmp);
        }

        return ans;
    }
    public string ReverseWords(string s)
    {

        // Console.WriteLine($"{s[0] == ' '}");

        List<string> ss = Split(s);
        ss.Reverse();
        // Console.WriteLine(ss);
        // foreach (string x in ss)
        // {
        //   Console.WriteLine($"word is {x}");
        // }
        return String.Join(" ", ss);
    }
}

public class M
{
    static public void Main()
    {
        Solution s = new Solution();
        string ans = s.ReverseWords("         tahe     s4ky is           bxaxlued rohit");
        Console.WriteLine(ans);

    }
}