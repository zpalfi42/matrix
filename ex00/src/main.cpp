#include <Vector.hpp>
#include <Matrix.hpp>

int main()
{
    std::vector<float>  vv;
    vv.push_back(1.0);
    vv.push_back(3.0);
    vv.push_back(2.0);
    Vector<float>   v(vv);
    std::cout << v << std::endl;

    std::vector<float>  vv2;
    vv2.push_back(1.0);
    vv2.push_back(3.0);
    vv2.push_back(2.0);
    std::vector<std::vector<float>> mm;
    mm.push_back(vv);
    mm.push_back(vv2);
    Matrix<float>   m(mm);
    std::cout << m << std::endl;
    Vector<float>   v2(m.reshape_to_vector());
    std::cout << v2 << std::endl;
    Matrix<float>   m2(v2.reshape_to_matrix(2, 3));
    std::cout << m2 << std::endl;
}