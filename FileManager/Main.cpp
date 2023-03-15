
#include <iostream>
#include <string>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <chrono> 
#include <Windows.h>
#include "FileManager.h"  


using namespace std; 
   
const char s[11] = { 201, 187, 200, 188, 186, 205, 204, 185, 203, 202, 206 };   
 
void Menu()          
{	 		      
 	cout << s[0] << s[5] << s[5] << s[5] << s[5] << s[5] << s[8] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[1] << endl;
	cout << s[4] << " [0] " << s[4] << " Open path\t\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl; 
	cout << s[4] << " [1] " << s[4] << " List folders and files\t" << s[4] << endl;
 	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [2] " << s[4] << " Create folder\t\t" << s[4] << endl;
 	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl; 
	cout << s[4] << " [3] " << s[4] << " Create file\t\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;  
	cout << s[4] << " [4] " << s[4] << " Delete folder or file\t" << s[4] << endl;
 	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [5] " << s[4] << " Rename folder or file\t" << s[4] << endl;
 	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [6] " << s[4] << " Copy folder or file\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [7] " << s[4] << " Move folder or file\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [8] " << s[4] << " Size of folder or file\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl;
	cout << s[4] << " [9] " << s[4] << " Find by mask\t\t" << s[4] << endl;
	cout << s[6] << s[5] << s[5] << s[5] << s[5] << s[5] << s[10] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[7] << endl; 
	cout << s[4] << " [x] " << s[4] << " Exit\t\t\t" << s[4] << endl;
	cout << s[2] << s[5] << s[5] << s[5] << s[5] << s[5] << s[9] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[5] << s[3] << endl; 
	cout << "\nChoose menu option = > ";
} 
       
int main() 
{  
	// "C:\\Users\\AxmedStark\\Desktop" 	
	 
	system("title File Explorer");
 	system("color 09");
      
 	FileManager F;  
	bool exit = false;
	string path;
  
	while (!exit)
	{  
 	 	Menu(); 
	 	char  menu; cin >> menu; cin.ignore();
			  
		switch (menu) 
		{
			case '0':  
			{  
	 			cout << "Enter path to open ->\n";
				getline(cin, path); 
				F.Open(path); 
			} break;   
			case '1':  
			{    
				F.List();   
				system("pause");  
			} break;    
	 		case '2':   
			{ 
				typeid(F);
				cout << "Enter folder name to create ->\n";
			 	getline(cin, path); 
		 		F.CreateFolder(path);
				system("pause");  
			} break; 
			case '3':   
			{ 
				cout << "Enter file name to create ->\n";
		  	  	getline(cin, path);
				F.CreateFiile(path); 
				system("pause");
			} break;	 
			case '4':    
			{   
				cout << "Enter path of file or folder to delete ->\n";
				getline(cin, path);
				F.Delete(path); 
				system("pause");	
			} break;  
			case '5':  
			{ 
				cout << "Rename =>\n";
				cout << "Enter old path ->\n"; 
				getline(cin, path);
				cout << "Enter new path ->\n"; 
				string new_path; 
				getline(cin, new_path);
				F.Rename(path, new_path);
				path = new_path;
				system("pause"); 
			}  break;
			case '6':   
		 	{    
			 	cout << "Copy =>\n";  
		 		cout << "Enter old path ->\n";
				getline(cin, path);
				cout << "Enter new path ->\n";
				string new_path; 
				getline(cin, new_path);
				F.Copy(path, new_path);
				path = new_path; 
				system("pause"); 
 	 		} break;  
	 		case '7': 
			{   
				cout << "Move =>\n";
				cout << "Enter old path ->\n";
				getline(cin, path); 
				cout << "Enter new path ->\n";
				string new_path;
				getline(cin, new_path);
				F.Move(path, new_path);
	 			path = new_path;
				system("pause");   
	 		} break;  
	 		case '8':  
			{ 
				cout << "Enter path to get size of file or folder ->\n";
				getline(cin, path); 
				F.Size(path);   
				system("pause"); 			 
	 		} break;     
	 		case '9':    
			{     
				cout << "Enter mask to search ->\n";  
		 		string mask;    
				getline(cin, mask);  
				F.Search(mask);   
				system("pause"); 
	 		} break;   
			case 'x': { exit = true; } system("pause"); break;
			default:
			{ 
				cout << "Invalid choice!" << endl; 
				system("pause");
			} break;   
		}  system("cls"); 	 
	}	  
}  