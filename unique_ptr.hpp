#ifndef OPENLIB_UNIQUE_PTR_HPP
#define OPENLIB_UNIQUE_PTR_HPP
namespace openlib {
    template<class T>
    class unique_ptr {
        T* m_ptr;
	 
        public:
            unique_ptr(const unique_ptr&) = delete;
            unique_ptr & operator=(const unique_ptr&) = delete;
            
            // No implicit conversions allowed. Need to call with
            // exact type along with constructor
            explicit unique_ptr(T *ptr = nullptr):m_ptr(ptr) {
            }
	 
            ~unique_ptr() {
                reset();
            }
    
            unique_ptr(unique_ptr&& other) {
              reset();
              m_ptr = other.release();
            }

            unique_ptr& operator=(unique_ptr&& other) {
              reset();
              m_ptr = other.release();
              return *this;
            }

            void swap(unique_ptr& other) {
               std::swap(*this,other);
            }
    
            T& operator *() { return (*m_ptr);}
            T* operator ->() { return m_ptr;}
            T* get() { return m_ptr;}
	    
            void reset(T *ptr = nullptr) {
                if(m_ptr) {
                    delete m_ptr;
                    m_ptr = nullptr;
                }
 
                if(ptr) {
                    m_ptr = ptr;
                }
            }
	 
            T* release() {
                if(m_ptr) {
                    T* tmp = m_ptr;
                    m_ptr = nullptr;
                    return tmp;
                }
            }
    };
}
#endif //OPENLIB_UNIQUE_PTR_HPP
