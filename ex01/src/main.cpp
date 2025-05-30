#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    Vector<float>   v1({1.,0.,0.});
    Vector<float>   v2({0.,1.,0.});
    Vector<float>   v3({0.,0.,1.});

    Vector<float>   v4({1.,2.,3.});
    Vector<float>   v5({0.,10.,-100.});

    try
    {
        std::vector<Vector<float>>  vv1 = {v1,v2,v3};
        std::vector<float>          vc1 = {10.,-2.,0.5};
        std::cout << linear_combination(vv1, vc1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::vector<Vector<float>>  vv1 = {v4,v5};
        std::vector<float>          vc1 = {10.,-2.};
        std::cout << linear_combination(vv1, vc1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}