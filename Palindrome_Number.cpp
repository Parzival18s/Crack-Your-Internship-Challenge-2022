class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x==10)
            return false;
        int y=x,tmp,z=0;
        while(x>0)
        {
            tmp=x%10;
            z+=tmp;
            z*=10;
            x/=10;
        }
        z/=10;
        if(y==z)
            return true;
        return false;
    }
};