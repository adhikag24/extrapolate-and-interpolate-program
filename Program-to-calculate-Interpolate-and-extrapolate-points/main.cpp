#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

void extrapolate(float x1, float x2, float y1, float y2, int n){
float extrapolation = y1 + ((n - x1) / (x2 - x1)) * (y2 - y1);
stringstream ss;
ss << fixed << setprecision(2) << extrapolation << endl;
string newStr = ss.str();
cout << newStr << endl;
}

void interpolate(float x1, float x2, float y1, float y2, int n){
float interpolation = y1 + ((y2 - y1) / (x2 - x1)) * (n - x1);
stringstream ss;
ss << fixed << setprecision(2) << interpolation << endl;
string newStr = ss.str();
cout << newStr << endl;
}

void convertToStr(float answer){
stringstream ss;
ss << fixed << setprecision(2) << answer << endl;
string newStr = ss.str();
cout << newStr << endl;
}

int main(){

int n;
int  m1, m2;
float answer = 0.0;
//case 1:
bool foundN = false;

//case 3:
int qCheck = 0;
int closest1number = 0;
int closest2number = 0;
float x1 = 0, x2 = 0;
float y1, y2;

//case 4:
int countNot0 = 0;
cout << "Input the estimated point:" << endl;
cin >> n;
cout << "Input how many point do you have:" << endl;
cin >> m1;

int instance[m1];
//for case 2:
int underN[m1];
int aboveN[m1];
cout << "Input the points:" <<endl;
for (int i = 0; i < m1; i++){
    cin >> instance[i];
    if (instance[i] == n){
        foundN = true;
    }
    if (n > instance[i]){
        qCheck += 1;
    }
    else if (n < instance[i]){
        qCheck -= 1;
    }
}
cout <<"Input the value of the points you have: "<< endl;
m2 = m1;
float price[m2];

for(int i = 0; i < m2; i++){
    cin >> price[i];
    if (price[i] != 0){
        countNot0 += 1;
    }
    //checking prices lapse
   if (price[i] == 0 || price[i] == -1){
        instance[i] = 0;
    }
}
//case 4:
if (countNot0 == 1){
    for (int i = 0; i < m2; i++){
        if (price[i] != 0){
            answer = price[i];
        }
        else{
            continue;
        }
    }
convertToStr(answer);
}
else{
    //case 1:
    if (foundN == true){
        for(int i = 0; i < m1; i++){
            if (instance[i] == n){
                answer = price[i];
            }
            else{
                continue;
            }
        }
convertToStr(answer);
    }
    //case 3:
    else if(qCheck - m1 == 0){
        for(int i = 0; i < m1; i++){
            if (instance[i] > closest1number){
                closest1number = instance[i];
                x1 = closest1number;
                y1 = price[i];
            }
        }
        for (int i = 0; i < m1; i++){
            if (instance[i] > closest2number && instance[i] < closest1number){
                closest2number = instance[i];
                x2 = closest2number;
                y2 = price[i];
            }
        }
        extrapolate(x1, x2, y1, y2, n);
    }
    else if(qCheck + m1 == 0){
            for (int i = 0; i < m1; i++){
                if (instance[i] != 0){
                    closest1number = instance[i];
                    y1 = price[i];
                    break;
                }
            }
            for (int i = 0; i < m2; i++){
                if (instance[i] != 0 && instance[i] > closest1number){
                    closest2number = instance[i];
                    y2 = price[i];
                    break;
                }
            }
         for(int i = 0; i < m1; i++){
            if (instance[i] == 0){
                continue;
            }
            if (instance[i] < closest1number){
                closest1number = instance[i];
                x1 = closest1number;
                y1 = price[i];
            }
        }
        if (x1 == 0){
            x1 = closest1number;
        }
        for (int i = 0; i < m1; i++){
            if (instance[i] == 0){
                continue;
            }
            if (instance[i] < closest2number && instance[i] > closest1number){
                closest2number = instance[i];
                x2 = closest2number;
                y2 = price[i];
            }
        }
        if (x2 == 0){
            x2 = closest2number;
        }
        extrapolate(x1, x2, y1, y2, n);
    }
    //case 2:
    else{
        for (int i = 0; i < m1; i++){
            underN[i] = 0;
            aboveN[i] = 0;
        }
        for (int i = 0; i < m1; i++){
            if (instance[i] == 0){
                continue;
            }
            if (instance[i] < n){
                underN[i] = instance[i];
            }
            else{
                aboveN[i] = instance[i];
            }
        }
        //find largest number in underN
        for (int i = 0; i < m1; i++){
            if (underN[i] == 0){
                continue;
            }
            if (underN[i] > closest1number){
                closest1number = underN[i];
                x1 = closest1number;
                y1 = price[i];
            }
            else {
                continue;
            }
        }
        //find smallest number in aboveN:
        for (int i = 0; i < m1; i++){
            if (aboveN[i] != 0){
                closest2number = aboveN[i];
                x2 = closest2number;
                y2 = price[i];
            }
        }
        for (int i = 0; i < m1; i++){
            if (aboveN[i] == 0){
                continue;
            }
            if (aboveN[i] < closest2number){

                closest2number = aboveN[i];
                x2 = closest2number;
                y2 = price[i];
            }
            else{
                continue;
            }
        }
        interpolate(x1, x2, y1, y2, n);
    }
}
}
