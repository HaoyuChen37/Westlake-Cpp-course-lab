
// 1.2
double Exponential(double base, int exp) {
    double ans = 1;
    for (int i = 0; i < exp; ++i){
        ans *= base;
    }
    return ans;
}

double Exponential(double base, int exp) {
    if (exp == 1){
        return base;
    }
    return Exponential(base, exp-1);
}

double Exponential(double base, int exp) {
    if (exp == 1){
        return base;
    }
    if (exp%2==1){
        return Exponential(base, exp/2)*2; 
    }
    else{
        return Exponential(base, exp/2)*2;
    }
}

int main(){
    Exponential(2,2);
    return 0;
}