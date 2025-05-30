#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    Vector<float>   v1({2., 1.});
    Vector<float>   v2({4., 2.});

    std::vector<float>   vv1({2., 1.});
    std::vector<float>   vv2({3., 4.});
    std::vector<float>   vv3({20., 10.});
    std::vector<float>   vv4({30., 40.});

    Matrix<float>   m1({vv1, vv2});
    Matrix<float>   m2({vv3, vv4});
    try
    {
        std::cout << lerp(0., 1., 0.) << std::endl;
        std::cout << lerp(0., 1., 1.) << std::endl;
        std::cout << lerp(0., 1., 0.5) << std::endl;
        std::cout << lerp(21., 42., 0.3) << std::endl;
        std::cout << lerp(v1, v2, 0.3) << std::endl;
        std::cout << lerp(m1, m2, 0.5) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}