
#ifndef TYPES_HEADER
#define TYPES_HEADER

typedef enum error_type_t {
    ENCODER_OK,
    ERROR_OPENING_FILES,
    ERROR_WRONG_INPUT_FORMAT,
    ERROR_MESSAGE_TOO_LONG,
    ERROR_NO_DECODING_MESSAGE
} error_type_t;

#endif
