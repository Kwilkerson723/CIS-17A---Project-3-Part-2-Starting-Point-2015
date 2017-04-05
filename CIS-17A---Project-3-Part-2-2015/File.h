#pragma once
#include <string>
#include <memory>
#include <vector>

class File
{
private:
	std::string _name;
public:
	File(std::string name);
	~File();

	std::string getName() { return _name; }
	//std::shared_ptr<File> FindFile(std::string name);
};


