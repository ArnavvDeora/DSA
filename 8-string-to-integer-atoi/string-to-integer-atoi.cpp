class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ')
        {
            i++;
        }
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long result=0;
        while(i<s.size() && s[i]>='0' && s[i]<='9')
        {
            result=result*10+(s[i]-'0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return (int)(result * sign);
    }
};