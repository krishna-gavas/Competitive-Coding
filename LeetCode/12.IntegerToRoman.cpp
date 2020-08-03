class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        while(num >= 1000){
            roman = roman + "M";
            num = num - 1000;
        }
        if(num >= 900){
            roman = roman + "CM";
            num = num - 900;
        }
        
        while(num >= 500){
            roman = roman + "D";
            num = num - 500;
        }
        if(num >= 400){
            roman = roman + "CD";
            num = num - 400;
        }
        
        while(num >= 100){
            roman = roman + "C";
            num = num - 100;
        }
        if(num >= 90){
            roman = roman + "XC";
            num = num - 90;
        }
        
        while(num >= 50){
            roman = roman + "L";
            num = num - 50;
        }
        if(num >= 40){
            roman = roman + "XL";
            num = num - 40;
        }
        
        while(num >= 10){
            roman = roman + "X";
            num = num - 10;
        }
        if(num == 9){
            roman = roman + "IX";
            num = num - 9;
        }
        
        while(num >= 5){
            roman = roman + "V";
            num = num - 5;
        }
        if(num == 4){
            roman = roman + "IV";
            num = num - 4;
        }
        
        while(num >= 1){
            roman = roman + "I";
            num = num - 1;
        }
        
        return roman;
    }
};