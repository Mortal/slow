#include "slowfile.h"
int main(int argc, char ** argv) {
	buffer b;
	for (size_t i = 0; i < 1024*1024*1024/sizeof(buffer::item_type); ++i) {
		b.write(i);
	}
}
