#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char *argv[]) {
	string input_str;
	int pos,id;
	ifstream values,tests;
	ofstream report;

	values.open(argv[1]);
	tests.open(argv[2]);

//	values.open("values.json");
//	tests.open("tests.json");

	map<int,bool> pass_info;

	while(values.peek() != ifstream::traits_type::eof()){
		getline(values, input_str);
		if(input_str[5]=='i'){
			pos = input_str.find(",");
			id = stoi(input_str.substr(10,pos - 10));
			getline(values, input_str);
			if(input_str[14]=='p'){
				pass_info[id] = true;
			}
			else{
				pass_info[id] = false;
			}
		}
	}

	report.open("report.json");
	while(tests.peek() != ifstream::traits_type::eof()){
		getline(tests,input_str);
//		cout << input_str;
		pos = input_str.find("\"id\"");
		if(pos >=0){
			pos += 6;
//			cout << "pos: " << pos << " find: " << input_str.find(',') << endl;
//			cout << input_str.substr(pos, input_str.find('\"', pos+1) - pos) << endl;
//			cout << id << endl;
			id = stoi(input_str.substr(pos, input_str.find('\"', pos+1) - pos));
			report << input_str << endl;
			continue;
		}
		pos = input_str.find("\"\"");
		if(pos >=0){
			report << input_str.substr(0, ++pos);
			if(pass_info[id]){
				report << "passed";
			}
			else{
				report << "failed";
			}

			report << input_str.substr(pos,input_str.size()-pos) << endl;
		}
		else{
			report << input_str << endl;
		}
	}
	values.close();
	tests.close();
	report.close();
	return 0;
}
