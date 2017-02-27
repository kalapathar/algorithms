#include <string>
#include "hash1.h"

hashtable::hashtable(int l) {
	length = l;
	table = new forward_list<string>*[length];
	for (int i = 0; i < length; i++) {
    	table[i] = NULL;
	}
}

int hashtable::hash(string itemKey)
{
	int value = 0;
	for ( int i = 0; i < itemKey.length(); i++ ){
    	char x=itemKey.at(i);
    	value=value+int(x);
	}
	return value % length;
}

bool hashtable::is_in_table(string itemkey) {
	// if hash index is void, return false
	int h = hash(itemkey);
	if (table[h] == NULL) {
return false;
} else {
	for (string&str : *table[h]) {
if (str.compare(itemkey)==0)
	return true;
}
}
return false;
}

void hashtable::insert_item(string itemkey) {
	// get hash value
	int h = hash(itemkey);
	// check to see if there is a forward_list initialized at table[h]
	if (table[h] == NULL) {
    	table[h] = new forward_list<string>;
}
	// push_front(itemkey) to that list
	table[h]->push_front(itemkey);
}

/*
hashtable::~hashtable(void){
	for (int i=0; i<=length; i++) {
	if (table[i] != NULL) {
    	~(*table[i]);
	}
}
	delete[] table;
}
*/
