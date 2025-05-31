#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    try
    {
        Matrix<float>   m1({{1., 0.}, {0., 1.}});
        Vector<float>   v1({4., 2.});
        std::cout << m1.mul_vec(v1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Matrix<float>   m1({{2., 0.}, {0., 2.}});
        Vector<float>   v1({4., 2.});
        std::cout << m1.mul_vec(v1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Matrix<float>   m1({{2., -2.}, {-2., 2.}});
        Vector<float>   v1({4., 2.});
        std::cout << m1.mul_vec(v1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Matrix<float>   m1({{1., 0.}, {0., 1.}});
        Matrix<float>   m2({{1., 0.}, {0., 1.}});
        std::cout << m1.mul_mat(m2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Matrix<float>   m1({{1., 0.}, {0., 1.}});
        Matrix<float>   m2({{2., 1.}, {4., 2.}});
        std::cout << m1.mul_mat(m2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Matrix<float>   m1({{3., -5.}, {6., 8.}});
        Matrix<float>   m2({{2., 1.}, {4., 2.}});
        std::cout << m1.mul_mat(m2) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}