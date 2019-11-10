namespace openlib {
	template<class T>
	class unique_ptr {
		T* m_ptr;
	 
		public:
		unique_ptr(T *ptr = nullptr):m_ptr(ptr) {
		}
	 
		~unique_ptr() {
			reset();
		}
	 
		T& operator *() { return (*m_ptr);}
		T* operator ->() { return m_ptr;}
	 
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

int main() {
	open::unique_ptr<int> ptr(new int());
	ptr.reset();
	return 0;
}