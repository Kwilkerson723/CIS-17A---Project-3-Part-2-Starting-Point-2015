#include "File.h"
#include "Folder.h"


File::File(std::string name) : _name(name)
{
}

File::~File()
{
}

/*std::shared_ptr<File> File::FindFile(std::string name)
{

	for (auto file : _folders)
	{
		if (file->getName() == name) {
			return file;
		}
	}
	return nullptr;


}*/
