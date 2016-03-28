#ifndef FINNIGAN_STRFCT
#define FINNIGAN_STRFCT

#include <string>

////////////////////
// HELP FUNCTIONS //
////////////////////

namespace org { namespace openscience { namespace ms { namespace finnigan {

	template<typename T> std::wstring arr2wstring(const T* p) {

        const T* q = p;
		while (*q != 0)
			++q;

		return std::wstring(p, q);
	}

}}}}

#endif // FINNIGAN_STRFCT
