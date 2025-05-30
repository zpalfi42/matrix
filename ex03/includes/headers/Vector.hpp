#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <iostream>
# include <cmath>

template <typename K>
class Matrix;

template <typename K>
class Vector;

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Vector<K>& v);

template <typename K>
Vector<K> operator+(const Vector<K>& lhs, const Vector<K>& rhs);

template <typename K>
Vector<K> operator-(const Vector<K>& lhs, const Vector<K>& rhs);

template <typename K>
Vector<K> operator*(const Vector<K>& lhs, const K a);

template <typename K>
class Vector
{
private:
    std::vector<K> _data;
public:
    Vector( void );
    Vector( const std::vector<K> &data );
    Vector( const Vector<K> &other );

    ~Vector( void );

    /*
    GETTERS
    */
    std::vector<K>  getData( void ) const;

    /*
    OPERATORS
    */
    Vector<K>   &operator=(Vector<K> const &rhs);
    friend std::ostream&    operator<< <>( std::ostream& os, const Vector<K>& v );
    
    K&          operator[]( size_t i );
    const K&    operator[]( size_t i ) const;

    friend Vector<K>   operator+ <>( const Vector<K> &lhs, const Vector<K> &rhs );
    friend Vector<K>   operator- <>( const Vector<K> &lhs, const Vector<K> &rhs );
    friend Vector<K>   operator* <>( const Vector<K> &lhs, const K a );

    Vector<K>&         operator+=( const Vector<K> &v );
    Vector<K>&         operator-=( const Vector<K> &v );
    Vector<K>&         operator*=( const K a );
    
    /*
    UTILS
    */
    size_t      size( void ) const;   
    void        print( void ) const;
    Matrix<K>   reshape_to_matrix( size_t rows, size_t cols );

    /*
    OPERATION
    */
    void    add( const Vector<K>  &v );
    void    sub( const Vector<K>  &v );
    void    scl( const K  a );
    K       dot( const Vector<K> &v );
};

template <typename K>
Vector<K>   linear_combination(const std::vector<Vector<K>>   &vecs, const std::vector<K>    &coefs);

# include <Vector.ipp>


#endif