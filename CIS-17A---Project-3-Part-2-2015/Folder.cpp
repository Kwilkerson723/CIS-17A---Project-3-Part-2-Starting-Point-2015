#include "Folder.h"

Folder::Folder(std::string name) : _name(name)
{
}

Folder::Folder(){}

Folder::~Folder()
{
}

std::vector<std::string> Folder::ListFiles()
{
	std::vector<std::string> list;
	for (auto file : _files) {
		list.push_back(file->getName());
	}
	return list;
}

std::string Folder::ListContents()
{
	std::string output = "\n";
	for (auto folder : _folders) {
		output += "\\" + folder->getName() + "\n";
	}
	for (auto file : _files) {
		output += file->getName() + "\n";		
	}
	return output;
}

void Folder::AddFile(std::shared_ptr<File> newFile)
{
	_files.push_back(newFile);
}

void Folder::AddFolder(std::shared_ptr<Folder> newFolder)
{
	_folders.push_back(newFolder);
}

std::shared_ptr<Folder> Folder::FindFolder(std::string name)
{
	for(auto folder : _folders)
	{
		if (folder->getName() == name) {
			return folder;
		}
	}
	return nullptr;
}

std::shared_ptr<File> Folder::Search(std::string name)
{
	for (auto file : _files) //so this line defines the pointer "file" //_files is a vector 
	{
		//auto file = file.Search();
		if (file->getName() == name) {    
			return file;
		}
		return nullptr;
	}
	
}


/*for (auto folder:folders)
{
folder.search(name)
}
*/


//now loop the folder's folders 
//search(each folder in the loop )

//if you find the file return the file so it does not search the rest of the files
//loop/iterate this folders files 
//if you find a file with the passed in name return it 
//otherwise return nullptr