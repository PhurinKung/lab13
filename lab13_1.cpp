#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double A[], int n, double B[]){
    
    double sum = 0;
    for(int i=0;i<n;i++) sum+=A[i];
    B[0] = sum/n;
    
    double sqrtsum = 0;
    for(int i=0;i<n;i++) sqrtsum+=A[i]*A[i];
    B[1] = sqrt(sqrtsum/n-B[0]*B[0]);

    double multiply = 1;
    for(int i=0;i<n;i++) multiply*=A[i];
    B[2] = pow(multiply, 1.0/n);

    double sumofpartion = 0;
    for(int i=0;i<n;i++) sumofpartion+=1/A[i];
    B[3] = n/sumofpartion;

    double mx = 0;
    double mn = 100;
    for(int i=0;i<n;i++){
        mn = min(mn,A[i]);
        mx = max(mx,A[i]);
    }
    B[4] = mx;
    B[5] = mn;
}
