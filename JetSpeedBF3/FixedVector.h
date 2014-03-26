
template <class T, INT Count, INT PadSize>
class fixed_vector
{
private:
	T* m_firstElement;
	T* m_lastElement;
	T* m_arrayBound;
	//LPVOID m_pad[PadSize];
	T m_data[Count];

public:
	fixed_vector( ) {
		m_firstElement = (T *)m_data;
		m_lastElement = (T *)m_data;
		m_arrayBound = (T *)&m_data[Count];
	}

	void push_back( T *const value ) {
		if( m_lastElement > m_arrayBound ) {

			return;
		}
		*m_lastElement = *value;
		m_lastElement = m_lastElement + 1;
	};

	void clear( ) {
		m_firstElement = m_data;
		m_lastElement = m_data;
	}

	UINT Size() {
		return m_lastElement - m_firstElement; 
	}

	T At(INT nIndex) { 
		return m_firstElement[nIndex];
	}

	T operator [](INT index) { return At(index); }
};