CC=gcc
PROJECT=3dviewer
SOURCES=./parser.c ./matrix.c
HEADERS=./parser.h
OBJECTS=parser.o matrix.o
OUTTESTSNAME=tests
REPORTNAME=Report
BUILDNAME=Build
TESTFILE=tests.c
OUTDIRPATH=Build
ARCHIVENAME=3DViewerArchive
GCOV=-fprofile-arcs -ftest-coverage
CFLAGS=-Wall -Werror -Wextra -std=c11

OS=$(shell uname -s)
ifeq ($(OS),Darwin)
	CHECKFLAGS=-lcheck
	OUTFILENAME=3DViewer.app
else
	CHECKFLAGS=-lcheck -pthread -lrt -lm -lsubunit -ldl
	OUTFILENAME=3DViewer
endif

all: install gcov_report

install:
	@mkdir ./$(OUTDIRPATH)
	@cd ./$(OUTDIRPATH) && qmake ../3DViewer.pro
	@cd ./$(OUTDIRPATH) && make qmake_all
	@cd ./$(OUTDIRPATH) && make -j4

uninstall:
	@rm -rf ./$(OUTDIRPATH)

dist:
	@tar -czf $(ARCHIVENAME).tar.gz ./$(TESTFILE) ./Makefile ./3DViewer.pro ./*.cc ./*.c ./*.h ./$(TESTFILE)

tests:
	@$(CC) -c $(SOURCES) $(TESTFILE)
	@$(CC) $(OBJECTS) $(TESTFILE:.c=.o) $(CHECKFLAGS) -o $(OUTTESTSNAME)
	@./$(OUTTESTSNAME)

gcov_report:
	@$(CC) $(GCOV) $(SOURCES) $(TESTFILE) $(CHECKFLAGS) -o GcovReport
	@./GcovReport
	@lcov -t "GcovReport" -o GcovReport.info -c -d . --no-external
	@genhtml -o $(REPORTNAME) GcovReport.info

clean:
	@rm -rf ./*.o ./*.a ./a.out ./$(REPORTNAME) ./GcovReport.info ./$(OUTTESTSNAME) ./a.out.dSYM
	@rm -rf ./*.gcno ./*.gcda ./GcovReport ./GcovReport.info ../build-3DViewer-* ./$(BUILDNAME)
	@rm -rf ./$(OUTFILENAME) ./$(ARCHIVENAME).tar.gz
	@rm -rf ./$(BUILDNAME) ./$(OUTDIRPATH) ./$(ARCHIVENAME) ./.qtc_clangd ./*.gch ./*.pro.user ./.vscode

clang:
	clang-format -i ./*.c ./*.cc ./*.h

linter:
	clang-format -n ./*.c ./*.cc ./*.h

cppcheck:
	cppcheck --check-config --enable=all --suppress=missingIncludeSystem ./*.c ./*.h
	cppcheck --check-config --std=c++17 --language=c++ --enable=all --suppress=missingIncludeSystem ./opengl.cc ./opengl.h

leaks:
	@$(CC) -c $(SOURCES) $(TESTFILE)
	@$(CC) $(OBJECTS) $(TESTFILE:.c=.o) $(CHECKFLAGS) -o $(OUTTESTSNAME)
	CK_FORK=no leaks -atExit -- ./$(OUTTESTSNAME)
	@rm -rf ./*.o ./*.a ./$(OUTTESTSNAME)

valgrind:
	@$(CC) -c $(SOURCES) $(TESTFILE) -g
	@$(CC) $(OBJECTS) $(TESTFILE:.c=.o) $(CHECKFLAGS) -o $(OUTTESTSNAME)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --show-reachable=yes ./$(OUTTESTSNAME)
	@rm -rf ./*.o ./*.a ./$(OUTTESTSNAME)
