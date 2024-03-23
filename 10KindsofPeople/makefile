CC = g++
CFLAGS = -std=c++11 -g -Wall

INPUTDIR = input
OUTPUTDIR = output
CORRECTDIR = correct
FILE = 10KindsofPeople
TESTS = sample1 sample2

all: compile run

compile:
	$(CC) $(CFLAGS) $(FILE).cpp -o $(FILE).exe

run:
	./$(FILE).exe < $(INPUTDIR)/sample1.txt

test:
	for i in $(TESTS); do \
		echo $$i ;\
		./$(FILE).exe < $(INPUTDIR)/$$i.txt > $(OUTPUTDIR)/$$i.txt ;\
		diff --strip-trailing-cr ./$(OUTPUTDIR)/$$i.txt ./$(CORRECTDIR)/$$i.txt ;\
	done
