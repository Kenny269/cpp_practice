#include <stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int money,profit;
    int start,end;
    cout<<"请输入你的理财本金和收益（不包含本金），以回车结束"<<endl;
    cin>>money>>profit;
    cout<<"请输入你的购买日期和取款日期，如「20240110」，以回车结束"<<endl;
    cin>>start>>end;
   //日期处理
   int y0,m0,d0,y1,m1,d1;
   y0=start/10000;
   start=start-(y0*10000);
   y1=end/10000;
   end=end-(y1*10000);
   m0=start/100;
   start=start-(m0*100);
   m1=end/100;
   end=end-(m1*100);
   d0=start;
   d1=end;
    int days;
    //将日期差转化为天数
    int start_days=360*y0+(m0-1)*30+d0;
    int end_days=360*y1+(m1-1)*30+d1;
    if(start_days>=end_days){
        cout<<"invalid input"<<endl;
        return 0;
    }
    days = end_days-start_days;

    float profit_per_day,cache0,cache1;
    cache0=profit;
    cache1=days;
    profit_per_day = cache0/cache1;
    //日均收益
    float daily_profit_rate,cache3;
    cache3=money;
    daily_profit_rate = profit_per_day/cache3;
    daily_profit_rate = daily_profit_rate * 100;
    // cout<<"da"<<daily_profit_rate;
    float year_prof=daily_profit_rate*360;
    cout<<"年化利率"<<year_prof<<"%"<<endl;
    return 0;
}
