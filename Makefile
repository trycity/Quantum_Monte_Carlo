# Top level makefile

COMMON_DIRS = src/utils
COMMON_DIRS += src/initialization
#COMMON_DIRS += src/system

#SOURCE_DIRS = src/initialization
#SOURCE_DIRS += src/system

#ARTIFACT_DIRS = logs
#ARTIFACT_DIRS += docs

.PHONY: all docs test analysis clean memcheck artifacts

all:
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make)||exit;\
	done

test:
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make test)||exit;\
	done
	
docs:
	doxygen Doxyfile
	zip -r docs/QMC_Documentation docs/latex/ docs/html/

analysis:
	for dir in $(SOURCE_DIRS); do \
	(cppcheck --enable=warning,information --check-config --suppress=missingIncludeSystem -Iutilities -Iinitialization -I$$dir \
	$$dir > logs/$$dir/cppcheck_results.txt)||exit;\
	done

# run with DEBUG=y on command line
artifacts: buildLogs analysis memcheck

buildLogs: clean
	for dir in $(COMMON_DIRS); do \
	(mkdir -p logs/$$dir)||exit;\
	done

# run with DEBUG=y on command line
memcheck: test
	for dir in $(SOURCE_DIRS); do \
	(valgrind --leak-check=yes $$dir/test/$$dir > logs/$$dir/memcheck_results.txt 2>&1)||exit;\
	done
	
	
clean: 
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make clean)||exit;\
	done
	
#	for dir in $(ARTIFACT_DIRS); do \
#	 (echo $$dir; cd $$dir; make clean)||exit;\
#	done

