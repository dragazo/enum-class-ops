#ifndef DRAGAZO_ENUM_CLASS_OPS
#define DRAGAZO_ENUM_CLASS_OPS

#include <type_traits>

// ------------------ //

// -- core defines -- //

// ------------------ //

// for all of the below: T is an enum class type, OP is a (non-assigning) operation, and A and B are of type T.

// where T is an enum class type, computes binary operation OP on A and B using built-in operations
#define ENUM_CLASS_CALC_BINARY(T, OP, A, B) (static_cast<T>(static_cast<typename std::underlying_type<T>::type>(A) OP static_cast<typename std::underlying_type<T>::type>(B)))
// where T is an enum class type, computes unary operation OP on A using built-in operations
#define ENUM_CLASS_CALC_UNARY(T, OP, A) (static_cast<T>(OP static_cast<typename std::underlying_type<T>::type>(A)))

// defines binary operator OP
#define ENUM_CLASS_DECL_BINARY_NEQ(T, OP) constexpr T  operator OP (T  a, T b) { return ENUM_CLASS_CALC_BINARY(T, OP, a, b); }
// defines binary operator OP=
#define ENUM_CLASS_DECL_BINARY_EQ(T, OP) constexpr          T &operator OP=(         T &a, T b) { a = ENUM_CLASS_CALC_BINARY(T, OP, a, b); return a; } \
                                         constexpr volatile T &operator OP=(volatile T &a, T b) { a = ENUM_CLASS_CALC_BINARY(T, OP, a, b); return a; }

// defines binary operators OP and OP=
#define ENUM_CLASS_DECL_BINARY(T, OP) \
	ENUM_CLASS_DECL_BINARY_NEQ(T, OP) \
	ENUM_CLASS_DECL_BINARY_EQ(T, OP)

// defines unary operator OP
#define ENUM_CLASS_DECL_UNARY(T, OP) constexpr T operator OP(T a) { return ENUM_CLASS_CALC_UNARY(T, OP, a); }

// ---------------------------------------- //

// -- convenience - operator collections -- //

// ---------------------------------------- //

// defines ~, &, &=, |, |=, ^, and ^= ops
#define ENUM_CLASS_DECL_BITWISE(T) \
	ENUM_CLASS_DECL_UNARY(T, ~) \
	ENUM_CLASS_DECL_BINARY(T, &) \
	ENUM_CLASS_DECL_BINARY(T, |) \
	ENUM_CLASS_DECL_BINARY(T, ^)

#endif
