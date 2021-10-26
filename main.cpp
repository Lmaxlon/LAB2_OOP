#include <iostream>
#include "hypocycloid.h"
#include "hypocycloid.cpp"
using namespace hypocyc;
int main(){

    double fi,x_,y_,R_,r_,dist_;

    x_ =  x();
    y_ =  y();

    R_ =  R();
    r_ =  r();
    dist_ =  dist();

    std::cout <<"\n";

    Point point(x_,y_);
    hypocycloid hip(point,R_,r_,dist_);

    while (true)
    {

        switch (choice())

        {
            case 1: {
                fi =  ungl();
                std::cout << hip.coordinates(fi);
                std::cout<<"\n";
                break;
            }

            case 2: {
                std::cout << "R = " << hip.get_R() << std::endl;
                std::cout << "r = " << hip.get_r() << std::endl;
                std::cout<<"\n";
                break;
            }

            case 3: {
                fi =  ungl();
                std::cout << hip.radius_of_curvature(fi);
                std::cout<<"\n";
                break;
            }

            case 4: {
                int k = hip.type();
                if (k == 1)
                    std:: cout<<"Ordinary\n";
                if (k == 2)
                    std::cout<<"Shortened\n";
                if (k == 3)
                    std::cout<<"Elongated\n";
                std::cout<<"\n";
                break;
            }

            case 5: {
                fi =  ungl();
                std::cout << hip.sec_square(fi);
                std::cout<<"\n";
                break;
            }

            case 6: {
                return EXIT_SUCCESS;
            }

            default: { return (EXIT_SUCCESS); }
        }
    }



}



//вынести диалоговые окна