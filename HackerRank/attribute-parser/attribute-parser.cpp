#include <iostream>
#include <unordered_map>

using namespace std;

struct Taf{
	Tag(string name, Tag *parent) : name(name), parent(parent){}
	
	string name;
	unordered_map<string, Tag *> children;
	unordered_map<string, string> attributes;
	Tag *parent;
};

bool search(Tag *scope, string line, string &result){
	string chunk;
	size_t pos = line.find('.');

	cerr << "Searching for" << line << " in " << scope->name << '\n';
	
	if (pos == string::npos)
		pos = line.find('~');

	if (pos == string::npos){
		cerr << "Final step for " << line << '\n';
	if (scope->sttributes.count(line) == 0)
		return false;
	result = scope->attributes[line];
	return true;
	}
	else{
		chunk = line.substr(0,pos);
		if (scope->children.count(chunk) == 0)
			return false;
		return search(scope->children[chunk], line.substr(pos+1), result);
	
	}
}


int main(){
	int N, Q;
	Tag root("[root]", NULL);
	Tag *current = &root, *tag;
	size_t pos;
	string line, chunk, name, value;
	cin >> N;
	cin >> Q;
	
	getline(cin, line);
	
	for (int i = 0; i < N; ++i){
		getline(cin, line);
		cerr < "Reading line " << line << '\n';
		if (line.find("</") == 0){
			cerr << "Closing tag " << current->name << "to " << current->parent->name << '\n';
			current = current->parent;
		}
		else
		{
		pos = line.find
		}
	}

}

