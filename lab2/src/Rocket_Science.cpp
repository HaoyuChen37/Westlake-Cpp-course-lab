#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>



int Single_stage_Rocket_Calculator() {
    double delta_v, w, m0, m1,mp;
    printf("input w, m0, m1,mp \n");
    scanf("%lf %lf %lf %lf", &w, &m0, &m1, &mp);
    printf("w = %lf, m0 = %lf, m1 = %lf, mp = %lf\n", w, m0, m1, mp);
    
    delta_v = w* log((m0+mp)/(m1+mp));
    
    printf("delta_v = %lf\n", delta_v);
    if (delta_v > 7900) {
        printf("This rocket can carry the designated payload to orbit \n");
    } else {
        printf("This rocket can't carry the designated payload to orbit \n");
    }
    
    return 0;
}

int Falcon_9_Rocket(){
    double delta_v, w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp;
    printf("input w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp \n");
    scanf("%lf %lf %lf %lf %lf %lf %lf", &w_1, &w_2, &m1_0, &m1_1, &m2_0, &m2_1, &mp);
    printf("w_1 = %lf, w_2 = %lf, m1_0 = %lf, m1_1 = %lf, m2_0 = %lf, m2_1 = %lf, mp = %lf\n", w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp);
    
    delta_v = w_1* log((m1_0+m2_0+mp)/(m1_1+m2_0+mp)) + w_2* log((m2_0+mp)/(m2_1+mp));
    
    printf("delta_v = %lf\n", delta_v);
    if (delta_v > 7900) {
        printf("This rocket can carry the designated payload to orbit \n");
    } else {
        printf("This rocket can't carry the designated payload to orbit \n");
    }
    return 0;
}

int main(int argc, char **argv) {
    // Single_stage_Rocket_Calculator();
    Falcon_9_Rocket();
    return 0;
}