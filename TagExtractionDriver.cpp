#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "TagExtraction.h"

using namespace std;

int main(int argc, char* argv[])
{
	char input;
	string filename, tag;
	vector <MTYATH003::TagStruct> TagGroup;
	
	for (;;) 
	{
	
		system("clear"); // Clears the terminal window (refresh window)
	
		cout << "r: Read and process tag file" << endl;
		cout << "p: Print all tags" << endl;
		cout << "d: Dump/write tags and data to a file" << endl;
		cout << "l: list/print tag data for given tag to console" << endl; 
		cout << "q: Quit" << endl;
		cout << "Enter an option (r,p,d,l) or q to quit, and press return..." << endl;
	
		cin >> input;
	
		switch(input) 
		{
  			case 'r':
    				cin >> filename;
				TagGroup = MTYATH003::read(TagGroup, filename);
    				break;
  			case 'p':
    				MTYATH003::print(TagGroup);
    				break;
    			
    			case 'd':
    				MTYATH003::dump(TagGroup);
    				break;
    			
    			case 'l':
    				cin >> tag;
    				MTYATH003::listData(TagGroup, tag);
    				break; 			
    			
  			default:
    				break;
		}
		
		if (input == 'q')
			break;
		
		system("read -p 'Press Enter to continue...' var"); // makes the program halt so the user can see the output of each command
	}
	
	return 0;	
}
