#include <cstdlib>
#include <algorithm>
class buffer {
public:
	typedef size_t item_type;
	const static size_t block_items = 2*1024*1024/sizeof(item_type);
	size_t current_block_size;
	size_t m_index;

	inline buffer(): current_block_size(0), m_index(0) {
	}

	static inline int64_t max(int64_t x, int64_t y) {
		return x-(((x-y)>>63)&(x-y));
	}

	void update_block();

	inline void write(const item_type & item) {
		if (m_index >= block_items) update_block();
		buf[m_index++] = item;

		//write_update():
#ifdef STDMAX
		current_block_size = std::max(current_block_size, m_index);
#else
		current_block_size = max(current_block_size, m_index);
#endif
	}

private:
	item_type buf[block_items];
};
