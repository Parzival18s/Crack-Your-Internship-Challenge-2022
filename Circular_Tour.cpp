class Solution{
  public:
    int tour(petrolPump p[],int n)
    {
       int g=0,d=0,f=0,ans=0;
       for(int i=0;i<n;i++)
       {
           g+=p[i].petrol;
           d+=p[i].distance;
           f+=p[i].petrol;
           f-=p[i].distance;
           if(f<0)
           {
               f=0;
               ans=i+1;
           }
       }
       if(g<d)
        return -1;
    return ans;
    }
};