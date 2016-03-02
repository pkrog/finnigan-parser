#ifndef FINNIGAN_COMMON
#define FINNIGAN_COMMON

#include <string>
#include <boost/any.hpp>

#define MAGIC 0xa101
#define SIGNATURE L"Finnigan"

namespace org::openscience::ms::finnigan {

	template<typename T> std::wstring arr2wstring(const T* p) {

		const T* q = p;
		while (*q != 0)
			++q;

		return std::wstring(p, q);
	}

}

#endif // FINNIGAN_COMMON
