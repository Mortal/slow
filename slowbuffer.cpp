#include "slowfile.h"

void buffer::update_block() {
	current_block_size = 0;
	m_index = 0;
}
