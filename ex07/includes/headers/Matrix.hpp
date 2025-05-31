#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <iostream>
# include <cmath>

template <typename K>
class Vector;

template <typename K>
class Matrix;

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Matrix<K> &m);

template <typename K>
Matrix<K> operator+(const Matrix<K>& lhs, const Matrix<K>& rhs);

template <typename K>
Matrix<K> operator-(const Matrix<K>& lhs, const Matrix<K>& rhs);

template <typename K>
Matrix<K> operator*(const Matrix<K>& lhs, const K a);

template <typename K>
class Matrix
{
private:
    std::vector<std::vector<K>> _data;
    size_t                      _rows;
    size_t                      _cols;
public:
    Matrix( void );
    Matrix( const std::vector<std::vector<K>> &data );
    Matrix( const Matrix<K> &other );

    ~Matrix( void );

    /*
    GETTERS
    */
    size_t                      getRows( void ) const;
    size_t                      getCols( void ) const;
    std::vector<std::vector<K>> getData( void ) const;


    /*
    OPERATORS
    */
    Matrix<K>   &operator=( const Matrix<K> &rhs );

    friend  std::ostream&    operator<< <>( std::ostream& os, const Matrix<K> &m );

    std::vector<K>&          operator[]( size_t i );
    const std::vector<K>&    operator[]( size_t i ) const;

    friend Matrix<K>         operator+ <>( const Matrix<K> &lhs, const Matrix<K> &rhs );
    friend Matrix<K>         operator- <>( const Matrix<K> &lhs, const Matrix<K> &rhs );
    friend Matrix<K>         operator* <>( const Matrix<K> &lhs, const K a );

    Matrix<K>&         operator+=( const Matrix<K> &m );
    Matrix<K>&         operator-=( const Matrix<K> &m );
    Matrix<K>&         operator*=( const K a );

    /*
    UTILS
    */
    void         print( void ) const;
    bool         isSquare( void ) const;
    Vector<K>    reshape_to_vector( void );

    /*
    OPERATIONS
    */
    void    add( Matrix<K>  &m );
    void    sub( Matrix<K>  &m );
    void    scl( K a );

    Vector<K>   mul_vec( const  Vector<K>   &vec ) const;
    Matrix<K>   mul_mat( const  Matrix<K>   &mat ) const;
};

# include <Matrix.ipp>

#endif