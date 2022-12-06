#include <iostream>
#include <math.h>

const double TLV = 0.000001;
const double h = TLV;

double f(double x);
double g(double x);
double df(double x);
double bisection(double x, double y);
double secant(double x, double y);
double newton(double x);
double fixed_point(double x);
double false_position(double x, double y);

int main(){
    int choice;
    double x, y;
    std::cout<<"Choose root finding algorithm:"<<std::endl;
    std::cout<<"1. Bisection Method"<<std::endl;
    std::cout<<"2. Secant Method"<<std::endl;
    std::cout<<"3. Newton's Method"<<std::endl;
    std::cout<<"4. Fixed Point Method"<<std::endl;
    std::cout<<"5. False Position Method"<<std::endl;
    std::cout<<"Choice: ";
    std::cin>>choice;
    switch (choice){
    case 1:
        std::cout<<"Value of X: ";
        std::cin>>x;
        std::cout<<"Value of Y: ";
        std::cin>>y;
        std::cout<<"Root = "<<bisection(x,y)<<std::endl;
        break;
    case 2:
        std::cout<<"Value of X: ";
        std::cin>>x;
        std::cout<<"Value of Y: ";
        std::cin>>y;
        std::cout<<"Root = "<<secant(x,y)<<std::endl;
        break;
    case 3:
        std::cout<<"Value of X: ";
        std::cin>>x;
        std::cout<<"Root = "<<newton(x)<<std::endl;
        break;
    case 4:
        std::cout<<"Value of X: ";
        std::cin>>x;
        std::cout<<"Root = "<<fixed_point(x)<<std::endl;
        break;
    case 5:
        std::cout<<"Value of X: ";
        std::cin>>x;
        std::cout<<"Value of Y: ";
        std::cin>>y;
        std::cout<<"Root = "<<false_position(x,y)<<std::endl;
        break;    
    default:
        break;
    }

}

//returns value of the function at x
double f(double x){
    return (cos(x)-3*x+1);
}

//returns value of the function at x
double g(double x){
    return ((1+cos(x))/3);
}

//returns value of the derivative at x
double df(double x){
    return (f(x+h) - f(x-h)) / (2*h);
}

//returns root from bisection method
double bisection(double x, double y){
    double z;
    while((y - x) / 2 > TLV){
        z = (x + y) / 2;
        if(f(z) * f(x) >= 0){
            x = z;
        }
        else{
            y = z;
        }
    }
    return(z);
}

//returns root from newton's method
double newton(double x){
    double y;
    while (true){
        y = x - (f(x) / df(x));
        if (abs(x - y) < TLV){
            break;
        }
        
        x = y;
    }
    return(y);  
}

//returns root from secant method
double secant(double x, double y){
    double z;
    while(true){
        z = x - f(x) * ((x - y) / (f(x)-f(y)));
        if (abs(z - y) < TLV){
            break;
        }
        y = z;
    }
    return(z);   
}

//returns root from fixed point iteration method
double fixed_point(double x){
    while (abs(f(x)) > TLV){
        x = g(x);
    }
    return(x); 
}

//returns root from false position method
double false_position(double x, double y){
    double z = x;
    while (abs(f(x)) > TLV){
        z = x - f(x)*(y-x)/(f(y)-f(x));

        if(f(z) * f(x) < 0){
            y = z;
        }
        else{
            x = z;
        }
    }
    return(z); 
}
