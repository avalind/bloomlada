CC=g++
TARGETNAME=test-bf

all: 
		$(CC) main.cpp hash.cpp bitvector.cpp bloomfilter.cpp -o $(TARGETNAME)

clean:
	rm -fr *o $(TARGETNAME)
