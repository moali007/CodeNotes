class Pair
{
    int value;
    boolean poss;
    public Pair(int value, boolean poss)
    {
        this.value = value;
        this.poss = poss;
    }
}
class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        Pair[][] dp = new Pair[n1][n2];
        for(int i = 0; i < n1; i++)
        {
            char ch1 = s1.charAt(i);
            for(int j = 0; j < n2; j++)
            {
                char ch2 = s2.charAt(j);
                if(i == 0 && j == 0)
                {
                    if(ch1 != ch2)
                    {
                        dp[i][j] = new Pair(ch1 + ch2, false);
                    }
                    else
                    {
                        dp[i][j] = new Pair(0, true);
                    }
                }
                else if(i == 0)
                {
                    Pair before = dp[i][j - 1];
                    if(ch1 != ch2)
                    {
                        dp[i][j] = new Pair(before.value + ch2, before.poss);
                    }
                    else
                    {
                        dp[i][j] = before.poss == true ? new Pair(before.value + ch2, before.poss) : new Pair(before.value - ch2, true);
                    }
                }
                else if(j == 0)
                {
                    Pair before = dp[i - 1][j];
                    if(ch1 != ch2)
                    {
                        dp[i][j] = new Pair(before.value + ch1, before.poss);
                    }
                    else
                    {
                        dp[i][j] = before.poss == true ? new Pair(before.value + ch1, before.poss) : new Pair(before.value - ch1, true);
                    }
                }
                else
                {
                    if(ch1 == ch2)
                    {
                        dp[i][j] = new Pair(dp[i - 1][j - 1].value, true);
                    }
                    else
                    {
                        Pair up = dp[i - 1][j];
                        Pair left = dp[i][j - 1];
                        dp[i][j] = new Pair(Math.min(up.value + ch1, left.value + ch2), up.poss || left.poss);
                    }
                }
            }
        }
        return dp[n1 - 1][n2 - 1].value;
    }
}

//       j
//       e     a     t
//  i  s 216   313   429

//     e 115   212   328

//     a 115    115   231

// a=97 b=98 c=99 d=100 e=101 f=102 g=103 h=104 i=105 j=106
// k=107 l=108 m=109 n=110 o=111 p=112 q=113 r=114 s=115 t=116
// u=117 v=118 w=119 x=120 y=121 z=122