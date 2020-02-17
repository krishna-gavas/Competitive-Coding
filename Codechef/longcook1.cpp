// Long Contest and Cook Off Overlaps

#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int m1,m2,day,d=1,count=0,flag=0;
        int y1,y2,y,year;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1 > 2)
            y1 = y1 + 1;
        if(m2 == 1)
            y2 = y2 - 1;

        int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 }; 
        int start,start1,start2,end,end1,end2;
        start1 = y1;end2=y2;
        if(y1 % 400 == 0){
            end1 = y1;
            end = y1;
        }
        else{
            end = ((y1/400)+1)*400;
            end1 = y2;
            if(y2-y1 >=400){
                flag = 1;
                if(y1 % 400 <= 100){
                    count = count + 76;
                    end1 = (y1/400)*400 + 100;
                } 
                else if(y1 % 400 <= 200){
                    count = count + 52;
                    end1 = (y1/400)*400 + 200;
                }
                else if(y1 % 400 <= 300){
                    count = count + 26;
                    end1 = (y1/400)*400 + 300;
                }
            }
        }

        if(y2 % 400 == 0){
            start2 = y2;
            start = y2;
        }
        else {
            start = ((y2/400)*400);
            start2 = y2;
            if(y2-y1 >=400){
                start2 = (y2/400)*400;
            }
        }

        year = start1;
        while(year < end1){
            //code
            y = year;
            y -= 2 < 3;
            day = ( y + (y/4) - (y/100) +  (y/400) + t[1] + d) % 7;
            
            if(day == 0 && ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) == false)
                count++;
 
            else if(day == 6)
                count++;
            year++;           
        }

        year = start2;
        while(year <= end2){
            //code
            y = year;
            y -= 2 < 3;
            day = ( y + (y/4) - (y/100) +  (y/400) + t[1] + d) % 7;
            
            if(day == 0 && ((year%4 == 0 && year%100 != 0) || (year%400 == 0)) == false)
                count++;
 
            else if(day == 6)
                count++;
            year++;           
        }
        if(flag == 1)
            count = count + ((start-end)/400)*101;

        cout<<count<<"\n";
	}
	return 0;
}
