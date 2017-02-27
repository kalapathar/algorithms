#include<iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

#include "elapsed_time.h"
#include "hash1.h"

void define_dictionary( const char *filename, hashtable &hashtable1 )
{
  ifstream f(filename);
  if ( ! f.good() ) {
	cerr << "Error:  unable to open " << filename << endl;
	exit(-1);
  }
  string s;
  //cout<<"This is the word from the file"<<endl;
  while ( f >> s ) hashtable1.insert_item(s);
}


void getWords( const char *filename, vector<string> &vec )
{
  ifstream f(filename);
  if ( ! f.good() ) {
	cerr << "Error:  unable to open " << filename << endl;
	exit(-1);
  }
  string s;
  while ( f >> s ) vec.push_back(s);
}


void check( const char *dictname , const char *filename, int height)
{
  hashtable hashtable1(height); //88001

  define_dictionary(dictname, hashtable1);
  vector<string> query;
  getWords(filename, query);

  start_timer();  // from elapsed_time.h

  int counter = 0, n = query.size();
  for ( int i = 0; i < n; ++i ) {
	string word = query[i];
	transform(word.begin(), word.end(), word.begin(), ::tolower);
	if ( ! hashtable1.is_in_table(word) ) {
  	// cout << query[i] << " ";
    
    cout<<word<<"This is from second file"<<endl;

  	++counter;
	}
  }
  cout << "Misspelled " << counter << " words." << endl;

  double cycles = elapsed_time();
  cout << " Total cycles: " << cycles << endl;
}



int main(int argc, char **argv)
{
  cout<<"EHY DEEPAK"<<endl;
  if ( argc != 4  ) {
	cerr << "Usage: spellCheck dictionaryFile inputFile height_of_table" << endl;
	exit(0);
  }
  check(argv[1], argv[2], atoi(argv[3]));

  return 0;
}
