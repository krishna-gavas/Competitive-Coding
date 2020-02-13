// Long Contest and Cook Off Overlaps

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int m1,m2,month,lcs,lce,co,day,d=1,d1,count=0;
        long int y1,y2,y,year,year1;
        cin>>m1>>y1;
        cin>>m2>>y2;

        month = m1; year = y1;
        int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  

        while(year < y2 && month <= 12){
            //code
            int max[] ={ 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
            if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
                max[1] = 29;
            year1 = year;
            year1 -= month < 3;
            y = year1;
            day = ( y + y / 4 - y / 100 +  y / 400 + t[month - 1] + d) % 7;
            day = (day - 5)%7;
            if(day >= 0)
                day = (7 - day)%7;
            else 
                day = 0 - day;
            lcs = day + d;
            lce = lcs + 10;

            if(lcs > 5)
                d1 = lcs - 5;
            else
                d1 = lcs + 2;

            for(int i=d1;i<=max[month%12];i=i+7)
                co = i;
            co = co - 7;
            if(co >= lcs && co<= lce){
                count++;
                // cout<<year<<" "<<month<<endl;
                // cout<<lcs<<" "<<lce<<" "<<co<<endl;
            }

            if(month == 0)
                year++;
            month = (month + 1) % 12;           
        }

        while(year == y2 && month <= m2){
            //code
            int max[] ={ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
                max[1] = 29;
            year1 = year;
            year1 -= month < 3;
            y = year1;
            day = ( y + y / 4 - y / 100 +  y / 400 + t[month - 1] + d) % 7;
            day = (day - 5)%7;
            if(day > 0)
                day = 7 - day;
            else 
                day = 0 - day;
            lcs = day + d;
            lce = lcs + 10;

            if(lcs > 5)
                d1 = lcs - 5;
            else
                d1 = lcs + 2;

            for(int i=d1;i<=max[month-1];i=i+7)
                co = i;
            co = co - 7;
            if(co >= lcs && co<= lce){
                count++;
                // cout<<year<<" "<<month<<endl;
                // cout<<lcs<<" "<<lce<<" "<<co<<endl;
            }

            if(month == 0)
                year++;
            month = (month + 1) % 12;           
        }

        cout<<count<<endl;
	}
	return 0;
}