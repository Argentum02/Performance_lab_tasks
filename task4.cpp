#include <iostream>
#include <fstream>
#include <queue>
#include <math.h>

using namespace std;

int main(int argc, char *argv[]) {
	queue<int> line;
	int buffer, target, res;
	target = 0;
	res = 0;
	ifstream file1;
	file1.open(argv[1]);
	while(file1.peek() != ifstream::traits_type::eof()){
		file1 >> buffer;
		target += buffer;
		line.push(buffer);
	}
	target = round(target/line.size());
	while(!line.empty()){
		res+= abs(line.front()-target);
		line.pop();
	}
	cout << res;
	file1.close();
	return 0;
}
