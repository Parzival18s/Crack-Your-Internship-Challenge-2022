class Solution {
public:
    bool isWhitespace(char charAt)
    {
        return charAt == ' ';
    }
    bool isNumber(char charAt)
    {
        return charAt >= '0' && charAt <= '9';
    }
    int getNumber(char charAt)
    {
        return (int)(charAt - '0');
    }
    bool isOperation(char charAt)
    {
        return charAt == '+' || charAt == '-' || charAt == '/' || charAt == '*';
    }
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int result = 0;
        int currentNum = 0;
        int prevNum = 0;
        char operation = '+';
        for(int i=0;i<s.size();i++)
        {
            char charAt = s[i];
            if(isNumber(charAt))
                currentNum=(currentNum*10)+getNumber(charAt);
            if(isOperation(charAt) || i==s.size()-1)
            {
                if(operation=='+')
                {
                    result+=prevNum;
                    prevNum = currentNum;
                }
                else if(operation == '-')
                {
                    result+=prevNum;
                    prevNum = -currentNum;
                }
                else if(operation == '/')
                    prevNum = prevNum / currentNum;
                else
                    prevNum = prevNum * currentNum;
                operation = charAt;
                currentNum = 0;
            }
        }
        result+=prevNum;
        return result;
    }
};