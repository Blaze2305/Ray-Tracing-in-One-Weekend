SOURCE_DIR = src
SOURCES = $(wildcard *.cpp) $(wildcard src/*/*.cpp)
BUILD_DIR = bin
GXX = g++ -std=c++17


default: build
.PHONY: default

ifeq ($(OS),Windows_NT) 
DETECTED_OS := Windows
else
DETECTED_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(DETECTED_OS),Windows)
BUILD_FILE = app.exe
endif

ifeq ($(DETECTED_OS),Linux)
BUILD_FILE = app.out
endif


build: |buildDir
	${GXX} ${SOURCES} -o ${BUILD_DIR}/${BUILD_FILE}
.PHONY: build

clean:
	rm -rf ${BUILD_DIR} 
	rm -rf output.ppm
	rm -rf output.png
.PHONY: clean

test: |build
	${BUILD_DIR}/${BUILD_FILE} && magick output.ppm output.png



buildDir:
	test -d ${BUILD_DIR} || mkdir ${BUILD_DIR}
.PHONY: buildDir

