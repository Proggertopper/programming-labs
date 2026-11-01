
#include <immintrin.h>
#include <iostream>
#include <intrin.h>
#include <windows.h>
#include <iomanip>
using namespace std;


void compute(float* A, float* B, float* x, float* y,
    float* result, int N, float a, float b)
{
    for (int i = 0; i < N; i++) {
        float s1 = 0.0f;
        float s2 = 0.0f;

        for (int j = 0; j < N; j++) {
            s1 += A[i * N + j] * x[j];
            s2 += B[i * N + j] * y[j];
        }

        result[i] = a * s1 - b * s2;
    }
}



int main()
{
    int CPUInfo[4];
    char CPUString[32];
    __cpuid(CPUInfo, 0);
    memset(CPUString, 0, sizeof(CPUString));
    *((int*)CPUString) = CPUInfo[1];
    *((int*)(CPUString + 4)) = CPUInfo[3];
    *((int*)(CPUString + 8)) = CPUInfo[2];
    printf("  CPU vendor: %s\n", CPUString);


	bool sseSupportted = false;
	bool sse2Supportted = false;
	bool sse3Supportted = false;
	bool ssse3Supportted = false;
	bool sse4_1Supportted = false;
	bool sse4_2Supportted = false;
	bool sse4aSupportted = false;
	bool sse5Supportted = false;
	bool avxSupportted = false;

	int cpuinfo[4];
	__cpuid(cpuinfo, 1);


	sseSupportted = cpuinfo[3] & (1 << 25) || false;
	sse2Supportted = cpuinfo[3] & (1 << 26) || false;
	sse3Supportted = cpuinfo[2] & (1 << 0) || false;
	ssse3Supportted = cpuinfo[2] & (1 << 9) || false;
	sse4_1Supportted = cpuinfo[2] & (1 << 19) || false;
	sse4_2Supportted = cpuinfo[2] & (1 << 20) || false;

	avxSupportted = cpuinfo[2] & (1 << 28) || false;
	bool osxsaveSupported = cpuinfo[2] & (1 << 27) || false;
	if (osxsaveSupported && avxSupportted)
	{
		unsigned long long xcrFeatureMask = _xgetbv(0);
		avxSupportted = (xcrFeatureMask & 0x6) == 0x6;
	}


	__cpuid(cpuinfo, 0x80000000);
	int numExtendedIds = cpuinfo[0];
	if (numExtendedIds >= 0x80000001)
	{
		__cpuid(cpuinfo, 0x80000001);
		sse4aSupportted = cpuinfo[2] & (1 << 6) || false;
		sse5Supportted = cpuinfo[2] & (1 << 11) || false;
	}

	cout << "SSE: " << (sseSupportted ? "+" : "-") << endl; 
	cout << "SSE2: " << (sse2Supportted ? "+" : "-") << endl;
	cout << "SSE3: " << (sse3Supportted ? "+" : "-") << endl;
	cout << "SSE4.1: " << (sse4_1Supportted ? "+" : "-") << endl;
	cout << "SSE4.2: " << (sse4_2Supportted ? "+" : "-") << endl;
	cout << "SSE4a: " << (sse4aSupportted ? "+" : "-") << endl;
	cout << "SSE5: " << (sse5Supportted ? "+" : "-") << endl;
	cout << "AVX: " << (avxSupportted ? "+" : "-") << endl; 

    int N;

    cout << "Enter size N : ";
    cin >> N;

    if (N % 8 != 0) {
        cout << "ERROR: N must be divided by 8 .\n";
        return 0;
    }

    float a = 2.0f;
    float b = 3.0f;

    float* A = new float[N * N];
    float* B = new float[N * N];
    float* x = new float[N];
    float* y = new float[N];
    float* result = new float[N];

    // заполняем
    for (int i = 0; i < N * N; i++) {
        A[i] = (i % 10) + 1;
        B[i] = (i % 7) + 1;
    }
    for (int i = 0; i < N; i++) {
        x[i] = i % 5 + 1;
        y[i] = i % 3 + 1;
    }

    cout << fixed << setprecision(3);

    
    clock_t t1 = clock();
    compute(A, B, x, y, result, N, a, b);
    clock_t t2 = clock();
    double naive_ms = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    
    
    
        t1 = clock();
        compute(A, B, x, y, result, N, a, b);
        t2 = clock();
        double avx_ms = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    cout << "\nRESULTS:\n";
    cout << "Naive time: " << naive_ms << " ms\n";
    cout << "AVX time:   " << avx_ms << " ms\n";


    delete[] A;
    delete[] B;
    delete[] x;
    delete[] y;
    delete[] result;

    return 0;
}


   
   

    
    void compute(float* A, float* B, float* x, float* v,
        float* result, int N, float a, float b)
    {
        __m256 av = _mm256_set1_ps(a);
        __m256 bv = _mm256_set1_ps(b);

        for (int i = 0; i < N; i++) {
            __m256 sum1 = _mm256_setzero_ps();
            __m256 sum2 = _mm256_setzero_ps();

            for (int j = 0; j < N; j += 8) {
                __m256 arow = _mm256_loadu_ps(&A[i * N + j]);
                __m256 brow = _mm256_loadu_ps(&B[i * N + j]);
                __m256 xv = _mm256_loadu_ps(&x[j]);
                __m256 vv = _mm256_loadu_ps(&v[j]);

                sum1 = _mm256_add_ps(sum1, _mm256_mul_ps(arow, xv));
                sum2 = _mm256_add_ps(sum2, _mm256_mul_ps(brow, vv));
            }

            // суммируем 8 элементов
            float t1[8], t2[8];
            _mm256_storeu_ps(t1, sum1);
            _mm256_storeu_ps(t2, sum2);

            float s1 = t1[0] + t1[1] + t1[2] + t1[3] + t1[4] + t1[5] + t1[6] + t1[7];
            float s2 = t2[0] + t2[1] + t2[2] + t2[3] + t2[4] + t2[5] + t2[6] + t2[7];

            result[i] = a * s1 - b * s2;
        }
    }

   

