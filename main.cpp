#include <iostream>

int global_variable = 5; // global_variable visible in all functions in the main.cpp file
int global_visible_variable = 6;

int my_func(int a);

class MyClass{
public:
    explicit MyClass(int arg):
    x{arg}{}
    MyClass():x{0}{}

    void print() const{
        int y = 10;
        std::cout<<"Y: "<<y<<std::endl;
        std::cout<<"X: "<<x<<std::endl;
    }

private:
    int x;
};

void my_new_func();

int main(){

    MyClass n1;
    n1.print();

    int local_variable = 3; // local_variable visible only in the main function

    std::cout<<global_visible_variable<<std::endl;

    int global_visible_variable = 7;

    std::cout<<global_variable<<" "<<local_variable<<std::endl;
    std::cout<<my_func(6)<<std::endl;

    int i = 10;

    //for(int i = 0; i < 5; ++i){ // lifetime of the i is limited by the for loop
    for(i = 0; i < 5; ++i){ 
        std::cout<<i<<std::endl;
    }

    std::cout<<i<<std::endl;

    std::cout<<global_visible_variable<<std::endl;
    std::cout<< ::global_visible_variable <<std::endl;

    my_new_func();

    return 0;
}

void my_new_func(){
    std::cout<<"My new func: ";
    std::cout<<global_visible_variable<<std::endl;
}

int my_func(int a){
    // int temp = local_variable; // local_variable doesn't visible in the function
    return a + global_variable;
}