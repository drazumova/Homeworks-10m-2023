#include<iostream>
#include<vector>
using namespace std;
template<int N>
class field{
	//int N;// = (int)n;
	public:
	vector< vector < int > > arr;
	
	int last;
	
	field(){
		arr.resize(N);
		for(int i = 0; i < N; i++){
			arr[i].resize(N, 0);
		}
		last = 0;
	}
	
	bool turn_x(int x, int y){
		if(arr[x][y] == 0 && last != 1){
			arr[x][y] = 1;
			last = 1;
			return 1;
		}
		return 0;
	}
	bool turn_o(int x, int y){
		if(arr[x][y] == 0 && last != 2){
			arr[x][y] = 2;
			last = 2;
			return 1;
		}
		return 0;
	}
	int condition(){			// 1 - X, 2 - O, 3 - draw, 0 - in process
		int cn = 0;
		for(int i = 0; i < N; i ++){		// vertical
			for(int j = 0; j < N - 2; j ++){
				if(arr[i][j] == arr[i][j+1] == arr[i][j+2] != 0){
					return arr[i][j];
				}
				//if(arr[i][j] == 0 || arr[i][j+1] == 0 || arr[i][j+2] == 0) cn = 0;
			}
		}
		for(int i = 0; i < N; i ++){		// vertical
			for(int j = 0; j < N; j ++){
				if(arr[i][j] == 0) cn = 1;
			}
		}
		for(int i = 0; i < N; i ++){		// horisontal
			for(int j = 0; j < N - 2; j ++){
				if(arr[j][i] == arr[j+1][i] == arr[j+2][i] != 0){
					return arr[i][j];
				}
			}
		}
		for(int j = 0; j < N - 2; j ++){	// diagonal 1
			if(arr[j][j] == arr[j+1][j+1] == arr[j+2][j+2] != 0){
				return arr[j][j];
			}
		}
		
		for(int j = 0; j < N - 2; j ++){	// diagonal 2
			if(arr[j][N - j - 1] == arr[j+1][N - j - 2] == arr[j+2][N - j - 3] != 0){
				return arr[j][j];
			}
		}
		if(cn) return 0;
		return 3;
	}
	
};

int main(){
	/*field <3>f;
	cout << f.condition();
	*/
}