#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
float calc_cost(float, int);

struct Cars {
    string mark [10] = {"Maruti S-Presso","Tata Tiago","Maruti Brezza (Diesel)","Renault Kwid","Tata Bolt","Renault Capture RXE","Maruti Celerio (Petrol)","Mahindra Scorpio","Hyundai Grand i10","Tata Tiago"};
    string transmission [10] = {"Manual","Manual","Automatic","Manual","Manual","Manual","Manual","Manual","Manual"};
    string color [10] = {"Red","black","yellow","Blue","Red","Brown","Silver","Black","grey"};
    string kilo_travelled[10] = {"9013 km","22817 km","12945 km","14537 km","2345 km","1400 km","49961 km","45685 km","35000 km"};
    int price [10] = {601,701,1184,622,632,945,1015,996,632,521};
    int seats[10] = {4, 6, 8, 4, 4, 4, 6, 6, 6, 8};
};

float petrol_price{100.72};
float diesel_price{85.89};

float extra_fuel{15.75};
float cost{0};

struct Lessee {
   string name [10];
   string phone_number;
   int distance{0} ;
   int no_of_days{0};
};
 
//Declaring struct
Cars car ;
Lessee lessee ;
 
//First output
void Minu () {
    int num=1;
    for(int i=0 ;i<9;++i) {
        cout<<"\t\t\t";
        cout<<"Enter " <<num<<"\t- To Select  "<<car.mark[i]<<endl;
        num++ ;
    }
}
 
//Second output
void Details (int theChoice) {
    system("CLS");
    cout<<"\n\n\n\t\t\t-----------------------------\n";
    cout<<"\t\t\tYou Have Selected - "<<car.mark[theChoice-1]<<endl;
    cout<<"\t\t\t-----------------------------\n\n\n";
    cout<< "\t\t\tTransmission mode : " << car.transmission[theChoice - 1] << endl;
    cout << "\t\t\tKilometers travelled: " << car.kilo_travelled[theChoice - 1] << endl;
    //  cout<<"\t\t\tModel : "<<car.model[theChoice-1]<<endl;
    cout<<"\t\t\tColor : "<<car.color[theChoice-1]<<endl;
   //  cout<<"\t\t\tMaximum Speed : "<<car.maxs_peed[theChoice-1]<<endl;
    cout<<"\t\t\tPrice for 72KM: Rs."<<car.price[theChoice-1]<<endl;
}

void user_input (int theChoice) {
    system("CLS");
    int j=theChoice-1 ;
    cout<<"\t\t\t----------------------------------------\n";
    cout<<"\t\t\tPlease Provide Your Personal Details  : \n";
    cout<<"\t\t\t----------------------------------------\n\n";
    cout<<"\n\tNOTE: PROVIDE FIRST NAME ONLY, DO NOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THEN THE RATE OF CAR\n\n\n\n";
    cout<<"\t\t\tEnter Your Name : ";
    cin>>lessee.name[j];
    int check = 1;
   //  string phone_check = "";

    while(check) {
      cout<<"\t\t\tEnter your Phone Number : ";
      cin>> lessee.phone_number;
      if(lessee.phone_number.length()==10)
      {
         check = 0;
      }
      else{
         cout << "\t\t\tSorry that phone number is invalid, please try again\n";
      }
    }

    cout << "\t\t\tEnter the number of kilometres you wish to travel, \n\t\t\t(first 72 km are free of charge)\t";
    cin >> lessee.distance;
    cout<<"\t\t\tEnter the number of days you wish to rent the vehicle\t";
    cin>>lessee.no_of_days ;
    if(lessee.distance<=72){
       cost = static_cast<float>(car.price[theChoice-1]);
    } else {
       cost = calc_cost(lessee.distance, lessee.no_of_days) + static_cast<float>(car.price[theChoice-1]);
    }
   int choice{0};

    cout << "\t\t\tThe total cost will be Rs." << cost;
    cout << "\n\t\t\tDo you want to pay now or pay later(25\% upfront will be charged) \n\t\t\t1:Pay now \n\t\t\t2:Pay Later\t\t";
    cin >> choice;

   switch(choice) {
      case 1:
         cout << "\t\t\t You have chosen to pay now, You will be charged Rs."<<cost;
         break;
      case 2:
         cout << "\t\t\t You have chosen to pay later, You will be charged 25\% of the amount right now Rs." << cost * 0.25 << " You will need to pay the remaining Rs." << cost * 0.75 << "at the time of return";
         break;
   }
}
 
 
int main() {
    int login();
    login();

    string decide ="yes" ;
    cout<<"\t\t\t----------------------------------------------\n";
    cout<<"\t\t\t\tSIMPLE CAR RENTAL SYSTEM \n";
    cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
    cout<<"\t\t\t----------------------------------------------\n";
    while(decide!="exit") {
     Minu();
     cout<<"\n\n\n\t\t\tYour Choice: ";
     int theChoice;
     cin>>theChoice;
     Details(theChoice);
     cout<<"\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no /exit ) : ";
     cin>>decide;
     if(decide=="yes") {
        user_input(theChoice);
        cout<<"\n\n\t\t\tDo you want to continue ?(yes/no) ";
        cin>>decide;
        if (decide=="no") break ;
        system("CLS");
     }
 
   else {
      if(decide=="no")
      {
       system("CLS");
          continue ;
      }
      else if  (decide=="exit")
      {
      system("CLS");
      cout<<"\n\n\n\t\t\tPrepared by group 6";
      break ;
      }
   }
    }
    return 0;
}

int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  Simple Car Rental System Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pblproject"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");
 
   } else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}

float calc_cost(float distance,int days){   
   float cost = ((distance - 72)*extra_fuel);
   return(cost);
}

