#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

float get_distance(const float& x1, const float& y1, const float& x2, const float& y2 ){
	return sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
}

int main(int argc, char *argv[]) {
	ifstream file1, file2;
	float x1, y1, R, x2, y2, distance;
	file1.open(argv[1]);
	file1 >> x1 >> y1 >> R;

	file2.open(argv[2]);
	while(file2.peek() != ifstream::traits_type::eof()){
		file2 >> x2 >> y2;
		distance = get_distance(x1,y1,x2,y2);
		if(R < distance){
			cout << 1;
		}
		else if(R > distance){
			cout << 2;
		}
		else if(R == distance){
			cout << 0;
		}
		cout << endl;
	}
	file1.close();
	file2.close();
	return 0;
}
