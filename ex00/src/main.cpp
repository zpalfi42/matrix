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

    std::vector<float>  vv1;
    vv1.push_back(1.0);
    vv1.push_back(3.0);
    vv1.push_back(2.0);
    std::vector<std::vector<float>> mm;
    mm.push_back(vv);
    mm.push_back(vv1);
    Matrix<float>   m(mm);
    std::cout << m << std::endl;
    Vector<float>   v2(m.reshape_to_vector());
    std::cout << v2 << std::endl;
    try
    {        
        Matrix<float>   m2(v2.reshape_to_matrix(2, 3));
        std::cout << m2 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Vector<float>   v3({2., 3.});
        Vector<float>   v4({5., 7.});

        std::cout << "v3 + v4 = " << v3+v4 << std::endl;
        // v3 += v4;
        v3.add(v4);
        std::cout << "v3 + v4 = " << v3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Vector<float>   v5({2., 3.});
        Vector<float>   v6({5., 7.});
        std::cout << "v5 - v6 = " << v5-v6 << std::endl;
        // v5 -= v6;
        v5.sub(v6);
        std::cout << "v5 - v6 = " << v5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Vector<float>   v7({2., 3.});
        std::cout << "v7 * 2 = " << v7 * float(2) << std::endl;
        // v7 *= 2.;
        v7.scl(2.);
        std::cout << "v7 * 2 = " << v7 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<float>   vv2({1., 2.});
    std::vector<float>   vv3({3., 4.});
    std::vector<float>   vv4({7., 4.});
    std::vector<float>   vv5({-2., 2.});

    try
    {
        Matrix<float>   m1({vv2, vv3});
        Matrix<float>   m2({vv4, vv5});
        std::cout << "m1 + m2 = " << (m1+m2) << std::endl;
        // m1 += m2;
        m1.add(m2);
        std::cout << "m1 + m2 = " << m1 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Matrix<float>   m3({vv2, vv3});
        Matrix<float>   m4({vv4, vv5});
        std::cout << "m3 - m4 = " << m3-m4 << std::endl;
        // m3 -= m4;
        m3.sub(m4);
        std::cout << "m3 - m4 = " << m3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        Matrix<float>   m5({vv2, vv3});
        std::cout << "m5 * 2 = " << m5 * float(2.0) << std::endl;
        // m5 *= 2.;
        m5.scl(2.0);
        std::cout << "m5 * 2 = " << m5 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


}