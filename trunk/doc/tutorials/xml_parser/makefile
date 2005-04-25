CC=gcc
#CFLAGS=-I/usr/include/libxml2 -L/usr/lib -lxml2 -lz -lpthread -lm
CFLAGS=`xml2-config --cflags --libs`


xmlparser: xmlparser.o libxml_example.o
	$(CC) $(CFLAGS) libxml_example.o xmlparser.o -o xmlparser

libxml_example.o: libxml_example.c libxml_example.h
	$(CC) $(CFLAGS) -c libxml_example.c -o libxml_example.o
	
xmlparser.o: xmlparser.c 
	$(CC) $(CFLAGS) -c xmlparser.c -o xmlparser.o


