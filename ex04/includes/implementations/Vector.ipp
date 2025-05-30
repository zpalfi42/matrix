#include <Vector.hpp>
#include <Matrix.hpp>

template <typename K>
Vector<K>::Vector( void )
{

}

template <typename K>
Vector<K>::Vector( const std::vector<K> &data )
{
    this->_data = data;
}

template <typename K>
Vector<K>::Vector( const Vector<K> &other )
{
    this->_data = other._data;
}

template <typename K>
Vector<K>::~Vector( void )
{

}

/*
GETTERS
*/
template <typename K>
std::vector<K>  Vector<K>::getData( void ) const
{
    return  this->_data;
}

/*
OPERATORS
*/
template <typename K>
Vector<K>   &Vector<K>::operator=(Vector<K> const &rhs)
{
    this->_data = rhs._data;
    return *this;
}

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Vector<K>& v)
{
    os << "[";
    for (size_t i = 0; i < v.size(); i++)
    {
        os << v[i] << ((i < v.size()-1) ? "," : "");
    }
    os << "]";
    return os;
};

template <typename K>
K   &Vector<K>::operator[]( size_t i)
{
    return  this->_data[i];
}

template <typename K>
const K   &Vector<K>::operator[]( size_t i) const
{
    return  this->_data[i];
}

template <typename K>
Vector<K>   operator+(const Vector<K> &lhs, const Vector<K> &rhs)
{
    if (lhs.size() != rhs.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    Vector<K>   res(lhs);

    for (size_t i = 0; i < res.size(); i++)
        res[i] += rhs[i];  
        
    return res;
}

template <typename K>
Vector<K>   operator-(const Vector<K> &lhs, const Vector<K> &rhs)
{
    if (lhs.size() != rhs.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    Vector<K>   res(lhs);

    for (size_t i = 0; i < res.size(); i++)
        res[i] -= rhs[i];  
        
    return res;
}

template <typename K>
Vector<K>   operator*(const Vector<K> &lhs, const K a)
{
    Vector<K>   res(lhs);

    for (size_t i = 0; i < res.size(); i++)
        res[i] *= a;  
        
    return res;
}

template <typename K>
Vector<K>&  Vector<K>::operator+=( const Vector<K> &v )
{
    if (this->_data.size() != v.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] += v[i];
    
    return  *this;
}

template <typename K>
Vector<K>&  Vector<K>::operator-=( const Vector<K> &v )
{
    if (this->_data.size() != v.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] -= v[i];    
    
    return  *this;
}

template <typename K>
Vector<K>&  Vector<K>::operator*=( const K a )
{
    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] *= a;

    return  *this;
}

/*
UTILS
*/
template <typename K>
size_t  Vector<K>::size( void ) const
{
    return _data.size();
};

template <typename K>
void    Vector<K>::print( void ) const
{
    std::cout << "[";
    for (size_t i = 0; i < _data.size(); i++)
    {
        std::cout << _data[i] << ((i < _data.size()-1) ? "," : "");
    }
    std::cout << "]" << std::endl;
}

template <typename K>
Matrix<K>   Vector<K>::reshape_to_matrix( size_t rows, size_t cols )
{
    if (this->size() != rows*cols)
        throw std::runtime_error("Vector to Matrix conversion not possible: total elements do not match rows * cols.");

    std::vector<std::vector<K>>  mm;
    for (size_t i = 0; i < rows; i++)
    {
        std::vector<K>  v;
        for (size_t  j = 0; j < cols; j++)
            v.push_back(this->_data[j+cols*i]);    
        mm.push_back(v);
    }
    return Matrix<K>(mm);
}

/*
OPERATIONS
*/

template <typename K>
void    Vector<K>::add( const Vector<K>  &v )
{
    if (this->_data.size() != v.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] += v[i];        
};

template <typename K>
void    Vector<K>::sub( const Vector<K>  &v )
{
    if (this->_data.size() != v.size())
        throw std::runtime_error("Could not compute sum of two vectors: Vectors are not the same size.");

    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] -= v[i];        
}

template <typename K>
void    Vector<K>::scl( const K  a )
{
    for (size_t i = 0; i < this->_data.size(); i++)
        this->_data[i] *= a;    
}

template <typename K>
K   Vector<K>::dot( const Vector<K> &v )
{
    if (this->size() != v.size())
        throw std::runtime_error("Could not compute dot of two vectors: Vectors are not the same size.");

    K   res = this->_data[0] * v[0];

    for (size_t i = 1; i < this->size(); i++)
        res += this->_data[i] * v[i];

    return res;
}

template <typename K>
float   Vector<K>::norm_1( void )
{
    if (this->size() == 0)
        throw   std::runtime_error("Could not compute norm_1 of vector: Vector empty");
    
    float res = 0;

    for (size_t i = 0; i < this->size(); i++)
        res = std::fma(this->_data[i], (this->_data[i] < 0) ? -1 : 1, res);
    
    return res;
}

template <typename K>
float   Vector<K>::norm( void )
{
    if (this->size() == 0)
        throw   std::runtime_error("Could not compute norm of vector: Vector empty");

    float res = 0;

    for (size_t i = 0; i < this->size(); i++)
        res = std::fma(this->_data[i], this->_data[i], res);
    
    return pow(res, 0.5f);
}

template <typename K>
float   Vector<K>::norm_inf( void )
{
    if (this->size() == 0)
        throw   std::runtime_error("Could not compute norm_inf of vector: Vector empty");
        
    float res = this->_data[0];

    for (size_t i = 1; i < this->size(); i++)
        res = std::max(res, this->_data[i] * (this->_data[i] < 0 ? -1 : 1));
    
    return res;
}

template <typename K>
Vector<K>   linear_combination(const std::vector<Vector<K>>   &vecs, const std::vector<K>    &coefs)
{
    if (vecs.size() != coefs.size() || vecs.size() < 2)
        throw std::runtime_error("Could not compute linear combination of vectors and coefs: Not the same number of vectors and coefs.");
    if (vecs[0].size() == 0)
        throw std::runtime_error("Could not compute linear combination of vectors and coefs: Vector empty.");  
    
    Vector<K>   res(vecs[0]*coefs[0]);
    for (size_t i = 1; i < vecs.size(); i++)
    {
        Vector<K>   temp(vecs[i]*coefs[i]);
        res.add(temp);
    }
    
    return res;
}

template <typename V>
V   lerp(const V    u, const V  v, const float  t)
{
    if constexpr (std::is_arithmetic_v<V>)
        return std::fma(u, (1 - t), (v * t));
    return (u * (1 - t)) + (v * t);
}