#include<stdio.h>
#include<windows.h>
#include<conio.h>
COORD xy = {0, 0};

void gotoxy (int x, int y)
{
        xy.X = x; xy.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
int main(){
    int ch;
    int d,m,y;
    char choice;
    while(1){
        system("cls");
    printf("\t\t\t\t\t\tWHAT DO YOU WANT ME TO DO?\n\n\t\t\t\t\t\t\tPRESS\n\n\t\t\t\t\t\t1:TELL ME THE DAY\n\t\t\t\t\t\t2:PRINT ALL DAYS OF A MONTH\n\t\t\t\t\t\t3:ADD A NOTE\n\t\t\t\t\t\t4:SHOW ME THE HOLIDAYS OF A YEAR\n");
   printf("ENTER YOUR CHOICE:");
   scanf("%d",&ch);
   switch(ch){
   case 1:printf("Enter the Date,Month and Year in DD MM YYYY format\n");
   scanf("%d %d %d",&d,&m,&y);
   printf("Day is : %s",getDay(d,m,y));
   printf("\nPress any key to continue......");
   getch();
    break;
   case 2:printf("Enter month and year (MM YYYY) : ");
          scanf("%d %d",&m,&y);
          while(choice!='q'){
            printMonth(m,y);
                    choice = getch();
                    if(choice == 'n'){
                        increase_month(m,y);
                        system("cls");
                        printMonth(m,y);
                    }else if(choice == 'p'){
                        decrease_month(m,y);
                        system("cls");
                        printMonth(m,y);
                    }else if(choice == 's'){
                        showNote(m);
                        system("cls");
                    }
          }

    break;
   case 3:
    break;
   case 4:AddNote();
   break;
    break;
   default:
    printf("INCORRECT CHOICE");
    exit(0);
}
    }
//checking leap year
int checkLeapYear(int year){
    if(year % 400 == 0 || (year % 100!=0 && year % 4 ==0))
       return 1;
    return 0;
}
//to get the day name **pointer in front of getday
char *getDay(int date,int month,int year){
    char getName[7][10]={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
int day;
if((month<1)||(month>12) )
    return("Invalid month value");
 if(date<1 || date>getNumberOfDays(month,year))
        return("Invalid date");
if(year>=1600){//whyyyyy
        day = getDayNumber(date,month,year);
        return(getName[day]);
    }
else
        return("Please give year more than 1600");

}
int getNumberOfDays(int mm,int yy){
    switch(mm){                          //returns no.of days in a given month
      case 1 : return(31);
      case 2 : if(checkLeapYear(yy)==1)
		 return(29);
	       else
		 return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
        }
int getDayNumber(int dd,int mm,int yy){ //returns day number
   int monthno[12]={0,3,3,6,1,4,6,2,5,0,3,5};
   int cent[7]={4,2,0,6,4,2,0};
    int yyy=yy%100;
    int k=((yyy+(yyy/4))%7)+monthno[mm-1]+cent[yy/100 -17]+dd;
    if((checkLeapYear(yy))&&((mm==1)||mm==2))
        k-=1;
    k=k%7;
    return k;
}
