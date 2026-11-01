#include <iostream>
#include <immintrin.h>
#include <ctime>
using namespace std;


template<typename T>
void fill(T* A, T* x, T* B , T* y ,  int N) {
    for (int i = 0; i < N * N; i++) A[i] = i % 7 + 1;
    for (int i = 0; i < N; i++) x[i] = i % 5 + 1;
    for (int i = 0; i < N; i++) B[i] = i % 4 + 1;
    for (int i = 0; i < N; i++) y[i] = i % 4 + 1;

}


template<typename T>
void matVecNormal(T* A, T* x, T* y, int N) {
    T* result1;
    T* result2;
    T* totalResult;
    for (int i = 0; i < N; i++) {
        T sum1 = 0;
        T sum2 = 0;
            for (int j = 0; j < N; j++) {
                sum1 += A[i * N + j] * x[j];
                sum2 +=B[i * N + j] * y[j]
        }   
        result1[i] = sum1 * a;
        result2[i] = sum2 * b;
        totalResult[i] = result1[i] - result2[i];
        cout << totalResult[i] << endl;
    }
}

// SSE для инта
void matVecSSE_int(int* A, int* x, int* y, int N) {
    for (int i = 0; i < N; i++) {
        __m128i vsum = _mm_setzero_si128();
        for (int j = 0; j < N; j += 4) {
            __m128i va = _mm_loadu_si128((__m128i*) & A[i * N + j]);
            __m128i vx = _mm_loadu_si128((__m128i*) & x[j]);
            __m128i mul = _mm_mullo_epi32(va, vx);
            vsum = _mm_add_epi32(vsum, mul);
        }
        int tmp[4];
        _mm_storeu_si128((__m128i*)tmp, vsum);
        y[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
    }
}

//SSE для флоата
void matVecSSE_float(float* A, float* x, float* y, int N) {
    for (int i = 0; i < N; i++) {
        __m128 vsum = _mm_setzero_ps();
        for (int j = 0; j < N; j += 4) {
            __m128 va = _mm_loadu_ps(&A[i * N + j]);
            __m128 vx = _mm_loadu_ps(&x[j]);
            vsum = _mm_add_ps(vsum, _mm_mul_ps(va, vx));
        }
        float tmp[4];
        _mm_storeu_ps(tmp, vsum);
        y[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
    }
}


void matVecSSE_double(double* A, double* x, double* y, int N) {
    for (int i = 0; i < N; i++) {
        __m128d vsum = _mm_setzero_pd();
        for (int j = 0; j < N; j += 2) {
            __m128d va = _mm_loadu_pd(&A[i * N + j]);
            __m128d vx = _mm_loadu_pd(&x[j]);
            vsum = _mm_add_pd(vsum, _mm_mul_pd(va, vx));
        }
        double tmp[2];
        _mm_storeu_pd(tmp, vsum);
        y[i] = tmp[0] + tmp[1];
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
        int Ax_i = tmp1[0] + tmp1[1] + tmp1[2] + tmp1[3] +
            tmp1[4] + tmp1[5] + tmp1[6] + tmp1[7];


       
        __m256i sum2 = _mm256_setzero_si256();
        for (int j = 0; j < N; j += 8) {
            __m256i vb = _mm256_loadu_si256((__m256i*) & B[i * N + j]);
            __m256i vy = _mm256_loadu_si256((__m256i*) & y[j]);
            __m256i mul = _mm256_mullo_epi32(vb, vy);
            sum2 = _mm256_add_epi32(sum2, mul);
        }

        int tmp2[8];
        _mm256_storeu_si256((__m256i*)tmp2, sum2);
        int By_i = tmp2[0] + tmp2[1] + tmp2[2] + tmp2[3] +
            tmp2[4] + tmp2[5] + tmp2[6] + tmp2[7];

        
        out[i] = a * Ax_i - b * By_i;
    }
}



void matVecAVX_float(float* A, float* x, float* y, int N) {
    for (int i = 0; i < N; i++) {
        __m256 vsum = _mm256_setzero_ps();
        for (int j = 0; j < N; j += 8) {
            __m256 va = _mm256_loadu_ps(&A[i * N + j]);
            __m256 vx = _mm256_loadu_ps(&x[j]);
            vsum = _mm256_add_ps(vsum, _mm256_mul_ps(va, vx));
        }
        float tmp[8];
        _mm256_storeu_ps(tmp, vsum);
        y[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3] +
            tmp[4] + tmp[5] + tmp[6] + tmp[7];
    }
}


void matVecAVX_double(double* A, double* x, double* y, int N) {
    for (int i = 0; i < N; i++) {
        __m256d vsum = _mm256_setzero_pd();
        for (int j = 0; j < N; j += 4) {
            __m256d va = _mm256_loadu_pd(&A[i * N + j]);
            __m256d vx = _mm256_loadu_pd(&x[j]);
            vsum = _mm256_add_pd(vsum, _mm256_mul_pd(va, vx));
        }
        double tmp[4];
        _mm256_storeu_pd(tmp, vsum);
        y[i] = tmp[0] + tmp[1] + tmp[2] + tmp[3];
    }
}

int main() {
    int N;
    cout << "Enter N (multiple of 8): ";
    cin >> N;

    int* Ai = new int[N * N];
    int* xi = new int[N];
    int* Bi = new int[N];
    int* yi = new int[N];
    int a = 5;
    int  b = 4;

    //float* Af = new float[N * N];
    //float* xf = new float[N];
    //float* yf = new float[N];

    //double* Ad = new double[N * N];
    //double* xd = new double[N];
    //double* yd = new double[N];


    fill(Ai, xi,  Bi , yi , N);
    int time = clock();
    


    //clock_t t = clock();
    //matVecAVX2_int(Ai, xi, yi, N);
    //t = clock() - t;

    //cout << "\nINT AVX2 time = " << (double)t / CLOCKS_PER_SEC << " sec\n";

    delete[] Ai;
    delete[] xi;
    delete[] yi;

    return 0;
}