#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    Vector<float>   v1({0., 0., 0.});
    Vector<float>   v2({1., 2., 3.});
    Vector<float>   v3({1., -2.});
    try
    {
        std::cout << v1.norm_1() << " " << v1.norm() << " " << v1.norm_inf() << std::endl;
        std::cout << v2.norm_1() << " " << v2.norm() << " " << v2.norm_inf() << std::endl;
        std::cout << v3.norm_1() << " " << v3.norm() << " " << v3.norm_inf() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}