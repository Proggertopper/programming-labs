#include <immintrin.h>
#include <iostream>
#include <intrin.h>
#include <windows.h>
#include <iomanip>
using namespace std;



template<typename T>
void fill(T* A, T* x, T* B, T* y, int N) {
    for (int i = 0; i < N * N; i++) A[i] = i % 7 + 1;
    for (int i = 0; i < N; i++) x[i] = i % 5 + 1;
    for (int i = 0; i < N * N; i++) B[i] = i % 4 + 1;
    for (int i = 0; i < N; i++) y[i] = i % 4 + 1;
}

template<typename T>
void normalMult(T* A, T* x, T* B, T* y,
    T* out, int N, T a, T b)
{
    for (int i = 0; i < N; i++) {
       T s1 = 0;
       T s2 = 0;

        for (int j = 0; j < N; j++) {
            s1 += A[i * N + j] * x[j];
            s2 += B[i * N + j] * y[j];
        }

        out[i] = a * s1 - b * s2;
    }
}

void AVX2int(int* A, int* x, int* B, int* y, int* out, int N, int a, int b) {
    for (int i = 0; i < N; i++) {

        __m256i sum1 = _mm256_setzero_si256();
        for (int j = 0; j < N; j += 8) {
            __m256i va = _mm256_loadu_si256((__m256i*) & A[i * N + j]);
            __m256i vx = _mm256_loadu_si256((__m256i*) & x[j]);
            __m256i mul = _mm256_mullo_epi32(va, vx);
            sum1 = _mm256_add_epi32(sum1, mul);
        }

        int tmp1[8];
        _mm256_storeu_si256((__m256i*)tmp1, sum1);
        int Ax_i = tmp1[0] + tmp1[1] + tmp1[2] + tmp1[3] +tmp1[4] + tmp1[5] + tmp1[6] + tmp1[7];



        __m256i sum2 = _mm256_setzero_si256();
        for (int j = 0; j < N; j += 8) {
            __m256i vb = _mm256_loadu_si256((__m256i*) & B[i * N + j]);
            __m256i vy = _mm256_loadu_si256((__m256i*) & y[j]);
            __m256i mul = _mm256_mullo_epi32(vb, vy);
            sum2 = _mm256_add_epi32(sum2, mul);
        }

        int tmp2[8];
        _mm256_storeu_si256((__m256i*)tmp2, sum2);
        int By_i = tmp2[0] + tmp2[1] + tmp2[2] + tmp2[3] +tmp2[4] + tmp2[5] + tmp2[6] + tmp2[7];


        out[i] = a * Ax_i - b * By_i;
    }
}


void AVX2float(float* A, float* x,float* B, float* y,float* out,int N,float a, float b)      
{
    for (int i = 0; i < N; i++) {

     
        __m256 sum1 = _mm256_setzero_ps();

        for (int j = 0; j < N; j += 8) {
            __m256 va = _mm256_loadu_ps(&A[i * N + j]); 
            __m256 vx = _mm256_loadu_ps(&x[j]);         
            __m256 mul = _mm256_mul_ps(va, vx);         
            sum1 = _mm256_add_ps(sum1, mul);            
        }

        float tmp1[8];
        _mm256_storeu_ps(tmp1, sum1);
        
        float Ax_i = tmp1[0] + tmp1[1] + tmp1[2] + tmp1[3] +tmp1[4] + tmp1[5] + tmp1[6] + tmp1[7];

        
        __m256 sum2 = _mm256_setzero_ps();

        for (int j = 0; j < N; j += 8) {
            __m256 vb = _mm256_loadu_ps(&B[i * N + j]); 
            __m256 vy = _mm256_loadu_ps(&y[j]);         
            __m256 mul = _mm256_mul_ps(vb, vy);
            sum2 = _mm256_add_ps(sum2, mul);
        }

        float tmp2[8];
        _mm256_storeu_ps(tmp2, sum2);

        float By_i =tmp2[0] + tmp2[1] + tmp2[2] + tmp2[3] +tmp2[4] + tmp2[5] + tmp2[6] + tmp2[7];

        out[i] = a * Ax_i - b * By_i;
    }
}

void AVX2double(double* A, double* x,double* B, double* y,  double* out, int N,double a, double b) 
{
    for (int i = 0; i < N; i++) {

        __m256d sum1 = _mm256_setzero_pd();

        for (int j = 0; j < N; j += 4) {
            __m256d va = _mm256_loadu_pd(&A[i * N + j]); 
            __m256d vx = _mm256_loadu_pd(&x[j]);         
            __m256d mul = _mm256_mul_pd(va, vx);         
            sum1 = _mm256_add_pd(sum1, mul);             
        }

       
        double tmp1[4];
        _mm256_storeu_pd(tmp1, sum1);

        double Ax_i = tmp1[0] + tmp1[1] + tmp1[2] + tmp1[3];

        __m256d sum2 = _mm256_setzero_pd();

        for (int j = 0; j < N; j += 4) {
            __m256d vb = _mm256_loadu_pd(&B[i * N + j]); 
            __m256d vy = _mm256_loadu_pd(&y[j]);         
            __m256d mul = _mm256_mul_pd(vb, vy);
            sum2 = _mm256_add_pd(sum2, mul);
        }

        double tmp2[4];
        _mm256_storeu_pd(tmp2, sum2);

        double By_i = tmp2[0] + tmp2[1] + tmp2[2] + tmp2[3];

        
        out[i] = a * Ax_i - b * By_i;
    }
}


int main() {

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
    cout << "Enter N (multiple of 8): ";
    cin >> N;

    int* Ai = new int[N * N];
    int* xi = new int[N];
    int* Bi = new int[N * N];
    int* yi = new int[N];
    int* outi_avx = new int[N];
    int* outi_normal = new int[N];
    int ai = 5;
    int  bi = 4;

    float* Af = new float[N * N];
    float* xf = new float[N];
    float* Bf = new float[N * N];
    float* yf = new float[N];
    float* outf_avx = new float[N];
    float* outf_normal = new float[N];
    float af = 5.0f;
    float bf = 4.0f;

    double* Ad = new double[N * N];
    double* xd = new double[N];
    double* Bd = new double[N * N];
    double* yd = new double[N];
    double* outd_avx = new double[N];
    double* outd_normal = new double[N];
    double ad = 5.0;
    double  bd = 4.0;

    fill(Ai, xi, Bi, yi , N);
    fill(Af, xf, Bf, yf, N);
    fill(Ad, xd, Bd, yd, N);


    int t1 = clock();
    AVX2int(Ai, xi, Bi, yi, outi_avx, N , ai, bi);
    int t2 = clock();
    double avx_ms1 = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    t1 = clock();
    normalMult(Ai, xi, Bi, yi, outi_normal, N, ai, bi);
    t2 = clock();
    double avx_ms2 = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;


    cout << "AVX for int " << avx_ms1 << "ms" << endl;
    cout << "Without AVX " << avx_ms2 << "ms" << endl;

    /*for (int i = 0; i < N; i++) {
        if (outi_avx[i] != outi_normal[i]) {
            cout << "error at i=" << i << endl;
        }
        else
            cout << "all good" << endl;
    }*/

    delete[] Ai;
    delete[] Bi;
    delete[] xi;
    delete[] yi;
    delete[] outi_avx;
    delete[] outi_normal;

    cout << "----------" << endl;


    t1 = clock();
    AVX2float(Af, xf, Bf, yf, outf_avx, N, af, bf);
    t2 = clock();
    double avx_ms3 = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    t1 = clock();
    normalMult(Af, xf, Bf, yf, outf_normal, N, af, bf);
    t2 = clock();
    double avx_ms4 = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    cout << "AVX for float " << avx_ms3 << "ms" << endl;
    cout << "Without AVX " << avx_ms4 << "ms" << endl;

    

    delete[] Af;
    delete[] Bf;
    delete[] xf;
    delete[] yf;
    delete[] outf_avx;
    delete[] outf_normal;


    cout << "----------" << endl;


     t1 = clock();
     AVX2double(Ad, xd, Bd, yd, outd_avx, N, ad, bd);
     t2 = clock();
    double avx_ms5 = 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    t1 = clock();
    normalMult(Ad, xd, Bd, yd, outd_normal, N, ad, bd);
    t2 = clock();
    double avx_ms6= 1000.0 * (t2 - t1) / CLOCKS_PER_SEC;

    cout << "AVX for double " << avx_ms5 << "ms" << endl;
    cout << "Without AVX " << avx_ms6 << "ms" << endl;

    delete[] Ad;
    delete[] Bd;
    delete[] xd;
    delete[] yd;
    delete[] outd_avx;
    delete[] outd_normal;

}

