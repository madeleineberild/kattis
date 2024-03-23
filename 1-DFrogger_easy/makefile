CC = g++
CFLAGS = -g -Wall

INPUTDIR = input
OUTPUTDIR = output
CORRECTDIR = correct
FILE = 1DFrogger
TESTS = sample1 sample2 left

all: compile

compile:
	$(CC) $(CFLAGS) $(FILE).cpp -o $(FILE).exe

test:
	for i in $(TESTS); do \
		echo $$i ;\
		./$(FILE).exe < $(INPUTDIR)/$$i.txt > $(OUTPUTDIR)/$$i.txt ;\
		diff --strip-trailing-cr ./$(OUTPUTDIR)/$$i.txt ./$(CORRECTDIR)/$$i.txt ;\
	done
