#ifndef MATRIX_HPP
# define MATRIX_HPP

# include <vector>
# include <iostream>
# include <Vector.hpp>

template <typename K>
class Matrix;

template <typename K>
std::ostream&   operator<<(std::ostream& os, const Matrix<K> &m);

template <typename K>
class Matrix
{
private:
    std::vector<std::vector<K>> _data;
public:
    Matrix(void) {};
    Matrix( const std::vector<std::vector<K>> data) { _data = data; };

    ~Matrix() {};

    size_t  getRows( void ) const
    {
        return this->_data.size();
    }

    size_t  getCols( void ) const
    {
        if (this->_data.size() == 0)
            return 0;
        return this->_data.back().size();
    }

    void    print( void ) const
    {
        std::cout << "[";
        for (size_t j = 0; j < this->_data.size(); j++)
        {
            std::cout << "[";
            for (size_t i = 0; i < _data[j].size(); i++)
            {
                std::cout << _data[j][i] << ((i < _data[j].size()-1) ? "," : "");
            }
            std::cout << "]" << ((j < _data.size()-1) ? "," : "");
        }
        
        std::cout << "]" << std::endl;
    }

    friend  std::ostream&   operator<< <>(std::ostream& os, const Matrix<K> &m);

    std::vector<K>& operator[](size_t i) {return this->_data[i];};
    const std::vector<K>& operator[](size_t i) const {return this->_data[i];};

    Vector<K>   reshape_to_vector( void )
    {
        std::vector<K>  vv;
        for (size_t i = 0; i < this->_data.size(); i++)
            for (size_t j = 0; j < this->_data[i].size(); j++)
                vv.push_back(this->_data[i][j]);
        Vector<K> v(vv);
        return vv;        
    }
};

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


#endif