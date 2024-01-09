#ifndef _TagExtraction_h
#define _TagExtraction_h
#include <string>
#include <vector>

namespace MTYATH003{ 

	struct TagStruct
	{
		std::string tagId;
		int numPairs;
		std::string concText;
	};

	std::vector <TagStruct> read(std::vector <TagStruct> TagGroups, std::string filename);
	void print(std::vector <TagStruct> TagGroups);
	void dump(std::vector <TagStruct> TagGroups);
	void listData(std::vector <TagStruct> TagGroups, std::string tag);	
}

#endif
