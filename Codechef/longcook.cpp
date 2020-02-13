// Long Contest and Cook Off Overlaps

#include <iostream>
using namespace std;

int main() {
	long int T;
	cin>>T;
	while(T--){
	    long int m1,m2,month,lcs,lce,co,day,d=1,d1,count=0;
        long int y1,y2,y,year,year1;
        cin>>m1>>y1;
        cin>>m2>>y2;

        if(y1==y2 && m1>m2){
            cout<<-1<<endl;
            return 0;
        }
        if(m1 > 2){
            month = 2;
            year = y1 + 1;
        }
        else{
            month = 2;
            year = y1;
        }
        int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  

        while(year < y2){
            //code
            int feb = 28;
            if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
                feb = 29;
            y = year;
            y -= month < 3;
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
            int i;
            for(i=d1;i<=feb;i=i+7)
                co = i;
            co = co - 7;
            if(co >= lcs && co<= lce){
                count++;
                cout<<year<<" "<<month<<endl;
                cout<<lcs<<" "<<lce<<" "<<co<<endl;
            }

            year++;           
        }

        while(year == y2 && month <= m2){
            //code
            int feb = 28;
            if((year%4 == 0 && year%100 != 0) || (year%400 == 0))
                feb = 29;
            y = year;
            y -= month < 3;
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
            int i;
            for(i=d1;i<=feb;i=i+7)
                co = i;
            co = co - 7;
            if(co >= lcs && co<= lce){
                count++;
                cout<<year<<" "<<month<<endl;
                cout<<lcs<<" "<<lce<<" "<<co<<endl;
            }

            if(month == 0)
                year++;
            month = (month + 1) % 12;           
        }

        cout<<count<<"\n";
	}
	return 0;
}