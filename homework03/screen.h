//화면 전환용
int clearBuffer(char* screenBuf, int width, int height);
int writeStringToBuffer(char* screenBuf ,const char* string, int x, int y);
int setGameOverToScreenBuffer(char* screenBuf, int width, int height);
int setMainScreenToScreenBuffer(char* screenBuf, int width, int height);
int setHowToPlayToScreenBuffer(char* screenBuf, int width, int height);
int setGamePlayScreenToScreenBuffer(char* screenBuf, int width, int height);