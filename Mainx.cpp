#include "FuncFind.h"

using namespace std;

int main(){
	bool check,check2 = true;
	int day=0;
	string name;
	int age,date;
	float hight,weight,bmi,bmr,tdee,focus;
	char gender;
	double cal_eat;
	char command;
	FindAll A(name,age,hight,weight,gender);
	do{
		cout << "You ever use this programs Y/N : ";
		cin >> command;
		command = toupper(command);
		if(command == 'N'){
			ofstream namelist("namelist.txt",ios::app);
			cout<<"Enter name : ";
			cin.ignore();
			getline(cin,A.name);
			cout << "Hello " << A.name << " plase fill the information\n";
			cout << "Age : ";
			cin >> A.age;
			do{
				cout << "Gender M/F : ";
				cin >> A.gender;
				A.gender = toupper(A.gender);
				if(!(A.gender != 'M' or A.gender != 'F')) cout << "Invalid command. Please input gender again." << endl;
				else break;
			}while(true);
			cout << "Hight : ";
			cin >> A.hight;
			cout << "Weight : ";
			cin >> A.weight;
			cout << "BMI = " << A.BMI() << endl;
			cout << "BMR = " << A.BMR() << endl;
			cout << "TDEE = " << A.TDEE() <<endl;
			cout << "You must the enegy " << A.Diet() << "(Kcal) per day" << endl;
			break;
		}else if(command == 'Y'){
			do{
				cout << "Enter name : ";
				cin.ignore();
				getline(cin,name);
				string names = name;
				string text;
				for(int i=0;i<name.size();i++){
						(name[i]) = toupper(name[i]);
					};
				ifstream namelist("namelist.txt",ios::in);
				cout << "Hello " << names << endl;
				cout << name;
				while(getline(namelist,text)){
					const char *textchar = text.c_str();
					char format[] = "%[^:]: %d %f %f %c %f %f %f %f %d";
					char namechar[100];
					sscanf(textchar,format,namechar,&A.age,&A.hight,&A.weight,&A.gender,&A.bmi,&A.bmr,&A.tdee,&A.focus,&A.remain_date);
					A.name = namechar;
					for(int i=0;i<100;i++){
						(namechar[i]) = toupper(namechar[i]);
					};
					
					if(namechar == name){
						cout << "Age : " << A.age << endl;
						cout << "Gender : " << A.gender << endl;
						cout << "Hight : " << A.hight << endl;
						cout << "Weight : " << A.weight << endl;
						cout << "BMI = " << A.bmi <<endl;
						cout << "BMR = " << A.bmr << endl;
						cout << "TDEE = " << A.tdee << endl;
						check2 = false; break;
					}else{
						check2 = true;
					}
				}
				if(check2 == true) cout << "Cannot Found. Please input your name again." << endl;
				}while(check2);
			}
			if(check2 == true) cout << "Invalid command. Please input Y or N." << endl;
		}while(check2);
	
	do{
		char i;
		day++;
		A.CalFood();
		cout<<A.CalCal(day)<<endl;
		cout<<"\nYou want to fill cal next day Y/N : ";
		cin>>i;
		i=toupper(i);
		if(i=='Y'){
			check=true;
		}else if(i=='N'){
			check=false;
		}
	}while(check);
	
	if(check2 == true){
		ofstream namelist("namelist.txt",ios::app);
		namelist << A.name << ": " << A.age << " " << A.hight << " " << A.weight << " " << A.gender << " " << A.bmi << " " << A.bmr << " " << A.tdee << " " << A.focus << " " << A.remain_date << endl;
		namelist.close();
	}
	return 0;
}
