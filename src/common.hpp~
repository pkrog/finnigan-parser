#ifndef FINNIGAN_COMMON
#define FINNIGAN_COMMON

#include <string>
#include <boost/any.hpp>

///////////////////
// ELEMENT NAMES //
///////////////////

// FEN = Finnigan Element Name
#define FEN_MAGIC               L"magic"
#define FEN_SIGNATURE           L"signature"
#define FEN_HEADER              L"header"
#define FEN_SEQUENCER_ROW       L"sequencer_row"
#define FEN_INJECTION           L"injection"
#define FEN_VERSION             L"version"
#define FEN_AUDIT_START         L"audit_start"
#define FEN_AUDIT_END           L"audit_end"
#define FEN_TAG                 L"tag"
#define FEN_ROW_NUMBER          L"row_number"
#define FEN_INJECTION_VOLUME    L"injection_volume"
#define FEN_SAMPLE_WEIGHT       L"sample_weight"
#define FEN_SAMPLE_VOLUME       L"sample_volume"
#define FEN_INT_STD_AMOUNT      L"international_standard_amount"
#define FEN_DILUTION_FACTOR     L"dilution_factor"
#define FEN_VIAL                L"vial"
#define FEN_ID                  L"id"
#define FEN_COMMENT             L"comment"
#define FEN_USER_LABEL_1        L"user_label_1"
#define FEN_USER_LABEL_2        L"user_label_2"
#define FEN_USER_LABEL_3        L"user_label_3"
#define FEN_USER_LABEL_4        L"user_label_4"
#define FEN_USER_LABEL_5        L"user_label_5"
#define FEN_INST_METHOD         L"inst_method"
#define FEN_PROC_METHOD         L"proc_method"
#define FEN_FILENAME            L"filename"
#define FEN_INFO_PREAMBLE       L"info_preamble"
#define FEN_PATH                L"path"
#define FEN_METHOD_FILE_PRESENT L"method_file_present"
#define FEN_YEAR                L"year"
#define FEN_MONTH               L"month"
#define FEN_WEEKDAY             L"weekday"
#define FEN_DAY                 L"day"
#define FEN_HOUR                L"hour"
#define FEN_MINUTE              L"minute"
#define FEN_MILLISECOND         L"millisecond"
#define FEN_DATA_ADRESS         L"data_address"
#define FEN_RUN_HEADER_ADDR     L"run_header_address"
#define FEN_PADDING             L"padding"
#define FEN_N_CONTROLLERS       L"n_controllers"
#define FEN_N_CONTROLLERS2      L"n_controllers_2"

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
