#include "TagExtraction.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

namespace MTYATH003{

	std::vector <TagStruct> read(vector <TagStruct> TagGroups, string filename)
	{		
		TagStruct temp;	// TagStruct that temporarily holds data read from each line then pushed into the list of TagGroups elements
		int position, TxtLength;
		string lines;   // To temporarily read and store each line from textfile
		string tag;	// Temporarily stores extracted tag
		string text;	// Temporarily stores extracted tag data
		bool is_pair; // Checks if a duplicate of a tag was found or notS
	
		ifstream inputFile(filename); 
	 
		if(inputFile.is_open())
		{
			while(inputFile.peek() != EOF)
			{
				getline(inputFile, lines);
				is_pair = false;
					
				tag = lines.substr(1, lines.find(">")-1);
				lines = lines.substr(1);  // Chopping of the 1st character of the line to prepare to extract text "<"
						
				if (lines.find("<") == -1)
				{
					getline(inputFile, lines);
					text = "";
				
					while (lines.find("<") == -1)
					{
						text += " " + lines;
						getline(inputFile, lines);
					}
				
				}
				else
				{
					TxtLength = lines.find("<") - lines.find(">") - 1;  // Getting the length of text in between the characters ">" and "<" 
					text = lines.substr(lines.find(">")+1, TxtLength);  // Copying the text in between the characters ">" and "<" exclusive
				}
		
				for (int i = 0; i < TagGroups.size(); i++)
				{
					if (tag == TagGroups[i].tagId)
					{
						is_pair = true;
						TagGroups[i].numPairs++;
						TagGroups[i].concText += ":"+ text;
						break; // break to terminate loop to prevent further iteration when tag pair found 
					
					}
				}
	
				if (!is_pair)	// if no duplicate of the tag was found then new tag is stored
				{
					temp.tagId = tag;
					temp.numPairs = 1;
					temp.concText = text;
			
					TagGroups.push_back(temp);
				}

			}
		
			inputFile.close();
		}
		else
			cout<<"File does not exist. Please check spelling or create one.\n";
		
		cout << "Reading done." << endl;		
		return TagGroups;
	}
	
	void print(vector <TagStruct> TagGroups)
	{
		for (TagStruct item : TagGroups) //loops through vector storing elements on item
		{
			cout << "Tag name: " << item.tagId << endl;
		}
	}
	
	
	void dump(vector <TagStruct> TagGroups)
	{
		ofstream outputFile("tag.txt"); // preparing to write to tag.txt
		
		for (TagStruct item : TagGroups)
		{
			outputFile << item.tagId << ", " << item.numPairs << ", " << item.concText << endl;
		}
		
		cout << "Writing done." << endl;
	}
	
	void listData(vector <TagStruct> TagGroups, string tag)
	{
		for (TagStruct item : TagGroups) //loop through vector and displaying only the desired tag's data and name
		{
			if (item.tagId == tag)
				cout << item.tagId << ", " << item.numPairs << ", " << item.concText << endl;
		}
	}
}
