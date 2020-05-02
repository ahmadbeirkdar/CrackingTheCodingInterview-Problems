#include <iostream>
// Constant space 
// TIme O(n^2)

void rotate(int **matrix, int N){
    for( int i = 0; i < N; ++i ) 
		for( int j = i; j < N; ++j )
			std::swap(matrix[i][j],matrix[j][i]);
    for ( int i = 0; i < N; ++i ) {
        for(int j = 0; j < N/2; j++)
            std::swap(matrix[i][j],matrix[i][N-j-1]);
	}

}

void printMatrix( int ** matrix, int N) {
	for ( int i = 0; i < N; ++i ) {
		for( int j = 0; j < N; ++j ) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int N;
	std::cout << "Enter N for NxN matrix:";
	std::cin >> N;
	int ** matrix = new int*[N];
	for ( int i = 0; i < N; ++i ) {
		matrix[i] = new int[N];
	}

	for ( int i = 0; i < N; ++i) {
		for ( int j = 0; j < N; ++j ) {
			std::cin >> matrix[i][j];
		}
	}
    printMatrix(matrix, N);
	std::cout << "Rotated matrix by 90 (clockwise):\n";
	rotate(matrix, N);
	printMatrix(matrix, N);
	return 0;
}