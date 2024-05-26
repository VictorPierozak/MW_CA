#include"cuda_runtime.h"
#include"basic_types.h"

template<typename T>
class buffer_device
{
    public:
    buffer_device(): _buffer_D(nullptr), _size(0) {}
    buffer_device(size_t size);
    ~buffer_device();

    explicit operator T*() {return _buffer_D;}
    T* get() {return _buffer_D;}
    m_int size() {return _size;}
    
    T* copy_to_host();
    void reset(T*=nullptr);

    private:
    T* _buffer_D;
    size_t _size;
};

