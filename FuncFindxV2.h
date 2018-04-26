#include <iostream>
#include <cmath>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<fstream>
#include<vector>
#include<Windows.h>
using namespace std;
 HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
class FindAll{
	public :
		double return_bmi[2];
		vector <int> menufood;
		int caseactivity;
		string saveall;
		string name;
		int age,rang,min,hour,walk,calwalk;
		int food_order,food_sum;
		float hight;
		float weight;
		float focus,minus;
		char gender;
		char menu,check_char;
		double calday;
		double cal_eat;
		double eat;
		float bmi,bmr,tdee,s;
		int diet,remain_date; 
		double sum; //calort for diet
		FindAll(string,int,float,float,char,float,float,float,int,int);
		double BMI();
		double BMR();
		double TDEE();
		double Diet();
		double CalCal(int );
		double choose();
		bool check;
		void CalFood();
		void reBMI();
		void walkcal();
};


FindAll::FindAll(string n,int a,float h,float w,char g,float q=0,float x=0,float y=0,int z=0,int i=0){
	name=n;
	age=a;
	hight=h;
	weight=w;
	bmi=q;
	bmr=x;
	tdee=y;
	focus=z;
	remain_date=i;
	g=toupper(g);
	gender=g;
}

double FindAll::BMI(){
	bmi = weight/pow((hight/100),2);
	if(bmi < 18.50){
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout <<endl<<setw(30)<< "Standard : Underweight/thin\n";
		cout <<setw(30)<< "Risk of disease : Much/Increase\n";
		cout <<setw(30)<< "Direction : 1.You should eat a variety 5 groups in the right proportion and increase the amount of rice, meat, fat and milk.2.You should the motion and exercise regularly, every day or almost every day, tired by the effort such as temperance, breathing fast biking.Accumulate at least 30 minutes a day don't need to exercise to exhaustion or breathlessness. The easiest is to walk\n";
	}else if(bmi < 22.90){
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout <<endl<<setw(30)<< "Standard : Normally\n";
		cout <<setw(30)<< "Risk of disease : Normally\n";
		cout <<setw(30)<< "Direction : 1.You should eat a variety of 5 groups in the right proportions. Eat as much as your body needs a day of overeating.They eat rice and flour and other grain to more than 6 per ladle vegetables including beans, fruits, no less than 5 parts per day, or half a kilogram.To prevent the excess energy will control the weight and balance.2.You should exercise regularly. At least, tired enough. At least 30 minutes a day.\n";	
	}else if(bmi < 24.90){
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout <<endl<<setw(30)<< "Standard : Plump\n";
		cout <<setw(30)<< "Risk of disease : Danger level 1\n";
		cout <<setw(30)<< "Direction : 1.Should a diet to reduce the amount of food or diet modifications from that much energy is energy food less.The energy shouldn't be less than 1,200 kcal a day by reducing fat, meat, sauce, fried, dessert and alcoholicbut eating the right proportions. Eat vegetables and friuts. To reduce energy The body has accumulated excess energy in the form of fat.2.You should the motion and aerobic exercise regularly, every day. Or nearly every day for at least 30 minutes a day can be a day 2-3 times.Then gradually add more time each week. Without adding weight When the body adapt gradually increase the intensity.Or exhaustion as needed In order to have the energy to rise. At least 200-300 kcal. 3.You should strength training muscle training exercises or weight training will help provide the body with more energy consumption. Causes of fat decreased.\n";
	}else if(bmi < 29.90){
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout <<endl<<setw(30)<< "Standard : Fat\n";
		cout <<setw(30)<< "Risk of disease : Danger level 2\n";
		cout <<setw(30)<< "Direction : 1.Should a diet to reduce the amount of food or diet modifications from that much energy is energy food less.The energy shouldn't be less than 1,200 kcal a day by reducing fat, meat, sauce, fried, dessert and alcoholicbut eating the right proportions. Eat vegetables and friuts. To reduce energy The body has accumulated excess energy in the form of fat.2.You should the motion and aerobic exercise regularly, every day. Or nearly every day for at least 30 minutes a day can be a day 2-3 times.Then gradually add more time each week. Without adding weight When the body adapt gradually increase the intensity.Or exhaustion as needed In order to have the energy to rise. At least 200-300 kcal. 3.You should strength training muscle training exercises or weight training will help provide the body with more energy consumption. Causes of fat decreased.4.If you can reduce the energy from food into a 400 kcal per day and increased use.The energy of 200 kcal per day for exercise. Then you have power sesame decreased to 600 kcal per day,6 days a gym about 3600 kcal of energy depletion will reduce by about half a kilogram per week.3500 kcal of energy into or out will increase or decrease fat, 1 lb or 0.45 kg.5.You should see a doctor.\n";
	}else if(bmi > 30){
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout <<endl<<setw(30)<< "Standard : Very fat\n";
		cout <<setw(30)<< "Risk of disease : Danger level 3\n";
		cout <<setw(30)<< "Standard : Fat\n";
		cout <<setw(30)<< "Risk of disease : Danger level 2\n";
		cout <<setw(30)<< "Direction : 1.Should a diet to reduce the amount of food or diet modifications from that much energy is energy food less.The energy shouldn't be less than 1,200 kcal a day by reducing fat, meat, sauce, fried, dessert and alcoholicbut eating the right proportions. Eat vegetables and friuts. To reduce energy The body has accumulated excess energy in the form of fat.2.You should the motion and aerobic exercise regularly, every day. Or nearly every day for at least 30 minutes a day can be a day 2-3 times.Then gradually add more time each week. Without adding weight When the body adapt gradually increase the intensity.Or exhaustion as needed In order to have the energy to rise. At least 200-300 kcal. 3.You should strength training muscle training exercises or weight training will help provide the body with more energy consumption. Causes of fat decreased.4.If you can reduce the energy from food into a 400 kcal per day and increased use.The energy of 200 kcal per day for exercise. Then you have power sesame decreased to 600 kcal per day,6 days a gym about 3600 kcal of energy depletion will reduce by about half a kilogram per week.3500 kcal of energy into or out will increase or decrease fat, 1 lb or 0.45 kg.5.You should see a doctor.\n";
	}
	return bmi;
}

double FindAll::BMR(){
	double s;
	if(gender=='M'){
		s=66.5+(13.75*weight)+(5.003*hight)-(6.775*age);
	}else if(gender == 'F'){
		s=655.1+(9.563*weight)+(1.85*hight)-(4.676*age);
	}
	bmr=s;
	return bmr;
}

double FindAll::TDEE(){
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout << "\n 1 : Don't exercise or exercise less." << endl;
	cout << " 2 : Exercise 1-3 days a week." << endl;
	cout << " 3 : Exercise 3-5 days a week." << endl;
	cout << " 4 : Exercise 6-7 days a week." << endl;
	cout << " 5 : Hard work." << endl << endl;
	do{
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"Enter your activity 1-5 : ";
		cin >> caseactivity;
		if(caseactivity>=1 or caseactivity<=5){
			check=false;
		}else{
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\tInput incorrect\n";
		}
	}while(check);
	
	switch(caseactivity){
		case 1: tdee=bmr*1.2; break;
		case 2: tdee=bmr*1.375; break;
		case 3: tdee=bmr*1.55; break;
		case 4: tdee=bmr*1.725; break;
		case 5: tdee=bmr*1.9; break;
	}
	return tdee;
}

double FindAll::Diet(){
	check=false;
	do{
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		if(check){
			cout<<"\tYou should add up to weight do you want or day \n";
		}cin.ignore();
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"How mush weight do you want : ";
		cin>>focus;
		cin.ignore();
		SetConsoleTextAttribute(h,FOREGROUND_BLUE| FOREGROUND_INTENSITY);
		cout<<"How many day do you have : ";
		
		cin>>remain_date;
		cout<<remain_date;
		minus=weight-focus;
		diet=tdee-(minus*7700/remain_date);
		if(diet<800){
			SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
			cout<<"\tIt's hard to do this plan.\n\tPlese change your plan\n";
			check=true;
		}else{
			check=false;
		}
	}while(check);
	return diet;
}

double FindAll::CalCal(int c){
	double e=minus*7700;
	double s=tdee-food_sum;
	double z;
	z=e-s;
	if(z<0){
		z*=-1;
	}
	SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"\ttotal CAL = " << z <<endl;
	calday= (e-(tdee+food_sum))/(remain_date);
	remain_date--;
	cout << "\tYour plan remaining " << remain_date << " day.\n\tYou must eat not over :";
	return calday;
}

void FindAll::reBMI(){
	return_bmi[0]=(18.6)*pow((hight/100),2);
	return_bmi[1]=(24.9)*pow((hight/100),2);
}

void FindAll::CalFood(){
	food_sum=0;
	ifstream fin("menufood.txt");
	string text;
	vector<int> menu;
	while(getline(fin,text)){
		int s = atoi(text.c_str());
		menu.push_back(s);
	}
	check=false;
	do{ 
	SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		//system("cls");
		cout<<"\nEnter food : ";
		cin.ignore();
		cin>>food_order;
		food_sum+= menu[food_order];
		cout<<"You eat "<<food_sum<<" cal";
		cout<<"\nIs there another Y/N :";
		cin>>check_char;
		check_char=toupper(check_char);
		if(check_char=='Y'){
			check=true;
		}else{
			check=false;
		}	
	}while(check);
	
}

void FindAll::walkcal(){
	SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	cout<<"Enter cal per day : ";
	cin>>rang;
	if(rang<bmr){
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<<"Walk 30 minute"; //standard
	}else if(rang<bmr+200){
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"Walk 40 minute" ;// plus 40 per 200 cal
	}else if(rang<bmr+400){
		SetConsoleTextAttribute(h,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"Walk 1 hour 20 minute";
	}else if(rang<bmr+600){
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<<"Walk 2 hour ";
	}else if(rang<bmr+800){
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<"Walk 2 hour 40 minute";
	}else{
		cout<<"Walk over 3 hour";
		/*walk=rang-bmr;
		calwalk=walk/5;
		do{
			for(;calwalk>=60;){
				hour++;
				calwalk-=60;
			}if(calwalk){
				min=calwalk;
			}
		}while(calwalk<60);
		cout<<"Walk "<<hour<<" hour "<<min<<" minute";
		*/
	}
		
	
}
