#include <cstdlib>
#include <new>
#include <limits>
#include <iostream>
#include <vector>

template<class T>
struct Mallocator
{
    typedef T value_type;

    Mallocator() = default;

    template<class U>
    constexpr Mallocator(const Mallocator <U>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t n)
    {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_array_new_length();

        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
        {
            report(p, n);
            return p;
        }

        throw std::bad_alloc();
    }

    void deallocate(T* p, std::size_t n) noexcept
    {
        report(p, n, 0);
        std::free(p);
    }
private:
    void report(T* p, std::size_t n, bool alloc = true) const
    {
        std::cout << (alloc ? "Alloc: " : "Dealloc: ") << sizeof(T) * n
            << " bytes at " << std::hex << std::showbase
            << reinterpret_cast<void*>(p) << std::dec << '\n';
    }
};

template<class T, class U>
bool operator==(const Mallocator <T>&, const Mallocator <U>&) { return true; }

template<class T, class U>
bool operator!=(const Mallocator <T>&, const Mallocator <U>&) { return false; }


int main()
{
	std::vector<int, Mallocator<int> > v;

	v.resize(10); // Mallocator이 가진 allocate 호출.

}

// cppreference.com 에 접속해 보세요
// 오른쪽 상단에서 "allocator" 검색


// 복습하실때 질문은 메일 주세요

// smkang @ codenuri.co.kr 

// git 은 1주일 뒤에 삭제 됩니다. 
// 필요하신분은 그전에 받아 두세요