#include <iostream>
using namespace std;

class EColor {
public:
	enum Enum {
		RED,
		GREEN,
		BLUE,
		YELLOW,
		ORANGE,
	};

	static const char* AsStr(Enum _eEnum) {
		switch (_eEnum) {
			case RED: return "RED";
			case GREEN: return "GREEN";
			case BLUE: return "BLUE";
			case YELLOW: return "YELLOW";
			case ORANGE: return "ORANGE";
			default: break;
		}
	}

	static Enum AsEnum(const char* _sEnum) {
		if (strcmp(_sEnum, "RED") == 0) return RED;
		if (strcmp(_sEnum, "GREEN") == 0) return GREEN;
		if (strcmp(_sEnum, "BLUE") == 0) return BLUE;
		if (strcmp(_sEnum, "YELLOW") == 0) return YELLOW;
		if (strcmp(_sEnum, "ORANGE") == 0) return ORANGE;
	}
};

#define EXPAND(x) x
#define GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, NAME) NAME
#define FE_1(_WHAT, X) _WHAT(X)
#define FE_2(_WHAT, X, ...) EXPAND(_WHAT(X)FE_1(_WHAT, __VA_ARGS__))
#define FE_3(_WHAT, X, ...) EXPAND(_WHAT(X)FE_2(_WHAT, __VA_ARGS__))
#define FE_4(_WHAT, X, ...) EXPAND(_WHAT(X)FE_3(_WHAT, __VA_ARGS__))
#define FE_5(_WHAT, X, ...) EXPAND(_WHAT(X)FE_4(_WHAT, __VA_ARGS__))
#define FE_6(_WHAT, X, ...) EXPAND(_WHAT(X)FE_5(_WHAT, __VA_ARGS__))
#define FE_7(_WHAT, X, ...) EXPAND(_WHAT(X)FE_5(_WHAT, __VA_ARGS__))
#define MACRO_FOR_EACH_ARGUMENT(_ACTION, ...) \
EXPAND(GET_MACRO(__VA_ARGS__, FE_7, FE_6, FE_5, FE_4, FE_3, FE_2, FE_1)(_ACTION, __VA_ARGS__))

#define DECLARE_ENUM_VALUE(_ENUM) _ENUM,

#define DECLARE_AS_STRING(_PARAM) \
	case _PARAM: \
		return #_PARAM;

#define DECLARE_AS_ENUM(_PARAM) \
		if (strcmp(_sEnum, #_PARAM) == 0) \
		{ \
			return _PARAM; \
		}

#define DECLARE_ENUM_CLASS(_NAME, ...) \
class _NAME \
{ \
public: \
	enum Enum \
	{ \
		MACRO_FOR_EACH_ARGUMENT(DECLARE_ENUM_VALUE, __VA_ARGS__) \
	}; \
	static const char* AsStr(Enum _eEnum) \
	{ \
		switch (_eEnum) \
		{ \
		MACRO_FOR_EACH_ARGUMENT(DECLARE_AS_STRING, __VA_ARGS__) \
		default: \
			break; \
		} \
	} \
	static Enum AsEnum(const char* _sEnum) \
	{ \
		MACRO_FOR_EACH_ARGUMENT(DECLARE_AS_ENUM, __VA_ARGS__) \
	} \
};

DECLARE_ENUM_CLASS(EMacroColor, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, DUMMY)

int main()
{
	printf("%s\n", EColor::AsStr(EColor::RED));
	printf("%s\n", EColor::AsStr(EColor::GREEN));
	EColor::Enum eColor = EColor::AsEnum("BLUE");
	printf("%s\n", EColor::AsStr(eColor));
	printf("\n");

	printf("%s\n", EMacroColor::AsStr(EMacroColor::YELLOW));
	printf("%s\n", EMacroColor::AsStr(EMacroColor::ORANGE));
	EMacroColor::Enum eMacroColor = EMacroColor::AsEnum("PURPLE");
	printf("%s\n", EMacroColor::AsStr(eMacroColor));
}