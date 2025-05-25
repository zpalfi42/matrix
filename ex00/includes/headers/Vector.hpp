#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <vector>
# include <iostream>
# include <Matrix.hpp>

template <typename K>
class Vector;

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Vector<K>& v);

template <typename K>
class Vector
{
private:
    std::vector<K> _data;
public:
    Vector( void ){};
    Vector( const std::vector<K> &data ) {_data = data;};
    Vector( const Vector<K> &other ) { _data = other._data;};

    ~Vector(){};

    size_t  size( void ) const
    {
        return _data.size();
    };

    void    print( void ) const
    {
        std::cout << "[";
        for (size_t i = 0; i < _data.size(); i++)
        {
            std::cout << _data[i] << ((i < _data.size()-1) ? "," : "");
        }
        std::cout << "]" << std::endl;
    }

    friend std::ostream&    operator<<  <>(std::ostream& os, const Vector<K>& v);

    K& operator[](size_t i) {return this->_data[i];};
    const K& operator[](size_t i) const {return this->_data[i];};

    Matrix<K>   reshape_to_matrix( size_t rows, size_t cols )
    {
        if (this->size() != rows*cols)
        {
            std::cerr << "Conversion not possible" << std::endl;
            return NULL;
        }

        std::vector<std::vector<K>>  mm;
        for (size_t i = 0; i < rows; i++)
        {
            std::vector<K>  v;
            for (size_t  j = 0; j < cols; j++)
                v.push_back(this->_data[j+cols*i]);    
            mm.push_back(v);
            v.clear();        
        }
        return(mm);
    };
};

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

#endif