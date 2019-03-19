#ifndef ANSIOUT_H
#define ANSIOUT_H

#include <windows.h> 

enum AnsiColor {
	ANSI_BLACK = 0x00,
	ANSI_BLUE = 0x01,
	ANSI_GREEN = 0x02,
	ANSI_RED = 0x04,
	ANSI_INTENSITY = 0x08,

	ANSI_CYAN = ANSI_BLUE | ANSI_GREEN,
	ANSI_MAGENTA = ANSI_RED | ANSI_BLUE,
	ANSI_OLIVE = ANSI_RED | ANSI_GREEN,
	ANSI_GRAY = ANSI_BLUE | ANSI_GREEN | ANSI_RED,

	ANSI_DARKGRAY = ANSI_INTENSITY | ANSI_BLACK,
	ANSI_LBLUE = ANSI_INTENSITY | ANSI_BLUE,
	ANSI_LGREEN = ANSI_INTENSITY | ANSI_GREEN,
	ANSI_LRED = ANSI_INTENSITY | ANSI_RED,
	ANSI_LCYAN = ANSI_INTENSITY | ANSI_BLUE | ANSI_GREEN,
	ANSI_LMAGENTA = ANSI_INTENSITY | ANSI_RED | ANSI_BLUE,
	ANSI_YELLOW = ANSI_INTENSITY | ANSI_RED | ANSI_GREEN,
	ANSI_WHITE = ANSI_INTENSITY | ANSI_BLUE | ANSI_GREEN | ANSI_RED
};

class AnsiOut {
public:

	enum ErrorCodes { INVALID_COLOR = 0, GETSTDHANDLE, GETCONSOLESCREENBUFFERINFO, GETCONSOLEMODE, SETCONSOLETEXTATTRIBUTE };

	class AnsiOutException {
	private:
		ErrorCodes error_code;
	public:
		AnsiOutException(ErrorCodes code) : error_code(code) { }
		ErrorCodes get_code() { return error_code; }
	};

	AnsiOut();
	~AnsiOut();

	void textAttr(AnsiColor text, AnsiColor background = ANSI_BLACK);
	void textAttrDefault();

private:
	HANDLE hStdout;
	WORD wOldColorAttrs;
	void textAttr(WORD attr);
};

#endif