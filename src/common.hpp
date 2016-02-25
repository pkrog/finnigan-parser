#ifndef FINNIGAN_COMMON
#define FINNIGAN_COMMON

#include <string>

namespace org::openscience::ms::finnigan {

	template<typename T> std::wstring arr2wstring(const T* p) {

		const T* q = p;
		while (*q != 0)
			++q;

		return std::wstring(p, q);
	}

}

#endif // FINNIGAN_COMMON
