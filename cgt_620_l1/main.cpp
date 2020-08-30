//
//  main.cpp
//  cgt_620_l1
//
//  Created by Saad Jamal on 8/30/20.
//  Copyright © 2020 Saad Jamal. All rights reserved.
//

#include <stdio.h>      /* printf */
#include <iostream>     /* cout */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <vector>
#include <omp.h>        /* OpenMP */

using namespace std;

int* merge(int *xs, int *ys);

int main(int argc, const char * argv[]) {
    
    // creating an array of random ints with length 1000000
    int lenRandArr = 1000000;
    int *randArr = new int[lenRandArr];
    
    vector<int> randList;
    
    srand((unsigned int)time(NULL));
    unsigned long t = clock();
    cout<<"creating an array of random ints with length "<<lenRandArr<<"\n";
    for (int i=0; i<lenRandArr; i++){
        randList.pushrand();
    }
    
    float seconds = ((float)(clock() - t))/CLOCKS_PER_SEC;
    cout<<"time taken to create array sequentially: "<< seconds <<" seconds\n";
    
    // finding max in array sequentially
    int max = INT_MIN;
    
    t = clock();
    for (int i=0; i<lenRandArr; i++){
        if(max< randArr[i]) max = randArr[i];
    }
    seconds = ((float)(clock() - t))/CLOCKS_PER_SEC;
    
    cout<<"max is: "<<max<<", sequential time: "<< seconds <<" seconds\n";
    
    // finding max in array parallel
    max = INT_MIN;
    
    t = clock();
    #pragma omp parallel
    #pragma omp for
    for (int i=0; i<lenRandArr; i++){
        if(max< randArr[i]) max = randArr[i];
    }
    seconds = ((float)(clock() - t))/CLOCKS_PER_SEC;
    
    cout<<"max is: "<<max<<", parallel time: "<< seconds <<" seconds\n";
    
    
    return 0;
}

int* merge(int *xs, int *ys){
    
}
