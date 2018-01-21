CC:=gcc  
  
fileop: fileop.o  
	$(CC) -o fileop fileop.o

fileop.o: fileop.c
	$(CC) -c fileop.c 
      
clean:  
	rm -f *.o fileop *.txt