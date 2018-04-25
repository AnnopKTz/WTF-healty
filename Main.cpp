#include "FuncFind.h"

using namespace std;

int main(){
	bool check,check2 = true;
	string name;
	int age,date,day;
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
			getline(cin,name);
			cout << "Hello " << name << " plase fill the information\n";
			cout << "Age : ";
			cin >> age;
			cout << "Gender M/F : ";
			cin >> gender;
			gender = toupper(gender);
			cout << "Hight : ";
			cin >> hight;
			cout << "Weight : ";
			cin >> weight;
			FindAll A(name,age,hight,weight,gender);
			namelist << endl << A.name << ": " << A.age << " " << A.hight << " " << A.weight << " " << A.gender;
			cout << "\n" << "BMI = " << A.BMI() << endl;
			cout << "BMR = " << A.BMR() << endl;
			cout << "TDEE = " << A.TDEE() <<endl;
			cout << "You must the enegy " << A.Diet() << "(Kcal) per day" << endl;
			namelist.close();
			break;
		}else if(command == 'Y'){
			do{
				ifstream namelist("namelist.txt");
				cout<<"Enter name : ";
				cin.ignore();
				getline(cin,name);
				string names = name;
				string text;
				for(int i=0;i<name.size();i++){
						(name[i]) = toupper(name[i]);
					};	
				cout << "Hello " << names << endl;
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
						cout << A.focus << endl;
						cout << A.remain_date << endl;
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
		day--;
	}while(check);
	
	return 0;
}
