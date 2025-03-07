#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>



int Falcon_9_Rocket_for_loop(){
    double delta_v, w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp;
    printf("input w_1, w_2, m1_0, m1_1, m2_0, m2_1 \n");
    // 2770 3410 421300 25600 96570 3900
    scanf("%lf %lf %lf %lf %lf %lf", &w_1, &w_2, &m1_0, &m1_1, &m2_0, &m2_1);
    printf("w_1 = %lf, w_2 = %lf, m1_0 = %lf, m1_1 = %lf, m2_0 = %lf, m2_1 = %lf\n", w_1, w_2, m1_0, m1_1, m2_0, m2_1);

    for (int i = 30000; i < 40000; i++) {
        mp = i;
        delta_v = w_1* log((m1_0+m2_0+mp)/(m1_1+m2_0+mp)) + w_2* log((m2_0+mp)/(m2_1+mp));
        if (delta_v < 7900) {
            printf("This rocket can not carry the designated payload to orbit when mp = %lf\n", mp);
            break;
        }
    }

    return 0;
}

int Falcon_9_Rocket_while_loop(){
    double delta_v, w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp;
    printf("input w_1, w_2, m1_0, m1_1, m2_0, m2_1 \n");
    // 2770 3410 421300 25600 96570 3900
    scanf("%lf %lf %lf %lf %lf %lf", &w_1, &w_2, &m1_0, &m1_1, &m2_0, &m2_1);
    printf("w_1 = %lf, w_2 = %lf, m1_0 = %lf, m1_1 = %lf, m2_0 = %lf, m2_1 = %lf\n", w_1, w_2, m1_0, m1_1, m2_0, m2_1);

    mp = 0;
    delta_v = w_1* log((m1_0+m2_0+mp)/(m1_1+m2_0+mp)) + w_2* log((m2_0+mp)/(m2_1+mp));
    while (delta_v >= 7900) {
        mp++;
        delta_v = w_1* log((m1_0+m2_0+mp)/(m1_1+m2_0+mp)) + w_2* log((m2_0+mp)/(m2_1+mp));
    }
    printf("This rocket can not carry the designated payload to orbit when mp = %lf\n", mp);

    return 0;
}

int Falcon_9_Rocket_dichotomy(){
    double delta_v, w_1, w_2, m1_0, m1_1, m2_0, m2_1, mp;
    printf("input w_1, w_2, m1_0, m1_1, m2_0, m2_1 \n");
    // 2770 3410 421300 25600 96570 3900
    scanf("%lf %lf %lf %lf %lf %lf", &w_1, &w_2, &m1_0, &m1_1, &m2_0, &m2_1);
    printf("w_1 = %lf, w_2 = %lf, m1_0 = %lf, m1_1 = %lf, m2_0 = %lf, m2_1 = %lf\n", w_1, w_2, m1_0, m1_1, m2_0, m2_1);

    double left = 0, right = 40000;
    int count = 0;
    bool flag_1 = true, flag_2 = true;
    while (right - left > 1e-6) {
        count++;
        mp = (left + right) / 2;
        delta_v = w_1* log((m1_0+m2_0+mp)/(m1_1+m2_0+mp)) + w_2* log((m2_0+mp)/(m2_1+mp));
        if (delta_v >= 7900) {
            left = mp;
        } else {
            right = mp;
        }
        
        if (flag_1 && right - left < 1) {
            flag_1 = false;
            printf("The number of iterations when the precision is 1kg is %d\n", count);
        }
        if (flag_2 && right - left < 1e-3) {
            flag_2 = false;
            printf("The number of iterations when the precision is 1g is %d\n", count);
        }
    }
    printf("This rocket can not carry the designated payload to orbit when mp = %lf\n", mp);

    return 0;
}


int main(int argc, char **argv) {
    // Falcon_9_Rocket_for_loop();
    // Falcon_9_Rocket_while_loop();
    Falcon_9_Rocket_dichotomy();
    return 0;
}