#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    try
    {
        Vector<float>   v1({1., 0.});
        Vector<float>   v2({1., 0.});
        std::cout << angle_cos(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v1({1., 0.});
        Vector<float>   v2({0., 1.});
        std::cout << angle_cos(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Vector<float>   v1({-1., 1.});
        Vector<float>   v2({1., -1.});
        std::cout << angle_cos(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v1({2., 1.});
        Vector<float>   v2({4., 2.});
        std::cout << angle_cos(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v1({1., 2., 3.});
        Vector<float>   v2({4., 5., 6.});
        std::cout << angle_cos(v1, v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}