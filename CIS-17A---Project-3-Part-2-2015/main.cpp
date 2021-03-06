#include "Folder.h"
#include <iostream>
using namespace std;
void DisplayMenu(shared_ptr<Folder> currentFolder, shared_ptr<Folder> parent);
void AddFileMenu(shared_ptr<Folder> currentFolder);
void AddFolderMenu(shared_ptr<Folder> currentFolder);
shared_ptr<Folder> NavigateToFolder(shared_ptr<Folder> currentFolder);
void Search(shared_ptr<Folder>currentFolder);


int main()
{
	auto currentFolder = make_shared<Folder>("Root");
	auto parentFolder = make_shared<Folder>();
	parentFolder = nullptr;
	int choice = 0;
	while (choice != -1) {
		DisplayMenu(currentFolder, parentFolder);
		cin >> choice;
		switch (choice)
		{
		case 1: system("cls"); 
			cout << "Contents of " << currentFolder->getName() << currentFolder->ListContents() << endl; 
			system("pause"); break;
		case 2: AddFileMenu(currentFolder); break;
		case 3: {
			auto newcurrent = NavigateToFolder(currentFolder); 
			parentFolder = currentFolder;
			currentFolder = newcurrent;
			cout << endl << "Now in folder " << newcurrent->getName() << "!";
			break;
		}
		case 5:	Search(currentFolder); break;				 //IMPLEMENT THIS //create another menu //like addfilemenu
		case 4: AddFolderMenu(currentFolder); break;
		case 6: {
			if (parentFolder != nullptr) {
				currentFolder = parentFolder;
				cout << endl << "Now in folder " << currentFolder->getName() << "!";
			}
			break;
		}
		default: choice = -1; break;
		}
	}
	system("pause");
}

shared_ptr<Folder> NavigateToFolder(shared_ptr<Folder> currentFolder) 
{
	cout << "Folder Name: ";
	string name;
	cin >> name;
	cin.ignore();

	auto folder = currentFolder->FindFolder(name);
	return folder;
}

void DisplayMenu(shared_ptr<Folder> currentFolder, shared_ptr<Folder> parent)
{
	system("cls");
	cout << "Now in " << currentFolder->getName() << endl;
	cout << "*****************************************" << endl;
	cout << "1) List folder contents" << endl;	
	cout << "2) Add file to folder" << endl;
	cout << "3) Open" << endl;
	cout << "4) Add sub folder" << endl;
	cout << "5) Search For File" << endl;
	if (parent != nullptr) {
		cout << "6) Return to [" << parent->getName() << "]";
	}
	
}

void AddFileMenu(shared_ptr<Folder> currentFolder)
{
	system("cls");
	cout << "Enter new file name: ";
	string name;
	cin >> name;
	cin.ignore();

	auto newFile = make_shared<File>(name);
	currentFolder->AddFile(newFile);
}

void AddFolderMenu(shared_ptr<Folder> currentFolder)
{
	system("cls");
	cout << "Enter new folder name: ";
	string name;
	cin >> name;
	cin.ignore();

	auto newFolder = make_shared<Folder>(name);
	currentFolder->AddFolder(newFolder);
}

void Search(shared_ptr<Folder>currentFolder)
{
	system("cls");
	cout << "Enter The File name: ";
	string fileName;
	cin >> fileName;
	cin.ignore();

	
	auto file = currentFolder->Search(fileName);

	if (Search != nullptr) //work on this  //got it!
	{
		cout << fileName << endl; 
	}

	else
		cout << "file not found" << endl; 
	//if found print "found"
	//else print not found

	system("pause");
	//promt user for a file name 
	//search the current folder for the file
	//add method in folder to seach for files
	//If search call returns nullptr 	



}