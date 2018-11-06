NAME = PBLoader
SRC = ./src
TMP = ./temp
WIN_BD = $(NAME)_Windows
WIN_TMP = temp
CR = g++
CRFLAGS = -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wno-write-strings -std=c++14
LRFLAGS = 
LRLIBS = -lSDL2
ATTR = 

ifeq ($(BUILD), release)
	# Release build - optimization and no debugging symbols
	CRFLAGS += -O3 -s -DNDEBUG
else
	# Debug build - no optimization and debugging symbols
	CRFLAGS += -O0 -g
endif

ifeq ($(MSYSTEM), MINGW32)
	BD = $(NAME)_Windows
	DEL = rm -rf "$(BD)/$(NAME)" "$(TMP)/*"
	TIME = `date +%T`
	NL = echo ""
	TEST = cd "$(WIN_BD)" && ./$(NAME) $(ATTR)
	EXT = dll
else ifeq ($(OS), Windows_NT)
	BD = $(NAME)_Windows
	DEL = del /f /q "$(WIN_TMP)/*" >nul 2>nul && del /f /q "$(WIN_BD)/$(NAME).exe" >nul 2>nul
	TIME = %date% %time:~0,8%
	NL = echo.
	TEST = cd "$(WIN_BD)" & start "$(NAME)" cmd /c "$(NAME).exe $(ATTR) & echo. & pause"
	CRFLAGS += -IC:/MinGW/include
	LRFLAGS += -LC:/MinGW/lib
	EXT = dll
else
	BD = $(NAME)_Linux
	DEL = rm -f "$(BD)/$(NAME)" "$(TMP)/*"
	TIME = `date +%T`
	NL = echo ""
	TEST = cd "$(BD)" && cp -f "$(NAME)" "/tmp/$(NAME)" && chmod +x "/tmp/$(NAME)" && xfce4-terminal -T "$(NAME)" -e "/tmp/$(NAME) $(ATTR)" && rm -f "/tmp/$(NAME)"
	EXT = so
endif

all: info clean compile

compile: main
	$(CR) $(LRFLAGS) -shared "$(TMP)/main.o" $(LRLIBS) -o "$(BD)/$(NAME).$(EXT)"

launcher:
	$(CR) $(CRFLAGS) -mwindows "$(SRC)/launcher.cpp" -o "$(BD)/Launcher"

clean:
	-@$(DEL)

info:
	@echo =====================================
	@echo   Compile Time: $(TIME)
	@echo =====================================
	@$(NL)

run test:
	@$(TEST)

main:
	$(CR) $(CRFLAGS) "$(SRC)/main.cpp" -c -o "$(TMP)/main.o"
