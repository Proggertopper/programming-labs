#include <immintrin.h>
#include <iostream>
#include <intrin.h>
using std::cout;
using std::endl;

/*int main()
{
	float* A, * B, * Rez;
	int n = 16;
	A = (float*)_mm_malloc(n * sizeof(float), 32);
	B = (float*)_mm_malloc(n * sizeof(float), 32);
	Rez = (float*)_mm_malloc(n * sizeof(float), 32);

	__m256 *SA, *SB, *SRez;
	SA = (__m256*)A;
	SB = (__m256*)B;
	SRez = (__m256*)Rez;


	int t1 = clock();
	for(int i = 0; i < n; i++)
	{
		Rez[i] = A[i] + B[i];
	}
	for(int i = 0; i < n / 8; i++)
	{
		SRez[i] = _mm256_add_ps(SA[i], SB[i]);
	}
}*/

int main() {
    int N = 3;                    
    float A[3][3] = {             
        {11, 15, 12},
        {15, 15, 19},
        {21, 12, 33}
    };
    float B[3][3] = {             
        {3, 5, 6},
        {7, 9, 12},
        {14, 15, 18}
    };

    float x[3] = { 4, 5, 6 };       
    float resultWithoutScalar[3];     
    
    float y[3] = { 3, 4, 4 };
    float resultWithoutScalar2[3];

    float a = 4.0f;   
    float b = 5.0f;
    float resultWith1[3];     
    float resultWith2[3];

	float resultOfMinus[3];

   
    for (int i = 0; i < N; i++) {
        float sum1 = 0;
		float sum2 = 0;
        for (int j = 0; j < N; j++) {
            sum1 += A[i][j] * x[j];
			sum2 += B[i][j] * y[j];
        }
        resultWithoutScalar[i] = sum1;
		resultWithoutScalar2[i] = sum2;
    }

    
    for (int i = 0; i < N; i++) {
        cout << "A*x{" << i << "} = " << resultWithoutScalar[i] << " "<< endl;
		cout<< "B*y{" << i <<"} = " <<  resultWithoutScalar2[i] << " " << endl;
        resultWith1[i] = a * resultWithoutScalar[i];
		resultWith2[i] = b * resultWithoutScalar2[i];
        cout << "-----------------" << endl;
        cout << "a*A*x{" << i << "} = " << resultWith1[i] << " " << endl;
        cout << "b*B*y{" << i << "} = " << resultWith2[i] << " " << endl;
        cout << "-----------------" << endl;

    }
	cout << endl;

    
    cout << "Result without SIMD: "<< endl;
    for (int i = 0; i < N; i++) {
	 resultOfMinus[i] = resultWith1[i] - resultWith2[i];
	 cout <<"a*A*x - b*B*y{"<< i << "} = "<< resultOfMinus[i] << endl;
    }
    cout << endl;





    

    return 0;
}


