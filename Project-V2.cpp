#include <windows.h>
#include "FuncFind.h"
#include <stdio.h>
#include <cmath>


#define FILE_MENU_NEW 1
#define FILE_MENU_OPEN 2
#define FILE_MENU_EXIT 3
#define DATA_BUTTON 4


char textBMI[50],textBMR[50],textTDEE[50];
void AddMenus(HWND);
void AddControls(HWND);
void AddControls1(HWND);
HMENU hMenu;
HWND hName,hAge,hOut,hGender,hWeight,hHight,hTDEE,haaa;
float a,w,s,h,BMR,BMI,TDEE;
int d;
bool check;
/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_COMMAND:
			
			switch(wParam)
			{
				case FILE_MENU_EXIT:
					DestroyWindow(hwnd);
					break;
				
				case FILE_MENU_NEW:
					MessageBeep(MB_ICONINFORMATION);
					break;
				
				case DATA_BUTTON:
					
					char name[30],age[10],out[1000],gender[10],weight[10],hight[10],teed[5];
					GetWindowText(hName,name,30);
					GetWindowText(hAge,age,10);
					GetWindowText(hWeight,weight,10);
					GetWindowText(hHight,hight,10);
					GetWindowText(hGender,gender,10);
					GetWindowText(hTDEE,teed,5);
					
					a=atof(age);
					w=atof(weight);
					h=atof(hight);
					d=atoi(teed);
					
					FindAll x ;
					x.name=name;
					x.gender=gender[0];
					x.age=a;
					x.weight=w;
					x.hight=h;
					x.tdee=d;
					

					sprintf(textBMI, "%.2f",x.BMI());
					sprintf(textBMR, "%.2f",x.BMR());
					sprintf(textTDEE, "%.2f",x.TDEE());
					
					
					
					strcat(out," BMI is ");
					strcat(out,textBMI);
					strcat(out," BMR is ");
					strcat(out,textBMR);
					strcat(out," TDEE is ");
					strcat(out,textTDEE);
					SetWindowText(hOut,out);
					break;
				
					
				
					
			}
			
			break;
				
					
		case WM_CREATE:{
			AddMenus(hwnd);
			AddControls(hwnd);
			break;
			}
			
				
		
		
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

void AddMenus(HWND hwnd){
	
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	HMENU hSubMenu = CreateMenu();
	
	AppendMenu(hSubMenu,MF_STRING,NULL,"SubMenu");
	
	AppendMenu(hFileMenu,MF_STRING,FILE_MENU_NEW,"New");
	AppendMenu(hFileMenu,MF_POPUP,(UINT_PTR)hSubMenu,"Open SubMenu");
	AppendMenu(hFileMenu,MF_SEPARATOR,NULL,NULL);
	AppendMenu(hFileMenu,MF_STRING,FILE_MENU_EXIT,"Exit");
	
	AppendMenu(hMenu,MF_POPUP,(UINT_PTR)hFileMenu,"File");
	AppendMenu(hMenu,MF_STRING,NULL,"Help");
	
	SetMenu(hwnd,hMenu);
}

void AddControls(HWND hwnd){
	CreateWindow("STATIC", "Name:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,90, 50, 60, 20, hwnd, NULL, NULL, NULL);
	hName=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 50, 200, 20, hwnd, NULL, NULL, NULL);
	
	CreateWindow("STATIC", "Age:    ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,90, 70, 60, 20, hwnd, NULL, NULL, NULL);
	hAge=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 70, 200,20 , hwnd, NULL, NULL, NULL);
	
	CreateWindow("STATIC", "Gender:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,90, 90, 60, 20, hwnd, NULL, NULL, NULL);
	hGender=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 90, 200, 20, hwnd, NULL, NULL, NULL);
	
	CreateWindow("STATIC", "Weight:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,90, 130, 60, 20, hwnd, NULL, NULL, NULL);
	hWeight=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 130, 200, 20, hwnd, NULL, NULL, NULL);
	
	CreateWindow("STATIC", "Hight:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,90, 110, 60, 20, hwnd, NULL, NULL, NULL);
	hHight=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 150, 110, 200, 20, hwnd, NULL, NULL, NULL);
	
	CreateWindow("STATIC", "TDEE:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,360, 50, 60, 20, hwnd, NULL, NULL, NULL);
	hTDEE=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 415, 50, 200, 20, hwnd, NULL, NULL, NULL);
	
	
	CreateWindow("Button", "Show DATA", WS_VISIBLE | WS_CHILD , 150, 180, 100, 50, hwnd,(HMENU)DATA_BUTTON, NULL, NULL);
	CreateWindow("Button", "werwer", WS_VISIBLE | WS_CHILD , 260, 180, 100, 50, hwnd,(HMENU)5, NULL, NULL);

	hOut=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 100, 250, 500, 300, hwnd, NULL, NULL, NULL);
}

void AddControls1(HWND hwnd){
	CreateWindow("STATIC", "TDEE:   ", WS_VISIBLE | WS_CHILD | WS_BORDER |SS_CENTER ,360, 220, 60, 20, hwnd, NULL, NULL, NULL);
	haaa=CreateWindow("EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL, 415, 220, 200, 20, hwnd, NULL, NULL, NULL);
	
}
	


/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+2);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Caption",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		1080, /* width */
		780, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
