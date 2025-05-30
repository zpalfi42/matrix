#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    Vector<float>   v1({0., 0.});
    Vector<float>   v2({1., 1.});
    try
    {
        std::cout << v1.dot(v2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    Vector<float>   v3({1., 1.});
    Vector<float>   v4({1., 1.});
    try
    {
        std::cout << v3.dot(v4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Vector<float>   v5({-1., 6.});
    Vector<float>   v6({3., 2.});
    try
    {
        std::cout << v5.dot(v6) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}