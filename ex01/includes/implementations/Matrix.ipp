#include <Matrix.hpp>
#include <Vector.hpp>

template <typename K>
Matrix<K>::Matrix(void)
{
    this->_cols = 0;
    this->_rows = 0;
}

template <typename K>
Matrix<K>::Matrix( const std::vector<std::vector<K>> &data)
{
    this->_data = data;
    this->_rows = data.size();
    if (data.size() == 0)
        this->_cols = 0;
    else
        this->_cols = data.back().size();
    for (size_t i = 0; i < this->_rows; i++)
    {
        if (this->_data[i].size() != this->_cols)
            throw   std::runtime_error("Failed construction of Matrix: Vectors are different size.");
    }
}

template <typename K>
Matrix<K>::Matrix( const Matrix<K> &other)
{
    this->_data = other._data;
    this->_cols = other._cols;
    this->_rows = other._rows;
}

template <typename K>
Matrix<K>::~Matrix()
{

}

/*
GETTERS
*/
template <typename K>
size_t  Matrix<K>::getRows( void ) const
{
    return this->_rows;
}

template <typename K>
size_t  Matrix<K>::getCols( void ) const
{
    return  this->_cols;
}

template <typename K>
std::vector<std::vector<K>> Matrix<K>::getData( void ) const {
    return  this->_data;
}

/*
OPERATORS
*/
template <typename K>
Matrix<K>   &Matrix<K>::operator=( const Matrix<K> &rhs )
{
    this->_data = rhs._data;
    this->_cols = rhs._cols;
    this->_rows = rhs._rows;

    return *this;
}

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Matrix<K> &m)
{
    os << "[";
    for (size_t j = 0; j < m.getRows(); j++)
    {
        os << "[";
        for (size_t i = 0; i < m.getCols(); i++)
        {
            os << m[j][i] << ((i < m.getCols()-1) ? "," : "");
        }
        os << "]" << ((j < m.getRows()-1) ? "," : "");
    }
    
    os << "]";
    return os;
}

template <typename K>
std::vector<K>& Matrix<K>::operator[](size_t i)
{
    return this->_data[i];
}

template <typename K>
const std::vector<K>& Matrix<K>::operator[](size_t i) const
{
    return this->_data[i];
}

template <typename K>
Matrix<K> operator+(const Matrix<K> &lhs, const Matrix<K> &rhs)
{
    if (lhs.getRows() != rhs.getRows() || lhs.getRows() != rhs.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    Matrix<K>   res(lhs);

    for (size_t i = 0; i < res.getRows(); i++)
        for (size_t j = 0; j < res.getCols(); j++)
            res[i][j] += rhs[i][j];

    return  res;
}

template <typename K>
Matrix<K>   operator-(const Matrix<K> &lhs, const Matrix<K> &rhs)
{
    if (lhs.getRows() != rhs.getRows() || lhs.getRows() != rhs.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    Matrix<K>   res(lhs);

    for (size_t i = 0; i < res.getRows(); i++)
        for (size_t j = 0; j < res.getCols(); j++)
            res[i][j] -= rhs[i][j];

    return  res;
}

template <typename K>
Matrix<K>   operator*(const Matrix<K> &lhs, const K a)
{
    Matrix<K>   res(lhs);

    for (size_t i = 0; i < res.getRows(); i++)
        for (size_t j = 0; j < res.getCols(); j++)
            res[i][j] *= a;

    return  res;
}

template <typename K>
Matrix<K>&  Matrix<K>::operator+=( const Matrix<K> &m )
{
    if (this->_rows != m.getRows() || this->_cols != m.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] += m[i][j];
    
    return  *this;
}

template <typename K>
Matrix<K>&  Matrix<K>::operator-=( const Matrix<K> &m )
{
    if (this->_rows != m.getRows() || this->_cols != m.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] -= m[i][j];      
    
    return  *this;
}

template <typename K>
Matrix<K>&  Matrix<K>::operator*=( const K a )
{
    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] *= a;

    return  *this;
}

/*
UTILS
*/

template <typename K>
void    Matrix<K>::print( void ) const
{
    std::cout << "[";
    for (size_t j = 0; j < this->_data.size(); j++)
    {
        std::cout << "[";
        for (size_t i = 0; i < this->_data[j].size(); i++)
        {
            std::cout << this->_data[j][i] << ((i < this->_data[j].size()-1) ? "," : "");
        }
        std::cout << "]" << ((j < this->_data.size()-1) ? "," : "");
    }
    
    std::cout << "]" << std::endl;
}

template <typename K>
bool    Matrix<K>::isSquare( void ) const
{
    return (this->_rows == this->_cols);
}

template <typename K>
Vector<K>   Matrix<K>::reshape_to_vector( void )
{
    std::vector<K>  vv;
    for (size_t i = 0; i < this->_data.size(); i++)
        for (size_t j = 0; j < this->_data[i].size(); j++)
            vv.push_back(this->_data[i][j]);
    Vector<K> v(vv);
    return vv;        
}

/*
OPERATIONS
*/
template <typename K>
void    Matrix<K>::add( Matrix<K>  &m )
{
    if (this->_rows != m.getRows() || this->_cols != m.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] += m[i][j];        
}

template <typename K>
void    Matrix<K>::sub( Matrix<K>  &m )
{
    if (this->_rows != m.getRows() || this->_cols != m.getCols())
        throw std::runtime_error("Could not compute sum of two matrix: Matrix are not the same size.");

    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] -= m[i][j];        
}

template <typename K>
void    Matrix<K>::scl( K a )
{
    for (size_t i = 0; i < this->_rows; i++)
        for (size_t j = 0; j < this->_cols; j++)
            this->_data[i][j] *= a;        
}