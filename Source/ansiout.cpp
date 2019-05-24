#include "ansiout.h"


AnsiOut::AnsiOut() {

	// Get handle to STDIN.
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdout == INVALID_HANDLE_VALUE) {
		throw AnsiOutException(GETSTDHANDLE);
	}

	// Save the current text colors. 
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	if (!GetConsoleScreenBufferInfo(hStdout, &csbiInfo)) {
		throw AnsiOutException(GETCONSOLESCREENBUFFERINFO);
	}

	wOldColorAttrs = csbiInfo.wAttributes;
}

AnsiOut::~AnsiOut() {
	textAttrDefault();
}

void AnsiOut::textAttr(WORD attr) {

	// Set the text attributes to draw red text on black background. 
	if (!SetConsoleTextAttribute(hStdout, attr)) {
		throw AnsiOutException(SETCONSOLETEXTATTRIBUTE);
	}
}

void AnsiOut::textAttr(AnsiColor text, AnsiColor background) {
	if (text > 0x0f || background > 0x0f) {
		throw AnsiOutException(INVALID_COLOR);
	}
	textAttr(static_cast<WORD>(background << 4 | text));
}

void AnsiOut::textAttrDefault() {

	// Restore the original text colors. 
	if (!SetConsoleTextAttribute(hStdout, wOldColorAttrs)) {
		throw AnsiOutException(SETCONSOLETEXTATTRIBUTE);
	}
}