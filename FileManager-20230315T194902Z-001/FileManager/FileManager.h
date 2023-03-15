#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING 

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <chrono>
#include <Windows.h>
 
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
 
using namespace std;
 
class FileManager  
{ 
private:    
	FILE* file; 
	string path;   
	    
	/////////////////////////////// 
		   
	void delete_folder(string path)
	{  
		if (fs::remove_all(path) == 1)
		{  
			perror("Folder deletion failed\n");
		} 
	 	else
		{    
	 	 	cout << "Folder deleted successfully\n";
		} 
	}
	     
	void delete_file(string path)
	{ 
		if (remove(path.data()) != 0) 
		{
			perror("File deletion failed\n"); 
		}
		else 
		{
			cout << "File deleted successfully\n";
		}
	}
	     
 	void copy_collision(string old_path, string& new_path)
	{  
		if (is_folder(new_path))  
		{ 
			new_path += " - Copy";
		}    
		else
		{ 
			int slash = new_path.find_last_of('\\'); 
			string full = new_path.substr(slash + 1);
			string onlypath = new_path.substr(0, slash + 1);
			int point = full.find_last_of('.');  
			string name = full.substr(0, point);
			string ext = full.substr(point);
			new_path = onlypath + name + " (Copy)" + ext;
		} 
	} 
	    
	bool is_folder(string path)
	{ 
		_finddata_t data;
		long groupHandle = _findfirst(path.data(), &data);

		if (data.attrib & _A_SUBDIR)
		{
			return true; 
		} 
		else 
		{
			return false;
		} 
	}
	  
	void list(string mask)
	{ 
		if (_access(this->path.data(), 0) != -1)
		{
			cout << "\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n";

			string path = this->path; 
			path = path + "\\" + mask;
			 
			_finddata_t data;
			long groupHandle = _findfirst(path.data(), &data);
			if (groupHandle != -1)
			{
				long result = groupHandle; 
				while (result != -1)
				{ 
					if (data.attrib & _A_SUBDIR)
					{
						cout << "Folder : ";
					}
					else
					{
						cout << "File   : ";
					}

					cout << "[ " << data.size / 1024 << "\tkB ]  [ ";
					tm tm;
					localtime_s(&tm, &data.time_create);
					cout << 1900 + tm.tm_year << '.' << tm.tm_mon + 1 << '.' << tm.tm_mday << ' ' << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << " \t]    * ";

					cout << data.name << "\n";

					result = _findnext(groupHandle, &data);
				}
			} _findclose(groupHandle); 

			cout << path << endl;
		}
		else
		{
			perror("Invalid path!\n");
		}
	} 
	  
public:    
	FileManager() 
	{ 
		this->file = nullptr;   
		path = ""; 
	}    
	~FileManager()
	{ 
		if (file != nullptr) { fclose(file); }  
	}    
      
	void Open(string path) 
	{	
		string new_path;
		if ((path[0] == 'C' || path[0] == 'D') && path[1] == ':') 
		{ 
			new_path = path;
		}  
		else 
		{  
			new_path = this->path + "\\" + path;

		}
		int x = _access(new_path.data(), 0);
		if (x==0)
		{ 
			this->path = new_path;   
			this->file = fopen(new_path.data(), "r+");
		}     
		else      
		{ 	
			perror("Invalid path!\n"); 
		}  
	 	system("pause");   
	}    
	 	            
 	void CreateFolder(string path)   
	{   
	 	string new_path;
		if ((path[0] == 'C' || path[0] == 'D') && path[1] == ':')
		{ 
			new_path = path; 
		}  
		else 
		{    
			new_path = this->path + "\\" + path; 
		} 
		//int x = _access(new_path.data(), 0);
		if (_access(new_path.data(), 0) == 0)
		{       
	 		perror("Folder already exists\n");    
			 
		}
		else if (_access(new_path.data(), 0) == -1)
		{
			if (_mkdir(new_path.data()) != 0)
			{
				perror("Folder creation failed\n");
			}
		}
		else   
		{
			perror("Invalid path!\n");    
	 	} 	  
	}        
 		 	   		       
   	void CreateFiile(string path)    
	{ 
		string new_path;
		if ((path[0] == 'C' || path[0] == 'D') && path[1] == ':')
		{ 
			new_path = path;
		} 
		else 
		{
			new_path = this->path + "\\" + path;
			 
		} 

		if (_access(new_path.data(), 0) == 0)
		{
			perror("File already exists\n");

		}
		else if (_access(new_path.data(), 0) == -1)
		{ 
			ofstream newFile(new_path); 
		}
		else
		{ 
			perror("Invalid path!\n");
		} 
	}       
	             
	void Size(string path)   
	{
		string new_path; 
	 	if ((path[0] == 'C' || path[0] == 'D') && path[1] == ':')
		{
			new_path = path;
		} 
		else 
		{
			new_path = this->path + "\\" + path;  
		}

		if (_access(new_path.data(), 0) != -1) 
		{  
 		 	_finddata_t data;
			  
			long groupHandle = _findfirst(new_path.data(), &data); 
			  
			if (is_folder(new_path))
			{
				cout << "Folder  :  ";   
			}  
			else  
			{ 
				cout << "File  :  ";
			} 

			cout << data.name << "  [ " << data.size / 1024 << " kB ]  [ "; 
			tm tm;
			localtime_s(&tm, &data.time_create);
			cout << 1900 + tm.tm_year << '.' << tm.tm_mon + 1 << '.' << tm.tm_mday << ' ' << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << " ]\n";

			_findclose(groupHandle);
		}
		else  
		{ 
			perror("Invalid path!\n");
		} 
	}       
  	          
  	void List ()   
	{       
		if (_access(this->path.data(), 0) != -1)
	 	{ 
			cout << "\n*\t*\t*\t*\t*\t*\t*\t*\t*\t*\n\n";
			
			string path = this->path;  
			path += "\\*"; 
				     
		 	_finddata_t data; 
			long groupHandle = _findfirst(path.data(), &data);
			if (groupHandle != -1) 
 			{    
		 	 	long result = groupHandle;  
			 	while (result != -1)
				{   
					if (data.attrib & _A_SUBDIR)
					{    
						cout << "Folder : "; 
			 		}  
					else	
					{
						cout << "File   : ";
					}  
					          
					cout << "[ " <<  data.size / 1024 << "\tkB ]  [ ";
			 		tm tm;      
					localtime_s(&tm, &data.time_create);  
					cout << 1900 + tm.tm_year << '.' << tm.tm_mon + 1 << '.' << tm.tm_mday << ' ' << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << " \t]    * ";
					  
					cout << data.name << "\n";   
		 	 		result = _findnext(groupHandle, &data);   
				}  
			} _findclose(groupHandle);    
	 	}       
 		else    
	 	{     
 		 	perror("Invalid path!\n");   
	 	}   
	}        
	        
  	void Delete(string path)
 	{	  
	 	string new_path;
		if ((path[0] == 'C' || path[0] == 'D') && path[1] == ':') 
		{
			new_path = path;   
		}  
		else 
	 	{
	 	 	new_path = this->path + "\\" + path;
		}  
		  
		if (_access(new_path.data(), 0) != -1)
 		{			  
			if (is_folder(new_path))
			{
			 	delete_folder(new_path);
			}  
			else
			{
				delete_file(new_path);
			}  
		} 
		else
		{ 
			perror("Invalid path!\n");
		}  
	}  
	             
	void Rename(string old_path, string new_path)
	{
		string new_old_path;
		if ((old_path[0] == 'C' || old_path[0] == 'D') && old_path[1] == ':')
		{
			new_old_path = old_path;
		}
		else
		{
			new_old_path = this->path + "\\" + old_path;

		} 

		string new_new_path; 
		if ((new_path[0] == 'C' || new_path[0] == 'D') && new_path[1] == ':')
		{
			new_new_path = new_path;
		}
		else
		{
			new_new_path = this->path + "\\" + new_path;

		} 
			
		if (_access(new_old_path.data(), 0) != -1)  
	 	{   
			if (rename(new_old_path.data(), new_new_path.data()) != 0) 
			{ 
				perror("File renaming fail\n");  
	 		}   
		}  
		else   
		{ 
			perror("Invalid path!\n");
		}   
 	}        
	    
	void Copy(string old_path, string new_path) 
  	{ 
		string new_old_path;
		if ((old_path[0] == 'C' || old_path[0] == 'D') && old_path[1] == ':')
		{ 
			new_old_path = old_path;
		} 
		else
		{
			new_old_path = this->path + "\\" + old_path;

		} 

		string new_new_path;
		if ((new_path[0] == 'C' || new_path[0] == 'D') && new_path[1] == ':')
		{
			new_new_path = new_path;
		} 
		else
		{  
			new_new_path = this->path + "\\" + new_path;

		} 
		 
		if (_access(new_old_path.data(), 0) != -1) 
		{
			if (new_old_path.compare(new_new_path) == 0) 
			{
				copy_collision(new_old_path, new_new_path);
				fs::copy(new_old_path, new_new_path, fs::copy_options::skip_existing);
			}  
			else  
			{
				fs::copy(new_old_path, new_new_path, fs::copy_options::skip_existing);
			}
		}	    
		else	  
		{	 
			perror("Invalid path!\n");
		} 
	}                     
	
 	void Move(string old_path, string new_path)
 	{
		string new_old_path;
		if ((old_path[0] == 'C' || old_path[0] == 'D') && old_path[1] == ':')
		{
			new_old_path = old_path;
		}
		else
		{
			new_old_path = this->path + "\\" + old_path;

		}

		string new_new_path;
		if ((new_path[0] == 'C' || new_path[0] == 'D') && new_path[1] == ':')
		{
			new_new_path = new_path;
		}
		else
		{
			new_new_path = this->path + "\\" + new_path;

		}

		if (_access(new_old_path.data(), 0) != -1)
		{ 
			if (rename(new_old_path.data(), new_new_path.data()) != 0)
			{
	 			perror("File moving fail\n");
			}
		} 
		else 
		{ 
			perror("Invalid path!\n");
		}    
	}  
 	                  
 	void Search(string mask) 
	{
		list(mask); 
  	}    
	     
};      