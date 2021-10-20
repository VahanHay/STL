#ifndef _BITSET_
#define _BITSET_
#include <iostream>
#include <string>
#include <exception>



#ifndef _BITSET_
#define _BITSET_
#include <iostream>
#include <string>
#include <exception>
#include <cmath>
template <std::size_t N>
class BitSet
{
public:
	//Constructor
	constexpr BitSet();
	~BitSet();
	constexpr BitSet(unsigned long long digit) ;
	BitSet(std::string str);	
	bool operator==(const BitSet<N>& rhs) const;
	bool operator!=(const BitSet<N>& rhs) const;
	//Element access
	constexpr bool operator[](std::size_t pos) const;
	bool test(std::size_t pos) const;
	//Capacity
	std::size_t size() const;
	
	//Modifiers
	BitSet<N>& set() ;
	BitSet<N>& set(std::size_t pos, bool value = true);
	BitSet<N>& reset();
	BitSet<N>& reset(std::size_t pos);
	BitSet<N>& flip();
	BitSet<N>& flip(std::size_t pos);
	BitSet<N>& operator&=(const BitSet<N>& other);
	BitSet<N>& operator|=(const BitSet<N>& other);
	BitSet<N>& operator^=(const BitSet<N>& other);
	BitSet<N>& operator~();
	//Non member functions
	template <std::size_t N>
	friend BitSet<N> operator&(const BitSet<N>& lhs, const BitSet<N>& rhs);
	template <std::size_t N>
	friend BitSet<N> operator|(const BitSet<N>& lhs, const BitSet<N>& rhs);
	template <std::size_t N>
	friend BitSet<N> operator^(const BitSet<N>& lhs, const BitSet<N>& rhs);
	template <std::size_t N>
	friend std::ostream& operator<<(std::ostream& mycout, const BitSet<N>& bit);
private:
	int get_size();
	int get_str_index(int size);
	
	const unsigned int m_size = get_size();
	unsigned long long*  m_table{ new unsigned long long[m_size] {0} };
	int m_index = N / (sizeof(long long) * 8);
	int m_posistion = N % (sizeof(long long) * 8);
	
};
template <std::size_t N>
constexpr BitSet<N>::BitSet(){}
template <std::size_t N>
BitSet<N>::~BitSet()
{
	delete[] m_table;
}
template<std::size_t N>
BitSet<N>::BitSet(std::string str)
{
	int size = str.size();
	int index = get_str_index(size);
	int position = size % (sizeof(long long) * 8);
	int j = 0;
	int k = size;
	if (index == 1)
	{
		for (int i = size-1,k=0; i >=0; --i, ++k)
		{	if(str[i]-48)
			m_table[0] += pow(str[i] - 47, k);
		}
		
	}
	else if (size % (sizeof(long long) * 8) == 0)
	{
		for (int i = 0; i <m_size; ++i)
		{
			for (int j = (sizeof(long long) * 8)-1; j>=0; --j)
			{
				if (str[j] - 48)
				m_table[i] += pow(str[j] - 47, j);
			}
		}
	}
	else
	{
		for (int i = 0; i < m_size; ++i)
		{
			for (int j = (sizeof(long long) * 8) - 1; j >= 0; --j)
			{
				if (str[j] - 48)
				m_table[i] += pow(str[j] - 47, j);
			}
		}
		for (int i = position-1; i >=0 ; --i)
		{
			if (str[i] - 48)
			m_table[m_size-1] += pow(str[i] - 47, i);
		}
	}
}
template<std::size_t N>
bool BitSet<N>::operator==(const BitSet<N>& rhs) const
{
	for (int i = 0; i < m_size; ++i)
	{
		if (m_table[i] != rhs.m_table[i])
			return false;
	}
	return true;
}
template<std::size_t N>
bool BitSet<N>::operator!=(const BitSet<N>& rhs) const
{
	int count = 0;
	for (int i = 0; i < m_size; ++i)
	{
		if (m_table[i] != rhs.m_table[i])
			++count;
	}
	if (count)
	{
		return true;
	}
	return false;
}
template<std::size_t N>
constexpr bool BitSet<N>::operator[](std::size_t pos) const
{
	int index = pos / (sizeof(long long) * 8);
	int p = pos % (sizeof(long long) * 8);
	return m_table[index] & (1 << p);
}
template<std::size_t N>
bool BitSet<N>::test(std::size_t pos) const
{
	if (pos > N)
	{
		std::cout << "Out_of_range";
	}
	int index = pos / (sizeof(long long) * 8);
	int p = pos % (sizeof(long long) * 8);
	return m_table[index] & (1 << p);
}
template <std::size_t N>
BitSet<N> operator&(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
	int k = 1;
	if (lhs.m_size) {
		return lhs.m_table[lhs.m_size-k] & rhs.m_table[rhs.m_size-k];
		++k;
		operator&(lhs, rhs);
	}
}
template <std::size_t N>
BitSet<N> operator|(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
	
	int k = 1;
	if (lhs.m_size) {
		return lhs.m_table[lhs.m_size - k] | rhs.m_table[rhs.m_size - k];
		++k;
		operator|(lhs, rhs);
	}
	
}
template <std::size_t N>
BitSet<N> operator^(const BitSet<N>& lhs, const BitSet<N>& rhs)
{
	
	int k = 1;
	if (lhs.m_size) {
		return lhs.m_table[lhs.m_size - k] ^ rhs.m_table[rhs.m_size - k];
		++k;
		operator^(lhs, rhs);
	}
	
}
template <std::size_t N>
constexpr BitSet<N>::BitSet(unsigned long long digit)
{
	if (m_size == 1)
	{
		m_table = new unsigned long long[m_size];
		*m_table = digit;
	}
	else
	{
		m_table = new unsigned long long[m_size];
		*m_table = digit;
		for (int i = 1; i < m_size; ++i)
		{
			m_table[i] = 0;
		}
	}
}
template<std::size_t N>
std::size_t BitSet<N>::size() const
{
	return N;
}
template <std::size_t N>
BitSet<N>& BitSet<N>::set()
{
	for (std::size_t i = 0; i < m_size; ++i)
	{
	   m_table[i] |= ~(0<<31);
	}
	return *this;
}
template <typename size_t N>
BitSet<N>& BitSet<N>::set(size_t pos, bool value)
{
	 if (pos <= N)
	 {
		 int p = pos % (sizeof(long long) * 8);
		 if (value)
		 {
			if (pos / sizeof(long long) * 8 > 0)
			{
				int id = m_size - N / pos;
				m_table[id] |= (1 << p);
			}
			else
			{
				m_table[0] |= (1 << p);
			}
		 }
		 else
		 {
			 if (pos / sizeof(long long) * 8 > 0)
			 {
				 int id = m_size - N / pos;
				 if (m_table[id] & (1 << p))
				 {
					 m_table[id] = ~m_table[id];
					 m_table[id] |= (1 << p);
					 m_table[id] = ~m_table[id];
				 }
			 }
			 else
			 {
				 if (m_table[0] & (1 << p))
				 {
					 m_table[0] = ~m_table[0];
					 m_table[0] |= (1 << p);
					 m_table[0] = ~m_table[0];
				 }
			 }
		 }
	 }
	 else {
		 std::cout << "Out_of_Range" << std::endl;
		 exit(1);
	 }
	 return *this;
}
template <std::size_t N>
BitSet<N>& BitSet<N>::reset()
{
	for (std::size_t i = 0; i < m_size; ++i)
	{
		m_table[i] &= (0 << 31);
	}
	return *this;
}
template <std::size_t N>
BitSet<N>& BitSet<N>::reset(std::size_t pos)
{
	if (pos <= N)
	{
		int p = pos % (sizeof(long long) * 8);
		if (pos / sizeof(long long) * 8 > 0)
		{
			int id = m_size - N / pos;
			unsigned int x = -1;
			x = x - (1 << p);
			m_table[id] &= x;
		}
		else
		{
			unsigned int x = -1;
			x = x - (1 << p);
			m_table[0] &= x;
		}
	}
	else
	{
		std::cout << "Out_of_Range" << std::endl;
		exit(1);
	}
	return *this;
}
template <std::size_t N>
BitSet<N>& BitSet<N>::flip()
{
	for (std::size_t i = 0; i < m_size; ++i)
	{
		m_table[i] = ~m_table[i];
	}
	return *this;
}
template <std::size_t N>
BitSet<N>& BitSet<N>::flip(std::size_t pos)
{
	int index = pos / (sizeof(long long) * 8);
	int position = pos % (sizeof(long long) * 8);
	m_table[index] ^= (1 << position);
	return *this;
}
template<std::size_t N>
BitSet<N>& BitSet<N>::operator&=(const BitSet<N>& other)
{
	for (int i = m_size; i >= 0; --i)
		m_table[i] &= other.m_table[i];
	return *this;
}
template<std::size_t N>
BitSet<N>& BitSet<N>::operator|=(const BitSet<N>& other)
{
	for (int i = 0; i < m_size; ++i)
		m_table[i] |= other.m_table[i];
	return *this;
}
template<std::size_t N>
BitSet<N>& BitSet<N>::operator^=(const BitSet<N>& other)
{
	for (int i = 0; i < m_size; ++i)
		m_table[i] ^= other.m_table[i];
	return *this;
}
template<std::size_t N>
BitSet<N>& BitSet<N>::operator~()
{
	
	for (size_t i = 0; i < m_size; ++i)
	{
		unsigned long long x = -1;
		x -= m_table[i];
		m_table[i] = x;
	}
	return *this;
}
template <std::size_t N>
int BitSet<N>::get_size()
{
	if (N % (sizeof(long long)*8) == 0)
	{
		return N / (sizeof(long long)*8);
	}
	else {
		return N / (sizeof(long long)*8) + 1;
	}
}
template<std::size_t N>
int BitSet<N>::get_str_index(int size)
{
	if (size % (sizeof(long long) * 8) == 0)
	{
		return size / (sizeof(long long) * 8);
	}
	else {
		return size / (sizeof(long long) * 8) + 1;
	}
	
}
template <std::size_t N>
std::ostream& operator<<(std::ostream& mycout, const BitSet<N>& bit)
{
	if (bit.m_size == 1)
	{
		for (int i = N-1 ; i>=0; --i)
		{
			bool bin_num = (bit.m_table[0] & (1LL << i));
			mycout << bin_num;
		}
		return mycout;
	}
	else
	{
		for (int i = bit.m_size - 1; i >= 0; --i)
		{
			if (N % (sizeof(long long) * 8) == 0)
			{
				for (int j = (N - 1) % (sizeof(long long)*8); j >= 0; --j)
				{
					bool bin_num = (bit.m_table[i] & (1LL << j));
					mycout << bin_num;
				}
			}
			else
			{
				for (int j = N  % (sizeof(long long)*8); j >= 0; --j)
				{
					bool bin_num = (bit.m_table[bit.m_size-1] & (1LL << j));
					mycout << bin_num;
					
				}
				for (int k = bit.m_size - 2; k >= 0; --k)
				{
					for (int j = sizeof(long long) * 8 - 1; j >= 0; --j)
					{
						bool bin_num = (bit.m_table[k] & (1LL << j));
						mycout << bin_num;
					}
					std::cout << std::endl;
				}
				return mycout;
			}	
		}
		
	}
	return mycout;
}

#endif //_BITSET_
