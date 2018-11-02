dirty: dirty.c
	gcc dirty.c -o dirty

run: dirty
	./dirty
