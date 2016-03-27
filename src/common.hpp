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
#define FEN_SECOND              L"second"
#define FEN_MILLISECOND         L"millisecond"
#define FEN_DATA_ADRESS         L"data_address"
#define FEN_RUN_HEADER_ADR      L"run_header_address"
#define FEN_RUN_HEADER          L"run_header"
#define FEN_PADDING             L"padding"
#define FEN_N_CONTROLLERS       L"n_controllers"
#define FEN_N_CONTROLLERS2      L"n_controllers_2"
#define FEN_SAMPLE_INFO         L"sample_info"
#define FEN_FILENAME_1          L"filename_1"
#define FEN_FILENAME_2          L"filename_2"
#define FEN_FILENAME_3          L"filename_3"
#define FEN_FILENAME_4          L"filename_4"
#define FEN_FILENAME_5          L"filename_5"
#define FEN_FILENAME_6          L"filename_6"
#define FEN_FILENAME_7          L"filename_7"
#define FEN_FILENAME_8          L"filename_8"
#define FEN_FILENAME_9          L"filename_9"
#define FEN_FILENAME_10         L"filename_10"
#define FEN_FILENAME_11         L"filename_11"
#define FEN_FILENAME_12         L"filename_12"
#define FEN_FILENAME_13         L"filename_13"
#define FEN_NSEGS               L"nsegs"
#define FEN_SCAN_TRAILER_ADR    L"scan_trailer_address"
#define FEN_SCAN_PARAMS_ADR     L"scan_params_address"
#define FEN_OWN_ADRESS          L"own_adress"
#define FEN_SCAN_INDEX_ADR      L"scan_index_adr"
#define FEN_DATA_ADR            L"data_adr"
#define FEN_INST_LOG_ADR        L"inst_log_adr"
#define FEN_ERROR_LOG_ADR       L"error_log_adr"
#define FEN_DEVICE              L"device"
#define FEN_MODEL               L"model"
#define FEN_SN                  L"sn"
#define FEN_SWVER               L"swver"
#define FEN_TAG_1               L"tag1"
#define FEN_TAG_2               L"tag2"
#define FEN_TAG_3               L"tag3"
#define FEN_TAG_4               L"tag4"
///////////////
// CONSTANTS //
///////////////

#define FINNIGAN_MAGIC      0xa101
#define FINNIGAN_SIGNATURE  L"Finnigan"

////////////////////
// HELP FUNCTIONS //
////////////////////

namespace org{ namespace openscience { namespace ms{ namespace finnigan {

	template<typename T> std::wstring arr2wstring(const T* p) {

        const T* q = p;
		while (*q != 0)
			++q;

		return std::wstring(p, q);
	}

}}}}

#endif // FINNIGAN_COMMON
