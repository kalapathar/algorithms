#ifndef _HASH_TABLE_
#define _HASH_TABLE_

#include <forward_list>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class hashtable{
	private:
	forward_list<string> ** table;
	int length;
	int hash(string itemkey);

	public:
	hashtable(int l);
	bool is_in_table(string itemkey);
	void insert_item(string itemkey);
	//~hashtable(void);
};
#endif
