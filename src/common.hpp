#ifndef FINNIGAN_COMMON
#define FINNIGAN_COMMON

#include <string>
#include <boost/any.hpp>

///////////////////
// ELEMENT NAMES //
///////////////////

// FEN = Finnigan Element Name
#define FEN_MAGIC       L"magic"
#define FEN_SIGNATURE   L"signature"
#define FEN_HEADER      L"header"

///////////////
// CONSTANTS //
///////////////

#define FINNIGAN_MAGIC      0xa101
#define FINNIGAN_SIGNATURE  L"Finnigan"

////////////////////
// HELP FUNCTIONS //
////////////////////

namespace org::openscience::ms::finnigan {

	template<typename T> std::wstring arr2wstring(const T* p) {

		const T* q = p;
		while (*q != 0)
			++q;

		return std::wstring(p, q);
	}

}

#endif // FINNIGAN_COMMON
