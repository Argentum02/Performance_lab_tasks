#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {

	ifstream file;
	int n,m, buffer;
	buffer = 1;
	file.open(argv[1]);
	file >> n >> m;
	m--;

	do{
		cout << buffer;
		buffer = (buffer + m);
		if(buffer > n){
			buffer -= n;
		}
	}while(buffer!=1);
	file.close();

	return 0;
}
