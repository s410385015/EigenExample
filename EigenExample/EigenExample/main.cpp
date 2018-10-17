#include<iostream>
#include <Eigen/Sparse>
#include <Eigen/Core>
using namespace std;
using namespace Eigen;

int main()
{
	// solve the linear system
	// 5x + 2y + 6z = 14
	// 3x +      9z = 10
	//      8y + 2z = 12
	// 2x + 8y      = 13

	vector<Triplet<double>> a;

	//VectorXd can be also in 2d 
	//eg. VectorXd b(2,2);
	//b(0,0)= ...

	VectorXd b(4);

	a.push_back(Triplet<double>(0, 0, 5));
	a.push_back(Triplet<double>(0, 1, 2));
	a.push_back(Triplet<double>(0, 2, 6));
	a.push_back(Triplet<double>(1, 0, 3));
	a.push_back(Triplet<double>(1, 2, 9));
	a.push_back(Triplet<double>(2, 1, 8));
	a.push_back(Triplet<double>(2, 2, 2));
	a.push_back(Triplet<double>(3, 0, 2));
	a.push_back(Triplet<double>(3, 1, 8));
	
	b(0) = 14;
	b(1) = 10;
	b(2) = 12;
	b(3) = 13;
	
	SparseMatrix<double> A(4,3);
	A.setFromTriplets(a.begin(), a.end());
	
	//Convert into ATA=ATb
	SparseMatrix<double> ATA= A.transpose()*A;
	b = A.transpose()*b;

	
	
	

	SimplicialCholesky<SparseMatrix<double>> chol(ATA);
	MatrixXd result = chol.solve(b);

	for (int i = 0; i < 3; i++)
		cout << result(i)<< endl;
	getchar();
}