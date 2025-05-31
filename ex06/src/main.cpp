#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    try
    {
        Vector<float>   v1({0., 0., 1.});
        Vector<float>   v2({1., 0., 0.});
        std::cout << cross_product(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v1({1., 2., 3.});
        Vector<float>   v2({4., 5., 6.});
        std::cout << cross_product(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v1({4., 2., -3.});
        Vector<float>   v2({-2., -5., 16.});
        std::cout << cross_product(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}